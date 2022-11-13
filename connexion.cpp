#include "connexion.h"

connexion::connexion()
{

}
bool connexion::create_cnx(){

    bool test=false;
    QSqlDatabase db=QSqlDatabase::addDatabase("QODBC");
    db.setDatabaseName("projet");
       db.setUserName("nour");
       db.setPassword("211JFT9533");
    if(db.open())
        test=true;
    return test;
}

void connexion::close_cnx(){db.close();}
