#include "settingswindow.h"
#include "ui_settings.h"

SettingsWindow::SettingsWindow(Settings& settings, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::SettingsWindow)
{
    ui->setupUi(this);
    ui->hourSelect->setValue(settings.intervalTimeHour);
    ui->minuteSelect->setValue(settings.intervalTimeMinute);
    switch (settings.intervalType) {
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
}

SettingsWindow::~SettingsWindow()
{
    delete ui;
}

int SettingsWindow::getHour()
{
    return ui->hourSelect->value();
}

int SettingsWindow::getMinute()
{
    return ui->minuteSelect->value();
}

Settings::_interval SettingsWindow::getInterval()
{
    if (ui->radioButton_custom->isChecked())
        return Settings::_interval::_custom;
    if( ui->radioButton_2h->isChecked())
        return Settings::_interval::_2h;
    if (ui->radioButton_1h->isChecked())
        return Settings::_interval::_1h;
    if(ui->radioButton_30m->isChecked())
        return Settings::_interval::_30m;
    if(ui->radioButton_20m->isChecked())
        return Settings::_interval::_20m;
    if(ui->radioButton_15m->isChecked())
        return Settings::_interval::_15m;
    if(ui->radioButton_10m->isChecked())
        return Settings::_interval::_10m;
    if(ui->radioButton_5m->isChecked())
        return Settings::_interval::_5m;
    if(ui->radioButton_1m->isChecked())
        return Settings::_interval::_1m;
    else {
        return Settings::_interval::_1m;
    }
}

QTime SettingsWindow::getTime()
{
    return ui->timeEdit->time();
}
