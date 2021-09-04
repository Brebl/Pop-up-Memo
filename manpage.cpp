#include "manpage.h"
#include "ui_manpage.h"

manpage::manpage(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::manpage)
{
    ui->setupUi(this);
}

manpage::~manpage()
{
    delete ui;
}
