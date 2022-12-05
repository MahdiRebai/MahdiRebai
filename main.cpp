<<<<<<< HEAD
<<<<<<< HEAD
=======

>>>>>>> d417753b0206d5dcaf751e7329a8634bb1685c15
=======

>>>>>>> 0ab4f713885d0fe53e6e35a8fab2b7c8e8d296d1
#include "mainwindow.h"
#include <QApplication>
#include <QMessageBox>
#include "connection.h"



int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    Connection c;
       bool test=c.createconnect();
       if(test)
       {
           QMessageBox::information(nullptr, QObject::tr("database is open"),
                       QObject::tr("connection successful.\n"
                                   "Click Cancel to exit."), QMessageBox::Cancel);

   }
       else
        {   QMessageBox::critical(nullptr, QObject::tr("database is not open"),
                       QObject::tr("connection failed.\n"
                                   "Click Cancel to exit."), QMessageBox::Cancel);}



    return a.exec();
}
