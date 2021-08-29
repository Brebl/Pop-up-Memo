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
    connect(ui->hourSelect, SIGNAL(valueChanged(int)), this, SLOT(onIntervalTimeHourChanged(int)));
    connect(ui->minuteSelect, SIGNAL(valueChanged(int)), this, SLOT(onIntervalTimeMinuteChanged(int)));
    connect(ui->timeEdit, SIGNAL(timeChanged(QTime)), this, SLOT(onStartTimeChanged(QTime)));
    connect(ui->intervalBox, SIGNAL(buttonClicked()),this,SLOT(onIntervaltypeChanged()));

}

SettingsWindow::~SettingsWindow()
{
    delete ui;
}

void SettingsWindow::onIntervalTimeHourChanged(int t)
{
    sw_settings.intervalTimeHour = t;
}

void SettingsWindow::onIntervalTimeMinuteChanged(int t)
{
    sw_settings.intervalTimeMinute = t;
}

void SettingsWindow::onIntervaltypeChanged()
{
    qDebug() << "radio changed";
//    sw_settings.intervalType = ui->
}

void SettingsWindow::onStartTimeChanged(QTime t)
{
    sw_settings.startTime = t;
}

Settings SettingsWindow::getSettings()
{
    return sw_settings;
}
