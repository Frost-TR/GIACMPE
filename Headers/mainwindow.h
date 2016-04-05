#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QObject>
#include <QMainWindow>
#include <QPushButton>
#include <QLabel>
#include <QComboBox>
#include <QRadioButton>
#include <QLineEdit>

#include "./Headers/gamewindow.h"

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = 0);
    ~MainWindow();


private slots:
    void SetLayoutToNewGame();
    void SetLayoutToLoadGame();
    void SetLayoutToAboutGame();
    void setLayoutToMenu();
    void SetLayoutForOpponent();
    void showGameWindow();

private:
    QPushButton *NewGameButton;
    QPushButton *LoadGameButton;
    QPushButton *AboutGameButton;
    QPushButton *ExitGameButton;
    QPushButton *PlayGameButton;
    QPushButton *LoadButton;
    QPushButton *BackButton;
    QPushButton *DeleteGameButton;

    QLabel *MenuLabel;
    QLabel *NewGameLabel;
    QLabel *BoardSizeLabel;
    QLabel *OpponentLabel;
    QLabel *OpponentDifficultLabel;
    QLabel *PlayerNameLabel;
    QLabel *PlayerNameLabel2;

    QRadioButton *HumanRadioButton;
    QRadioButton *AIRadioButton;

    QLineEdit *PlayerNameEdit;
    QLineEdit *PlayerNameEdit2;

    QComboBox *BoardSizeComboBox;
    QComboBox *OpponentDifficultComboBox;

    int actualLayout;
    GameWindow *NewGameWindow;
};

#endif // MAINWINDOW_H
