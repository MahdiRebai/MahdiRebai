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


   bool ajouter();
   QSqlQueryModel * afficher();
   bool supprimer(int);
   bool modifier(int NUM,QString Theme, int classe);
   QSqlQueryModel* afficher_S_trie_NUM();
   QSqlQueryModel* afficher_S_trie_theme();
    QSqlQueryModel *rechercher(QString );

private:
    int NUM, classe;
    QString Theme;

};

#endif // SERVICE_H
