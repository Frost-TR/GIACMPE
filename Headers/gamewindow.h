#ifndef GAMEWINDOW_H
#define GAMEWINDOW_H

#include <QObject>
#include <QMainWindow>
#include <QLabel>
#include <QPushButton>
#include <QString>
#include <QFrame>
#include <QFileDialog>
#include <QMessageBox>
#include <QTextStream>
#include <QThread>

#include "./Headers/gamedata.h"
#include "./Headers/gamelogic.h"
#include "./Headers/gameinteligence.h"

class GameWindow : public QMainWindow
{
    Q_OBJECT

public:
    GameWindow(GameData *GameParam,QMainWindow *parent = 0);
    ~GameWindow();
    void CreateGameGrid();
    void CreateGameHints();
    void CreateCorners();
    QPixmap GetImage(int index,int line);
    void RenderGrid();
    void UpdateScore();
    void InitGame();
    void SwitchActivePlayer();
    void SwitchActivePlayerFrame();
    void DissableButtonGrid();
    void SaveGameToFile();

private slots:
    void ButtonGridEvent();
    void QuitButtonEvent();
    void SaveButtonEvent();
    void UndoButtonEvent();
    void RedoButtonEvent();


private:
    QPushButton *GameGridButton[12][12];
    QPushButton *UndoButton;
    QPushButton *RedoButton;
    QPushButton *QuitButton;
    QPushButton *SaveButton;

    QLabel *GameBottonLabel[12];
    QLabel *GameCornerLabel[4];
    QLabel *GameLeftLabel[12];
    QLabel *GameRightLabel[12];
    QLabel *GameTopLabel[12];
    QLabel *Spacer;
    QLabel *Player1Name;
    QLabel *Player1Score;
    QLabel *Player1Color;
    QLabel *InfoLabel;

    QLabel *Player2Name;
    QLabel *Player2Score;
    QLabel *Player2Color;

    QFrame *Player1Frame;
    QFrame *Player2Frame;
    QFrame *HistoryButtonsFrame;
    QFrame *QuitSaveButtonsFrame;

    QString pathToFiles = ":/Images/Others/";
    GameData *GameDat;

    QIcon white;
    QIcon black;
    QIcon empty;
    bool isSaved;
    bool DisableGrid[12][12];

};
#endif // GAMEWINDOW_H
