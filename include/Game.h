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
    std::vector<int> list_1;
    std::vector<int> list_2;
    bool is_over(int &player,std::vector<int> list1,std::vector<int> list2);
    bool is_overlap(int a);
    float p_to_win(std::vector<int> list1,std::vector<int> list2);
    void play(int pos, int style);
};
#endif