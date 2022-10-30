#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "evenement.h"
#include <QIntValidator>
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->laREF->setValidator( new QIntValidator(0, 99999, this));
    ui->leNOMS->setValidator( new QIntValidator(0, 9, this));
    ui->leCIN->setValidator( new QIntValidator(0, 9999, this));
   ui->TabEv->setModel(E.afficher());
    ui->tabWidget_2->tabBar()->hide();
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
}

void MainWindow::on_PbAjouter_clicked()
{   int ref=ui->laREF->text().toInt();
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
   ui->TabEv->setModel((E.afficher()));
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

void MainWindow::on_pushButton_5_clicked()
{
    ui->TabEv->setModel(E.afficher());

}

void MainWindow::on_SuppButt_clicked()
{
    Evenement E1;

    E1.setRef(ui->LineSupp->text().toInt());
     bool test=E1.supprimer(E1.getRef());
     QMessageBox msgBox;
     if(test)
     {
         QMessageBox::information(nullptr, QObject::tr("database is open"),
                     QObject::tr("suppression successful.\n"
                                 "Click Cancel to exit."), QMessageBox::Cancel);
ui->TabEv->setModel(E.afficher());
 }
     else
      {   QMessageBox::critical(nullptr, QObject::tr("database is not open"),
                     QObject::tr("suppression failed.\n"
                                 "Click Cancel to exit."), QMessageBox::Cancel);}
}
void MainWindow::on_PBmodifier_clicked()
{
    int ref=ui->LineMod->text().toInt();
    int cin=ui->LineCin->text().toInt();
    int numS=ui->LineNumS->text().toInt();

    Evenement E;
    bool test;

    test=E.modifier(ref,cin,numS);
    if(test)

    {ui->TabEv->setModel(E.afficher());
        QMessageBox::information(nullptr, QObject::tr("database is open"),
                    QObject::tr("modification successful.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);}
    else
    {
        QMessageBox::critical(nullptr, QObject::tr("database is not open"),
                            QObject::tr("modification failed.\n"
                                        "Click Cancel to exit."), QMessageBox::Cancel);}

    }



