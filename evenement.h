#ifndef EVENEMENT_H
#define EVENEMENT_H
<<<<<<< HEAD

#include<QSqlQueryModel>
=======
#include <QSqlQueryModel>
#include <QString>
#include <vector>

>>>>>>> d417753b0206d5dcaf751e7329a8634bb1685c15
class Evenement
{
public:
    Evenement();
<<<<<<< HEAD
    Evenement(QString,int,int);
=======
    Evenement(QString,int,int,int);
>>>>>>> d417753b0206d5dcaf751e7329a8634bb1685c15
    QString getRef();
    int getCin();
    int getNumS();
    void setRef(QString);
    void setCin(int);
    void setNumS(int);
<<<<<<< HEAD
    bool ajouter();
    QSqlQueryModel *afficher(QString numS,QString ordre,QString parametre);
     bool supprimer(QString ref);
     bool modifier(QString ref,int cin, int numS);
=======
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


>>>>>>> d417753b0206d5dcaf751e7329a8634bb1685c15

private: QString ref;
         int cin;
         int numS;
<<<<<<< HEAD
=======
         int PRIX;
         QString date ;
         int PENALITE;
         std::vector<int> TabStandby[4];

>>>>>>> d417753b0206d5dcaf751e7329a8634bb1685c15
};

#endif // EVENEMENT_H
