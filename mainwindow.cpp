#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "evenement.h"
#include <QIntValidator>
#include <QMessageBox>
<<<<<<< HEAD
<<<<<<< HEAD
=======
=======
>>>>>>> 0ab4f713885d0fe53e6e35a8fab2b7c8e8d296d1
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


<<<<<<< HEAD
>>>>>>> d417753b0206d5dcaf751e7329a8634bb1685c15
=======
>>>>>>> 0ab4f713885d0fe53e6e35a8fab2b7c8e8d296d1

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
<<<<<<< HEAD
<<<<<<< HEAD
=======
    int ret=A.connect_arduino();
    switch(ret)
       {case(0):qDebug()<< "arduino is available and connected to :" << A.getarduino_port_name();
        break;
        case(1):qDebug()<< "arduino is available but not connected to :"<< A.getarduino_port_name();
            break;
          case(-1):qDebug()<<"arduino is not available";
         }
    QObject::connect(A.getserial(),SIGNAL(readyRead()),this,SLOT(update_label()));


>>>>>>> 0ab4f713885d0fe53e6e35a8fab2b7c8e8d296d1
   // ui->laREF->setValidator( new QIntValidator(0, 99999, this));
    ui->leNUMS->setValidator( new QIntValidator(0, 9, this));
    ui->leCIN->setValidator( new QIntValidator(0, 999999, this));
    ui->TabEv->setModel(E.afficher(ui->lineEdit_recherche->text(),ui->comboBox_ordre->currentText(),ui->comboBox_parametre->currentText()));
    ui->tableView_penalite->setModel(P.afficher(ui->lineEdit_refpen->text()));
    //ui->tbview->setModel(E.afficher_standby());
    ui->tabWidget_2->tabBar()->hide();
    ui->tabWidget_6->tabBar()->hide();
    ui->tabservice->tabBar()->hide();
    ui->ZINA->hide();
    ui->ZINA_2->hide();
    ui->LEX->setReadOnly("events");

<<<<<<< HEAD
=======
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
    ui->leNUMS->setValidator( new QIntValidator(0, 9, this));
    ui->leCIN->setValidator( new QIntValidator(0, 999999, this));
    ui->TabEv->setModel(E.afficher(ui->lineEdit_recherche->text(),ui->comboBox_ordre->currentText(),ui->comboBox_parametre->currentText()));
    ui->tableView_penalite->setModel(P.afficher(ui->lineEdit_refpen->text()));
    //ui->tbview->setModel(E.afficher_standby());
    ui->tabWidget_2->tabBar()->hide();
    ui->tabWidget_6->tabBar()->hide();
    ui->tabservice->tabBar()->hide();
    ui->ZINA->hide();
    ui->ZINA_2->hide();
    ui->LEX->setReadOnly("events");

=======
>>>>>>> 0ab4f713885d0fe53e6e35a8fab2b7c8e8d296d1
    //ui->tbview->setModel(E.afficher_simple());

    chartevent = new QChart();
    QChartView *chartViewEvents= new QChartView(chartevent);
    chartViewEvents->setRenderHint(QPainter::Antialiasing);
    chartViewEvents->setParent(ui->horizontalFrame);

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
<<<<<<< HEAD
>>>>>>> d417753b0206d5dcaf751e7329a8634bb1685c15
=======
>>>>>>> 0ab4f713885d0fe53e6e35a8fab2b7c8e8d296d1


}

MainWindow::~MainWindow()
{
    delete ui;
}


<<<<<<< HEAD
<<<<<<< HEAD
=======

>>>>>>> d417753b0206d5dcaf751e7329a8634bb1685c15
=======

>>>>>>> 0ab4f713885d0fe53e6e35a8fab2b7c8e8d296d1
void MainWindow::on_lineEdit_2_returnPressed()
{
    ui->stackedWidget->setCurrentIndex(1);
}

void MainWindow::on_pushButton_clicked()
{
    ui->stackedWidget->setCurrentIndex(2);
}

