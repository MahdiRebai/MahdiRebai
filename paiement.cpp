#include "paiement.h"

paiement::paiement()
{
    montant="";
    reference="";
    type="";
    date="";

}

void paiement::setmontant(QString n) {montant=n;}
void paiement::setreference(QString n) {reference=n;}
void paiement::settype(QString n) {type=n;}
void paiement::setdate(QString n) {date=n;}

QString paiement::get_montant(){return montant;}
QString paiement::get_reference(){return reference;}
QString paiement::get_type(){return type;}
QString paiement::get_date(){return date;}
