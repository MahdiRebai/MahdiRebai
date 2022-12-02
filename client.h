#ifndef CLIENT_H
#define CLIENT_H
#include <QString>
#include <QSqlQueryModel>
#include <QTableView>
//test
class Client
{
public:
    Client();
    Client(int,QString,QString,int,QString,QString);
    QSqlQueryModel* afficher();
     QSqlQueryModel * afficheroncombo();
       QSqlQueryModel * afficheroncomboidrec();
    bool supprimer(int);
    bool ajouter();
    bool ajRdv(int,QString);
   bool modifier(int,QString,QString,int,QString,QString);
    bool rechercher(int id);
    QSqlQueryModel* tri(QString,QString);
    void genererPDFr();
    void excel(QTableView *tab);
private:
    int cin,tel;
    QString nom,prenom,mail,sexe,datee;
};

#endif // CLIENT_H
