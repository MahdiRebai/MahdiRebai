#ifndef PAIEMENT_H
#define PAIEMENT_H
#include<QString>
#include<QDate>
#include<QSqlQuery>
#include<QSqlQueryModel>

class paiement
{
    QString TYPE_PAIEMENT;
    QString REFERENCE;
    int MONTANT;
    QString DATE_PAIEMENT;
public:
    paiement();
    paiement(QString,int,QString,QString);

    void setmontant(int MONTANT );
    void setreference(QString REFERENCE);
    void settype(QString TYPE_PAIEMENT);
    void setdate(QString DATE_PAIEMENT);
    float get_montant();
    int get_reference();
    QString get_type();
    QString get_date();
    bool ajouter();
    QSqlQueryModel * afficher();
    bool supprimer(QString);
    bool modifier (QString,int,QString,QString);
    QSqlQueryModel * affichervaleur(QString);
    QSqlQueryModel *afficher_trier(QString arg);
    QSqlQuery *statistique();
    QSqlQueryModel *recherche_avance(QString arg, int checkedButton);
    bool ajouter_remboursement(QString REFERENCE, QString Montant_Rembourse, QString Cause_Remboursement);
    QSqlQuery *affichage_remboursement();
    QSqlQuery *affichage_chiffre_affaire();
private:


};

#endif // PAIEMENT_H
