#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "client.h"
#include "rdv.h"
#include "statclient.h"
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
    void on_npushButton_clicked();

    void on_npushButton_2_clicked();

    void on_ncomboBox_3_currentIndexChanged(int index);

    void on_npushButton_3_clicked();

    void on_npushButton_4_clicked();

    void on_nlineEdit_textChanged(const QString &arg1);

    void on_lineEdit_rech_textChanged(const QString &arg1);

    void on_npushButton_5_clicked();

    void on_b_aj_rdv_clicked();

    void on_cb_idclient_currentIndexChanged(int index);

    void on_npushButton_6_clicked();

    void on_npushButton_7_clicked();

    //void on_lineEdit_rech_cursorPositionChanged(int arg1, int arg2);



private:
    Ui::MainWindow *ui;
    Client cl;
    rdv r;
    statclient *stat_client;
};
#endif // MAINWINDOW_H
