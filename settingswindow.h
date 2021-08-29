#ifndef SETTINGSWINDOW_H
#define SETTINGSWINDOW_H

#include <QDialog>
#include <QDebug>
#include <QTime>
#include "settings.h"

namespace Ui {
class SettingsWindow;
}

class SettingsWindow : public QDialog
{
    Q_OBJECT

public:


    explicit SettingsWindow(Settings&, QWidget *parent = nullptr);
    ~SettingsWindow();

    int getHour();
    int getMinute();
    Settings::_interval getInterval();
    QTime getTime();


private:
    Ui::SettingsWindow *ui;
};

#endif // SETTINGS_H
