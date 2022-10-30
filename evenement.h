#ifndef EVENEMENT_H
#define EVENEMENT_H

#include<QSqlQueryModel>
class Evenement
{
public:
    Evenement();
    Evenement(int,int,int);
    int getRef();
    int getCin();
    int getNumS();
    void setRef(int);
    void setCin(int);
    void setNumS(int);
    bool ajouter();
    QSqlQueryModel *afficher();
    bool supprimer(int );
     bool modifier(int ref,int cin, int numS);

private: int ref;
         int cin;
         int numS;
};

#endif // EVENEMENT_H
