#ifndef GAMEWINDOW_H
#define GAMEWINDOW_H

#include <QObject>
#include <QMainWindow>
#include <QLabel>
#include <QPushButton>
#include <QString>

class GameWindow : public QMainWindow
{
    Q_OBJECT

public:
    GameWindow(int Size,QMainWindow *parent = 0);
    ~GameWindow();
    void CreateGameGrid(int size);
    void CreateGameHints(int size);
    void CreateCorners(int size);
    QPixmap GetImage(int index,int line);

private slots:
    void TestChange();

private:
    QLabel *testlabel;
    QPushButton *GameGridButton[12][12];

    QLabel *GameBottonLabel[12];
    QLabel *GameCornerLabel[4];
    QLabel *GameLeftLabel[12];
    QLabel *GameRightLabel[12];
    QLabel *GameTopLabel[12];

    int arraySize;
    QString pathToFiles = ":/Images/Others/";

    QIcon white;
    QIcon black;
    QIcon empty;

};
#endif // GAMEWINDOW_H
