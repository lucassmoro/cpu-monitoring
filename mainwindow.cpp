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
    connect(ui->comboBox, QOverload<int>::of(&QComboBox::currentIndexChanged),
        ui->stackedWidget, &QStackedWidget::setCurrentIndex);
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
    int numberof_processes = monitor->getProcessQtd();
    double cpu_frequency = monitor->getCPUfrequency();
    double memory_value = monitor->getMemoryUsage();
    double diskC_value = monitor->getDiskUsageC();
    double diskD_value = monitor->getDiskUsageD();

    ui->cpu_progressbar->setValue(static_cast<int>(cpu_value));
    ui->process_number->setText(QString("%1").arg(numberof_processes));
    ui->threads_number->setText(QString("%1").arg(numberof_threads));
    ui->frequency_number->setText(QString("%1 GHz").arg(cpu_frequency, 0, 'f', 2));
    
    ui->memory_progressbar->setValue(static_cast<int>(memory_value));
    ui->diskC_progressbar->setValue(static_cast<int>(diskC_value));
    ui->diskD_progressbar->setValue(static_cast<int>(diskD_value));

    ui->cpu_porcentage->setText(QString("%1%").arg(cpu_value, 0, 'f', 2));
    ui->memory_porcentage->setText(QString("%1%").arg(memory_value, 0, 'f', 2));
    ui->diskC_porcentage->setText(QString("%1%").arg(diskC_value, 0, 'f', 2));
    ui->diskD_porcentage->setText(QString("%1%").arg(diskD_value, 0, 'f', 2));

    updateProgressBarColor(ui->cpu_progressbar, cpu_value);
    updateProgressBarColor(ui->memory_progressbar, memory_value);
    updateProgressBarColor(ui->diskC_progressbar, diskC_value);
    updateProgressBarColor(ui->diskD_progressbar, diskD_value);
}

void MainWindow::updateProgressBarColor(QProgressBar *progressBar, double value){
    if (value < 50) {
        progressBar->setStyleSheet("QProgressBar::chunk { background-color: green; }");
    } else if (value < 80) {
        progressBar->setStyleSheet("QProgressBar::chunk { background-color: yellow; }");
    } else {
        progressBar->setStyleSheet("QProgressBar::chunk { background-color: red; }");
    }
}

