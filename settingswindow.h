#ifndef SETTINGSWINDOW_H
#define SETTINGSWINDOW_H

#include <QDialog>
#include <QDebug>
#include <QTime>
#include "settings.h"
#include <QSpinBox>
#include <QButtonGroup>

namespace Ui {
class SettingsWindow;
}

class SettingsWindow : public QDialog
{
    Q_OBJECT

public:
    explicit SettingsWindow(const Settings&, QWidget *parent = nullptr);
    ~SettingsWindow();

    Settings getSettings();

private slots:
    void on_buttonGroup_buttonClicked(int);
    void on_timeEdit_timeChanged(QTime t);

private:
    Ui::SettingsWindow *ui;
    Settings sw_settings;
};

#endif // SETTINGS_H
