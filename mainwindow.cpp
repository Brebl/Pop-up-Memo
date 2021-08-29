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

void MainWindow::changeState()
{
    if(this->windowState() == Qt::WindowMinimized || this->windowState() == Qt::WindowNoState) {
        this->showNormal();
        this->activateWindow();
    }
}

void MainWindow::updateTime()
{
    QTime time = QTime::currentTime();
    QString text = time.toString("hh:mm");
    if ((time.second() % 2) == 0)
        text[2] = ' ';
    ui->lcdNumber->display(text);
    if(time.minute() == intervalTimeMinute && time.second() == 0){
        changeState();
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
    Settings set(this, intervalTimeHour, intervalTimeMinute, intervalType);
    set.setModal(true);
    if ( set.exec() == QDialog::Accepted ) {
        intervalTimeHour = set.getHour();
        intervalTimeMinute = set.getMinute();
        intervalType = set.getInterval();
        startTime = set.getTime();
    }
}
