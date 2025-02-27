#include "../include/monitor.h"
#include <iostream>

void SystemMonitor::displaySystemInfo() {
    std::cout << "Displaying system information..." << std::endl;

    getCPUUsage();
    getMemoryUsage();
    getDiskUsage();
}

void SystemMonitor::getCPUUsage() {
    std::cout << "CPU Usage: " << std::endl;  
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
    std::cout << "Disk Usage: " << std::endl;
}
