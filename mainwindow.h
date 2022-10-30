#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "evenement.h"
#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_lineEdit_2_returnPressed();

    void on_pushButton_clicked();

    void on_pushButton_2_clicked();


    void on_pushButton_3_clicked();

    void on_pushButton_7_clicked();







    void on_pbcancel_2_clicked();

    void on_pbcancel_3_clicked();



    void on_BUTTNEXT_clicked();


    void on_CONFIRM_clicked();

    void on_RETOUR_clicked();

    void on_pushButton_26_clicked();


    void on_pushButton_21_clicked();

    void on_pushButton_19_clicked();

    void on_SERVICE_butt_clicked();



    void on_pushButton_22_clicked();

    void on_pushButton_24_clicked();

    void on_pushButton_20_clicked();

    void on_pushButton_23_clicked();

    void on_pushButton_5_clicked();

    void on_PBRECHERCHE_clicked();

    void on_PSSTATS_clicked();

    void on_PBFICHIER_clicked();

    void on_PBANNULER_clicked();

    void on_PBREPORTER_clicked();

    void on_PbAjouter_clicked();

    void on_TR_clicked();

    void on_SuppButt_clicked();

    void on_pushButton_6_clicked();

    void on_PBmodifier_clicked();

private:
    Ui::MainWindow *ui;
        Evenement E;
};
#endif // MAINWINDOW_H
