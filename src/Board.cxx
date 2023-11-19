#include "Board.h"
#include <iostream>
Board::Board()
{
}
Board::~Board()
{
}
void Board::Show()
{
    printf("\033[2J\033[1;1H");
    for (int i = 0; i < size * 3 + 2; i++)
    {
        printf("\033[%d;%dH#", i + 1, 2 * size + 1);
        printf("\033[%d;%dH#", i + 1, 4 * size + 2);
        printf("\033[%d;%dH#", size + 1, 2 * i + 1);
        printf("\033[%d;%dH#", 2 * size + 2, 2 * i + 1);
    }
    printf("\033[%d;1H\n", size * 3 + 3);
    Show_number();
}
void Board::Show_number()
{
    for (int pos = 0; pos < 9; pos++)
    {
        printf("\033[%d;%dH%d", (pos / 3) * (size + 1) + size / 2 + 1, pos % 3 * 2 * (size + 1) + size - 1, pos);
    }
    printf("\033[%d;1H\n", size * 3 + 3);
}
void Board::play(int pos, int style)
{
    int x = pos % 3 * 2 * (size + 1);
    int y = (pos / 3) * (size + 1);
    // printf("\033[%d;%dH ", y + size / 2 + 1, x + size - 1);
    if (style == 1)
    {
        printf("\033[%d;%dH\033[31m          \033[0m", y + 1, x);
        printf("\033[%d;%dH\033[31m  **  **  \033[0m", y + 2, x);
        printf("\033[%d;%dH\033[31m    **    \033[0m", y + 3, x);
        printf("\033[%d;%dH\033[31m  **  **  \033[0m", y + 4, x);
        printf("\033[%d;%dH\033[31m          \033[0m", y + 5, x);
        // printf("\033[%d;%dH", y, x);
    }
    else if (style == 2)
    {
        printf("\033[%d;%dH\033[36m         *\033[0m", y + 1, x);
        printf("\033[%d;%dH\033[36m        * \033[0m", y + 2, x);
        printf("\033[%d;%dH\033[36m **   **  \033[0m", y + 3, x);
        printf("\033[%d;%dH\033[36m   ***    \033[0m", y + 4, x);
        printf("\033[%d;%dH\033[36m    *     \033[0m", y + 5, x);
    }
}