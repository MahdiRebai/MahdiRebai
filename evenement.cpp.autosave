#include "evenement.h"
#include <QSqlQuery>
#include<QtDebug>
#include<QObject>
Evenement::Evenement()
{
    ref=0;  cin=0;  numS=0;
}


    Evenement::Evenement(int ref,int cin,int numS)
{ this->ref=ref;this->cin=cin;this->numS=numS;}


    int Evenement::getRef(){return ref;}
    int Evenement::getCin(){return cin;}
    int Evenement::getNumS(){return numS;}

    void Evenement:: setRef(int ref){this->ref=ref;}
    void Evenement::setCin(int cin){this->cin=cin;}
    void Evenement::setNumS(int numS){this->numS=numS;}


    bool Evenement::ajouter()
    {
        QSqlQuery query;

    //    QString ref_string=QString::number(ref);
              query.prepare("INSERT INTO events (REFERENCE, cin, numS) VALUES (:ref, :cin, :numS)");

              query.bindValue(":ref", ref);
              query.bindValue(":cin", cin);
              query.bindValue(":numS", numS);
              return query.exec();
    }
    bool Evenement::supprimer(int ref)
    {

        QSqlQuery query;

    //    QString ref_string=QString::number(ref);
              query.prepare("Delete from events where (REFERENCE=:ref)");

              query.bindValue(":ref", ref);

              return query.exec();


    }

       QSqlQueryModel *Evenement::afficher()
        {
              QSqlQueryModel * model=new  QSqlQueryModel();
              model->setQuery("SELECT * FROM events");
              model->setHeaderData(0, Qt::Horizontal, QObject::tr("REFERENCE"));
              model->setHeaderData(1, Qt::Horizontal, QObject::tr("CIN"));
              model->setHeaderData(2, Qt::Horizontal, QObject::tr("NUMS"));
   return model;
        }
  bool Evenement::modifier(int ref,int cin, int numS)
        {

                   QSqlQuery query;
                   query.prepare("update events set CIN=:cin,NUMS=:numS where REFerence=:ref");
                   query.bindValue(":ref",ref);
                   query.bindValue(":CIN",cin);
                   query.bindValue(":numS",numS);

           return query.exec();
        }





