#include "settingswindow.h"
#include "ui_settingswindow.h"

SettingsWindow::SettingsWindow(const Settings& mainwin_settings, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::SettingsWindow),
    sw_settings(mainwin_settings)
{
    ui->setupUi(this);
    switch (sw_settings.intervalType) {
    case Settings::_interval::_custom:
        ui->radioButton_custom->setChecked(true);
        break;
    case Settings::_interval::_4h:
        ui->radioButton_4h->setChecked(true);
        break;
    case Settings::_interval::_3h:
        ui->radioButton_3h->setChecked(true);
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
    }
    ui->timeEdit->setTime(sw_settings.customTime);
    ui->filename->setText(sw_settings.filename);
}

SettingsWindow::~SettingsWindow()
{
    delete ui;
}

void SettingsWindow::on_buttonGroup_buttonClicked(int button)
{
    if(button == -2)
        sw_settings.intervalType = Settings::_interval::_custom;
    if(button == -3)
        sw_settings.intervalType = Settings::_interval::_4h;
    if(button == -4)
        sw_settings.intervalType = Settings::_interval::_3h;
    if(button == -5)
        sw_settings.intervalType = Settings::_interval::_2h;
    if(button == -6)
        sw_settings.intervalType = Settings::_interval::_1h;
    if(button == -7)
        sw_settings.intervalType = Settings::_interval::_30m;
    if(button == -8)
        sw_settings.intervalType = Settings::_interval::_20m;
    if(button == -9)
        sw_settings.intervalType = Settings::_interval::_15m;
    if(button == -10)
        sw_settings.intervalType = Settings::_interval::_10m;
}

void SettingsWindow::on_timeEdit_timeChanged(QTime t)
{
    sw_settings.customTime = t;
}

Settings SettingsWindow::getSettings()
{
    return sw_settings;
}

void SettingsWindow::on_filename_textEdited(const QString &arg1)
{
    sw_settings.filename = arg1;
}
