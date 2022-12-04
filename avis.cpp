#include "avis.h"
#include<QSqlDatabase>
#include<QSqlQuery>

avis::avis()
{
    Numavis=0;
    Nom="";
    Objet="";
    Reclamation="";
}
avis::avis (int Numavis, QString Nom, QString Objet, QString Reclamation)
{
    this->Numavis=Numavis;
        this->Nom=Nom;
        this->Objet=Objet;
        this->Reclamation=Reclamation;
}

int avis::getNum_avis() {return Numavis;}
QString avis:: getNom(){ return  Nom;}
QString avis:: getObjet(){return  Objet;}
QString avis:: getReclamation(){return  Reclamation;}
void avis:: setNum_avis(int Numavis){this->Numavis=Numavis;}
void avis:: setObjet(QString Objet){this->Objet=Objet;}
void avis:: setReclamation(QString Reclamation){this->Reclamation=Reclamation;}
void avis:: setNom(QString Nom){this->Nom=Nom;}

bool avis::ajouter(){
    QSqlQuery query(QSqlDatabase::database("test-bd"));



        query.prepare("INSERT INTO avis (Numavis,Nom, Objet, Reclamation) "
                      "VALUES (:Numavis, :Nom, :Objet, :Reclamation)");
        query.bindValue(":Numavis",Numavis);

        query.bindValue(":Nom",Nom);
        query.bindValue(":Objet",Objet);
        query.bindValue(":Reclamation", Reclamation);

        return query.exec();
}
QSqlQueryModel *avis::afficher(){
    QSqlQueryModel *model=new QSqlQueryModel();
    model->setQuery("select * from avis");
    model->setHeaderData(0,Qt::Horizontal,QObject::tr("Numavis"));
    model->setHeaderData(1,Qt::Horizontal,QObject::tr("Nom"));
    model->setHeaderData(2,Qt::Horizontal,QObject::tr("Objet"));
    model->setHeaderData(3,Qt::Horizontal,QObject::tr("Reclamation"));



    return  model;


}
bool avis::supprime(int Numavis) {
    QSqlQuery query;
    QString res=QString::number(Numavis);
    query.prepare("delete from avis where Numavis=:Numavis");
    query.bindValue(":Numavis",Numavis);
    return  query.exec();
}



bool avis::modifier(int Num_avis)
{
    QSqlQuery query;
    query.prepare("update avis set Nom = ?, Objet = ?, Reclamation = ? where Numavis = ?");
    query.addBindValue(Num_avis);
    query.addBindValue(Nom);
    query.addBindValue(Objet);
    query.addBindValue(Reclamation);

    return query.exec();
}
QSqlQueryModel *avis:: trier(){
    QSqlQueryModel *model=new QSqlQueryModel();
    model->setQuery("select * from avis  order by Nom desc");
    model->setHeaderData(0,Qt::Horizontal,QObject::tr("Numavis"));
    model->setHeaderData(1,Qt::Horizontal,QObject::tr("Nom"));
    model->setHeaderData(2,Qt::Horizontal,QObject::tr("Objet"));
    model->setHeaderData(3,Qt::Horizontal,QObject::tr("Reclamation"));

    return  model;


}
QSqlQueryModel *avis:: trier1(){
    QSqlQueryModel *model=new QSqlQueryModel();
    model->setQuery("select * from avis  order by Objet desc");
    model->setHeaderData(0,Qt::Horizontal,QObject::tr("Numavis"));
    model->setHeaderData(1,Qt::Horizontal,QObject::tr("Nom"));
    model->setHeaderData(2,Qt::Horizontal,QObject::tr("Objet"));
    model->setHeaderData(3,Qt::Horizontal,QObject::tr("Reclamation"));

    return  model;


}
QSqlQueryModel *avis:: trier2(){
    QSqlQueryModel *model=new QSqlQueryModel();
    model->setQuery("select * from avis  order by Reclamation desc");
    model->setHeaderData(0,Qt::Horizontal,QObject::tr("Numavis"));
    model->setHeaderData(1,Qt::Horizontal,QObject::tr("Nom"));
    model->setHeaderData(2,Qt::Horizontal,QObject::tr("Objet"));
    model->setHeaderData(3,Qt::Horizontal,QObject::tr("Reclamation"));


    return  model;


}

QSqlQueryModel * avis::rechercher(QString Nom){
    QSqlQueryModel *model=new QSqlQueryModel();
    model->setQuery("select * from avis WHERE(Numavis='"+Nom+"' OR Nom='"+Nom+"' OR Objet='"+Nom+  "'OR Reclamation='"+Nom+"' )");

    model->setHeaderData(0,Qt::Horizontal,QObject::tr("Numavis"));
    model->setHeaderData(1,Qt::Horizontal,QObject::tr("Nom"));
    model->setHeaderData(2,Qt::Horizontal,QObject::tr("Objet"));
    model->setHeaderData(3,Qt::Horizontal,QObject::tr("Reclamation"));
    return  model;
}
QString avis:: printPDF()
{

    QString text="             ** Les Reclamations   **       \n \n " ;
        QSqlQuery query ;
        QString i,x,z;


         query.exec("select * from avis");
         while (query.next())
         {
            i=query.value(0).toString();
             x=query.value(1).toString();
             z=query.value(2).toString();

           text += "\n Nom: "+i+"\n - Objet : "+ x+"\n  - -Reclamation : "+ z+"\n_____________\n";



        }

                return text ;
}

