#ifndef STATS_EVENT_H
#define STATS_EVENT_H
#include <QtCharts>
#include <QChartView>
#include <QLineSeries>
#include <QSqlQuery>
class stats_event
{
public:
    stats_event();
    QLineSeries * Money_Stats(QString input_month) ;

};

#endif // STATS_EVENT_H
