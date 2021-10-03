#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QTimer *timer = new QTimer(this);
    connect(timer, &QTimer::timeout, this, &MainWindow::updateTime);
    timer->start(100);
    updateTime();
    connect(ui->pushButton,&QPushButton::pressed, this, &MainWindow::writeFile);
    ui->textEdit->installEventFilter(this);
    settings.intervalType = static_cast<Settings::_interval>(saved_settings.value("intervaltype", static_cast<int>(Settings::_interval::_1h)).toInt());
    settings.customTime = saved_settings.value("customtime", QTime(settings.customTime)).value<QTime>();
    settings.filename = saved_settings.value("filename", QString(settings.filename)).value<QString>();
}

MainWindow::~MainWindow()
{
    saved_settings.setValue("customtime", settings.customTime);
    saved_settings.setValue("filename",settings.filename);
    saved_settings.setValue("intervaltype", static_cast<int>(settings.intervalType));
    delete ui;
}

void MainWindow::updateTime()
{
    QTime time = QTime::currentTime();
    QString text = time.toString("hh:mm");
    if ((time.second() % 2) == 0)
        text[2] = ' ';
    ui->lcdNumber->display(text);
    if(time.second() == 0){
        checkState(time);
    }
}

void MainWindow::checkState(const QTime& time)
{
    bool changestate(false);
    switch (settings.intervalType) {
    case Settings::_interval::_custom:
        if(time.secsTo(settings.customTime) == 0) {changestate = true;}
        break;
    case Settings::_interval::_4h:
        if(time.minute() == 0 && time.hour() % 4 == 0) {changestate = true;}
        break;
    case Settings::_interval::_3h:
        if(time.minute() == 0 && time.hour() % 3 == 0) {changestate = true;}
        break;
    case Settings::_interval::_2h:
        if(time.minute() == 0 && time.hour() % 2 == 0) {changestate = true;}
        break;
    case Settings::_interval::_1h:
        if(time.minute() == 0) {changestate = true;}
        break;
    case Settings::_interval::_30m:
        if(time.minute() == 0 || time.minute() == 30) {changestate = true;}
        break;
    case Settings::_interval::_20m:
        if(time.minute() == 0 || time.minute() % 20 == 0) {changestate = true;}
        break;
    case Settings::_interval::_15m:
        if(time.minute() == 0 || time.minute() % 15 == 0) {changestate = true;}
        break;
    case Settings::_interval::_10m:
        if(time.minute() == 0 || time.minute() % 10 == 0) {changestate = true;}
        break;
    }
    if(changestate && (this->windowState() == Qt::WindowMinimized || this->windowState() == Qt::WindowNoState)) {
        this->showNormal();
        this->activateWindow();
    }
}

void MainWindow::writeFile()
{
    if(!QDir("log").exists()) {
        QDir().mkdir("log");
    }
    QDate date = QDate::currentDate();
    QString filename = "log/" + settings.filename;
    QTime time = QTime::currentTime();
    QFile file(filename);
    if (!file.open(QIODevice::WriteOnly | QIODevice::Text | QIODevice::Append)) {
        QMessageBox msgBox;
        msgBox.setText("Can't open file for write operations.");
        msgBox.exec();
        return;
    }
    QTextStream out(&file);
    out << date.toString("dd.MM.yyyy") << "," << time.toString("hh:mm") << ",\"" << ui->textEdit->toPlainText() << "\"\n";
    file.close();
    ui->textEdit->setPlainText(QString(""));
    this->showMinimized();
}

bool MainWindow::eventFilter(QObject* obj, QEvent* event)
{
    if (obj == ui->textEdit && event->type() == QEvent::KeyPress) {
        QKeyEvent *keyEvent = static_cast<QKeyEvent *>(event);
        if(keyEvent->key() == Qt::Key_Enter || keyEvent->key() == Qt::Key_Return) {
            writeFile();
            return true;
        }
        if(keyEvent->key() == Qt::Key_Escape) {
            this->showMinimized();
            return true;
        }
    }
    return false;
}

void MainWindow::on_actionClose_triggered()
{
    close();
}

void MainWindow::on_actionSettings_triggered()
{
    SettingsWindow sw(settings, this);
    sw.setModal(true);
    if ( sw.exec() == QDialog::Accepted ) {
        settings = sw.getSettings();
    }
}

void MainWindow::on_actionHelp_triggered()
{
    manpage mp(this);
    mp.exec();
}
