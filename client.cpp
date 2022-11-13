#include "client.h"
#include <QSqlQuery>
#include <QFileDialog>
#include<QMessageBox>
#include <QtDebug>
#include "mainwindow.h"
#include "ui_mainwindow.h"
Client::Client()
{
cin=0;
nom="";
prenom="";
tel=0;
mail="";
sexe="";
}
Client::Client(int cin,QString nom,QString prenom,int tel,QString mail,QString sexe)
{
    this->cin=cin;
    this->nom=nom;
    this->prenom=prenom;
    this->tel=tel;
    this->mail=mail;
    this->sexe=sexe;
}

bool Client::ajouter()
{

    QSqlQuery query;


  query.prepare("INSERT INTO CLIENTT (CIN,NOM,PRENOM,TEL,MAIL,SEXE) "
                "VALUES (:CIN, :NOM, :PRENOM, :TEL,:MAIL ,:SEXE)");
  query.bindValue(":CIN", cin);
  query.bindValue(":NOM", nom);
  query.bindValue(":PRENOM",prenom);
  query.bindValue(":TEL",tel);
query.bindValue(":MAIL",mail);
query.bindValue(":SEXE",sexe);
     return query.exec();

}

QSqlQueryModel* Client::afficher()
{
    QSqlQueryModel* model=new QSqlQueryModel();
     model->setQuery("SELECT* FROM clientt");
     return model;
}

bool Client::modifier(int cin, QString nom, QString prenom, int tel, QString mail, QString sexe)
{
    QSqlQuery query;


         query.prepare("update clientt set nom=:nom, prenom=:prenom, tel=:tel ,mail=:mail ,sexe=:sexe "
                       "where cin=:cin");

         query.bindValue(":nom", nom);
         query.bindValue(":prenom", prenom);
         query.bindValue(":tel",tel);
          query.bindValue(":mail",mail);
           query.bindValue(":sexe",sexe);
            query.bindValue(":cin",cin);
        return query.exec();

}
QSqlQueryModel * Client::afficheroncombo()
{
    QSqlQueryModel * model= new QSqlQueryModel();

    model->setQuery("select * from clientt");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("cin"));

        return model;

}

bool Client::supprimer(int cin)
{
    QSqlQuery query;
            query.prepare("select * from clientt where cin=:cin");
            query.bindValue(":cin", cin);
            query.exec();
            if (query.next())
            {
             query.prepare(" Delete from clientt where cin=:cin");
             query.bindValue(":cin", cin);

                    query.exec();
                 return true;

            }

             return false;
}
QSqlQueryModel*  Client::tri(QString colone, QString ordre)
{
QSqlQueryModel* model=new QSqlQueryModel();
model->setQuery("select * from clientt order by "+colone+" "+ordre+"");
return model;
}

void Client::excel(QTableView *tab)
{

    //QTableView *table;
                // table = ui->tab_view;

                 QString filters("CSV files (.csv);;All files (.*)");
                 QString defaultFilter("CSV files (*.csv)");
                 QString fileName = QFileDialog::getSaveFileName(0, "Save file", QCoreApplication::applicationDirPath(),
                                    filters, &defaultFilter);
                 QFile file(fileName);

                 QAbstractItemModel *model =  tab->model();
                 if (file.open(QFile::WriteOnly | QFile::Truncate)) {
                     QTextStream data(&file);
                     QStringList strList;
                     for (int i = 0; i < model->columnCount(); i++) {
                         if (model->headerData(i, Qt::Horizontal, Qt::DisplayRole).toString().length() > 0)
                             strList.append("\"" + model->headerData(i, Qt::Horizontal, Qt::DisplayRole).toString() + "\"");
                         else
                             strList.append("");
                     }
                     data << strList.join(";") << "\n";
                     for (int i = 0; i < model->rowCount(); i++) {
                         strList.clear();
                         for (int j = 0; j < model->columnCount(); j++) {

                             if (model->data(model->index(i, j)).toString().length() > 0)
                                 strList.append("\"" + model->data(model->index(i, j)).toString() + "\"");
                             else
                                 strList.append("");
                         }
                         data << strList.join(";") + "\n";
                     }
                     file.close();
                   //  QMessageBox::information(this,"Exporter To Excel","Exporter En Excel Avec Succées ");
                 }
}

