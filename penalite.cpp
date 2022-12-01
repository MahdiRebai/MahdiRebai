#include "penalite.h"
#include "evenement.h"
#include <QDebug>
penalite::penalite()
{

}

QSqlQueryModel *penalite::afficher(QString ref)
   {
         QSqlQueryModel * model=new  QSqlQueryModel();
         QString queryText ;
         if (ref!= "")
            queryText = "select * from events where reference = \'" + ref+"\'" ;
            else
             queryText = "select * from events " ;

         model->setQuery(queryText);
         model->setHeaderData(0, Qt::Horizontal, QObject::tr("REFERENCE"));
         model->setHeaderData(1, Qt::Horizontal, QObject::tr("CIN"));
         model->setHeaderData(2, Qt::Horizontal, QObject::tr("NUMS"));
         model->setHeaderData(3, Qt::Horizontal, QObject::tr("PRIX"));

return model;
   }
bool penalite::updateDate(QString ref,QString newDate)
{
    QString queryText;
    queryText = "update events SET DATE_MOD = TO_DATE(\'" + newDate+"\',\'DD/MM/YYYY\') where reference = \'" + ref+"\'" ;
    QSqlQuery query(queryText) ;

    return query.exec() ;
}

int penalite::diff_jours(QString ref)
{
    QString queryText ;
    queryText = "select date_mod - date_res from events where reference = \'" + ref +"\'" ;
    QSqlQuery query(queryText) ;
    while (query.next())
        return (query.value(0).toInt()) ;

}

QString penalite::verif(QString ref)
{
    QString queryText ;
    QString returnval="";
    queryText = "select reference from events where reference = \'" + ref +"\'" ;
    QSqlQuery query(queryText) ;
    while (query.next())
        return query.value(0).toString();

    return returnval ;

}

void penalite::set_sound(int a)
{
    sound = a;
}

int penalite::get_sound()
{
    return sound ;
}

bool penalite::penality2(QString ref,int ptheme)
{

    int pR=0;
    int pen=0 ;
    Evenement E;
   // int nb_jours=diff_jours((ref));
    QString test="";
    int nb_jours =23 ;
     pR=E.getPrix(ref);
      if(nb_jours<=7)
          pen=(pR*10)/100;
       if((nb_jours>=7)&&(nb_jours<=20))
          pen=(pR*15)/100;
         if (nb_jours>=20)
          pen=(pR*20)/100;
      QString pens=QString::number(pen+ptheme);
      //return pen;
      test = verif(ref);
      qDebug()<< "TEST "<<test;
       if(test!="")
           sound = 1;
      QString queryText;
      if (ptheme==0)
      queryText = "update events SET PENALITE=\'"+pens+"\'where reference = \'"+ref+"\'" ;
      else
          queryText = "update events SET PENALITE=\'"+pens+"\',etat = '0' where reference = \'"+ref+"\'" ;


      qDebug() << queryText;

      QSqlQuery query(queryText);


      return query.exec() ;
}



bool penalite::penality(QString ref/*,int ptheme*/)
{

    int pR,pen;
    Evenement E;
    int nb_jours=diff_jours((ref));
     pR=E.getPrix(ref);
      if(nb_jours<=7)
          pen=(pR*10)/100;
       if((nb_jours>=7)&&(nb_jours<=20))
          pen=(pR*15)/100;
         if (nb_jours>=20)
          pen=(pR*20)/100;
      QString pens=QString::number(pen/*+ptheme*/);
      //return pen;
      QString queryText;
      //if (ptheme==0)

      queryText = "update events SET PENALITE=\'"+pens+"\'where reference = \'"+ref+"\'" ;
      /*else
          queryText = "update events SET PENALITE=\'"+pens+"\',etat = '0' where reference = \'"+ref+"\'" ;*/

      QSqlQuery query(queryText) ;

      return query.exec() ;
}

 bool penalite::penality_ann(QString ref)
 {   penalite p;
     int ptheme=p.penalite_theme(ref);
     int pR,pen;
     Evenement E;
     int nb_jours=diff_jours((ref));
      pR=E.getPrix(ref);
       if(nb_jours<=7)
           pen=(pR*10)/100;
        if((nb_jours>=7)&&(nb_jours<=20))
           pen=(pR*15)/100;
          if (nb_jours>=20)
           pen=(pR*20)/100;
       int n=pen+ptheme;
       QString pens=QString::number(n);
       //return pen;
       QString queryText;

      // queryText = "update events SET PENALITE=\'"+pens+"\',etat = '0' where reference = \'"+ref+"\'" ;
       queryText = "update events SET PENALITE=\'"+pens+"\' where reference = \'"+ref+"\'" ;

      /* //if (ptheme==0)
       queryText = "update events SET PENALITE=\'"+pens+"\'where reference = \'"+ref+"\'" ;
       *else*/

       QSqlQuery query(queryText) ;

       return query.exec() ;






 }













QString penalite:: get_theme(QString ref)
   {
    QString queryText;
    queryText = "SELECT theme from service where REFERENCE=\'"+ref+"\'";
    QSqlQuery query(queryText) ;
    while(query.next())
        return(query.value(0).toString());
  }
int penalite::penalite_theme(QString ref)
{
    Evenement E;


    int prix=E.getPrix(ref);
    //int prix= 1;
    //QString theme=get_theme(ref);
    QString theme = "anniversaire" ;
    if(theme == "anniversaire" )
         return (int)(0.05*prix) ;
     if(theme == "ceremonie" )
         return (int)(0.1*prix);
     if(theme=="mariage")
         return (int)(0.2*prix);

     return 0;
}

















