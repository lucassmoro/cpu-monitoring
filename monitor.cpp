#include "monitor.h"
#include <iostream>

#ifdef _WIN32
    #include <io.h> 
#else
    #include <Windows.h>  
#endif

// #include <QApplication>
// #include <QMainWindow>

void SystemMonitor::displaySystemInfo() {
    std::cout << "Displaying system information..." << std::endl;
    getCPUUsage();
    getMemoryUsage();
    getDiskUsage();
    std::cout << std::endl;
    
    // getCPUUsage();
    // getMemoryUsage();
    // getDiskUsage();
}

double SystemMonitor::getCPUUsage() {
    double cpuUsage;
    FILETIME idleTime, kernelTime, userTime;
    if (GetSystemTimes(&idleTime, &kernelTime, &userTime)) {
    ULONGLONG idle = ((ULONGLONG)idleTime.dwHighDateTime << 32) + idleTime.dwLowDateTime;
    ULONGLONG kernel = ((ULONGLONG)kernelTime.dwHighDateTime << 32) + kernelTime.dwLowDateTime;
    ULONGLONG user = ((ULONGLONG)userTime.dwHighDateTime << 32) + userTime.dwLowDateTime;
    
    ULONGLONG total = kernel + user;
    cpuUsage = (1.0 - (double)idle / total) * 100;
    std::cout << "CPU Usage: " << cpuUsage << " %" << std::endl;  
    } else {
        std::cout << "Failed to retrieve CPU information" << std::endl;
    }
    return cpuUsage;
}

void SystemMonitor::getMemoryUsage() {
    MEMORYSTATUSEX status;
    status.dwLength = sizeof(status);
    if (GlobalMemoryStatusEx(&status)){
        std::cout << "Total Memory: "<< status.ullTotalPhys / (1024 * 1024 * 1024) << " GB" << std::endl;
        std::cout << "Used Memory: " << (status.ullTotalPhys - status.ullAvailPhys) /  (1024 * 1024 * 1024) << " GB" << std::endl;
        std::cout << "Available Memory: " << status.ullAvailPhys / (1024 * 1024 * 1024)  << " GB" << std::endl;
    } else {
        std::cout << "Failed to retrieve memory information" << std::endl;
    }
}

void SystemMonitor::getDiskUsage() {
    ULARGE_INTEGER freebytes, totalbytes, totalfreebytes;
    if (GetDiskFreeSpaceEx(nullptr, &freebytes, &totalbytes, &totalfreebytes)){
        std::cout << "Free space in Disk: " << freebytes.QuadPart / (1024*1024*1024) << " GB" <<std::endl;
        std::cout << "Total space in Disk: " << totalbytes.QuadPart / (1024*1024*1024) << " GB"<<std::endl;
    } else {
        std::cout << "Failed to retrieve Disc information" << std::endl;
    }
}
