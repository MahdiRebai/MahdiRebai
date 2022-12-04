#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "evenement.h"
#include <QIntValidator>
#include <QMessageBox>
#include <QSqlQuery>
#include <QPrinter>
#include <QPrintDialog>
#include "stats_event.h"
#include <QtCharts>
#include <QChartView>
#include <QLineSeries>
#include<QtDebug>
#include "arduino.h"
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
#include <QDebug>
#include "statclient.h"
#include "client.h"
#include "avis.h"
#include "notification.h"
#include <QPropertyAnimation>
#include <QPalette>
#include <dialog.h>

void MainWindow::update_label()
{
    qDebug() <<"arduino";
}

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->tableView_2->setModel(p.afficher());
    ui->cbref->setModel(p.affichervaleur("REFERENCE"));
    ui->sup_ref->setModel(p.affichervaleur("REFERENCE"));
    ui->TWW->tabBar()->hide();

    ui->sup_ref_2->setModel(p.affichervaleur("REFERENCE"));
    int ret=A.connect_arduino();
    switch(ret)
       {case(0):qDebug()<< "arduino is available and connected to :" << A.getarduino_port_name();
        break;
        case(1):qDebug()<< "arduino is available but not connected to :"<< A.getarduino_port_name();
            break;
          case(-1):qDebug()<<"arduino is not available";
         }
    QObject::connect(A.getserial(),SIGNAL(readyRead()),this,SLOT(update_label()));


   // ui->laREF->setValidator( new QIntValidator(0, 99999, this));
    ui->leNUMS->setValidator( new QIntValidator(0, 99, this));
    ui->leCIN->setValidator( new QIntValidator(0, 999999, this));
    ui->TabEv->setModel(E.afficher(ui->lineEdit_recherche->text(),ui->comboBox_ordre->currentText(),ui->comboBox_parametre->currentText()));
    ui->tableView_penalite->setModel(P.afficher(ui->lineEdit_refpen->text()));
    //ui->tbview->setModel(E.afficher_standby());
    ui->tabWidget_2->tabBar()->hide();
    ui->tabWidget_6->tabBar()->hide();
    ui->tabservice->tabBar()->hide();
    ui->ZINA->hide();
    ui->ZINA_2->hide();
    ui->ZINA_3->hide();
    ui->ZINA_7->hide();
    ui->ZINA_9->hide();

    //ui->LEX->setReadOnly("events");

   /* animation =new QPropertyAnimation(ui->pushButton_26,"geometry");
    animation->setDuration(3000);
    animation->setStartValue(ui->pushButton_26->geometry());
    animation->setEndValue(QRect(480,500,300,100));
    animation->start();*/

    ui->ntableView->setModel(cl.afficher());
    ui->ncomboBox_3->setModel(cl.afficheroncombo());
    ui->cb_idclient->setModel(cl.afficheroncombo());
    ui->tableView_rdv->setModel(r.afficherrdv());
    //controle aziz
    ui->tableView_2->setModel(p.afficher());
    //ui->lineEdit_ref->setValidator(new QIntValidator(1,99999999,this));
    ui->sup_ref->setModel(p.affichervaleur("REFERENCE"));
    //ui->comboBox_3->setModel(p.affichervaleur("REFERENCE"));
    ui->sup_ref_2->setModel(p.affichervaleur("REFERENCE"));
    //controle louay
    ui->tab_c->setModel(Etmp.afficher());
    QRegularExpression rx("\\b[A-Z._%+-]+@[A-Z.-]+\\.[A-Z]\\b",
                                          QRegularExpression::CaseInsensitiveOption);
                ui->Objet->setValidator(new QRegularExpressionValidator(rx, this));
                ui->Num_avis->setValidator( new QIntValidator(0, 999999, this));
                QRegularExpression rx1("\\b[A-Z._%+-]+@[A-Z.-]+\\.[A-Z]\\b",
                                                      QRegularExpression::CaseInsensitiveOption);
                            ui->Nom->setValidator(new QRegularExpressionValidator(rx1, this));
                            QRegularExpression rx2("\\b[A-Z._%+-]+@[A-Z.-]+\\.[A-Z]\\b",
                                                                  QRegularExpression::CaseInsensitiveOption);
                                        ui->Reclamation->setValidator(new QRegularExpressionValidator(rx2, this));
 //stat aziz

                                        QSqlQuery *query = p.statistique();
                                        QPieSeries *series = new QPieSeries();
                                        // carte bancaire Cheque Espece
                                        int montantCheque =0;
                                        int montantEspece =0;
                                        int montantCarte =0;
                                        while ( query->next() ){
                                            if ( query->value(2).toString() == "Carte bancaire"){
                                                montantCarte+= query->value(1).toInt();
                                            }
                                            if ( query->value(2).toString() == "Cheque"){
                                                montantCheque+= query->value(1).toInt();
                                            }
                                            if ( query->value(2).toString() == "Espece"){
                                                montantEspece+= query->value(1).toInt();
                                            }
                                        }

                                        series->append("Cheque", montantCheque);
                                        series->append("carte Bancaire", montantCarte);
                                        series->append("Especes", montantEspece);

                                        QChart *chart = new QChart();
                                        chart->addSeries(series);
                                        chart->setTitle("statistique type de paiements");

                                        QChartView *chartView = new QChartView(chart);
                                        chartView->setParent(ui->horizontalFrame);




    //ui->tbview->setModel(E.afficher_simple());

    chartevent = new QChart();
    QChartView *chartViewEvents= new QChartView(chartevent);
    chartViewEvents->setRenderHint(QPainter::Antialiasing);
    //chartViewEvents->setParent(ui->horizontalFrame);

//exemplee youtube
 /* QLineSeries *series =new QLineSeries();
  series->append(0,6);
  series->append(2,4);
  series->append(3,8);
  series->append(7,4);
  series->append(10,5);

  *series <<QPointF(11,1)<< QPointF(13,3)<<QPointF(17,6)<<QPointF(18,3)
         <<QPointF(20,2);
       QChart *chart =new QChart();
       chart->legend()->hide();
       chart->addSeries(series);
       chart->setTitle("Line chart");

       QChartView *chartView =new QChartView(chart);
       chartView->setRenderHint(QPainter::Antialiasing);
       chartView->setParent(ui->horizontalFrame);*/

    ui->le_NUM->setValidator( new QIntValidator(100, 9999999, this));
    ui->tab_service->setModel(S.afficher());
    //timerId = startTimer(5000);


}

MainWindow::~MainWindow()
{
    delete ui;
}



void MainWindow::on_lineEdit_2_returnPressed()
{
    ui->stackedWidget->setCurrentIndex(1);
}

