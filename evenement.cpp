#include "evenement.h"
#include <QSqlQuery>
#include<QtDebug>
#include<QObject>
#include <QString>
#include<QSqlQueryModel>
#include <iostream>
#include <sstream>
#include <iterator>
#include <QMessageBox>
Evenement::Evenement()
{
    ref="";  cin=0;  numS=0; PRIX=0;

}


void Evenement::set_prix(int input){

    PRIX=input;}


    Evenement::Evenement(QString ref,int cin,int numS,int PRIX)
{      this->ref=ref;
        this->PRIX=PRIX;
        this->cin=cin;
        this->numS=numS;}


    QString Evenement::getRef(){return ref;}
    int Evenement::getCin(){return cin;}
    int Evenement::getNumS(){return numS;}

    void Evenement:: setRef(QString ref) {this->ref=ref;}
    void Evenement::setCin(int cin){this->cin=cin;}
    void Evenement::setNumS(int numS){this->numS=numS;}


    bool Evenement::ajouter(QString date_res)
    {
        QSqlQuery query;
        QString queryText ="INSERT INTO events (REFERENCE, cin, numS, DATE_RES,PRIX,ETAT) VALUES (:ref, :cin, :numS ,TO_DATE(\'"+date_res+"\',\'DD/MM/YYYY\'),:PRIX,'1')";
     //  QString ref_string=QString::number(ref);
        qDebug() <<PRIX ;
            //  query.prepare("INSERT INTO events (REFERENCE, cin, numS,PRIX) VALUES (:ref, :cin, :numS, :PRIX)");
                query.prepare(queryText) ;
                query.bindValue(":ref", ref);
                query.bindValue(":cin", cin);
                query.bindValue(":numS", numS);
                query.bindValue(":PRIX", PRIX);





              return query.exec();
    }
    bool Evenement::supprimer(QString ref)
    {

        QSqlQuery query;

    //    QString ref_string=QString::number(ref);
              query.prepare("Delete from events where (REFERENCE=:ref)");
                //scanf/cin
              query.bindValue(":ref", ref);

              return query.exec();


    }


    /*int Evenement::get_standby()
    {
        QString queryText ;
        int i=0;
       // queryText = "select * from service where  =1" ;
        queryText = "select num from servcie where STANDBY =1" ;
        //QString
        QSqlQuery query(queryText) ;
        while(query.next())
        {  TabStandby->push_back( query.value(0).toInt());
                i++;

        }
        return 0;
    }*/

   QSqlQueryModel *Evenement::afficher_standby()
    { QString queryText ;

       queryText = "select * from events where nums =1 or nums=2" ;

                 QSqlQueryModel * model=new  QSqlQueryModel();



                        //  QString line = QString::fromStdString(ss.str());
        model->setHeaderData(0, Qt::Horizontal, QObject::tr("REFERENCE"));
        model->setHeaderData(1, Qt::Horizontal, QObject::tr("CIN"));
        model->setHeaderData(2, Qt::Horizontal, QObject::tr("NUMS"));
        model->setHeaderData(3, Qt::Horizontal, QObject::tr("ETAT"));
       // model->setHeaderData(7, Qt::Horizontal, QObject::tr("ETAT"));



return model;


    }




  /* QSqlQueryModel *Evenement::afficher_simple()
    {
        QSqlQueryModel * model=new  QSqlQueryModel();
        QString queryText ;
        queryText="select * from events where NUMS between 1 and 5";
        qDebug()<< queryText ;
        model->setQuery(queryText);
        model->setHeaderData(0, Qt::Horizontal, QObject::tr("REFERENCE"));
        model->setHeaderData(1, Qt::Horizontal, QObject::tr("CIN"));
        model->setHeaderData(2, Qt::Horizontal, QObject::tr("NUMS"));
        model->setHeaderData(3, Qt::Horizontal, QObject::tr("ETAT"));



    }*/


     QSqlQueryModel *Evenement::afficher(QString numLine,QString ordre,QString parametre)
        {
              QSqlQueryModel * model=new  QSqlQueryModel();
              QString queryText ;
              if (parametre == "numero de service")
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
              model->setHeaderData(3, Qt::Horizontal, QObject::tr("PRIX"));
             // model->setHeaderData(7, Qt::Horizontal, QObject::tr("ETAT"));

   return model;
        }

  //   bool Evenement::annuler_event(int NUMS)


  bool Evenement::modifier(QString REFERENCE,int CIN, int NUMS,int PRIX)
        {     // QString ref_i=ref;
                   QSqlQuery query;
                   query.prepare("UPDATE events set REFERENCE=:REFERENCE , CIN=:CIN , NUMS=:NUMS , PRIX=:PRIX where REFERENCE=:REFERENCE" );
                   //UPDATE nom_de_table SET nom_colonne = 'nouvelle valeur’ WHERE condition

                   query.bindValue(":REFERENCE",REFERENCE);
                   query.bindValue(":CIN",CIN);
                   query.bindValue(":NUMS",NUMS);
                   query.bindValue(":PRIX",PRIX);



           return query.exec();
  }
  void Evenement::statistique(QVector<double>* ticks,QVector<QString> *labels)
  {
      QSqlQuery q;
      int i=0;
      q.exec("select PRIX from events");
      while (q.next())
      {
          QString identifiant = q.value(0).toString();
          i++;
          *ticks<<i;
          *labels <<identifiant;
      }
  }
 int Evenement::getPrix(QString ref)
 {
      QString queryText ;
      queryText = "select PRIX from events where reference = \'" + ref +"\'" ;
      QSqlQuery query(queryText) ;
      // QSqlQuery query("select PRIX from events where reference = \'A64\'") ;
      while (query.next())
      {return (query.value(0).toInt());}
      return 0;

 }



 QString Evenement::getname(QString input)
 {   QString returnname="";
     QString queryText ;
     queryText = "select name from agents where name = \'" + input +"\'" ;
     QSqlQuery query(queryText) ;
     while (query.next())
     {return (query.value(0).toString());}
     return returnname;
 }





 QString Evenement::getpwd(QString input2)
{QString returnpwd="";
     QString queryText ;
     queryText = "select pwd from agents where pwd = \'" + input2 +"\'" ;
     QSqlQuery query(queryText) ;
     while (query.next())
     {return (query.value(0).toString());}
     return returnpwd;

 }

 QSqlQueryModel *Evenement::show()
 {
     QSqlQueryModel* model=new QSqlQueryModel();
      model->setQuery("SELECT * FROM agents");
      return model;
 }




 bool Evenement::add()
 {
  /*
     QSqlQuery query;
     QString queryText ="INSERT INTO agents (name,pwd) VALUES (:NAME,:PWD)";
             query.prepare(queryText) ;
             query.bindValue(":NAME", NAME);
             query.bindValue(":PWD",PWD);
    return query.exec();*/


 }
