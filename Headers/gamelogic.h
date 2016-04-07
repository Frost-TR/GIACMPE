#ifndef GAMELOGIC_H
#define GAMELOGIC_H

#include "./Headers/gamedata.h"


class GameLogic
{
public:
    GameLogic();
    GameData* SolveMove(GameData *GameDat,int i, int j);
    bool CanMove(GameData *GameDat);
};

#endif // GAMELOGIC_H
