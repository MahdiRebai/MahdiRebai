#include "stats_event.h"

stats_event::stats_event()
{

}

QLineSeries * stats_event::Money_Stats(QString input_month)
{
    QLineSeries *series = new QLineSeries();
    int moneyTotal = 0;
   QString queryText = "SELECT prix from events ";
    QSqlQuery query(queryText) ;
   /* series->append(0,0);
    series->append(2,100);
    series->append(4,1000);
    series->append(6,10000);
    series->append(8,100000);
    series->append(10,1000000);
    series->append(12,10000000);*/
    series->append(0,0);

      while (query.next())
    {   moneyTotal += query.value(0).toInt();
         // int x =moneytatquery.value(1).toInt() ;
          int y = query.value(0).toInt() ;
        //  qDebug() << "x= "<<x ;
          qDebug() << "y= "<<y ;
        series->append(moneyTotal,y);
        qDebug() <<moneyTotal ;
        *series << QPointF (moneyTotal,y) ;


    }

    return series ;

}
