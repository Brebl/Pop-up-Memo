#ifndef SETTINGS_H
#define SETTINGS_H
#include <QTime>
#include <QListWidget>

class Settings
{
public:
    Settings();

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
    _interval intervalType = _interval::_1h;
    QTime customTime{8,0,0};
    QString filename = "lokitiedosto.txt";
    QListWidget* log_profiles;
};

#endif // SETTINGS_H
