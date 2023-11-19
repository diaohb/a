#include "Game.h"
#include <cstdio>
#include <string>
#include <iostream>
#include <algorithm>
Game::Game()
{
}
Game::~Game()
{
}
void Game::Run()
{
    board.Show();
    judge_first();
    if (is_first)
        result = first_hand();
    else
        result = second_hand();
    if (result)
        printf("\033[19;1H\033[Kyou lose! game over!\n");
    else
        printf("\033[19;1H\033[Kdraw! game over!\n");
}
void Game::judge_first()
{
    std::string a;
    while (true)
    {
        printf("\033[19;1H\033[Kselect first hand(1) or second hand(2): ");
        std::cin >> a;
        if (a == "1")
        {
            is_first = 1;
            break;
        }
        else if (a == "2")
        {
            is_first = 0;
            break;
        }
    }
    board.Show();
}
bool Game::first_hand()
{
    play(0, 1);
    int i, tmp;
    play(i = get_input(), 2);
    if (i == 4)
    {
        play(8, 1);
        play(i = get_input(), 2);
        tmp = i;
        play(8 - i, 1);
        play(i = get_input(), 2);
        if (tmp % 2 == 1)
        {
            play(8 - i, 1);
            if (i != (8 - tmp % 4 * 2))
            {
                return 1;
            }
            play(i = get_input(), 2);
            play(8 - i, 1);
            return ((i + 4) % 8 != tmp);
        }
        else
        {
            if (i != 4 - tmp / 2)
            {
                play(4 - tmp / 2, 1);
                return 1;
            }
            play(8 - tmp / 2, 1);
            return 1;
        }
    }
    else if (i == 8)
    {
        play(2, 1);
        play(i = get_input(), 2);
        if (i != 1)
        {
            play(1, 1);
            return 1;
        }
        play(6, 1);
        play(i = get_input(), 2);
        if (i != 3)
        {
            play(3, 1);
            return 1;
        }
        if (i != 4)
        {
            play(4, 1);
            return 1;
        }
    }
    else if (i % 2 == 0)
    {
        play(8 - i, 1);
        tmp = i;
        play(i = get_input(), 2);
        if (i != 4 - tmp / 2)
        {
            play(4 - tmp / 2, 1);
            return 1;
        }
        play(8, 1);
        play(i = get_input(), 2);
        if (i != 8 - tmp / 2)
        {
            play(8 - tmp / 2, 1);
            return 1;
        }
        if (i != 4)
        {
            play(4, 1);
            return 1;
        }
    }
    else
    {
        play(4, 1);
        tmp = abs(4 - i);
        play(i = get_input(), 2);
        if (i != 8)
        {
            play(8, 1);
            return 1;
        }
        play(2 * tmp, 1);
        play(i = get_input(), 2);
        if (i != tmp)
        {
            play(tmp, 2);
            return 1;
        }
        else if (i != 8 - 2 * tmp)
        {
            play(8 - 2 * tmp, 2);
            return 1;
        }
    }
    return 0;
}
bool Game::second_hand()
{
    int i;
    play(i = get_input(), 2);
    int tmp = i;
    if (i == 4)
    {
        play(0, 1);
        play(i = get_input(), 2);
        tmp = i;
        if (i == 8)
        {
            play(6, 1);
            play(i = get_input(), 2);
            if (i != 3)
            {
                play(3, 1);
                return 1;
            }
            play(5, 1);
            play(i = get_input(), 2);
            if (i != 1)
                play(1, 1);
            else
                play(7, 1);
            play(i = get_input(), 2);
        }
        else if (i % 2 == 0)
        {
            play(8 - i, 1);
            play(i = get_input(), 2);
            if (i != 4 - tmp / 2)
            {
                play(4 - tmp / 2, 1);
                return 1;
            }
            play(4 + tmp / 2, 1);
            play(i = get_input(), 2);
            if (i != tmp / 2)
                play(tmp / 2, 1);
            else
                play(8 - tmp / 2, 1);
            play(i = get_input(), 2);
        }
        else if (i / 4 == 0)
        {
            play(8 - i, 1);
            play(i = get_input(), 2);
            tmp = i;
            if (i == 8)
            {
                play(tmp * 2, 1);
                play(i = get_input(), 2);
                if (i != 4 - tmp)
                {
                    play(4 - tmp, 1);
                }
                else
                {
                    play(4 + tmp, 1);
                }
                play(i = get_input(), 2);
            }
            else
            {
                play(8 - i, 1);
                play(i = get_input(), 2);
                if (i == 8)
                {
                }
            }
        }
    }
    else if (i % 2 == 1)
    {
    }
    else if (i % 2 == 0)
    {
    }
    return 0;
}
int Game::get_input()
{
    int a = -1;
    std::string s;
    while (true)
    {
        printf("\033[19;1H\033[Kselect the position you will play: ");
        std::cin >> s;
        try
        {
            a = stoi(s);
            if (a < 0 || a > 8 || is_overlap(a))
                printf("Wrong input!!!\n");
            else
                break;
        }
        catch (std::invalid_argument)
        {
            printf("Wrong input!!!\n");
        }
    }
    return a;
}
bool Game::is_overlap(int a)
{
    return (find(list.begin(), list.end(), a) != list.end());
}
void Game::play(int pos, int style)
{
    board.play(pos, style);
    list.push_back(pos);
}