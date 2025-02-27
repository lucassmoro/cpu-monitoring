#include "/monitor.h"
#include <iostream>

void SystemMonitor::displaySystemInfo() {
    std::cout << "Displaying system information..." << std::endl;

    // Exemplo de como você pode pegar informações do sistema, por exemplo:
    getCPUUsage();
    getMemoryUsage();
    getDiskUsage();
}

void SystemMonitor::getCPUUsage() {
    // Lógica para pegar a utilização da CPU
    std::cout << "CPU Usage: 30%" << std::endl;  // Exemplo
}

void SystemMonitor::getMemoryUsage() {
    // Lógica para pegar a utilização da memória
    std::cout << "Memory Usage: 50%" << std::endl;  // Exemplo
}

void SystemMonitor::getDiskUsage() {
    // Lógica para pegar a utilização do disco
    std::cout << "Disk Usage: 70%" << std::endl;  // Exemplo
}
