#ifndef BOARD_HH
#define BOARD_HH
class Board
{
public:
    Board();
    ~Board();
    void Show();
    void Show_number();
    void play(int pos, int style);

private:
    int position_x;
    int position_y;
    int size = 5;
};
#endif