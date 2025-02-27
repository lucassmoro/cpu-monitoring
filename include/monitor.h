#ifndef MONITOR_H
#define MONITOR_H

#include <iostream>
#include <Windows.h>  // Para funções relacionadas ao sistema (Windows)

class SystemMonitor {
public:
    void displaySystemInfo();
    void getCPUUsage();
    void getMemoryUsage();
    void getDiskUsage();
};

#endif
