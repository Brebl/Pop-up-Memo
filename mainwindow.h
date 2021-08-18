#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTimer>
#include <iostream>
#include <QTime>
#include <QFile>
#include <QTextStream>
#include <QDir>

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

    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
