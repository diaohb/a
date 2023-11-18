#ifndef GAME_HH
#define GAME_HH
#include "Board.h"
class Game{
    public:
        Game();
        ~Game();
        void Run();
    private:
        int size;
        Board board;
};
#endif