#include "ui_mainwindow.h"
#include "mainwindow.h"
#include <QIntValidator>
#include "service.h"
#include <QDesktopServices>
#include <QUrl>
#include <QFileDialog>
#include<QDate>
#include <QPainter>
#include<QPrinter>
#include <QPieSeries>
#include <QPieSlice>
#include <QtCharts/QChartView>
QT_CHARTS_USE_NAMESPACE

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->le_NUM->setValidator( new QIntValidator(100, 9999999, this));
    ui->tab_service->setModel(S.afficher());


}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pb_ajouter_clicked()
{
    int NUM=ui->le_NUM->text().toInt();
    QString Theme=ui->le_Theme->text();
    int classe=ui->la_classe->text().toInt();

    Service S(NUM,Theme,classe);

    bool test=S.ajouter();
    if(test)
    {
        ui->tab_service->setModel(S.afficher());
        QMessageBox::information(nullptr, QObject::tr("ok"),QObject::tr("Ajout effectué \n"
                                                                        "Click cancel to exit."),QMessageBox::Cancel);
    }

}

void MainWindow::on_pb_supprimer_clicked()
{
    Service S1; S1.setNUM(ui->le_num_sup->text().toInt());
    bool test=S1.supprimer(S1.getNUM());
    if(test)
    {
        ui->tab_service->setModel(S.afficher());
        QMessageBox::information(nullptr, QObject::tr("ok"),QObject::tr("suppression effectuée \n"
                                                                        "Click cancel to exit."),QMessageBox::Cancel);
    }
    else
    {
        QMessageBox::critical(nullptr,QObject::tr("not ok"),QObject::tr("suppression non effectuée\n"
                                                                        "click cancel to exit."),QMessageBox::Cancel);
    }
}

void MainWindow::on_pushButton_2_clicked()
{
    int NUM=ui->le_NUM_modif->text().toInt();
    QString Theme=ui->Theme_modif->text();
    int classe=ui->classe_modif->text().toInt();

    Service S;
    bool test;
    test=S.modifier(NUM,Theme,classe);
    if(test)
    {ui->tab_service->setModel(S.afficher());
        QMessageBox::information(nullptr,QObject::tr("OK"),QObject::tr("service modifié"),QMessageBox::Ok);

}
    else
        QMessageBox::critical(nullptr,QObject::tr("Not Ok"),QObject::tr("Erreur!./n""Click Ok to exit."),QMessageBox::Ok);


}
void MainWindow::on_comboBox_tri_currentIndexChanged(const QString &arg1)
{
    QString crit=ui->comboBox_tri->currentText();
    if(crit=="NUM")
    {
      ui->tab_service->setModel(S.afficher_S_trie_NUM());
    }
    else if (crit=="CLASSE")
    {
      ui->tab_service->setModel(S.afficher_S_trie_classe());
    }

}
void MainWindow::on_lineEdit_cherche_num_textChanged(const QString &arg1)
{
    ui->lineEdit_cherche_num->setValidator( new QIntValidator(0, 999999, this));
    if(ui->lineEdit_cherche_num->text()!="")
    {
      QString NUM=ui->lineEdit_cherche_num->text();
      ui->tab_service->setModel(S.rechercher(NUM));
    }
    else
     ui->tab_service->setModel(S.afficher());
}
QString currDate()
{
    QDate date = QDate::currentDate();
    return date.toString("dd.MM.yyyy");
}
void MainWindow::on_pb_pdf_clicked()
{

    QPrinter printer(QPrinter::HighResolution);
    printer.setOutputFormat(QPrinter::PdfFormat);
    printer.setOutputFileName("C:/Users/easytech/Desktop/PDF/services.pdf");

    QPainter painter(&printer);
    painter.drawPixmap(QRect(100,200,2500,2500),QPixmap("C:/Users/user/Desktop/Gestion_des_emloyer/valence.png"));
    int i = 4000;
    painter.setPen(Qt::blue);
    painter.setFont(QFont("Arial", 40));
    painter.drawText(3050,1400,"Liste des services");
    painter.setPen(Qt::black);
    painter.setFont(QFont("Arial", 20));
    painter.drawRect(2700,200,6500,2000);
    painter.drawRect(0,3000,9600,500);
    painter.setFont(QFont("Arial",10));
    painter.drawText(350,3300,"NUM");
    painter.drawText(1000,3300,"Theme");
    painter.drawText(2150,3300,"classe");


    QString date= currDate() ;
    painter.drawText(8500,30,date);

    QSqlQuery query;
    query.prepare("select * from SERVICE  ");
    query.exec();
    while (query.next())
    {
        painter.drawText(200,i,query.value(0).toString());
        painter.drawText(1000,i,query.value(1).toString());
        painter.drawText(2150,i,query.value(2).toString());


        i = i + 500;
    }

    int reponse = QMessageBox::question(this, "PDF généré", "Afficher le PDF ?", QMessageBox::Yes |  QMessageBox::No);
    if (reponse == QMessageBox::Yes)
    {
        QDesktopServices::openUrl(QUrl::fromLocalFile("C:/Users/easytech/Desktop/PDF/services.pdf"));

        painter.end();
    }
    if (reponse == QMessageBox::No)
    {
        painter.end();
    }
}



