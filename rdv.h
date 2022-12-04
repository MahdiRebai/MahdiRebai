#ifndef RDV_H
#define RDV_H
#include <QString>
#include <QSqlQueryModel>
class rdv
{
public:
    rdv();
    rdv(int,QString);
    bool ajRdv();
    bool modifrdv(int,QString);
    bool supprimerrdv(int);
      QSqlQueryModel* afficherrdv();
       QSqlQueryModel * afficheroncombo();
public:
    int cin;
    QString datee;


};

#endif // RDV_H
