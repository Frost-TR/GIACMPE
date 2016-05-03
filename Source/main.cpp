#include "./Headers/mainwindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.setFixedSize(500,600);
    w.setWindowTitle("ICP - Hra 2016 Reversi");
    w.show();

    return a.exec();
}
