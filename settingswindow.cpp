#include "settingswindow.h"
#include "ui_settingswindow.h"

SettingsWindow::SettingsWindow(const Settings& mainwin_settings, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::SettingsWindow),
    sw_settings(mainwin_settings)
{
    ui->setupUi(this);
    ui->hourSelect->setValue(sw_settings.intervalTimeHour);
    ui->minuteSelect->setValue(sw_settings.intervalTimeMinute);
    switch (sw_settings.intervalType) {
    case Settings::_interval::_custom:
        ui->radioButton_custom->setChecked(true);
        break;
    case Settings::_interval::_2h:
        ui->radioButton_2h->setChecked(true);
        break;
    case Settings::_interval::_1h:
        ui->radioButton_1h->setChecked(true);
        break;
    case Settings::_interval::_30m:
        ui->radioButton_30m->setChecked(true);
        break;
    case Settings::_interval::_20m:
        ui->radioButton_20m->setChecked(true);
        break;
    case Settings::_interval::_15m:
        ui->radioButton_15m->setChecked(true);
        break;
    case Settings::_interval::_10m:
        ui->radioButton_10m->setChecked(true);
        break;
    case Settings::_interval::_5m:
        ui->radioButton_5m->setChecked(true);
        break;
    case Settings::_interval::_1m:
        ui->radioButton_1m->setChecked(true);
        break;
    }
    ui->timeEdit->setTime(sw_settings.startTime);
}

SettingsWindow::~SettingsWindow()
{
    delete ui;
}

void SettingsWindow::on_hourSelect_valueChanged(int t)
{
    sw_settings.intervalTimeHour = t;
    sw_settings.nextCustomTime = sw_settings.startTime.addSecs(sw_settings.intervalTimeHour*3600 + sw_settings.intervalTimeMinute*60);
}

void SettingsWindow::on_minuteSelect_valueChanged(int t)
{
    sw_settings.intervalTimeMinute = t;
    sw_settings.nextCustomTime = sw_settings.startTime.addSecs(sw_settings.intervalTimeHour*3600 + sw_settings.intervalTimeMinute*60);
}

void SettingsWindow::on_buttonGroup_buttonClicked(int button)
{
    if(button == -2)
        sw_settings.intervalType = Settings::_interval::_custom;
    if(button == -3)
        sw_settings.intervalType = Settings::_interval::_2h;
    if(button == -4)
        sw_settings.intervalType = Settings::_interval::_1h;
    if(button == -5)
        sw_settings.intervalType = Settings::_interval::_30m;
    if(button == -6)
        sw_settings.intervalType = Settings::_interval::_20m;
    if(button == -7)
        sw_settings.intervalType = Settings::_interval::_15m;
    if(button == -8)
        sw_settings.intervalType = Settings::_interval::_10m;
    if(button == -9)
        sw_settings.intervalType = Settings::_interval::_5m;
    if(button == -10)
        sw_settings.intervalType = Settings::_interval::_1m;
}

void SettingsWindow::on_timeEdit_timeChanged(QTime t)
{
    sw_settings.startTime = t;
    sw_settings.nextCustomTime = sw_settings.startTime.addSecs(sw_settings.intervalTimeHour*3600 + sw_settings.intervalTimeMinute*60);
}

Settings SettingsWindow::getSettings()
{
    return sw_settings;
}
