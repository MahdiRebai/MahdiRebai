#include "paiement.h"
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QString>
#include <QDebug>
paiement::paiement()
{
    REFERENCE="";
    MONTANT=0;
    TYPE_PAIEMENT="";
    DATE_PAIEMENT="";
}

paiement::paiement(QString REFERENCE,int MONTANT,QString TYPE_PAIEMENT,QString DATE_PAIEMENT)
{
    this->REFERENCE=REFERENCE;
    this->MONTANT = MONTANT;
    this->TYPE_PAIEMENT=TYPE_PAIEMENT;
    this->DATE_PAIEMENT=DATE_PAIEMENT;
}

 bool paiement::ajouter()
 {
     QSqlQuery query;


       // QString MON = QString::number(MONTANT);

      /* query.prepare("insert into PAIEMENT(REFERENCE,MONTANT,TYPE_PAIEMENT/*,DATE_PAIEMENT)"
                     "values(:REFERENCE,:MONTANT,:TYPE_PAIEMENT,:DATE_PAIEMENT)");*/
          query.prepare("insert into PAIEMENT(REFERENCE,MONTANT,TYPE_PAIEMENT,DATE_PAIEMENT)"
                     "values(:REFERENCE,:MONTANT,:TYPE_PAIEMENT,TO_DATE(\'"+DATE_PAIEMENT+"\',\'DD/MM/YYYY\'))");
          query.bindValue(":REFERENCE",REFERENCE);
          query.bindValue(":MONTANT",MONTANT);
          query.bindValue(":TYPE_PAIEMENT",TYPE_PAIEMENT);
          query.bindValue(":DATE_PAIEMENT",DATE_PAIEMENT);

   return query.exec();
 }
QSqlQueryModel *paiement::afficher()
{
        QSqlQueryModel * model=new QSqlQueryModel();
        model->setQuery("select REFERENCE,MONTANT,TYPE_PAIEMENT,DATE_PAIEMENT from PAIEMENT");
        model->setHeaderData(0,Qt::Horizontal,QObject::tr("REFERENCE"));
        model->setHeaderData(1,Qt::Horizontal,QObject::tr("MONTANT"));
        model->setHeaderData(2,Qt::Horizontal,QObject::tr("TYPE_PAIEMENT"));
        model->setHeaderData(3,Qt::Horizontal,QObject::tr("DATE_PAIEMENT"));
            return model;
    };

bool paiement::modifier(QString REFERENCE,int MONTANT,QString TYPE_PAIEMENT,QString DATE_PAIEMENT)
{
    QSqlQuery query;
    QString mon=QString::number(MONTANT);

            query.prepare("update PAIEMENT set REFERENCE =:REFERENCE,MONTANT=:MONTANT,TYPE_PAIEMENT=:TYPE_PAIEMENT,DATE_PAIEMENT=TO_DATE(\'"+DATE_PAIEMENT+"\',\'DD/MM/YYYY\') WHERE REFERENCE=:REFERENCE");
            query.bindValue(":REFERENCE",REFERENCE);
            query.bindValue(":MONTANT",mon);
            query.bindValue(":TYPE_PAIEMENT",TYPE_PAIEMENT);
            query.bindValue(":DATE_PAIEMENT",DATE_PAIEMENT);
            return  query.exec();
};

bool paiement::supprimer(QString REFERENCE)
{

    QSqlQuery query;
   // QString res=QString::number(REFERENCE);
    query.prepare("Delete from PAIEMENT where REFERENCE = :REFERENCE");
    query.bindValue(":REFERENCE",REFERENCE);
    return  query.exec();
};
QSqlQueryModel* paiement::affichervaleur(QString valeur)
{
    QSqlQueryModel * model=new QSqlQueryModel();
    QString ch="SELECT ";
    QString query=" FROM PAIEMENT";
    query=ch+valeur+query;
    qDebug() << query;
    model->setQuery(query);
    return model;
}


// select * from messages where id= 11 ;

///  select * from messages where id = "'"select * from messages where 1=1  //"'" idaziz


bool paiement::ajouter_remboursement(QString REFERENCE, QString Montant_Rembourse, QString Cause_Remboursement)
{

    QSqlQuery query;
   // QString res=QString::number(REFERENCE);
            query.prepare("update PAIEMENT set REMBOURSEMENT=:rem,MONTANT_REMBOURSE=:mr,CAUSE_REMBOURSEMENT=:cr  WHERE REFERENCE=:REFERENCE");
            query.bindValue(":rem",1);
            query.bindValue(":mr",Montant_Rembourse);
            query.bindValue(":cr",Cause_Remboursement);
            query.bindValue(":REFERENCE",REFERENCE);
            return query.exec();
};

QSqlQueryModel *paiement::afficher_trier(QString arg)
{
        QSqlQueryModel * model=new QSqlQueryModel();
        if ( arg == "Montant" ){
            model->setQuery("select * from PAIEMENT ORDER BY MONTANT ASC");
        }else if ( arg == "Type de paiement" ){
            model->setQuery("select * from PAIEMENT ORDER BY TYPE_PAIEMENT ASC");
        }
        else if ( arg == "Reference" ){
            model->setQuery("select * from PAIEMENT ORDER BY REFERENCE ASC");
        }
        else if ( arg == "Date" ){
             model->setQuery("select * from PAIEMENT ORDER BY DATE_PAIEMENT ASC");
        }else{
            model->setQuery("select * from PAIEMENT");
        }

        model->setHeaderData(0,Qt::Horizontal,QObject::tr("REFERENCE"));
        model->setHeaderData(1,Qt::Horizontal,QObject::tr("MONTANT"));
        model->setHeaderData(2,Qt::Horizontal,QObject::tr("TYPE_PAIEMENT"));
        model->setHeaderData(3,Qt::Horizontal,QObject::tr("DATE_PAIEMENT"));
            return model;
    };


QSqlQuery* paiement::statistique(){
    QSqlQuery* query = new QSqlQuery();
    query->prepare("select * from PAIEMENT");
    query->exec();
    return query;
}


QSqlQueryModel *paiement::recherche_avance(QString arg, int checkedButton)
{
        QSqlQueryModel * model=new QSqlQueryModel();

        if ( checkedButton == 0 ){
            model->setQuery("select * from PAIEMENT WHERE REFERENCE like '" "%" + arg + "%" "'  ");
        }else if ( checkedButton == 1 ){
            model->setQuery("select * from PAIEMENT WHERE TYPE_PAIEMENT like '" "%" + arg + "%" "'  ");
        }

        model->setHeaderData(0,Qt::Horizontal,QObject::tr("REFERENCE"));
        model->setHeaderData(1,Qt::Horizontal,QObject::tr("MONTANT"));
        model->setHeaderData(2,Qt::Horizontal,QObject::tr("TYPE_PAIEMENT"));
        model->setHeaderData(3,Qt::Horizontal,QObject::tr("DATE_PAIEMENT"));
        return model;

};



QSqlQuery* paiement::affichage_remboursement(){
    QSqlQuery* query = new QSqlQuery();
    query->prepare("select REFERENCE,MONTANT,MONTANT_REMBOURSE,CAUSE_REMBOURSEMENT from PAIEMENT");
    query->exec();
    return query;
}

QSqlQuery* paiement::affichage_chiffre_affaire(){
    QSqlQuery* query = new QSqlQuery();
    query->prepare("select MONTANT,REMBOURSEMENT,MONTANT_REMBOURSE from PAIEMENT");
    query->exec();
    return query;
}

