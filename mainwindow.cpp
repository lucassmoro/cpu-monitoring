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
    //monitor = new SystemMonitor();

    // Atualiza a cada 1 segundo
    QTimer *timer = new QTimer(this);
    connect(timer, &QTimer::timeout, this, &MainWindow::updateCPUUsage);
    timer->start(1000); 
}

MainWindow::~MainWindow()
{
    delete monitor;
    delete ui;
}

void MainWindow::updateCPUUsage()
{
    double cpu_value = monitor->getCPUUsage();
    ui->progressBar_6->setValue(static_cast<int>(cpu_value) + 40);

    if (cpu_value < 20) {
        ui->progressBar_6->setStyleSheet("QProgressBar::chunk { background-color: green; }");
    } else if (cpu_value < 40) {
        ui->progressBar_6->setStyleSheet("QProgressBar::chunk { background-color: yellow; }");
    } else {
        ui->progressBar_6->setStyleSheet("QProgressBar::chunk { background-color: red; }");
    }
}
