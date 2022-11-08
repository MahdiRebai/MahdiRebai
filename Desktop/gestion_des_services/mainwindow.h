#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QMainWindow>
#include<QMessageBox>
#include "service.h"


namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_pb_ajouter_clicked();

    void on_pb_supprimer_clicked();

    void on_pushButton_2_clicked();
    void on_comboBox_tri_currentIndexChanged(const QString &arg1);
    void on_lineEdit_cherche_num_textChanged(const QString &arg1);
    void on_pb_pdf_clicked();

    void stats(QString table,QString critere,int valeur1,int valeur2,QString unite);

    void on_pushButton_clicked();

    void on_pushButton_5_clicked();

private:
    Ui::MainWindow *ui;
    Service S;
};

#endif // MAINWINDOW_H
