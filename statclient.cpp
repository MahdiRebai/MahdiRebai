#include "statclient.h"
#include "ui_statclient.h"
#include <QtCharts>
#include <QChartView>
#include <QPieSeries>
#include <QSqlQuery>


statclient::statclient(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::statclient)
{
    ui->setupUi(this);
    QPieSeries *series =new QPieSeries ;

    QList<qreal> list= stat_client();
     QList<QString> list2=stat_client_sexe();

     for(int i=0 ;i<list.size();i++)
     {
          series->append(list2[i],list[i]);

     }
       QChart *chart =new QChart;
       chart->addSeries(series);
        chart->setTitle("STATS des liv");
        QChartView *chartview= new QChartView(chart);
        chartview->chart()->setAnimationOptions(QChart::AllAnimations);
        chartview->chart()->legend()->setAlignment(Qt::AlignRight);
        QChart::ChartTheme theme= static_cast<QChart::ChartTheme>(QChart::ChartThemeBrownSand);
        chartview->chart()->setTheme(theme);
         chartview->setParent(ui->horizontalFrame_2);
}

statclient::~statclient()
{
    delete ui;
}








QList<qreal> statclient::stat_client()
{
    QList<qreal> list ;
    QSqlQuery query;
    query.prepare("select SEXE,count(SEXE) from CLIENT group by SEXE");
    query.exec();
    while(query.next())
    {list.append(query.value(1).toInt());}

    return list;
}

QList<QString> statclient::stat_client_sexe()
{QList<QString> list ;
    QSqlQuery query;
    query.prepare("select SEXE,count(SEXE) from CLIENT group by SEXE");
    query.exec();
    while(query.next())
    {list.append(query.value(0).toString());}

  return list;

}
