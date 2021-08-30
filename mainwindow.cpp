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
}

MainWindow::~MainWindow()
{
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
        if(time == settings.nextCustomTime) {
            settings.nextCustomTime = settings.nextCustomTime.addSecs(settings.intervalTimeHour*3600 + settings.intervalTimeMinute*60);
            if(settings.nextCustomTime < settings.startTime) {
                settings.nextCustomTime = settings.startTime;
            }
            changestate = true;
        }
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
    case Settings::_interval::_5m:
        if(time.minute() == 0 || time.minute() % 5 == 0) {changestate = true;}
        break;
    case Settings::_interval::_1m:
        changestate = true;
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
    QString filename = "log/lokitiedosto.txt";
    QTime time = QTime::currentTime();
    QString timestamp = date.toString("dd.MM.yy-ddd") + " " + time.toString("hh:mm") + " ";
    QFile file(filename);
    if (!file.open(QIODevice::WriteOnly | QIODevice::Text | QIODevice::Append))
        return;
    QTextStream out(&file);
    out << timestamp << ui->textEdit->toPlainText() << "\n";
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
    }
    return false;
}

void MainWindow::on_actionClose_triggered()
{
    close();
}

void MainWindow::on_actionClose_hovered()
{
//    QToolTip::showText(ui->menuFile->mapToGlobal(QPoint(0,0)),ui->actionClose->toolTip());
}

void MainWindow::on_actionSettings_triggered()
{
    SettingsWindow sw(settings, this);
    sw.setModal(true);
    if ( sw.exec() == QDialog::Accepted ) {
        settings = sw.getSettings();
    }
}
