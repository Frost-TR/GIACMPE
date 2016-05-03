#ifndef GAMELOGIC_H
#define GAMELOGIC_H

#include "./Headers/gamedata.h"

class GameLogic
{
public:
    GameLogic();
    GameData *Move(GameData *GameDat, int i, int j);
    bool CanMove(GameData *GameDat);
    GameData *ReCountScore(GameData *GameDat);
    bool SolveMove(int Grid[12][12], int i, int j, int size, int player);
private:


};

#endif // GAMELOGIC_H