void MainWindow::on_pushButton_clicked()
{       QString testname="";
             QString testpwd="";

    QString input=ui->name->text();
    QString input2=ui->pwd->text();
            testname=E.getname(input);
            testpwd=E.getpwd(input2);
    //if((testname!="")&&(testpwd!=""))



                 QMessageBox msgBox;
                 if((testname!="")&&(testpwd!=""))
                 {
                     QMessageBox::information(nullptr, QObject::tr("database is open"),
                                 QObject::tr("login successful.\n"
                                             "Click Cancel to exit."), QMessageBox::Cancel);
                    ui->stackedWidget->setCurrentIndex(3);
             }
                 else
                  {
                     QMessageBox::critical(nullptr, QObject::tr("database is not open"),
                                 QObject::tr("login failed.\n"
                                             "Click Cancel to exit."), QMessageBox::Cancel);}

}
void MainWindow::on_testtt_clicked()
{
    QString testname="";
              QString testpwd="";

     QString input=ui->name->text();
     QString input2=ui->pwd->text();
             testname=E.getname(input);
             testpwd=E.getpwd(input2);

     if(testname!="")
     ui->stackedWidget->setCurrentIndex(3);
}
void MainWindow::on_pushButton_2_clicked()
{
   ui->stackedWidget->setCurrentIndex(2);
}

void MainWindow::on_pushButton_3_clicked()
{
      ui->stackedWidget->setCurrentIndex(2);
}



void MainWindow::on_pushButton_7_clicked()
{
 ui->stackedWidget->setCurrentIndex(2);}

void MainWindow::on_pbcancel_2_clicked()
{
     ui->stackedWidget->setCurrentIndex(3);
}

void MainWindow::on_pbcancel_3_clicked()
{
      ui->stackedWidget->setCurrentIndex(3);
}


