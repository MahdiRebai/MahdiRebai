
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

     return model;
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
 QSqlQueryModel* Service:: afficher_S_trie_theme()
 {
     QSqlQueryModel * model= new QSqlQueryModel();

     model->setQuery("SELECT * FROM SERVICE ORDER BY THEME ;");
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
