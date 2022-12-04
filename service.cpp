#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "service.h"
#include <QString>
#include <QtDebug>
#include <QObject>

Service::Service()
{
 NUM=0;classe=0;Theme="";
}

Service::Service(int NUM,QString Theme ,int classe)
{
    this->NUM=NUM; this->Theme=Theme;this->classe=classe;
}
int Service:: getNUM(){return NUM;}
QString  Service:: getTheme(){return Theme;}
int Service:: getclasse(){return classe;}

void Service::setNUM(int NUM){this->NUM=NUM;}
void Service::setTheme(QString Theme){this->Theme=Theme;}
void Service::setclasse(int classe){this->classe=classe;}

int Service:: getstandby(){return standby;}

void Service::setstandby(int standby){this->standby=standby;}
 bool Service::ajouter()
 {
     QSqlQuery query;
    QString NUM_string = QString::number(NUM);
    query.prepare("INSERT INTO Service (NUM, Theme, classe) "
                  "VALUES (:NUM, :Theme, :classe)");
    query.bindValue(":NUM", NUM_string);
    query.bindValue(":Theme", Theme);
    query.bindValue(":classe", classe);


    return query.exec();
 }
 bool Service::supprimer(int NUM)
 {
     QSqlQuery query;
    query.prepare("Delete from service where NUM=:NUM");
    query.bindValue(":NUM", NUM);



    return query.exec();
 }



 QSqlQueryModel* Service:: afficher()
 {
     QSqlQueryModel* model=new QSqlQueryModel();

           model->setQuery("SELECT * FROM Service");
           model->setHeaderData(0, Qt::Horizontal, QObject::tr("NUM"));
           model->setHeaderData(1, Qt::Horizontal, QObject::tr("Theme"));
           model->setHeaderData(2, Qt::Horizontal, QObject::tr("classe"));
           model->setHeaderData(3, Qt::Horizontal, QObject::tr("standby"));

     return model;
 }
 bool Service::modifier(int NUM, bool rain)
 {
     QString NUM_string=QString::number(NUM);
         QSqlQuery query;
            query.prepare("update service set standby=:standby where NUM=:NUM");
            query.bindValue(":NUM",NUM_string);
            query.bindValue(":standby",(int)rain);

    return query.exec();
 }

 bool Service::modifier(int NUM,QString Theme, int classe)
 {
     QString NUM_string=QString::number(NUM);
         QSqlQuery query;
            query.prepare("update service set NUM=:NUM,Theme=:Theme,classe=:classe where NUM=:NUM");
            query.bindValue(":NUM",NUM_string);
            query.bindValue(":Theme",Theme);
            query.bindValue(":classe",classe);

    return query.exec();
 }
 QSqlQueryModel * Service::afficher_S_trie_NUM()
 {
     QSqlQueryModel * model= new QSqlQueryModel();

     model->setQuery("SELECT * FROM SERVICE ORDER BY NUM ;");
     model->setHeaderData(0,Qt::Horizontal,QObject::tr("NUM"));
     model->setHeaderData(1,Qt::Horizontal,QObject::tr("theme"));
     model->setHeaderData(2,Qt::Horizontal,QObject::tr("classe"));

     return model;
 }
 QSqlQueryModel* Service:: afficher_S_trie_classe()
 {
     QSqlQueryModel * model= new QSqlQueryModel();

     model->setQuery("SELECT * FROM SERVICE ORDER BY CLASSE ;");
     model->setHeaderData(0,Qt::Horizontal,QObject::tr("NUM"));
     model->setHeaderData(1,Qt::Horizontal,QObject::tr("theme"));
     model->setHeaderData(2,Qt::Horizontal,QObject::tr("classe"));

     return model;
 }
 QSqlQueryModel * Service::rechercher(QString NUM)
 {
     QSqlQueryModel * model= new QSqlQueryModel();

     model->setQuery("SELECT * FROM SERVICE WHERE NUM LIKE '%"+NUM+"%' ");

     model->setHeaderData(0,Qt::Horizontal,QObject::tr("NUM"));
     model->setHeaderData(1,Qt::Horizontal,QObject::tr("Theme"));
     model->setHeaderData(2,Qt::Horizontal,QObject::tr("classe"));

     return model;
 }

 QSqlQueryModel * Service::classification()
 {
     QSqlQueryModel * model= new QSqlQueryModel();
     model->setQuery("SELECT EVENTS.NUMS, AVG(AVIS.NOTE), CASE WHEN AVG(AVIS.NOTE)>=0 and AVG(AVIS.NOTE)<=2 then '3' WHEN AVG(AVIS.NOTE)>2 and AVG(AVIS.NOTE)<5 then '2' else '1' end as classe FROM AVIS INNER JOIN EVENTS ON EVENTS.REFERENCE=AVIS.REFERENCE GROUP BY EVENTS.NUMS ORDER BY EVENTS.NUMS");
     model->setHeaderData(0,Qt::Horizontal,QObject::tr("EVENTS.NUMS"));
     model->setHeaderData(1,Qt::Horizontal,QObject::tr("AVIS.NOTE"));

     // model->setQuery("SELECT NUM  FROM EVENEMENT");
     return model;
 }

 QSqlQueryModel * Service::Promotion()
 {
     QSqlQueryModel * model= new QSqlQueryModel();

       model->setQuery("SELECT PAIEMENT.REFERENCE ,(MONTANT-MONTANT*0.2) AS PRIXFINAL FROM PAIEMENT WHERE REFERENCE in (SELECT REFERENCE FROM EVENTS WHERE NUMS in (SELECT NUM FROM SERVICE WHERE CLASSE=3)) ");


     model->setHeaderData(0,Qt::Horizontal,QObject::tr("REFERENCE"));
     //model->setHeaderData(0,Qt::Horizontal,QObject::tr("MONTANT"));

     return model;

 }
