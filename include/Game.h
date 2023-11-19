#ifndef GAME_HH
#define GAME_HH
#include "Board.h"
#include <vector>
class Game
{
public:
    Game();
    ~Game();
    void Run();
    bool result;

private:
    int size;
    Board board;
    bool is_first;
    void judge_first();
    bool first_hand();
    bool second_hand();
    int get_input();
    std::vector<int> list;
    bool is_overlap(int a);
    void play(int pos, int style);
};
#endif