void MainWindow::on_pushButton_2_clicked()
{
   ui->stackedWidget->setCurrentIndex(3);
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






void MainWindow::on_BUTTNEXT_clicked()
{
     ui->stackedWidget->setCurrentIndex(3);
}


void MainWindow::on_CONFIRM_clicked()
{
    ui->stackedWidget->setCurrentIndex(2);
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
<<<<<<< HEAD
<<<<<<< HEAD
=======
    ui->ZINA->hide();
    ui->ZINA_2->hide();
>>>>>>> 0ab4f713885d0fe53e6e35a8fab2b7c8e8d296d1
}


void MainWindow::on_pushButton_19_clicked()
{            ui->ZINA->hide();
     ui->stackedWidget_2->setCurrentIndex(1);
<<<<<<< HEAD
=======
    ui->ZINA->hide();
    ui->ZINA_2->hide();
}


void MainWindow::on_pushButton_19_clicked()
{            ui->ZINA->hide();
     ui->stackedWidget_2->setCurrentIndex(1);
     ui->ZINA_2->show();
>>>>>>> d417753b0206d5dcaf751e7329a8634bb1685c15
=======
     ui->ZINA_2->show();
>>>>>>> 0ab4f713885d0fe53e6e35a8fab2b7c8e8d296d1
}


void MainWindow::on_pushButton_21_clicked()
<<<<<<< HEAD
<<<<<<< HEAD
{
=======
{        ui->ZINA_2->hide();

>>>>>>> 0ab4f713885d0fe53e6e35a8fab2b7c8e8d296d1
     ui->stackedWidget_2->setCurrentIndex(2);
     ui->ZINA->show();
}

void MainWindow::on_pushButton_20_clicked()
<<<<<<< HEAD
{
=======
{        ui->ZINA_2->hide();

     ui->stackedWidget_2->setCurrentIndex(2);
     ui->ZINA->show();
}

void MainWindow::on_pushButton_20_clicked()
{ui->ZINA->hide();
    ui->ZINA_2->hide();
>>>>>>> d417753b0206d5dcaf751e7329a8634bb1685c15
=======
{ui->ZINA->hide();
    ui->ZINA_2->hide();
>>>>>>> 0ab4f713885d0fe53e6e35a8fab2b7c8e8d296d1
     ui->stackedWidget_2->setCurrentIndex(3);
}

void MainWindow::on_pushButton_22_clicked()
{
     ui->stackedWidget_2->setCurrentIndex(4);
<<<<<<< HEAD
<<<<<<< HEAD
=======
     ui->ZINA->hide();
     ui->ZINA_2->hide();
>>>>>>> d417753b0206d5dcaf751e7329a8634bb1685c15
=======
     ui->ZINA->hide();
     ui->ZINA_2->hide();
>>>>>>> 0ab4f713885d0fe53e6e35a8fab2b7c8e8d296d1
}

void MainWindow::on_pushButton_23_clicked()
{
     ui->stackedWidget_2->setCurrentIndex(5);
<<<<<<< HEAD
<<<<<<< HEAD
=======
     ui->ZINA->hide();
     ui->ZINA_2->hide();
>>>>>>> d417753b0206d5dcaf751e7329a8634bb1685c15
=======
     ui->ZINA->hide();
     ui->ZINA_2->hide();
>>>>>>> 0ab4f713885d0fe53e6e35a8fab2b7c8e8d296d1
}


void MainWindow::on_PBRECHERCHE_clicked()
{
<<<<<<< HEAD
<<<<<<< HEAD
    ui->tabWidget_2->setCurrentIndex(0);
=======
    ui->tabWidget_2->setCurrentIndex(5);
>>>>>>> d417753b0206d5dcaf751e7329a8634bb1685c15
=======
    ui->tabWidget_2->setCurrentIndex(5);
>>>>>>> 0ab4f713885d0fe53e6e35a8fab2b7c8e8d296d1
}

void MainWindow::on_PSSTATS_clicked()
{
     ui->tabWidget_2->setCurrentIndex(1);
<<<<<<< HEAD
<<<<<<< HEAD
=======
=======
>>>>>>> 0ab4f713885d0fe53e6e35a8fab2b7c8e8d296d1
     stats_event *stat = new stats_event ;
     QLineSeries *series = stat ->Money_Stats("12") ;

    chartevent->legend()->hide();
    chartevent->addSeries(series);
    chartevent->setTitle("LINE CHART ONE");

<<<<<<< HEAD
>>>>>>> d417753b0206d5dcaf751e7329a8634bb1685c15
=======
>>>>>>> 0ab4f713885d0fe53e6e35a8fab2b7c8e8d296d1
}

void MainWindow::on_PBFICHIER_clicked()
{
     ui->tabWidget_2->setCurrentIndex(2);
}

void MainWindow::on_PBANNULER_clicked()
{
     ui->tabWidget_2->setCurrentIndex(3);
}

void MainWindow::on_PBREPORTER_clicked()
{
     ui->tabWidget_2->setCurrentIndex(4);
<<<<<<< HEAD
<<<<<<< HEAD
=======
     ui->tableView_penalite->setModel(P.afficher(ui->lineEdit_refpen->text()));

>>>>>>> d417753b0206d5dcaf751e7329a8634bb1685c15
=======
     ui->tableView_penalite->setModel(P.afficher(ui->lineEdit_refpen->text()));

>>>>>>> 0ab4f713885d0fe53e6e35a8fab2b7c8e8d296d1
}
// boutton ajouter base de données
void MainWindow::on_PbAjouter_clicked()
{   QString ref=ui->laREF->text();
<<<<<<< HEAD
<<<<<<< HEAD

    int cin=ui->leCIN->text().toInt();

    int numS=ui->leNUMS->text().toInt();
     Evenement E(ref,cin,numS);
     bool test=E.ajouter();
=======
    int PRIX=ui->lineEdit_price->text().toInt();
    int cin=ui->leCIN->text().toInt();

    int numS=ui->leNUMS->text().toInt();
=======
    int PRIX=ui->lineEdit_price->text().toInt();
    int cin=ui->leCIN->text().toInt();

    int numS=ui->leNUMS->text().toInt();
>>>>>>> 0ab4f713885d0fe53e6e35a8fab2b7c8e8d296d1
     Evenement E(ref,cin,numS,PRIX);
     E.set_prix(ui->lineEdit_price->text().toInt());
     bool test=E.ajouter(ui->dateEvent->text());
     qDebug() <<test ;

<<<<<<< HEAD
>>>>>>> d417753b0206d5dcaf751e7329a8634bb1685c15
=======
>>>>>>> 0ab4f713885d0fe53e6e35a8fab2b7c8e8d296d1
     QMessageBox msgBox;
     if(test)
     {
         QMessageBox::information(nullptr, QObject::tr("database is open"),
                     QObject::tr("ajout successful.\n"
                                 "Click Cancel to exit."), QMessageBox::Cancel);
         ui->TabEv->setModel(E.afficher(ui->lineEdit_recherche->text(),ui->comboBox_ordre->currentText(),ui->comboBox_parametre->currentText()));

 }
     else
<<<<<<< HEAD
<<<<<<< HEAD
      {   QMessageBox::critical(nullptr, QObject::tr("database is not open"),
=======
      {
         QMessageBox::critical(nullptr, QObject::tr("database is not open"),
>>>>>>> d417753b0206d5dcaf751e7329a8634bb1685c15
=======
      {
         QMessageBox::critical(nullptr, QObject::tr("database is not open"),
>>>>>>> 0ab4f713885d0fe53e6e35a8fab2b7c8e8d296d1
                     QObject::tr("ajout failed.\n"
                                 "Click Cancel to exit."), QMessageBox::Cancel);}

}

void MainWindow::on_TR_clicked()
{
     ui->tabWidget_2->setCurrentIndex(5);
}
<<<<<<< HEAD
<<<<<<< HEAD

=======
// bouton afficher
>>>>>>> d417753b0206d5dcaf751e7329a8634bb1685c15
=======
// bouton afficher
>>>>>>> 0ab4f713885d0fe53e6e35a8fab2b7c8e8d296d1
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
<<<<<<< HEAD
<<<<<<< HEAD

=======
//bouton modifier
>>>>>>> d417753b0206d5dcaf751e7329a8634bb1685c15
=======
//bouton modifier
>>>>>>> 0ab4f713885d0fe53e6e35a8fab2b7c8e8d296d1
void MainWindow::on_PBmodifierX_clicked()
{
    QString ref=ui->LineMod->text();
    int cin=ui->LineCin->text().toInt();
    int numS=ui->LineNumS->text().toInt();
<<<<<<< HEAD
<<<<<<< HEAD
=======
    int PRIX=ui->pxB->text().toInt();
>>>>>>> d417753b0206d5dcaf751e7329a8634bb1685c15
=======
    int PRIX=ui->pxB->text().toInt();
>>>>>>> 0ab4f713885d0fe53e6e35a8fab2b7c8e8d296d1

    Evenement E;
    bool test;

<<<<<<< HEAD
<<<<<<< HEAD
    test=E.modifier(ref,cin,numS);
    if(test)

    {   ui->TabEv->setModel(E.afficher(ui->lineEdit_recherche->text(),ui->comboBox_ordre->currentText(),ui->comboBox_parametre->currentText()));

=======
    test=E.modifier(ref,cin,numS,PRIX);
    if(test)

    {  ui->TabEv->setModel(E.afficher(ui->lineEdit_recherche->text(),ui->comboBox_ordre->currentText(),ui->comboBox_parametre->currentText()));
>>>>>>> d417753b0206d5dcaf751e7329a8634bb1685c15
=======
    test=E.modifier(ref,cin,numS,PRIX);
    if(test)

    {  ui->TabEv->setModel(E.afficher(ui->lineEdit_recherche->text(),ui->comboBox_ordre->currentText(),ui->comboBox_parametre->currentText()));
>>>>>>> 0ab4f713885d0fe53e6e35a8fab2b7c8e8d296d1
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

<<<<<<< HEAD
<<<<<<< HEAD
void MainWindow::on_lineEdit_recherche_textChanged(const QString &arg1)
=======
/*void MainWindow::on_lineEdit_recherche_textChanged(const QString &arg1)
>>>>>>> d417753b0206d5dcaf751e7329a8634bb1685c15
=======
/*void MainWindow::on_lineEdit_recherche_textChanged(const QString &arg1)
>>>>>>> 0ab4f713885d0fe53e6e35a8fab2b7c8e8d296d1
{
//    ui->TabEv->setModel(E.afficher(ui->lineEdit_recherche->text(),ui->comboBox_ordre->currentText(),ui->comboBox_parametre->currentText()));

}

<<<<<<< HEAD
<<<<<<< HEAD
/*void MainWindow::on_tettt_clicked()
=======
void MainWindow::on_tettt_clicked()
>>>>>>> d417753b0206d5dcaf751e7329a8634bb1685c15
=======
void MainWindow::on_tettt_clicked()
>>>>>>> 0ab4f713885d0fe53e6e35a8fab2b7c8e8d296d1
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
<<<<<<< HEAD
<<<<<<< HEAD
=======
=======
>>>>>>> 0ab4f713885d0fe53e6e35a8fab2b7c8e8d296d1

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
    ui->tbview->setModel(E.afficher_standby());
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
                chartView->show();}
void MainWindow::on_pbstatservice_clicked()
{
    stats("SERVICE","CLASSE",1,2,"TYPES");

}

void MainWindow::on_pushButtonclasser_clicked()
{
    ui->tableView->setModel(S.classification());

}
void MainWindow::on_pbpromo_clicked()
{
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
{
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
<<<<<<< HEAD
>>>>>>> d417753b0206d5dcaf751e7329a8634bb1685c15
=======
>>>>>>> 0ab4f713885d0fe53e6e35a8fab2b7c8e8d296d1
