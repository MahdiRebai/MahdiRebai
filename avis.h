#ifndef ENQUETE_H
#define ENQUETE_H
#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>


class avis
{
    int Numavis;
    QString Nom;
    QString Objet;
    QString Reclamation;
public:
    avis();
    avis(QString,QString,QString,int);

    avis(int,QString,QString,QString);
    int getNum_avis();
    QString getNom();
    QString getObjet();
    QString getReclamation();
    void setNum_avis(int );
    void setNom(QString );
    void setObjet(QString );
    void setReclamation(QString );


    bool ajouter();
    QSqlQueryModel* afficher();
    bool supprime(int);
     bool modifier(int);

     QSqlQueryModel * trier();
     QSqlQueryModel * trier1();
     QSqlQueryModel * trier2();
     QSqlQueryModel* rechercher(QString Nom);
     QString printPDF();


};




#endif // ENQUETE_H

