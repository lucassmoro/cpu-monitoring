//gcc -I../include ./src/main.cpp ./src/monitor.cpp -o main -lstdc++
// SystemMonitor monitor;
//     monitor.displaySystemInfo();

#include "mainwindow.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    return a.exec();
}