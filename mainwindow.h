#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "evenement.h"
#include <QMainWindow>
#include <QtCharts>
#include <QChartView>
#include <QLineSeries>
#include "penalite.h"
#include "arduino.h"
#include "service.h"
#include <QMessageBox>


QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    QChart *chartevent ;
    QChartView *chartViewEvents ;
 private slots:
    void update_label();
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

    void on_ajout_clicked();

    void on_affichage_clicked();

    void on_supprimer_clicked();

    void on_modifier_clicked();

    void on_option_clicked();

    void on_PBmodifierX_clicked();

    void on_comboBox_ordre_currentTextChanged(const QString &arg1);

    void on_comboBox_parametre_currentTextChanged(const QString &arg1);

    void on_lineEdit_recherche_textChanged(const QString &arg1);

    void on_tettt_clicked();

    void on_comboBox_parametre_activated(const QString &arg1);

    void on_pdf_clicked();

    void on_ds_clicked();

    void on_lineEdit_refpen_returnPressed();

    void on_pushButton_35_clicked();

    void on_pushButton_34_clicked();

    void on_pushButton_RE_clicked();

    void on_pushButtonANN_clicked();

    void on_xe_clicked();

    void on_TESTTT_clicked();

    void on_pd2_clicked();


    void on_ON_clicked();

    void on_OFF_clicked();

    void on_plus_clicked();

    void on_moins_clicked();

    void on_pushan_clicked();

    void on_pushcon_clicked();

    void on_ARDPUSH_clicked();

    void on_buttard_clicked();

    void on_retourbutt_clicked();

    void on_tbview_activated(const QModelIndex &index);

    void on_pbajouter_clicked();

    void on_pbmodif_clicked();

    void on_pb_supprimer_clicked();

    void on_pb_pdf_clicked();
    //QString currDate();

    void stats(QString table,QString critere,int valeur1,int valeur2,QString unite);


    void on_pbstatservice_clicked();

    void on_pushButtonclasser_clicked();

    void on_pbpromo_clicked();

    void on_comboBox_tri_activated(const QString &arg1);

    void on_comboBox_tri_currentIndexChanged(const QString &arg1);

    void on_lineEdit_chercher_num_textChanged(const QString &arg1);

    void on_ajj_clicked();

    void on_modd_clicked();

    void on_supp_clicked();

    void on_aff_clicked();

    void on_stat_clicked();

    void on_classif_clicked();

    void on_promo_clicked();

    void on_ard_clicked();

    void on_PbAjouter_pressed();

    void on_pushButton_pressed();

    void on_LEX_textEdited(const QString &arg1);

    void on_pushButton_25_clicked();

private:
    Ui::MainWindow *ui;
        Evenement E;
        penalite P ;
        arduino A;
        QByteArray data;
        Service S;

};
#endif // MAINWINDOW_H
