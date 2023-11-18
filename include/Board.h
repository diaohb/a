#ifndef BOARD_HH
#define BOARD_HH
class Board{
    public:
        Board();
        ~Board();
        void Show();
    private:
        int position_x;
        int position_y;
        int size = 5;
};
#endif