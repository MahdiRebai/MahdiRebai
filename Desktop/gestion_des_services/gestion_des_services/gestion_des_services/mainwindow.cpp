#include "ui_mainwindow.h"
#include "mainwindow.h"

#include "service.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
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
