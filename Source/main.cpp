/**
 * @file   main.cpp
 * @author QT
 */
#include "./Headers/mainwindow.h"
#include <QApplication>

/**
 * @brief main  Funkce main generována pomoci QT creatoru
 * @param argc Počet parametru programu
 * @param argv Parametry programu
 * @return
 */
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.setFixedSize(500,600);
    w.setWindowTitle("ICP - Hra 2016 Reversi");
    w.show();

    return a.exec();
}
