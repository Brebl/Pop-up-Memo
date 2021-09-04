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
#include <QMessageBox>
#include <QSettings>
#include "settingswindow.h"
#include "settings.h"
#include "manpage.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    void checkState(const QTime&);
    void updateTime();
    void writeFile();
    bool eventFilter(QObject*, QEvent*);

    Ui::MainWindow *ui;
private:
    Settings settings;
    QSettings saved_settings;

private slots:
    void on_actionClose_triggered();
    void on_actionSettings_triggered();
    void on_actionHelp_triggered();
};

#endif // MAINWINDOW_H
