#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "monitor.h"
#include <QTimer>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , monitor(new SystemMonitor)
{
    ui->setupUi(this);
    QTimer *timer = new QTimer(this);
    connect(timer, &QTimer::timeout, this, &MainWindow::updateCPUinfos);
    timer->start(1000); 
}

MainWindow::~MainWindow()
{
    delete monitor;
    delete ui;
}

void MainWindow::updateCPUinfos()
{
    double cpu_value = monitor->getCPUUsage();
    int numberof_threads = monitor->getThreadsQtd();
    int numerof_processes = monitor->getProcessQtd();
    double cpu_frequncy = monitor->getCPUfrequency();

    ui->cpu_progressbar->setValue(static_cast<int>(cpu_value));

    if (cpu_value < 50) {
        ui->cpu_progressbar->setStyleSheet("QProgressBar::chunk { background-color: green; }");
    } else if (cpu_value < 80) {
        ui->cpu_progressbar->setStyleSheet("QProgressBar::chunk { background-color: yellow; }");
    } else {
        ui->cpu_progressbar->setStyleSheet("QProgressBar::chunk { background-color: red; }");
    }
}
