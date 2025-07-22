#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QProgressBar>
#include "monitor.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void updateCPUinfos();
    void updateProgressBarColor(QProgressBar *progressBar, double value);

private:
    Ui::MainWindow *ui;
    SystemMonitor *monitor;
};
#endif // MAINWINDOW_H