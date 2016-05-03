#ifndef GAMEINTELIGENCE_H
#define GAMEINTELIGENCE_H

#include "./Headers/gamedata.h"
#include "./Headers/gamelogic.h"

class GameInteligence
{
public:
    GameInteligence();
    GameData *SwitchInteligence(GameData *GameDat);

private:
    GameData *Hard(GameData *GameDat);
    GameData *Medium(GameData *GameDat);
    GameData *Stupid(GameData *GameDat);
    struct ScoreArray{
        int i;
        int j;
        int diffscore;

    };
};

#endif // GAMEINTELIGENCE_H
