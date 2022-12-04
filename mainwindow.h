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
#include "statclient.h"
#include "client.h"
#include "rdv.h"
#include "avis.h"
#include "notification.h"
#include<QPropertyAnimation>
#include <dialog.h>
#include "paiement.h"



QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
        int mode=1;
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
    void statm(QString table,QString critere,int valeur1,int valeur2,QString unite);


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

    void on_npushButton_clicked();

    void on_npushButton_2_clicked();

    void on_ncomboBox_3_currentIndexChanged(int index);

    void on_npushButton_3_clicked();

    void on_npushButton_5_clicked();

    void on_npushButton_4_clicked();

    void on_lineEdit_rech_textChanged(const QString &arg1);

    void on_b_aj_rdv_clicked();

    void on_npushButton_6_clicked();

    void on_npushButton_7_clicked();

    void on_cb_idclient_currentIndexChanged(int index);

    void on_ajouter_clicked();

    void on_modifier_2_clicked();

    void on_tri_nom_clicked();

    void on_tri_cin_clicked();

    void on_tri_pass_clicked();

    void on_supprimer_3_clicked();

    void on_supprimer_4_clicked();

    void on_tri_nom_2_clicked();

    void on_supprimer_2_clicked();

    void on_testing_clicked();

    void on_sttbutt_clicked();

    void on_pushButton_4_clicked();

    void on_ldx_returnPressed();

    void on_pushButton_27_clicked();

    void on_testtt_clicked();

    void on_lock_clicked();

    void on_ooo_clicked();

    void on_lastpb_clicked();

    void on_paiementaj_clicked();

    void on_pbmodpai_clicked();

    void on_pbsuppapi_clicked();

    void on_rembpai_clicked();

    void on_comboBox_currentIndexChanged(const QString &arg1);

    void on_lineEdit_2_textChanged(const QString &arg1);

    void on_sombre_clicked();

    void on_tabWidget_tabBarClicked(int index);

    void on_poo_clicked();

    void on_tabWidget_6_currentChanged(int index);

    void on_tabWidget_6_tabBarClicked(int index);

    void on_toolButton_triggered(QAction *arg1);

    void on_toolButton_clicked();

    void on_statpa_clicked();

    void on_rembooo_clicked();

    void on_premb_clicked();

    void on_chiffred_clicked();

    void on_ajpaix_clicked();

    void on_affpaix_clicked();

    void on_modpaix_clicked();

    void on_suppmai_clicked();

    void on_TWW_tabBarClicked(int index);

private:
    Ui::MainWindow *ui;
        Evenement E;
        penalite P ;
        arduino A;
        QByteArray data;
        Service S;
        Client cl;
        rdv r;
        statclient *stat_client;
        avis Etmp;
        Dialog *dialog;
          paiement p;

        QPropertyAnimation *animation;


};
#endif // MAINWINDOW_H
