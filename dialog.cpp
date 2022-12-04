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

void Dialog::on_ooo_clicked()
{
    QString input=ui->ldd->text();
Dialog dialog;
    if(input=="0000")
       { Dialog dialog;


        }


}
