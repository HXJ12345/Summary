#include <QCoreApplication>
#include "Sort.h"
#include <QVector>
#include <QTime>
#include <QDebug>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

   QVector<int> values;
   values.resize(100);

   qsrand(QTime(0,0,0).secsTo(QTime::currentTime()));
   for(int i=0; i<values.size(); i++)
   {
       values[i] = qrand()%1000;
       qDebug() << values[i];
   }

   HXJ::BubbleSort(values.begin(), values.end());

   for(int i=0; i<values.size(); i++)
   {
       qDebug() << values[i];
   }
    return a.exec();
}
