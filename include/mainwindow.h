#ifndef MAINWINDOW_H_
#define MAINWINDOW_H_
#include <QtWidgets/QMainWindow>
#include <ui_mainwindow.h>


class MainWindow : public QMainWindow
{
    Q_OBJECT
public:
    MainWindow(QWidget *parent = 0);
    ~MainWindow();
private:
    Ui::MainWindow::ui;
};
#endif