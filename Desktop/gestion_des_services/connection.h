#ifndef CONNEXION_H
#define CONNEXION_H
#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlQuery>

class Connection
{
    QSqlDatabase db;
public:
    Connection();
    bool createconnection();
    void closeconnection();
};


#endif // CONNEXION_H
