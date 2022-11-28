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



MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
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
}

void MainWindow::on_pushButton_19_clicked()
{
     ui->stackedWidget_2->setCurrentIndex(1);
}


void MainWindow::on_pushButton_21_clicked()
{
     ui->stackedWidget_2->setCurrentIndex(2);
}

void MainWindow::on_pushButton_20_clicked()
{
     ui->stackedWidget_2->setCurrentIndex(3);
}

void MainWindow::on_pushButton_22_clicked()
{
     ui->stackedWidget_2->setCurrentIndex(4);
}

void MainWindow::on_pushButton_23_clicked()
{
     ui->stackedWidget_2->setCurrentIndex(5);
}


void MainWindow::on_PBRECHERCHE_clicked()
{
    ui->tabWidget_2->setCurrentIndex(0);
}

void MainWindow::on_PSSTATS_clicked()
{
     ui->tabWidget_2->setCurrentIndex(1);
     stats_event *stat = new stats_event ;
     QLineSeries *series = stat ->Money_Stats("12") ;

    chartevent->legend()->hide();
    chartevent->addSeries(series);
    chartevent->setTitle("LINE CHART ONE");

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
     QMessageBox msgBox;
     if(test)
     {
         QMessageBox::information(nullptr, QObject::tr("database is open"),
                     QObject::tr("ajout successful.\n"
                                 "Click Cancel to exit."), QMessageBox::Cancel);
         ui->TabEv->setModel(E.afficher(ui->lineEdit_recherche->text(),ui->comboBox_ordre->currentText(),ui->comboBox_parametre->currentText()));

 }
     else
      {   QMessageBox::critical(nullptr, QObject::tr("database is not open"),
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

