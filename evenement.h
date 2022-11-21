#ifndef EVENEMENT_H
#define EVENEMENT_H

#include<QSqlQueryModel>
class Evenement
{
public:
    Evenement();
    Evenement(QString,int,int);
    QString getRef();
    int getCin();
    int getNumS();
    void setRef(QString);
    void setCin(int);
    void setNumS(int);
    bool ajouter();
    QSqlQueryModel *afficher(QString numS,QString ordre,QString parametre);
     bool supprimer(QString ref);
     bool modifier(QString ref,int cin, int numS);

private: QString ref;
         int cin;
         int numS;
};

#endif // EVENEMENT_H
