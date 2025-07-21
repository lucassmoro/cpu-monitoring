#ifndef MONITOR_H
#define MONITOR_H

#include <iostream>
#include <Windows.h>  

class SystemMonitor {
public:
    void displaySystemInfo();
    double getCPUUsage();
    void getMemoryUsage();
    void getDiskUsage();
};

#endif