void MainWindow::on_pushButton_clicked()
{
     ui->tableView->setModel(S.classification());
}

void MainWindow::stats(QString table,QString critere,int valeur1,int valeur2,QString unite)
{
    QSqlQueryModel * model= new QSqlQueryModel();
    QString valeur1QString=QString::number(valeur1);
    QString valeur2QString=QString::number(valeur2);

                model->setQuery("select * from "+table+" where "+critere+"<"+valeur1QString);

                float countFirst=model->rowCount();
                model->setQuery("select * from "+table+" where " +critere+" between " +valeur1QString+ " and "+valeur2QString);
                float countSecond=model->rowCount();
                model->setQuery("select * from "+table+" where " +critere+">"+valeur2QString);
                float countThird=model->rowCount();
                float total=countFirst+countSecond+countThird;
                QString a=QString("moins de "+valeur1QString+" "+unite+" "+QString::number((countFirst*100)/total,'f',2)+"%" );

                QString b=QString("entre "+valeur1QString+ " et " +valeur2QString+" "+unite+" "+QString::number((countSecond*100)/total,'f',2)+"%" );
                QString c=QString("Plus que "+valeur2QString +" "+unite+" "+QString::number((countThird*100)/total,'f',2)+"%" );
                QPieSeries *series = new QPieSeries();
                series->append(a,countFirst);
                series->append(b,countSecond);
                series->append(c,countThird);
        if (countFirst!=0)
        {QPieSlice *slice = series->slices().at(0);
         slice->setLabelVisible();
         slice->setPen(QPen());}
        if ( countSecond!=0)
        {
                 // Add label, explode and define brush for 2nd slice
                 QPieSlice *slice1 = series->slices().at(1);
                 //slice1->setExploded();
                 slice1->setLabelVisible();
        }
       if(countThird!=0)
        {
                 // Add labels to rest of slices
                 QPieSlice *slice2 = series->slices().at(2);
                 //slice1->setExploded();
                 slice2->setLabelVisible();
        }
                // Create the chart widget
                QChart *chart = new QChart();
                // Add data to chart with title and hide legend
                chart->addSeries(series);
                if(critere=="CLASSE")
                    critere="classe";
                chart->setTitle("Pourcentage Par " +critere+":Nombre Des " +table+" :" +QString::number(total));
                chart->legend()->hide();
                // Used to display the chart
                QChartView *chartView = new QChartView(chart);
                chartView->setRenderHint(QPainter::Antialiasing);
                chartView->resize(1000,500);
                chartView->show();

}

void MainWindow::on_pushButton_5_clicked()
{
    stats("SERVICE","CLASSE",1,5,"TYPES");
}
