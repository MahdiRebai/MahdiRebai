#ifndef STATCLIENT_H
#define STATCLIENT_H

#include <QDialog>

namespace Ui {
class statclient;
}

class statclient : public QDialog
{
    Q_OBJECT

public:
    explicit statclient(QWidget *parent = nullptr);
    ~statclient();
    QList <qreal> stat_client();
    QList <QString> stat_client_sexe();


private:
    Ui::statclient *ui;
};

#endif // STATCLIENT_H
