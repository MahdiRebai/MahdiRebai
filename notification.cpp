#include "notification.h"
notification::notification()
{

}

void notification::notification_ajout()
{

    QSystemTrayIcon *notifyIcon = new QSystemTrayIcon;
   // notifyIcon->setIcon(QIcon(":/new/prefix1/MyResources/computer-icons-avatar-user-login-avatar.jpg"));
    notifyIcon->show();
    notifyIcon->showMessage("Gestion avis ","nouveauelle reclamation a  ete ajoutée ",QSystemTrayIcon::Information,15000);

}
