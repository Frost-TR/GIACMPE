#include "./Headers/gamelogic.h"

GameLogic::GameLogic()
{

}


GameData * GameLogic::SolveTah(GameData *GameDat, int i, int j){
    GameDat->Game.History[GameDat->Game.actual+1]= GameDat->Game.History[GameDat->Game.actual];
    GameDat->Game.actual++;
    GameDat->Game.last++;
    if(GameDat->Game.History[GameDat->Game.actual].ActivePlayer==0){
        GameDat->Game.History[GameDat->Game.actual].Player1Score++;
        GameDat->Game.History[GameDat->Game.actual].grid[i][j]=1;
    }else{
        GameDat->Game.History[GameDat->Game.actual].Player2Score++;
        GameDat->Game.History[GameDat->Game.actual].grid[i][j]=2;
    }

    return GameDat;
}
