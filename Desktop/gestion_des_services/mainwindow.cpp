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
