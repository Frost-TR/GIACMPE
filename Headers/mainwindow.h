#ifndef MAINWINDOW_H
#define MAINWINDOW_H

/**
 * @file   mainwindow.h
 * @author Rys Tomáš, Tadeáš Kovář
 */

#include <QObject>
#include <QMainWindow>
#include <QPushButton>
#include <QLabel>
#include <QComboBox>
#include <QRadioButton>
#include <QLineEdit>

#include "./Headers/gamewindow.h"
#include "./Headers/gamedata.h"

/**
 * @brief The MainWindow class Třída obsahující herni menu a práci s ním.
 */

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
    void GetFileName();
    void LoadGame();
    GameData *createNewGame();

private:
    QPushButton *NewGameButton;
    QPushButton *LoadGameButton;
    QPushButton *AboutGameButton;
    QPushButton *ExitGameButton;
    QPushButton *PlayGameButton;
    QPushButton *LoadButton;
    QPushButton *BackButton;
    QPushButton *ChooseGameButton;

    QLabel *MenuLabel;
    QLabel *NewGameLabel;
    QLabel *LoadGameLabel;
    QLabel *BoardSizeLabel;
    QLabel *OpponentLabel;
    QLabel *OpponentDifficultLabel;
    QLabel *PlayerNameLabel;
    QLabel *PlayerNameLabel2;
    QLabel *NewGameInfoLabel;
    QLabel *LoadGameInfoLabel;
    QLabel *AuthorsLabel;
    QLabel *Author1NameLabel;
    QLabel *Author2NameLabel;
    QLabel *DescriptionLabel;

    QRadioButton *HumanRadioButton;
    QRadioButton *AIRadioButton;

    QLineEdit *PlayerNameEdit;
    QLineEdit *PlayerNameEdit2;
    QLineEdit *LoadFileEdit;

    QComboBox *BoardSizeComboBox;
    QComboBox *OpponentDifficultComboBox;

    int actualLayout;
    GameWindow *NewGameWindow;
};

#endif // MAINWINDOW_H
