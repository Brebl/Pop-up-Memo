#ifndef SETTINGSWINDOW_H
#define SETTINGSWINDOW_H

#include <QDialog>
#include <QDebug>
#include <QTime>
#include "settings.h"
#include <QSpinBox>
#include <QButtonGroup>

namespace Ui {
class SettingsWindow;
}

class SettingsWindow : public QDialog
{
    Q_OBJECT

public:


    explicit SettingsWindow(const Settings&, QWidget *parent = nullptr);
    ~SettingsWindow();

//    int getHour();
//    int getMinute();
//    Settings::_interval getInterval();
//    QTime getTime();
    Settings getSettings();

private slots:
    void onIntervalTimeHourChanged(int);
    void onIntervalTimeMinuteChanged(int);
    void onIntervaltypeChanged(int);
    void onStartTimeChanged(QTime t);

private:
    Ui::SettingsWindow *ui;
    Settings sw_settings;
};

#endif // SETTINGS_H
