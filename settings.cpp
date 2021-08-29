#include "settings.h"
#include "ui_settings.h"

Settings::Settings(QWidget *parent, const int hour, const int minute, const Settings::_interval inter) :
    QDialog(parent),
    ui(new Ui::Settings)
{
    ui->setupUi(this);
    ui->hourSelect->setValue(hour);
    ui->minuteSelect->setValue(minute);
    switch (inter) {
    case _interval::_custom:
        ui->radioButton_custom->setChecked(true);
        break;
    case _interval::_2h:
        ui->radioButton_2h->setChecked(true);
        break;
    case _interval::_1h:
        ui->radioButton_1h->setChecked(true);
        break;
    case _interval::_30m:
        ui->radioButton_30m->setChecked(true);
        break;
    case _interval::_20m:
        ui->radioButton_20m->setChecked(true);
        break;
    case _interval::_15m:
        ui->radioButton_15m->setChecked(true);
        break;
    case _interval::_10m:
        ui->radioButton_10m->setChecked(true);
        break;
    case _interval::_5m:
        ui->radioButton_5m->setChecked(true);
        break;
    case _interval::_1m:
        ui->radioButton_1m->setChecked(true);
        break;
    }
}

Settings::~Settings()
{
    delete ui;
}

int Settings::getHour()
{
    return ui->hourSelect->value();
}

int Settings::getMinute()
{
    return ui->minuteSelect->value();
}

Settings::_interval Settings::getInterval()
{
    if (ui->radioButton_custom->isChecked())
        return _interval::_custom;
    if( ui->radioButton_2h->isChecked())
        return _interval::_2h;
    if (ui->radioButton_1h->isChecked())
        return _interval::_1h;
    if(ui->radioButton_30m->isChecked())
        return _interval::_30m;
    if(ui->radioButton_20m->isChecked())
        return _interval::_20m;
    if(ui->radioButton_15m->isChecked())
        return _interval::_15m;
    if(ui->radioButton_10m->isChecked())
        return _interval::_10m;
    if(ui->radioButton_5m->isChecked())
        return _interval::_5m;
    if(ui->radioButton_1m->isChecked())
        return _interval::_1m;
    else {
        return _interval::_1m;
    }
}

QTime Settings::getTime()
{
    return ui->timeEdit->time();
}
