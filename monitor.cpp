#include "monitor.h"
#include <iostream>
#include <windows.h>
#include <tlhelp32.h>
#include <psapi.h>
#include <intrin.h>
#include <chrono>
#include <thread>
#include <powrprof.h>
#pragma comment(lib, "PowrProf.lib")

#ifdef _WIN32
    #include <io.h> 
#else
    #include <Windows.h>  
#endif

// #include <QApplication>
// #include <QMainWindow>

void SystemMonitor::displaySystemInfo() {
    std::cout << "Displaying system information..." << std::endl;
    // getCPUUsage();
    // getMemoryUsage();
    // getDiskUsage();
    getThreadsQtd();
    std::cout << std::endl;
    
    // getCPUUsage();
    // getMemoryUsage();
    // getDiskUsage();
}

double SystemMonitor::getCPUUsage() {
    static ULONGLONG lastIdle = 0, lastKernel = 0, lastUser = 0;
    FILETIME idleTime, kernelTime, userTime;

    if (GetSystemTimes(&idleTime, &kernelTime, &userTime)) {
        ULONGLONG idle = ((ULONGLONG)idleTime.dwHighDateTime << 32) + idleTime.dwLowDateTime;
        ULONGLONG kernel = ((ULONGLONG)kernelTime.dwHighDateTime << 32) + kernelTime.dwLowDateTime;
        ULONGLONG user = ((ULONGLONG)userTime.dwHighDateTime << 32) + userTime.dwLowDateTime;

        ULONGLONG deltaIdle = idle - lastIdle;
        ULONGLONG deltaKernel = kernel - lastKernel;
        ULONGLONG deltaUser = user - lastUser;
        ULONGLONG deltaTotal = deltaKernel + deltaUser;

        lastIdle = idle;
        lastKernel = kernel;
        lastUser = user;

        if (deltaTotal == 0) return 0.0;

        double cpuUsage = (1.0 - (double)deltaIdle / deltaTotal) * 100.0;
        std::cout << "CPU Usage: " << cpuUsage << " %" << std::endl;
        return cpuUsage;
    } else {
        std::cerr << "Failed to retrieve CPU information" << std::endl;
        return 0.0;
    }
}

int SystemMonitor::getThreadsQtd() {
    int threadCount = 0;
    HANDLE hSnapshot = CreateToolhelp32Snapshot(TH32CS_SNAPTHREAD, 0);
    if (hSnapshot != INVALID_HANDLE_VALUE) {
        THREADENTRY32 te32;
        te32.dwSize = sizeof(THREADENTRY32);
        if (Thread32First(hSnapshot, &te32)) {
            do {
                ++threadCount;
            } while (Thread32Next(hSnapshot, &te32));
        }
        CloseHandle(hSnapshot);
    }
    std::cout<<"THREADS:"<<threadCount<<std::endl;
    return threadCount;
}
int SystemMonitor::getProcessQtd(){
    DWORD processes[1024];
    DWORD bytesReturned;

    if (!EnumProcesses(processes, sizeof(processes), &bytesReturned)) {
        return -1; // erro
    }

    int processesqtd = bytesReturned / sizeof(DWORD);
    std::cout<<"PROCESSES:"<<processesqtd<<std::endl;

    return processesqtd;
}

double SystemMonitor::getCPUfrequency(){

    auto start_time = std::chrono::high_resolution_clock::now();
    unsigned __int64 start_cycles = __rdtsc();

    std::this_thread::sleep_for(std::chrono::milliseconds(100));

    auto end_time = std::chrono::high_resolution_clock::now();
    unsigned __int64 end_cycles = __rdtsc();

    std::chrono::duration<double> elapsed_seconds = end_time - start_time;
    double elapsed_time_sec = elapsed_seconds.count();

    double frequency = (end_cycles - start_cycles) / (elapsed_time_sec * 1e9); // MHz

    std::cout<<frequency<<" GHz"<<std::endl;

    return frequency;
}


double SystemMonitor::getMemoryUsage() {
    MEMORYSTATUSEX status;
    status.dwLength = sizeof(status);
    if (GlobalMemoryStatusEx(&status)) {
        DWORDLONG total = status.ullTotalPhys;
        DWORDLONG used = total - status.ullAvailPhys;
        double usagePercent = (double)used / total * 100.0;
        return usagePercent;
    }
    return -1.0; // erro
}


double SystemMonitor::getDiskUsage() {
    ULARGE_INTEGER freeBytes, totalBytes, totalFreeBytes;
    if (GetDiskFreeSpaceEx(nullptr, &freeBytes, &totalBytes, &totalFreeBytes)) {
        ULONGLONG used = totalBytes.QuadPart - freeBytes.QuadPart;
        double usagePercent = (double)used / totalBytes.QuadPart * 100.0;
        return usagePercent;
    }
    return -1.0; // erro
}

