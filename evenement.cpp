#include "evenement.h"
#include <QSqlQuery>
#include<QtDebug>
#include<QObject>

Evenement::Evenement()
{
    ref="";  cin=0;  numS=0;
}


    Evenement::Evenement(QString ref,int cin,int numS)
{ this->ref=ref;
        this->cin=cin;
        this->numS=numS;}


    QString Evenement::getRef(){return ref;}
    int Evenement::getCin(){return cin;}
    int Evenement::getNumS(){return numS;}

    void Evenement:: setRef(QString ref) {this->ref=ref;}
    void Evenement::setCin(int cin){this->cin=cin;}
    void Evenement::setNumS(int numS){this->numS=numS;}


    bool Evenement::ajouter()
    {
        QSqlQuery query;

     //  QString ref_string=QString::number(ref);
              query.prepare("INSERT INTO events (REFERENCE, cin, numS) VALUES (:ref, :cin, :numS)");

              query.bindValue(":ref", ref);
              query.bindValue(":cin", cin);
              query.bindValue(":numS", numS);
              return query.exec();
    }
    bool Evenement::supprimer(QString ref)
    {

        QSqlQuery query;

    //    QString ref_string=QString::number(ref);
              query.prepare("Delete from events where (REFERENCE=:ref)");

              query.bindValue(":ref", ref);

              return query.exec();


    }

       QSqlQueryModel *Evenement::afficher(QString numLine,QString ordre,QString parametre)
        {
              QSqlQueryModel * model=new  QSqlQueryModel();
              QString queryText ;
              if (parametre == "numero de service" )
                   parametre = "nums" ;

              if (numLine == "")
                 { if (ordre == "Croissant")
                  queryText = "SELECT * FROM events ORDER BY "+ parametre +" ASC" ;
                  else
                      queryText = "SELECT * FROM events ORDER BY "+ parametre +" DESC" ;
                      }
              else
                 { if (ordre == "Croissant")
                                    queryText = "SELECT * FROM events WHERE numS = '"+numLine+"' ORDER BY "+ parametre +" ASC" ;
                                    else
                                       queryText = "SELECT * FROM events WHERE numS = '"+numLine+"' ORDER BY "+ parametre +" DESC" ;
                }

              qDebug()<< queryText ;
              model->setQuery(queryText);
              model->setHeaderData(0, Qt::Horizontal, QObject::tr("REFERENCE"));
              model->setHeaderData(1, Qt::Horizontal, QObject::tr("CIN"));
              model->setHeaderData(2, Qt::Horizontal, QObject::tr("NUMS"));
   return model;
        }
  bool Evenement::modifier(QString ref,int cin, int numS)
        {   //    QString ref_i=QString::number(ref);
                   QSqlQuery query;
                   query.prepare("update events set  CIN=:cin,NUMS=:numS where REFERENCE=:ref");
                   query.bindValue(":ref",ref);
                   query.bindValue(":CIN",cin);
                   query.bindValue(":numS",numS);

           return query.exec();
        }








