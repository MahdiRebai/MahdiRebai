#ifndef SERVICE_H
#define SERVICE_H

#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>
class Service
{
public:
    Service();
    Service(int, QString,int );
    int getNUM();
    QString getTheme();
    int getclasse();
   void setNUM(int);
   void setTheme(QString);
   void setclasse(int);
   void setstandby(int);
   int getstandby();


   bool ajouter();
   QSqlQueryModel * afficher();
   bool supprimer(int);
   bool modifier(int NUM,bool rain);
   bool modifier(int NUM,QString Theme, int classe);
   QSqlQueryModel* afficher_S_trie_NUM();
   QSqlQueryModel* afficher_S_trie_classe();
    QSqlQueryModel *rechercher(QString );
     QSqlQueryModel * classification();
    QSqlQueryModel * Promotion();
private:
    int NUM, classe,standby;
    QString Theme;

};

#endif // SERVICE_H
