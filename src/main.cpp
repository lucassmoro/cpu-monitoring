#include <iostream>
#include "../include/monitor.h"
#include "../include/mainwindow.h"

int main() {
    SystemMonitor monitor;
    monitor.displaySystemInfo();
    return 0;
}
//gcc -I../include ./src/main.cpp ./src/monitor.cpp -o main -lstdc++