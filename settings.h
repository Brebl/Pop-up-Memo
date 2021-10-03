#ifndef SETTINGS_H
#define SETTINGS_H
#include <QTime>

class Settings
{
public:
    Settings();

    enum class _interval : int {
        _custom,
        _4h,
        _3h,
        _2h,
        _1h,
        _30m,
        _20m,
        _15m,
        _10m,
    };
    _interval intervalType = _interval::_1h;
    QTime customTime{15,55,0};
    QString filename = "logfile.csv";
};

#endif // SETTINGS_H
