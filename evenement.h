#ifndef EVENEMENT_H
#define EVENEMENT_H
#include <QSqlQueryModel>
#include <QString>
#include <vector>

class Evenement
{
public:
    Evenement();
    Evenement(QString,int,int,int);
    QString getRef();
    int getCin();
    int getNumS();
    void setRef(QString);
    void setCin(int);
    void setNumS(int);
    bool ajouter(QString date_res);
    QSqlQueryModel *afficher(QString numS,QString ordre,QString parametre);
    QSqlQueryModel *afficher_standby();
    QSqlQueryModel *afficher_simple();
    void updating();
    bool supprimer(QString ref);
    bool modifier(QString ref,int cin, int numS,int PRIX);
    void set_prix(int input);
    void statistique(QVector<double>* ticks,QVector<QString> *labels);
    void nb_jours();
    int getPrix(QString ref);
    int get_standby();



private: QString ref;
         int cin;
         int numS;
         int PRIX;
         QString date ;
         int PENALITE;
         std::vector<int> TabStandby[4];

};

#endif // EVENEMENT_H
