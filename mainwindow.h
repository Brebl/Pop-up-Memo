#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTimer>
#include <iostream>
#include <QTime>
#include <QFile>
#include <QTextStream>
#include <QDir>
#include <QKeyEvent>
#include <QTextEdit>
#include <QToolTip>
#include <QPoint>
#include "settings.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    void changeState();
    void showTime();
    void writeFile();
    bool eventFilter(QObject*, QEvent*);

    Ui::MainWindow *ui;
private:
    int popupTimeHour = 0;
    int popupTimeMinute = 0;

private slots:
    void on_actionClose_triggered();
    void on_actionClose_hovered();
    void on_actionSettings_triggered();
};

#endif // MAINWINDOW_H
