#ifndef GAMELOGIC_H
#define GAMELOGIC_H

#include "./Headers/gamedata.h"


class GameLogic
{
public:
    GameLogic();
    GameData* SolveTah(GameData *GameDat,int i, int j);
};

#endif // GAMELOGIC_H
