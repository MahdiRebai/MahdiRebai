#ifndef PENALITE_H
#define PENALITE_H
#include <QSqlQuery>
#include <QSqlQueryModel>

class penalite
{
public:
    penalite();
    QSqlQueryModel *afficher(QString ref);
    bool updateDate(QString ref,QString newDate) ;
    int diff_jours(QString ref) ;
    bool penality(QString ref/*int ptheme*/);
   int penalite_theme(QString);
    QString get_theme(QString ref);
   bool penality_ann(QString ref);
    int diff_jours_ann(QString ref);
    bool penality2(QString ref,int ptheme);
    QString verif(QString ref);
   void set_sound(int a);
    int get_sound();


    //QString get_today();
private:
    int sound =0    ;





};

#endif // PENALITE_H
