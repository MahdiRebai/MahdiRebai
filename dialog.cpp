#include "dialog.h"
#include "ui_dialog.h"

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);
}

Dialog::~Dialog()
{
    delete ui;
}

void Dialog::setpaiement(paiement p)
{
/* ui->lineEdit_montantD->setText(p.get_montant());
 ui->lineEdit_referenceD->setText(p.get_reference());
 ui->lineEdit_typeD->setText(p.get_type());
 ui->lineEdit_dateD->setText(p.get_date());*/
 }
