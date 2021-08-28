#ifndef SETTINGS_H
#define SETTINGS_H

#include <QDialog>
#include <QDebug>

namespace Ui {
class settings;
}

class settings : public QDialog
{
    Q_OBJECT

public:
    explicit settings(QWidget *parent = nullptr, int = 0, int = 0);
    ~settings();

    int getHour();
    int getMinute();

private:
    Ui::settings *ui;
    QDialog parent_;
};

#endif // SETTINGS_H
