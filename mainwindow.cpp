#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "client.h"
#include <QMessageBox>
#include <QSqlQuery>
#include "statclient.h"
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->tableView->setModel(cl.afficher());
    ui->comboBox_3->setModel(cl.afficheroncombo());
    ui->cb_idclient->setModel(cl.afficheroncombo());
    ui->tableView_rdv->setModel(r.afficherrdv());

}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()
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
    ui->tableView->setModel(c.afficher());
    ui->comboBox_3->setModel(cl.afficheroncombo());
  }
else
{
    msgBox.setText("Echec d'ajout");
    msgBox.exec();

}
}

void MainWindow::on_pushButton_2_clicked()
{int cin=ui->aj_cin->text().toInt();
    QString nom=ui->aj_nom->text();
    QString prenom=ui->aj_pren->text();
    int tel=ui->aj_tel->text().toInt();
    QString mail=ui->aj_mail->text();
    QString sexe=ui->cb_sexe->currentText();
    bool    test=cl.modifier(cin,nom,prenom,tel,mail,sexe) ;
          if (test)
          {
ui->cb_idclient->setModel(cl.afficheroncombo());

 ui->tableView->setModel(cl.afficher());
              QMessageBox::information(nullptr,QObject::tr("OK"),
                                   QObject::tr("modification établie"),
                                   QMessageBox::Ok);}
          else{
          QMessageBox::critical(nullptr,QObject::tr("ERROR404"),
                                  QObject::tr("modification non établie"),
                                  QMessageBox::Cancel);}
}

void MainWindow::on_comboBox_3_currentIndexChanged(int index)
{
     ui->comboBox_3->currentText();
}

void MainWindow::on_pushButton_3_clicked()
{
    bool test=cl.supprimer(ui->comboBox_3->currentText().toInt());
    bool test1=r.supprimerrdv(ui->comboBox_3->currentText().toInt());
    if(test)
    { ui->tableView->setModel(cl.afficher());
        ui->comboBox_3->setModel(cl.afficheroncombo());
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

void MainWindow::on_pushButton_4_clicked()
{
    QString colone=ui->colone_tri->currentText();
        QString ordre=ui->ordre_tri->currentText();
        Client c;
        ui->tableView->setModel(c.tri(colone,ordre));
}

void MainWindow::on_lineEdit_textChanged(const QString &arg1)
{

}

void MainWindow::on_lineEdit_rech_textChanged(const QString &arg1)
{
    QSqlQueryModel *model= new QSqlQueryModel();
            QSqlQuery   *query= new QSqlQuery();
    if(ui->comboBox_rech->currentText()=="CIN"
            ){
        query->prepare("SELECT * FROM clientt WHERE cin LIKE'"+arg1+"%'");//
query->exec();
    model->setQuery(*query);
ui->tableView->setModel(model);


    }
    else {
        if(ui->comboBox_rech->currentText()=="NOM"){
            query->prepare("SELECT * FROM CLIENTT WHERE NOM LIKE'"+arg1+"%'");//+tri
    query->exec();
        model->setQuery(*query);
    ui->tableView->setModel(model);
        }
        else{
            if(ui->comboBox_rech->currentText()=="PRENOM")
                query->prepare("SELECT * FROM CLIENTT WHERE PRENOM LIKE'"+arg1+"%'");//+tri
        query->exec();
            model->setQuery(*query);
        ui->tableView->setModel(model);
            }

        }
}

void MainWindow::on_pushButton_5_clicked()
{
 cl.excel(ui->tableView);
}

void MainWindow::on_b_aj_rdv_clicked()
{
    rdv rd(ui->cb_idclient->currentText().toInt(),ui->dateEdit->text());
    bool test=rd.ajRdv();
     ui->tableView_rdv->setModel(r.afficherrdv());
      ui->cb_idclient->setModel(cl.afficheroncombo());
}

void MainWindow::on_cb_idclient_currentIndexChanged(int index)
{
    ui->cb_idclient->currentText();

}

void MainWindow::on_pushButton_6_clicked()
{

        bool    test=r.modifrdv(ui->cb_idclient->currentText().toInt(),ui->dateEdit->text());
              if (test)
              {
    ui->cb_idclient->setModel(cl.afficheroncombo());
    ui->tableView_rdv->setModel(r.afficherrdv());
     ui->cb_idclient->setModel(cl.afficheroncombo());
     ui->tableView->setModel(cl.afficher());
                  QMessageBox::information(nullptr,QObject::tr("OK"),
                                       QObject::tr("modification établie"),
                                       QMessageBox::Ok);}
              else{
              QMessageBox::critical(nullptr,QObject::tr("ERROR404"),
                                      QObject::tr("modification non établie"),
                                      QMessageBox::Cancel);}
}

void MainWindow::on_pushButton_7_clicked()
{
    stat_client=new statclient(this);
    stat_client->show();
}
