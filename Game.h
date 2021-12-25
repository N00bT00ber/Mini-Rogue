// Game.h

#ifndef GAME_INCLUDED
#define GAME_INCLUDED
#include "dungeon.h"

// You may add data members and other member functions to this class.

class Game
{
public:
    Game(int goblinSmellDistance);
    ~Game();
    void play();
    char Players_move();
private:
    dungeon* m_dungeon ;
};

#endif // GAME_INCLUDED
