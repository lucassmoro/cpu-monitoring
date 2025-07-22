#ifndef MONITOR_H
#define MONITOR_H

#include <iostream>
#include <Windows.h>  

class SystemMonitor {
public:
    void displaySystemInfo();
    double getCPUUsage();
    double getMemoryUsage();
    double getDiskUsage();
    int getThreadsQtd();
    double getCPUfrequency();
    int getProcessQtd();
};

#endif
