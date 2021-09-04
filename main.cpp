#include "mainwindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QCoreApplication::setOrganizationName("Breblsoft");
    QCoreApplication::setOrganizationDomain("gsb.fi");
    QCoreApplication::setApplicationName("pop-up memo");

    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    return a.exec();
}
