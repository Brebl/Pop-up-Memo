#include "settings.h"
#include "ui_settings.h"

settings::settings(QWidget *parent, int hour, int minute) :
    QDialog(parent),
    ui(new Ui::settings)
{
    ui->setupUi(this);
    ui->hourSelect->setValue(hour);
    ui->minuteSelect->setValue(minute);
}

settings::~settings()
{
    delete ui;
}

int settings::getHour()
{
    return ui->hourSelect->value();
}

int settings::getMinute()
{
    return ui->minuteSelect->value();
}


