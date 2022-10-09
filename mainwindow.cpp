#include "mainwindow.h"
#include "ui_mainwindow.h"
#include"paiement.h"
#include"dialog.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
 /*   ui->lineEdit_montant->setValidator(new QIntValidator(0,99999999,this));*/
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{
   /* paiement p;
    p.setmontant(ui->lineEdit_montant->text());
     p.setreference(ui->lineEdit_reference->text());
      p.settype(ui->lineEdit_type->text());
       p.setdate(ui->lineEdit_date->text());
    Dialog d;
    d.setpaiement(p);
    d.exec();*/
}
