#ifndef SETTINGS_H
#define SETTINGS_H
#include <QTime>

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
    QTime startTime{8,0,0};
    QTime nextCustomTime;
    int intervalTimeHour = 0;
    int intervalTimeMinute = 0;
};

#endif // SETTINGS_H
