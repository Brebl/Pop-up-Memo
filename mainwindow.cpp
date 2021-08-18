#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QTimer *timer = new QTimer(this);
    connect(timer, &QTimer::timeout, this, &MainWindow::showTime);
    timer->start(100);
    showTime();
    connect(ui->pushButton,&QPushButton::pressed, this, &MainWindow::writeFile);
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

void MainWindow::showTime()
{
    QTime time = QTime::currentTime();
    QString text = time.toString("hh:mm");
    if ((time.second() % 2) == 0)
        text[2] = ' ';
    ui->lcdNumber->display(text);
    if(time.minute() == 0 && time.second() == 0){
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