void MainWindow::on_ooo_clicked()
{  QString input=ui->ldd->text();


    QMessageBox msgBox;

    if(input=="0000")
       { ui->tv44->setModel(E.show());
      }
    else if(input=="")
    { QMessageBox::critical(nullptr, QObject::tr("database is not open"),
                            QObject::tr("code secret incorrect.\n"
                                        "Click Cancel to exit."), QMessageBox::Cancel);}
    else
     {
        QMessageBox::critical(nullptr, QObject::tr("database is not open"),
                    QObject::tr("code secret incorrect.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);}


}




void MainWindow::on_BUTTNEXT_clicked()
{
     ui->stackedWidget->setCurrentIndex(3);
}


void MainWindow::on_CONFIRM_clicked()
{
    QString input=ui->lineEdit_4->text();
    QString input1=ui->lineEdit_5->text();

    QSqlQuery query;
    QString queryText ="INSERT INTO agents (name,pwd) VALUES (\'" + input +"\', \'" + input1 +"\')";
            query.prepare(queryText) ;
            query.bindValue("\'" + input +"\'", input);
            query.bindValue("\'" + input1 +"\'",input1);
    QMessageBox msgBox;
    {
        QMessageBox::information(nullptr, QObject::tr("database is open"),
                    QObject::tr("sign up successful.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);
       ui->stackedWidget->setCurrentIndex(1);}
}



void MainWindow::on_lock_clicked()
{

   ui->stackedWidget->setCurrentIndex(4);


}











void MainWindow::on_RETOUR_clicked()
{
     ui->stackedWidget->setCurrentIndex(0);}

void MainWindow::on_pushButton_26_clicked()
{
     ui->stackedWidget->setCurrentIndex(1);
}

void MainWindow::on_SERVICE_butt_clicked()
{
     ui->stackedWidget->setCurrentIndex(4);
}
void MainWindow::on_pushButton_24_clicked()
{
    ui->stackedWidget_2->setCurrentIndex(0);
    ui->ZINA->hide();
    ui->ZINA_2->hide();
    ui->ZINA_3->hide();
    ui->ZINA_7->hide();
    ui->ZINA_9->hide();


}


void MainWindow::on_pushButton_19_clicked()
{            ui->ZINA->hide();
             ui->ZINA_3->hide();
                      ui->ZINA_9->hide();
                      ui->ZINA_7->hide();

     ui->stackedWidget_2->setCurrentIndex(1);
     ui->ZINA_2->show();
}


void MainWindow::on_pushButton_21_clicked()
{        ui->ZINA_2->hide();
         ui->ZINA_3->hide();
              ui->ZINA_9->hide();

              ui->ZINA_7->hide();

     ui->stackedWidget_2->setCurrentIndex(2);
     ui->ZINA->show();
}

void MainWindow::on_pushButton_20_clicked()
{ui->ZINA->hide();
    ui->ZINA_2->hide();
    ui->ZINA_9->hide();

    ui->ZINA_3->show();

     ui->stackedWidget_2->setCurrentIndex(3);
}

void MainWindow::on_pushButton_22_clicked()
{    ui->ZINA_7->hide();
     ui->ZINA_9->show();


     ui->stackedWidget_2->setCurrentIndex(4);
     ui->ZINA->hide();
     ui->ZINA_3->hide();
     ui->ZINA_2->hide();
}

void MainWindow::on_pushButton_23_clicked()
{
     ui->stackedWidget_2->setCurrentIndex(5);
     ui->ZINA->hide();
     ui->ZINA_3->hide();
     ui->ZINA_9->hide();

     ui->ZINA_2->hide();
     ui->ZINA_7->show();
}


void MainWindow::on_PBRECHERCHE_clicked()
{
    ui->tabWidget_2->setCurrentIndex(4);
}

void MainWindow::on_PSSTATS_clicked()
{
     ui->tabWidget_2->setCurrentIndex(0);
     /*stats_event *stat = new stats_event ;
     QLineSeries *series = stat ->Money_Stats("12") ;

    chartevent->legend()->hide();
    chartevent->addSeries(series);
    chartevent->setTitle("LINE CHART ONE");*/



}

void MainWindow::on_PBFICHIER_clicked()
{
     ui->tabWidget_2->setCurrentIndex(1);
}

void MainWindow::on_PBANNULER_clicked()
{
     ui->tabWidget_2->setCurrentIndex(2);
}

void MainWindow::on_PBREPORTER_clicked()
{
     ui->tabWidget_2->setCurrentIndex(3);
     ui->tableView_penalite->setModel(P.afficher(ui->lineEdit_refpen->text()));

}
// boutton ajouter base de données
void MainWindow::on_PbAjouter_clicked()
{   QString ref=ui->laREF->text();
    int PRIX=ui->lineEdit_price->text().toInt();
    int cin=ui->leCIN->text().toInt();

    int numS=ui->leNUMS->text().toInt();
     Evenement E(ref,cin,numS,PRIX);
     E.set_prix(ui->lineEdit_price->text().toInt());
     bool test=E.ajouter(ui->dateEvent->text());
     qDebug() <<test ;

     QMessageBox msgBox;
     if(test)
     {
         QMessageBox::information(nullptr, QObject::tr("database is open"),
                     QObject::tr("ajout successful.\n"
                                 "Click Cancel to exit."), QMessageBox::Cancel);
         ui->TabEv->setModel(E.afficher(ui->lineEdit_recherche->text(),ui->comboBox_ordre->currentText(),ui->comboBox_parametre->currentText()));

 }
     else
      {
         QMessageBox::critical(nullptr, QObject::tr("database is not open"),
                     QObject::tr("ajout failed.\n"
                                 "Click Cancel to exit."), QMessageBox::Cancel);}

}

void MainWindow::on_TR_clicked()
{
     ui->tabWidget_2->setCurrentIndex(5);
}
// bouton afficher
void MainWindow::on_pushButton_5_clicked()
{
    ui->TabEv->setModel(E.afficher(ui->lineEdit_recherche->text(),ui->comboBox_ordre->currentText(),ui->comboBox_parametre->currentText()));


}
//bouton supprimer dce la base données

void MainWindow::on_SuppButt_clicked()
{
    Evenement E1;

    E1.setRef(ui->LineSupp->text());
     bool test=E1.supprimer(E1.getRef());
     QMessageBox msgBox;
     if(test)
     {
         QMessageBox::information(nullptr, QObject::tr("database is open"),
                     QObject::tr("suppression successful.\n"
                                 "Click Cancel to exit."), QMessageBox::Cancel);
         ui->TabEv->setModel(E.afficher(ui->lineEdit_recherche->text(),ui->comboBox_ordre->currentText(),ui->comboBox_parametre->currentText()));

 }
     else
      {   QMessageBox::critical(nullptr, QObject::tr("database is not open"),
                     QObject::tr("suppression failed.\n"
                                 "Click Cancel to exit."), QMessageBox::Cancel);}
}

// bouton suprimer de la base de données

void MainWindow::on_ajout_clicked()
{
    ui->tabWidget_6->setCurrentIndex(0);
}

void MainWindow::on_affichage_clicked()
{
    ui->tabWidget_6->setCurrentIndex(1);
}

void MainWindow::on_supprimer_clicked()
{
    ui->tabWidget_6->setCurrentIndex(2);
}

void MainWindow::on_modifier_clicked()
{
    ui->tabWidget_6->setCurrentIndex(3);
}

void MainWindow::on_option_clicked()
{
    ui->tabWidget_2->setCurrentIndex(5);
}
//bouton modifier
void MainWindow::on_PBmodifierX_clicked()
{
    QString ref=ui->LineMod->text();
    int cin=ui->LineCin->text().toInt();
    int numS=ui->LineNumS->text().toInt();
    int PRIX=ui->pxB->text().toInt();

    Evenement E;
    bool test;

    test=E.modifier(ref,cin,numS,PRIX);
    if(test)

    {  ui->TabEv->setModel(E.afficher(ui->lineEdit_recherche->text(),ui->comboBox_ordre->currentText(),ui->comboBox_parametre->currentText()));
        QMessageBox::information(nullptr, QObject::tr("database is open"),
                    QObject::tr("modification successful.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);}
    else
    {
        QMessageBox::critical(nullptr, QObject::tr("database is not open"),
                            QObject::tr("modification failed.\n"
                                        "Click Cancel to exit."), QMessageBox::Cancel);}

    }




/*void MainWindow::on_ajout_clicked()
{
    ui->tabWidget_6->setCurrentIndex(0);
}
*/

void MainWindow::on_comboBox_ordre_currentTextChanged(const QString &arg1)
{
    ui->TabEv->setModel(E.afficher(ui->lineEdit_recherche->text(),ui->comboBox_ordre->currentText(),ui->comboBox_parametre->currentText()));

}

void MainWindow::on_comboBox_parametre_currentTextChanged(const QString &arg1)
{
    ui->TabEv->setModel(E.afficher(ui->lineEdit_recherche->text(),ui->comboBox_ordre->currentText(),ui->comboBox_parametre->currentText()));

}

/*void MainWindow::on_lineEdit_recherche_textChanged(const QString &arg1)
{
//    ui->TabEv->setModel(E.afficher(ui->lineEdit_recherche->text(),ui->comboBox_ordre->currentText(),ui->comboBox_parametre->currentText()));

}

void MainWindow::on_tettt_clicked()
{
    QString ref=ui->laREF->text();

        int cin=ui->leCIN->text().toInt();

        int numS=ui->leNOMS->text().toInt();
         Evenement E(ref,cin,numS);
         bool test=E.ajouter();
         QMessageBox msgBox;
         if(test)
         {
             QMessageBox::information(nullptr, QObject::tr("database is open"),
                         QObject::tr("ajout successful.\n"
                                     "Click Cancel to exit."), QMessageBox::Cancel);
             ui->TabEv->setModel(E.afficher(ui->lineEdit_recherche->text(),ui->comboBox_ordre->currentText(),ui->comboBox_parametre->currentText()));
}}

*/

void MainWindow::on_pdf_clicked()
{
         QSqlQuery query("select * from events") ;
         QString text="        ***** events  *****      \n \n " ;
         QString a,b,c,d,e,f,g;


          while (query.next())
          {
            a=query.value(0).toString();
            b=query.value(1).toString();
            c=query.value(2).toString();
            d=query.value(3).toString();
            e=query.value(4).toString();
            f=query.value(5).toString();
            text += "\n reference : "+a+"\n\n - CIN : "+b+"\n  - - NUMS : "+c+"\n  - - PRIX : "+d+"\n  - - DateR : "+e+"\n  - - DateM : "+f+"\n  - - PANALITE : "+g+"\n";

         }
                 ui->textEdit->setText(text);
                 QPrinter printer ;
                 printer.setPrinterName("impression");
                 QPrintDialog dialog (&printer,this);
                 if(dialog.exec()==QDialog::Rejected) return ;
                 ui->textEdit->print(&printer);

}


void MainWindow::on_lineEdit_refpen_returnPressed()
{
    ui->tableView_penalite->setModel(P.afficher(ui->lineEdit_refpen->text()));

}



/*void MainWindow::on_pushButton_34_clicked()
{



}
*/

void MainWindow::on_pushButton_RE_clicked()
{
    A.write_to_arduino("2");

    P.updateDate(ui->lineEdit_refpen->text(),ui->dateEdit_reporter->text()) ;
    P.penality(ui->lineEdit_refpen->text()) ;
    ui->tableView_penalite->setModel(P.afficher(ui->lineEdit_refpen->text()));
}




void MainWindow::on_xe_clicked()
{
    qDebug()<< "NEZLET" ;
    P.updateDate(ui->rerfann->text(),ui->dateEdit_annuler->text()) ;
    int penTheme =P.penalite_theme(ui->rerfann->text()) ;
      if (P.penality2(ui->rerfann->text(),penTheme))
          qDebug() << "cbn";
      else {
          qDebug() << "mochkol";

      }

    ui->annview->setModel(P.afficher(ui->rerfann->text()));
}


void MainWindow::on_TESTTT_clicked()
{

    P.updateDate(ui->rerfann->text(),ui->dateEdit_annuler->text()) ;
    int penTheme =P.penalite_theme(ui->rerfann->text()) ;
    qDebug()<< "penTheme" <<penTheme ;
     P.penality2(ui->rerfann->text(),penTheme);
    qDebug()<<P.get_sound();
     if (P.get_sound()==1)
          {
         A.write_to_arduino("1");
         P.set_sound(0) ;
     }

     ui->annview->setModel(P.afficher(ui->rerfann->text()));
    /* if (P.get_sound()==1)
    {A.write_to_arduino("1");
         P.set_sound(0);
     }*/
}

void MainWindow::on_pd2_clicked()
{
    QSqlQuery query("select * from events") ;
    QString text="        ***** events  *****      \n \n " ;
    QString a,b,c,d,e,f,g;


     while (query.next())
     {
       a=query.value(0).toString();
       b=query.value(1).toString();
       c=query.value(2).toString();
       d=query.value(3).toString();
       e=query.value(4).toString();
       f=query.value(5).toString();
       text += "\n reference : "+a+"\n\n - CIN : "+b+"\n  - - NUMS : "+c+"\n  - - PRIX : "+d+"\n  - - DateR : "+e+"\n  - - DateM : "+f+"\n";
       //  - - PANALITE : "+g+"*/\n

    }
            ui->textEdit->setText(text);
            QPrinter printer ;
            printer.setPrinterName("impression");
            QPrintDialog dialog (&printer,this);
            if(dialog.exec()==QDialog::Rejected) return ;
            ui->textEdit->print(&printer);
}






void MainWindow::on_pushan_clicked()
{
     A.write_to_arduino("1");

}

void MainWindow::on_pushcon_clicked()
{
     A.write_to_arduino("2");
}

void MainWindow::on_ARDPUSH_clicked()
{
    //ui->tbview->setModel(E.afficher_standby());
    //->TabEv->setModel(E.afficher(ui->lineEdit_recherche->text(),ui->comboBox_ordre->currentText(),ui->comboBox_parametre->currentText()));
  //  ui->tbview->setModel(E.afficher_simple());

}

void MainWindow::on_buttard_clicked()
{
    ui->stackedWidget->setCurrentIndex(4);
}

void MainWindow::on_retourbutt_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);

}


void MainWindow::on_pbajouter_clicked()
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

void MainWindow::on_pbmodif_clicked()
{
    int NUM=ui->le_NUM_modif->text().toInt();
    QString Theme=ui->Theme_modif->text();
    int classe=ui->classe_modif->text().toInt();

    Service S;
    bool test;
    test=S.modifier(NUM,Theme,classe);
    if(test)
    {
        ui->tab_service->setModel(S.afficher());
        QMessageBox::information(nullptr,QObject::tr("OK"),QObject::tr("service modifié"),QMessageBox::Ok);

}
    else
        QMessageBox::critical(nullptr,QObject::tr("Not Ok"),QObject::tr("Erreur!./n""Click Ok to exit."),QMessageBox::Ok);


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
QString currDate()
{
    QDate date = QDate::currentDate();
    return date.toString("dd.MM.yyyy");
}
void MainWindow::on_pb_pdf_clicked()
{
    QPrinter printer(QPrinter::HighResolution);
    printer.setOutputFormat(QPrinter::PdfFormat);
    printer.setOutputFileName("C:/Users/hichem rebai/Desktop/PDF/services.pdf");

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
        QDesktopServices::openUrl(QUrl::fromLocalFile("C:/Users/hichem rebai/Desktop/PDF/services.pdf"));

        painter.end();
    }
    if (reponse == QMessageBox::No)
    {
        painter.end();
    }
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
         slice->setPen(QPen());
        //slice->setColor("#b3404a");
        slice->setColor("#facdc8");}


        if ( countSecond!=0)
        {
                 // Add label, explode and define brush for 2nd slice
                 QPieSlice *slice1 = series->slices().at(1);
                 //slice1->setExploded();
                  slice1->setColor("#facdc8");
                 slice1->setLabelVisible();
        }
       if(countThird!=0)
        {
                 // Add labels to rest of slices
                 QPieSlice *slice2 = series->slices().at(2);
                 //slice1->setExploded();
                 slice2->setLabelVisible();
                 slice2->setColor("#b3404a");
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
                chartView->show();}
void MainWindow::on_pbstatservice_clicked()
{ stats("SERVICE","CLASSE",1,2,"TYPES");

}
void MainWindow::statm(QString table,QString critere,int valeur1,int valeur2,QString unite)
{  QSqlQueryModel * model= new QSqlQueryModel();
    QString valeur1QString=QString::number(valeur1);
    QString valeur2QString=QString::number(valeur2);

                model->setQuery("select * from "+table+" where "+critere+"="+valeur1QString);

                float countFirst=model->rowCount();
                model->setQuery("select * from "+table+" where "+critere+"="+valeur2QString);

                float countSecond=model->rowCount();

                float total=countFirst+countSecond;
                QString a=QString("le pourcentage des ETAT= "+valeur1QString+"  "" est "+QString::number((countFirst*100)/total,'f',2)+"%" );

                QString b=QString("le pourcentage des ETAT= "+valeur2QString+" "" est "+QString::number((countSecond*100)/total,'f',2)+"%" );

                QPieSeries *series = new QPieSeries();
                series->append(a,countFirst);
                series->append(b,countSecond);
        if (countFirst!=0)
        {QPieSlice *slice = series->slices().at(0);
         slice->setLabelVisible();
         //slice->setColor("#ffe4e1");
         slice->setColor("#b3404a");


         slice->setPen(QPen());}
        if ( countSecond!=0)
        {
                 // Add label, explode and define brush for 2nd slice
                 QPieSlice *slice1 = series->slices().at(1);
                 slice1->setColor("#facdc8");
                 //slice1->setExploded();
                 slice1->setLabelVisible();
        }

                // Create the chart widget
                QChart *chart = new QChart();
                // Add data to chart with title and hide legend
                chart->addSeries(series);

                if(critere=="ETAT")
                    critere="ETAT";
                chart->setTitle("Pourcentage Par " +critere+" : Nombre des événements " ":" +QString::number(total));

                // Used to display the chart
                QChartView *chartView = new QChartView(chart);
                chartView->setRenderHint(QPainter::Antialiasing);
                chartView->resize(1000,500);
                chart->legend()->show();
                chartView->show();
}


void MainWindow::on_testing_clicked()
{
     statm("EVENTS","ETAT",0,1,"TYPES");

}


void MainWindow::on_pushButtonclasser_clicked()
{
    ui->tableView->setModel(S.classification());

}
void MainWindow::on_pbpromo_clicked()
{
   qDebug()<<"test";
    ui->tbviewpro->setModel(S.Promotion());


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

void MainWindow::on_lineEdit_chercher_num_textChanged(const QString &arg1)
{
    ui->lineEdit_chercher_num->setValidator( new QIntValidator(0, 999999, this));
    if(ui->lineEdit_chercher_num->text()!="")
    {
      QString NUM=ui->lineEdit_chercher_num->text();
      ui->tab_service->setModel(S.rechercher(NUM));
    }
    else
     ui->tab_service->setModel(S.afficher());
}

void MainWindow::on_ajj_clicked()
{
    ui->tabservice->setCurrentIndex(0);
}

void MainWindow::on_modd_clicked()
{    ui->tabservice->setCurrentIndex(1);


}

void MainWindow::on_supp_clicked()
{
    ui->tabservice->setCurrentIndex(2);

}


void MainWindow::on_aff_clicked()
{ ui->tab_service->setModel(S.afficher());
    ui->tabservice->setCurrentIndex(3);

}


void MainWindow::on_stat_clicked()
{
    ui->tabservice->setCurrentIndex(4);

}

void MainWindow::on_classif_clicked()
{
    ui->tabservice->setCurrentIndex(5);

}

void MainWindow::on_promo_clicked()
{
    ui->tabservice->setCurrentIndex(6);

}

void MainWindow::on_ard_clicked()
{
    ui->tabservice->setCurrentIndex(7);

}

void MainWindow::on_npushButton_clicked()
{
    int cin=ui->aj_cin->text().toInt();
    QString nom=ui->aj_nom->text();
    QString prenom=ui->aj_pren->text();
    int tel=ui->aj_tel->text().toInt();
    QString mail=ui->aj_mail->text();
    QString sexe=ui->cb_sexe->currentText();
Client c(cin,nom,prenom,tel,mail,sexe);

bool test=c.ajouter();
QMessageBox msgBox;

if(test)
  {
ui->cb_idclient->setModel(cl.afficheroncombo());
    msgBox.setText("Ajout avec succes.");
    ui->ntableView->setModel(c.afficher());
    ui->ncomboBox_3->setModel(cl.afficheroncombo());
  }
else
{
    msgBox.setText("Echec d'ajout");
    msgBox.exec();

}
}


void MainWindow::on_npushButton_2_clicked()
{
    int cin=ui->aj_cin->text().toInt();
        QString nom=ui->aj_nom->text();
        QString prenom=ui->aj_pren->text();
        int tel=ui->aj_tel->text().toInt();
        QString mail=ui->aj_mail->text();
        QString sexe=ui->cb_sexe->currentText();
        bool    test=cl.modifier(cin,nom,prenom,tel,mail,sexe) ;
              if (test)
              {
    ui->cb_idclient->setModel(cl.afficheroncombo());

     ui->ntableView->setModel(cl.afficher());
                  QMessageBox::information(nullptr,QObject::tr("OK"),
                                       QObject::tr("modification établie"),
                                       QMessageBox::Ok);}
              else{
              QMessageBox::critical(nullptr,QObject::tr("ERROR404"),
                                      QObject::tr("modification non établie"),
                                      QMessageBox::Cancel);}
}



void MainWindow::on_ncomboBox_3_currentIndexChanged(int index)
{
    ui->ncomboBox_3->currentText();

}

void MainWindow::on_npushButton_3_clicked()
{
    bool test=cl.supprimer(ui->ncomboBox_3->currentText().toInt());
    bool test1=r.supprimerrdv(ui->ncomboBox_3->currentText().toInt());
    if(test)
    { ui->ntableView->setModel(cl.afficher());
        ui->ncomboBox_3->setModel(cl.afficheroncombo());
        ui->tableView_rdv->setModel(r.afficherrdv());

    ui->cb_idclient->setModel(cl.afficheroncombo());
        //actualisation taa afficher
            QMessageBox::information(nullptr,QObject::tr("ok"),
                                     QObject::tr("suppression succful .\n"),
                    QMessageBox::Cancel);
        }

        else
            QMessageBox::critical(nullptr,QObject::tr("supprimer not open"),
                                    QObject::tr("click cancel to exist"),
                                    QMessageBox::Cancel);
}

void MainWindow::on_npushButton_5_clicked()
{
    cl.excel(ui->ntableView);

}


void MainWindow::on_npushButton_4_clicked()
{
    QString colone=ui->colone_tri->currentText();
        QString ordre=ui->ordre_tri->currentText();
        Client c;
        ui->ntableView->setModel(c.tri(colone,ordre));
}



void MainWindow::on_lineEdit_rech_textChanged(const QString &arg1)
{
    QSqlQueryModel *model= new QSqlQueryModel();
            QSqlQuery   *query= new QSqlQuery();
    if(ui->comboBox_rech->currentText()=="CIN"
            ){
        query->prepare("SELECT * FROM client WHERE cin LIKE'"+arg1+"%'");//
query->exec();
    model->setQuery(*query);
ui->ntableView->setModel(model);


    }
    else {
        if(ui->comboBox_rech->currentText()=="NOM"){
            query->prepare("SELECT * FROM CLIENT WHERE NOM LIKE'"+arg1+"%'");//+tri
    query->exec();
        model->setQuery(*query);
    ui->ntableView->setModel(model);
        }
        else{
            if(ui->comboBox_rech->currentText()=="PRENOM")
                query->prepare("SELECT * FROM CLIENT WHERE PRENOM LIKE'"+arg1+"%'");//+tri
        query->exec();
            model->setQuery(*query);
        ui->ntableView->setModel(model);
            }

        }
}

void MainWindow::on_b_aj_rdv_clicked()
{
    rdv rd(ui->cb_idclient->currentText().toInt(),ui->dateEdit->text());
    bool test=rd.ajRdv();
     ui->tableView_rdv->setModel(r.afficherrdv());
      ui->cb_idclient->setModel(cl.afficheroncombo());
}

void MainWindow::on_npushButton_6_clicked()
{
    bool    test=r.modifrdv(ui->cb_idclient->currentText().toInt(),ui->dateEdit->text());
          if (test)
          {
ui->cb_idclient->setModel(cl.afficheroncombo());
ui->tableView_rdv->setModel(r.afficherrdv());
 ui->cb_idclient->setModel(cl.afficheroncombo());
 ui->ntableView->setModel(cl.afficher());
              QMessageBox::information(nullptr,QObject::tr("OK"),
                                   QObject::tr("modification établie"),
                                   QMessageBox::Ok);}
          else{
          QMessageBox::critical(nullptr,QObject::tr("ERROR404"),
                                  QObject::tr("modification non établie"),
                                  QMessageBox::Cancel);}
}

void MainWindow::on_npushButton_7_clicked()
{
    stat_client=new statclient(this);
    stat_client->show();
}

void MainWindow::on_cb_idclient_currentIndexChanged(int index)
{
    ui->cb_idclient->currentText();

}

void MainWindow::on_ajouter_clicked()
{
    notification n;
    int Numavis=ui->Num_avis->text().toInt();
    QString Nom=ui->Nom->text();
    QString Objet=ui->Objet->text();
    QString Reclamation=ui->Reclamation->text();

    avis C(Numavis,Nom,Objet,Reclamation);
     bool test=C.ajouter();
     QMessageBox msgBox ;

     if  ((ui->Num_avis->text().isEmpty())||(ui->Nom->text().isEmpty())||(ui->Objet->text().isEmpty())||(ui->Reclamation->text().isEmpty()))
     {

 QMessageBox::warning(this,"we deliver","Veuillez remplir les champs obligatoires marqués en rouge");}
     else {
     if(test)
     { msgBox.setText(" ajout avec succes.") ;
         n.notification_ajout();
        ui->tab_c->setModel(C.afficher());}
     else
          msgBox.setText("echec.") ;
         msgBox.exec();}

}



void MainWindow::on_modifier_2_clicked()
{
    QString Nom=ui->Nom->text();
    QString Objet=ui->Objet->text();
    QString Reclamation=ui->Reclamation->text();
    int Numavis=ui->Num_avis->text().toInt();

    avis a (QString,QString,QString,int);
    Etmp.setNom(Nom);
    Etmp.setObjet(Objet);
    Etmp.setReclamation(Reclamation);
   bool test=Etmp.modifier(Etmp.getNum_avis());
   if (test)
   {
       ui->tab_c->setModel(Etmp.afficher());

       QMessageBox::information(nullptr,QObject::tr("ok"),
                                QObject::tr("modif effectué\n"
                                            "Click Cancel to exit."),QMessageBox::Cancel);



   }
   else QMessageBox::critical(nullptr,QObject::tr("NOT OK"),
                         QObject::tr("modif non effectué.\n"
                                     "Click Cancel to exit."), QMessageBox::Cancel);
}

void MainWindow::on_tri_nom_clicked()
{
    avis r;
       ui->tab_c->setModel(r.trier1());
}

void MainWindow::on_tri_cin_clicked()
{

    avis r;
       ui->tab_c->setModel(r.trier2());
}

void MainWindow::on_tri_pass_clicked()
{
    avis r;
    ui->tab_c->setModel(r.trier());
}




void MainWindow::on_supprimer_3_clicked()
{
    avis C;
    ui->tab_c->setModel(C.afficher());
}

void MainWindow::on_supprimer_4_clicked()
{
    QString strStream;
            QTextStream out(&strStream);

            const int rowCount = ui->tab_c->model()->rowCount();
            const int columnCount = ui->tab_c->model()->columnCount();

            out <<  "<html>\n"
                "<head>\n"
                "<meta Content=\"Text/html; charset=Windows-1251\">\n"
                <<  QString("<title>%1</title>\n").arg("strTitle")
                <<  "</head>\n"
                "<body bgcolor=#ffffff link=#5000A0>\n"

                //     "<align='right'> " << datefich << "</align>"
                "<center> <H1>Liste Des Reclamation </H1></br></br><table border=1 cellspacing=0 cellpadding=2>\n";

            // headers
            out << "<thead><tr bgcolor=#f0f0f0> <th>Numero</th>";
            for (int column = 0; column < columnCount; column++)
                if (!ui->tab_c->isColumnHidden(column))
                    out << QString("<th>%1</th>").arg(ui->tab_c->model()->headerData(column, Qt::Horizontal).toString());
            out << "</tr></thead>\n";

            // data table
            for (int row = 0; row < rowCount; row++)
            {
                out << "<tr> <td bkcolor=0>" << row + 1 << "</td>";
                for (int column = 0; column < columnCount; column++)
                {
                    if (!ui->tab_c->isColumnHidden(column))
                    {
                        QString data = ui->tab_c->model()->data(ui->tab_c->model()->index(row, column)).toString().simplified();
                        out << QString("<td bkcolor=0>%1</td>").arg((!data.isEmpty()) ? data : QString("&nbsp;"));
                    }
                }
                out << "</tr>\n";
            }
            out <<  "</table> </center>\n"
                "</body>\n"
                "</html>\n";

            QString fileName = QFileDialog::getSaveFileName((QWidget * )0, "Sauvegarder en PDF", QString(), "*.pdf");
            if (QFileInfo(fileName).suffix().isEmpty())
            {
                fileName.append(".pdf");
            }

            QPrinter p (QPrinter::PrinterResolution);
            p.setOutputFormat(QPrinter::PdfFormat);
            p.setPaperSize(QPrinter::A4);
            p.setOutputFileName(fileName);

            QTextDocument doc;
            doc.setHtml(strStream);
            doc.setPageSize(p.pageRect().size()); // This is necessary if you want to hide the page number
            doc.print(&p);
}

void MainWindow::on_tri_nom_2_clicked()
{/*
    // NOTE: At this point you will use the API to get the encoding and format you want, instead of my hardcoded stuff:

           int tabprod=ui->tab_c->currentIndex().row();
           QVariant numcc=ui->tab_c->model()->data(ui->tab_c->model()->index(tabprod,0));
           QString Num_avis = numcc.toString();
           QSqlQuery qry;
           qry.prepare("select * from avis where Numavis=:Numavis");
           qry.bindValue(":Num_avis",Num_avis);
           qry.exec();
          // QDate date_signification;
           QString Nom,Objet,Reclamation;
           while(qry.next()){
               Nom=qry.value(1).toString();
               Objet=qry.value(2).toString();
               Reclamation=qry.value(3).toString();
              // cin==qry.value(4).toString();
           }
          // numcs=QString::number(numc);
           Num_avis="Num_avis: "+Nom+" Nom: "+Objet+" Objet: "+Reclamation+"Reclamation: ";
           //qrcodegen::QrCode  qr = qrcodegen::QrCode::encodeText(Num_avis.toUtf8().constData(), qrcodegen::QrCode::Ecc::HIGH);


           QImage im(qr.getSize(),qr.getSize(), QImage::Format_RGB888);
           // NOTE: For performance reasons my implementation only draws the foreground parts in supplied color.
           // It expects background to be prepared already (in white or whatever is preferred).
           for (int y = 0; y < qr.getSize(); y++) {
               for (int x = 0; x < qr.getSize(); x++) {
                   int color = qr.getModule(x, y);  // 0 for white, 1 for black

                   // You need to modify this part
                   if(color==0)
                       im.setPixel(x, y,qRgb(254, 254, 254));
                   else
                       im.setPixel(x, y,qRgb(0, 0, 0));
               }
           }

           im=im.scaled(200,200);
          ui->label->setPixmap(QPixmap::fromImage(im));*/
}



void MainWindow::on_supprimer_2_clicked()
{
    avis C ;
       int Num_avis=ui->le_cin_sup->text().toInt();
       bool test=C.supprime(Num_avis);
       QMessageBox msgBox ;
       if(test)
          { msgBox.setText("suppression avec succes.") ;
       ui->tab_c->setModel(C.afficher());}
       else
            msgBox.setText("echec.") ;
       ui->tab_c->setModel(C.afficher());

           msgBox.exec();

}


void MainWindow::on_sttbutt_clicked()
{
    statm("EVENTS","ETAT",0,1,"TYPES");

}




void MainWindow::on_ldx_returnPressed()
{
    QString input=ui->ldx->text();
    if(input=="service")
    {ui->stackedWidget_2->setCurrentIndex(1);
    ui->ZINA->hide();
    ui->ZINA_3->hide();
    ui->ZINA_9->hide();
    ui->ZINA_7->hide();
    ui->ZINA_2->show();}

    else if(input=="events")
    {ui->stackedWidget_2->setCurrentIndex(2);
        ui->ZINA_2->hide() ;
        ui->ZINA->hide();
        ui->ZINA_3->hide();
        ui->ZINA_7->hide();
        ui->ZINA->show();}
    else if(input=="client")
    {ui->stackedWidget_2->setCurrentIndex(3);
        ui->ZINA->hide();
            ui->ZINA_2->hide();
            ui->ZINA_3->show();



            ui->ZINA_7->hide();
          ui->ZINA_9->hide();}
    else if(input=="paiement")
    {
        ui->stackedWidget_2->setCurrentIndex(4);
        ui->ZINA->hide();
        ui->ZINA_3->hide();
        ui->ZINA_2->hide();
        ui->ZINA_7->hide();
      ui->ZINA_9->show();
    }
    else if(input=="avis")
    {ui->stackedWidget_2->setCurrentIndex(5);
        ui->ZINA->hide();
        ui->ZINA_3->hide();
        ui->ZINA_2->hide();
        ui->ZINA_9->hide();
        ui->ZINA_7->show();}

}

void MainWindow::on_pushButton_27_clicked()
{

    QString input=ui->ldx->text();
    if(input=="service")
    {ui->stackedWidget_2->setCurrentIndex(1);
    ui->ZINA->hide();
    ui->ZINA_3->hide();
    ui->ZINA_7->hide();
    ui->ZINA_2->show();}

    else if(input=="events")
    {ui->stackedWidget_2->setCurrentIndex(2);
        ui->ZINA_2->hide() ;
        ui->ZINA_3->hide();
        ui->ZINA_7->hide();
        ui->ZINA->show();}
    else if(input=="client")
    {ui->stackedWidget_2->setCurrentIndex(3);
        ui->ZINA->hide();
            ui->ZINA_2->hide();
            ui->ZINA_3->show();}
    else if(input=="paiement")
        ui->stackedWidget_2->setCurrentIndex(4);
    else if(input=="avis")
    {ui->stackedWidget_2->setCurrentIndex(5);
        ui->ZINA->hide();
        ui->ZINA_3->hide();
        ui->ZINA_2->hide();
        ui->ZINA_7->show();}
}





void MainWindow::on_lastpb_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
}

void MainWindow::on_pushButton_4_clicked()
{
    QApplication::quit();
}

//butt aziz
void MainWindow::on_paiementaj_clicked()
{
    QString REFERENCE=ui->lineEdit_ref->text();
    int MONTANT=ui->lineEdit_mont->text().toInt();
     QString TYPE_PAIEMENT=ui->comboBox_t->currentText();
     QString DATE_PAIEMENT=ui->dateEdit_d->text();
      paiement p(REFERENCE,MONTANT,TYPE_PAIEMENT,DATE_PAIEMENT);

      if ((ui->lineEdit_ref->text().isEmpty()) || (ui->lineEdit_mont->text().isEmpty()))
      {
          A.write_to_arduino("2");
          QMessageBox::critical(nullptr,QObject::tr("not ok"),
                     QObject::tr("remplir tout les donées.\n"
                                 "click Cancel to exit."),QMessageBox::Cancel);
      }
      else
      {
          bool test=p.ajouter();
                  if (test)
                  {
                      A.write_to_arduino("1");
                      // Refresh (Actualiser)
                      ui->tableView_2->setModel(p.afficher());
                      QMessageBox::information(nullptr,QObject::tr("ok"),
                                               QObject::tr("ajout effectué.\n"
                                                           "click Cancel to exit."),QMessageBox::Cancel);
                  }else{
                      A.write_to_arduino("3");
                      QMessageBox::critical(nullptr,QObject::tr("not ok"),
                                 QObject::tr("ajout non effectué.\n"
                                             "click Cancel to exit."),QMessageBox::Cancel);

                  }

  }
}


void MainWindow::on_pbmodpai_clicked()
{
    paiement p;
       QString REFERENCE=ui->cbref->currentText();
       int MONTANT=ui->lem->text().toInt();
       QString TYPE_PAIEMENT=ui->cbtype->currentText();
       QString DATE_PAIEMENT=ui->dateEdit_3->text();
     bool test=p.modifier(REFERENCE,MONTANT,TYPE_PAIEMENT,DATE_PAIEMENT);

       if (test)
       {
           // Refresh (Actualiser)
            ui->tableView_2->setModel(p.afficher());
           QMessageBox::information(nullptr,QObject::tr("ok"),
                                    QObject::tr("modification effectué.\n"
                                                "click Cancel to exit."),QMessageBox::Cancel);

       }
       else
           QMessageBox::critical(nullptr,QObject::tr("Not OK"),
                      QObject::tr("modification non effectué.\n"
                                  "Click Cancel to exit."),QMessageBox::Cancel);
}

void MainWindow::on_pbsuppapi_clicked()
{
    QString REF=ui->sup_ref->currentText();

     bool test1=p.supprimer(REF);
     if (test1)
     {
         // Refresh (Actualiser)
          ui->tableView_2->setModel(p.afficher());
         QMessageBox::information(nullptr,QObject::tr("ok"),
                                  QObject::tr("supression effectué.\n"
                                              "click Cancel to exit."),QMessageBox::Cancel);

     }
     else
         QMessageBox::critical(nullptr,QObject::tr("Not OK"),
                    QObject::tr("Supression non effectué.\n"
                                "Click Cancel to exit."),QMessageBox::Cancel);
}

void MainWindow::on_rembpai_clicked()
{
    //sup_ref_2
    QString ref=ui->sup_ref_2->currentText();
    QString pourcentage_rembourse = ui->sup_ref_3->currentText()+"%";
    QString Cause_Remboursement = ui->sup_ref_4->currentText();
    bool test1=p.ajouter_remboursement(ref,pourcentage_rembourse,Cause_Remboursement);
    if (test1)
    {
        // Refresh (Actualiser)
         ui->tableView_2->setModel(p.afficher());
        QMessageBox::information(nullptr,QObject::tr("ok"),
                                 QObject::tr("remboursement effectué.\n"
                                             "click Cancel to exit."),QMessageBox::Cancel);

    }
    else
        QMessageBox::critical(nullptr,QObject::tr("Not OK"),
                   QObject::tr("remboursement non effectué.\n"
                               "Click Cancel to exit."),QMessageBox::Cancel);
}

void MainWindow::on_comboBox_currentIndexChanged(const QString &arg1)
{
      ui->tableView_2->setModel(p.afficher_trier(arg1));
}

void MainWindow::on_lineEdit_2_textChanged(const QString &arg1)
{
    int checkButton= 2;
    if( ui->radioButton_2->isChecked() ){
        checkButton = 0;
    }else if(ui->radioButton_3->isChecked()){
        checkButton = 1;
    }

    qDebug() << checkButton << arg1;
    ui->tableView_2->setModel(p.recherche_avance(arg1,checkButton));
}

void MainWindow::on_sombre_clicked()
{
    ui->cbref->setModel(p.affichervaleur("REFERENCE"));

    if ( mode == 0){
        ui->sombre->setText("mode sombre");
        ui->TWW->setStyleSheet(
                    "QWidget {background-color: #ffffff; color:#000000;}"
                    "QTabBar::tab:!selected {background-color: #ffffff; color:#000000;}"
                    "QTabBar::tab:selected {background-color: #ffffff; color:#000000;}"

            );
        ui->tableView_2->setStyleSheet(
                    "QHeaderView::section { background-color:#ffffff ; color:#000000}"
                    "QTableCornerButton::section {background-color:#ffffff ;}"
                    );
        mode = 1;
    }else{
        ui->sombre->setText("mode jour");
        ui->TWW->setStyleSheet(
                    "QWidget {background-color: #595959; color:#ffffff;}"
                    "QTabBar::tab:!selected {background-color: #595959; color:#ffffff;}"
                    "QTabBar::tab:selected {background-color: #ACACAC; color:#ffffff;}"

            );
        ui->tableView_2->setStyleSheet(
                    "QHeaderView::section { background-color:#595959 ; color:white}"
                    "QTableCornerButton::section {background-color:#595959 ;}"
                    );
        mode = 0;
    }
}

void MainWindow::on_tabWidget_tabBarClicked(int index)
{    ui->cbref->setModel(p.affichervaleur("REFERENCE"));
     ui->sup_ref->setModel(p.affichervaleur("REFERENCE"));
     ui->tableView_2->setModel(p.afficher());
     ui->sup_ref_2->setModel(p.affichervaleur("REFERENCE"));
    if ( index == 6 ){
        QSqlQuery* query = p.affichage_remboursement();

        int rowCount=0;
        ui->tableWidget->setColumnCount(5);
        QStringList labels;
        labels << "Reference" << "Montant Totale" << "% Remboursement" << "Montant Remboursé" << "Cause de Remboursement" ;
        ui->tableWidget->setHorizontalHeaderLabels(labels);
        ui->tableWidget->setRowCount(0);

        while ( query->next()){
            if ( query->value(2).toString() != NULL){
                ui->tableWidget->insertRow(rowCount);

                int montantTotale = query->value(1).toInt();
                QString PourcentageRemboursement = query->value(2).toString().remove(2,1);
                int PourcentageDeRemboursement = PourcentageRemboursement.toInt();
                int totalRembourse = montantTotale * PourcentageDeRemboursement / 100;
                QString CauseRemboursement = query->value(3).toString();

                QTableWidgetItem* Reference = new QTableWidgetItem;
                QTableWidgetItem* MontantTotale = new QTableWidgetItem;
                QTableWidgetItem* Pourcentage = new QTableWidgetItem;
                QTableWidgetItem* MontantRembourse = new QTableWidgetItem;
                QTableWidgetItem* Cause = new QTableWidgetItem;

                Reference->setText(query->value(0).toString());
                MontantTotale->setText(QString::number(montantTotale));
                Pourcentage->setText(query->value(2).toString());
                MontantRembourse->setText(QString::number(totalRembourse));
                Cause->setText(CauseRemboursement);

                ui->tableWidget->setItem(rowCount,0,Reference);
                ui->tableWidget->setItem(rowCount,1,MontantTotale);
                ui->tableWidget->setItem(rowCount,2,Pourcentage);
                ui->tableWidget->setItem(rowCount,3,MontantRembourse);
                ui->tableWidget->setItem(rowCount,4,Cause);

                rowCount++;
            }

        }


    }


    if ( index == 7){

        QSqlQuery* query = p.affichage_chiffre_affaire();

        int montant_totale_paiement = 0;
        int nbr_remboursement_totale = 0;
        int montant_rembourse_totale = 0;
        int nbr_remboursement_10 =0;
        int nbr_remboursement_30 =0;
        int nbr_remboursement_50 =0;
        int nbr_remboursement_70 =0;
        int nbr_remboursement_100 =0;
        while ( query->next() ){
             montant_totale_paiement+= query->value(0).toInt();
             if ( query->value(1).toInt() == 1){
                 nbr_remboursement_totale++;
                 montant_rembourse_totale+= query->value(0).toInt() * query->value(2).toString().remove(2,1).toInt() / 100;
                 if ( query->value(2).toString() == "10%" ){
                     nbr_remboursement_10++;
                 }else if ( query->value(2).toString() == "30%" ){
                     nbr_remboursement_30++;
                 }else if ( query->value(2).toString() == "50%" ){
                     nbr_remboursement_50++;
                 }else if ( query->value(2).toString() == "70%" ){
                     nbr_remboursement_70++;
                 }else if ( query->value(2).toString() == "100%" ){
                     nbr_remboursement_100++;
                 }
             }
        }
        ui->montant_totale->setText(QString::number(montant_totale_paiement));
        ui->remboursement_totale->setText(QString::number(nbr_remboursement_totale));
        ui->remboursement10->setText(QString::number(nbr_remboursement_10));
        ui->remboursement30->setText(QString::number(nbr_remboursement_30));
        ui->remboursement50->setText(QString::number(nbr_remboursement_50));
        ui->remboursement70->setText(QString::number(nbr_remboursement_70));
        ui->remboursement100->setText(QString::number(nbr_remboursement_100));
        ui->montant_remboursement_totale->setText(QString::number(montant_rembourse_totale));
        ui->remboursement_totale_finale->setText(QString::number(montant_totale_paiement - montant_rembourse_totale));
    }

}



void MainWindow::on_tabWidget_6_tabBarClicked(int index)
{
    ui->TabEv->setModel(E.afficher(ui->lineEdit_recherche->text(),ui->comboBox_ordre->currentText(),ui->comboBox_parametre->currentText()));

}


void MainWindow::on_toolButton_clicked()
{

    arduino* ard = new arduino();
    int connect = ard->connect_arduino();
    qDebug() <<"arduino_port_connect is:"<<connect;
    if(connect > -1)
    {   qDebug() <<"test";
        if(ard->write2_to_arduino("GET"))
        {
            Service* service = new Service();
            bool rain = ard->read_bool_from_arduino();
            service->modifier(8, rain);
            ui->tab_service->setModel(S.afficher());
            ui->label_11->setText( rain ? "Rain" : "No Rain");
            qDebug() <<"rain is:"<<rain;
        }
    }
    ard->close_arduino();
}
/*ui->cbref->setModel(p.affichervaleur("REFERENCE"));
     ui->sup_ref->setModel(p.affichervaleur("REFERENCE"));
     ui->tableView_2->setModel(p.afficher());
     ui->sup_ref_2->setModel(p.affichervaleur("REFERENCE"));*/
void MainWindow::on_statpa_clicked()
{
    ui->TWW->setCurrentIndex(4);
}

void MainWindow::on_rembooo_clicked()
{
    ui->TWW->setCurrentIndex(5);
    ui->sup_ref_2->setModel(p.affichervaleur("REFERENCE"));


}

void MainWindow::on_premb_clicked()
{
    ui->TWW->setCurrentIndex(6);

}

void MainWindow::on_chiffred_clicked()
{
    ui->TWW->setCurrentIndex(7);

}

void MainWindow::on_ajpaix_clicked()
{
    ui->TWW->setCurrentIndex(0);

}

void MainWindow::on_affpaix_clicked()
{
    ui->TWW->setCurrentIndex(1);
    ui->tableView_2->setModel(p.afficher());


}

void MainWindow::on_modpaix_clicked()
{
    ui->TWW->setCurrentIndex(2);
    ui->cbref->setModel(p.affichervaleur("REFERENCE"));

}

void MainWindow::on_suppmai_clicked()
{
    ui->TWW->setCurrentIndex(3);
    ui->sup_ref->setModel(p.affichervaleur("REFERENCE"));


}





