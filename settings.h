#ifndef SETTINGS_H
#define SETTINGS_H

#include <QDialog>
#include <QDebug>
#include <QTime>

namespace Ui {
class Settings;
}

class Settings : public QDialog
{
    Q_OBJECT

public:
    enum class _interval {
        _custom,
        _2h,
        _1h,
        _30m,
        _20m,
        _15m,
        _10m,
        _5m,
        _1m,
    };

    explicit Settings(QWidget *parent = nullptr, int = 0, int = 0, _interval=_interval::_1h);
    ~Settings();

    int getHour();
    int getMinute();
    _interval getInterval();
    QTime getTime();


private:
    Ui::Settings *ui;
};

#endif // SETTINGS_H
