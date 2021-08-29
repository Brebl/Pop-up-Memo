#ifndef SETTINGSWINDOW_H
#define SETTINGSWINDOW_H

#include <QDialog>
#include <QDebug>
#include <QTime>
#include "settings.h"
#include <QSpinBox>

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
    void onIntervalTimeHourChanged();
    void onIntervalTimeMinuteChanged();
    void onIntervaltypeChanged();
    void onStartTimeChanged();

private:
    Ui::SettingsWindow *ui;
    Settings sw_settings;
};

#endif // SETTINGS_H
