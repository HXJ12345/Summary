#include <QCoreApplication>
#include "Sort.h"
#include <QVector>
#include <QTime>
#include <iostream>
#include <chrono>

using namespace std;
int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

   QVector<int> values;
   values.resize(100000);

   while(1)
   {
       cout << "*********help**********" << endl;
       cout << "*******0 : quit********" << endl;
       cout << "*******1 : BubbleSort****" << endl;
       cout << "*******2 : SelectSort****" << endl;
       cout << "*******3 : MergeSort****" << endl;
       cout << "*******4 : QuickSort****" << endl;

       cout << "Please select a sorting method: " <<endl;

       qsrand(QTime(0,0,0).secsTo(QTime::currentTime()));
       for(int i=0; i<values.size(); i++)
       {
           values[i] = qrand()%1000;
           //cout << values[i] << "--";
       }
       cout << endl;

       int input = 0;
       cin >> input;
       cout << "------------begin sort-----------------" << endl;
       auto start = std::chrono::steady_clock::now();
       switch (input) {
       case 1:
       {
           HXJ::BubbleSort(values.begin(), values.end());
           break;
       }
       case 2:
       {
           HXJ::SelectSort(values.begin(), values.end());
           break;
       }
       case 3:
       {
           HXJ::MergeSort(values.begin(), values.end());
           break;
       }
       case 4:
       {
           HXJ::QuickSort(values.begin(), values.end());
           break;
       }
       default:
           return a.exec();
       }

       auto end = std::chrono::steady_clock::now();
       std::chrono::duration<double> elapsed_seconds = std::chrono::duration<double>(end-start);

       cout << "------------end sort-----------------" << endl;
       cout << "sort time : " << elapsed_seconds.count() << endl;

//       for(int i=0; i<values.size(); i++)
//       {
//           cout << values[i] << "--";
//       }
       cout << endl;

   }

    return a.exec();
}
