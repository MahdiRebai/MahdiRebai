#ifndef PAIEMENT_H
#define PAIEMENT_H
#include<QString>
class paiement
{
public:
    void setmontant(QString n);
    void setreference(QString n);
    void settype(QString n);
    void setdate(QString n);
    QString get_montant();
    QString get_reference();
    QString get_type();
    QString get_date();
    paiement();

private:
    QString montant,reference,type,date;
};

#endif // PAIEMENT_H
