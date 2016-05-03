#ifndef GAMEDATA_H
#define GAMEDATA_H

#include <QString>

class GameData
{
public:
    GameData();

    struct gameHistoryList{
        int Grid[12][12]; //0 prazdna 1 bila 2 cerna

    };

    struct GameInfo{
        int GridSize;
        int Actual;
        int Last;
        int Player1Score;
        int Player2Score;
        int RemainingStones;
        int ActivePlayer; //0 player1 1 player2
        QString *Player1Name;
        QString *Player2Name;
        bool OpponentIsHuman;
        int AIlevel; // 0 very stupid 1 stupid
        struct gameHistoryList History[200];
    };

    struct GameInfo Game;
};

#endif // GAMEDATA_H
