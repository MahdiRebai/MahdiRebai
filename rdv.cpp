#include "rdv.h"
#include <QSqlQuery>
rdv::rdv()
{

}
rdv::rdv(int cin,QString datee)
{
    this->cin=cin;
    this->datee=datee;
}
bool rdv::ajRdv()
{
    QSqlQuery query;


  query.prepare("INSERT INTO RDV (CIN,datee) "
                "VALUES (:CIN, :datee)");
  query.bindValue(":CIN", cin);
  query.bindValue(":datee", datee);
  return query.exec();
}
QSqlQueryModel* rdv::afficherrdv()
{
    QSqlQueryModel* model=new QSqlQueryModel();
     model->setQuery("SELECT * FROM RDV INNER JOIN CLIENTT ON RDV.CIN=CLIENTT.CIN ");
     return model;
}

bool rdv::supprimerrdv(int cin)
{
    QSqlQuery query;
            query.prepare("select * from rdv where cin=:cin");
            query.bindValue(":cin", cin);
            query.exec();
            if (query.next())
            {
             query.prepare(" Delete from rdv where cin=:cin");
             query.bindValue(":cin", cin);

                    query.exec();
                 return true;

            }

             return false;
}
QSqlQueryModel * rdv::afficheroncombo()
{
    QSqlQueryModel * model= new QSqlQueryModel();

    model->setQuery("select * from rdv");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("cin"));

        return model;

}

bool rdv::modifrdv(int cin, QString datee)
{
    QSqlQuery query;


         query.prepare("update rdv set datee=:datee "
                       "where cin=:cin");

         query.bindValue(":datee", datee);
         query.bindValue(":cin", cin);

        return query.exec();
}

