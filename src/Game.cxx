#include "Game.h"
#include <cstdio>
#include <unistd.h>
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
// TODO
float Game::p_to_win(std::vector<int> list1,std::vector<int> list2){
    float p=0;
    int player;
    int n_total=0,n_win=0;
    // std::vector<int> list1, list2;
    int n1=list1.size(),n2=list2.size();
    if(is_over(player,list1,list2)){
        return player==1;
    }
    for(int i=0;i<9;i++){
        // list1.clear();list2.clear();
        // copy(list_1.begin(),list_1.end(),list1.begin());
        // copy(list_2.begin(),list_2.end(),list2.begin());
        if(find(list1.begin(), list1.end(), i) == list1.end()&&find(list2.begin(), list2.end(), i) == list2.end()){
            if(n1>n2)list1.push_back(i);
            else list2.push_back(i);
            p+=p_to_win(list1,list2)/(9-n1-n2);
        }
    }
    // while(!is_over(player,list1,list2)){

    // }
    return p;
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
            play(tmp, 1);
            return 1;
        }
        else if (i != 8 - 2 * tmp)
        {
            play(8 - 2 * tmp, 1);
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
        else if(i/4==1){
            play(8-i,1);
            play(i=get_input(),2);
            if(i!=2*(8-tmp)){
                play(2*(8-tmp),1);
                return 1;
            }
            play(2*tmp-8,1);
            play(i=get_input(),2);
            if(i!=tmp-4){
                play(tmp-4,1);
                return 1;
            }
            play(12-tmp,1);
            play(i=get_input(),2);
        }
    }
    else if (i % 2 == 1)
    {
        play((i+5)%10,1);
        play(i=get_input(),2);
        if(i==4){
            play(8-tmp,1);
            play(i=get_input(),2);
            if(i!=(11-tmp%4*3-2*(tmp>4))){
                play((11-tmp%4*3-2*(tmp>4)),1);
                return 1;
            }
            play(8-i,1);
            play(i=get_input(),2);
            // printf("%d",(99+tmp*(-25+tmp*(-3+tmp)))/24);
            if(i!=(-27+tmp*(+119+tmp*(-21+tmp)))/24){
                play((-27+tmp*(+119+tmp*(-21+tmp)))/24,1);
                return 1;
            }
            play(8-i,1);
            play(i=get_input(),2);
        }
        else if(i==(11-tmp%4*3-2*(tmp>4))){
            play(8-i,1);
            play(i=get_input(),2);
            if(i!=(tmp*2+1)-(tmp>4)*10){
                play((tmp*2+1)-(tmp>4)*10,1);
                return 1;
            }
            play(4,1);
            play(i=get_input(),2);
            if(i!=(3-tmp+(tmp>4)*10)){
                play(3-tmp+(tmp>4)*10,1);
                return 1;
            }
            play(i=get_input(),2);
        }
        else if(i==8-tmp){
            play(4,1);
            play(i=get_input(),2);
            if(i!=8-(tmp+5)%10){
                play(8-(tmp+5)%10,1);
                return 1;
            }
            play((tmp-1)*3-(tmp>4)*10,1);
            play(i=get_input(),2);
            if(i!=3-tmp/2){
                play(3-tmp/2,1);
                return 1;
            }
            play(8-tmp/2,1);
            return 1;
        }
        else if(i==(tmp-1)*3-(tmp>4)*10){
            play(2*tmp-i,1);
            play(i=get_input(),2);
            if(i!=4){
                play(4,1);
                return 1;
            }
            play(11-tmp*3+(tmp>4)*10,1);
            play(i=get_input(),2);
            if(i!=7-tmp*2+(tmp>4)*10){
                play(7-tmp*2+(tmp>4)*10,1);
                return 1;
            }
            play(8-tmp,1);
            return 1;
        }
        else if(i==8-(tmp+5)%10){
            play(2*tmp-i,1);
            play(i=get_input(),2);
            if(i!=tmp*2+1-(tmp>4)*10){
                play(tmp*2+1-(tmp>4)*10,1);
                return 1;
            }
            play(11-3*tmp+(tmp>4)*10,1);
            play(i=get_input(),2);
            if(i!=4){
                play(4,1);
                return 1;
            }
            play(8-tmp,1);
            return 1;
        }
        else{
            play(11-3*tmp+(tmp>4)*10,1);
            play(i=get_input(),2);
            if(i!=8-tmp){
                play(8-tmp,1);
                return 1;
            }
            play(4,1);
            play(i=get_input(),2);
            if(i!=3-tmp+(tmp>4)*10){
                play(3-tmp+(tmp>4)*10,1);
                return 1;
            }
            play(tmp*3-3-(tmp>4)*10,1);
            return 1;
        }
    }
    else if (i % 2 == 0)
    {
        play(8-i,1);
        play(i=get_input(),2);
        if(i==4){
            play(3*abs(4-tmp)-6,1);
            play(i=get_input(),2);
            if(i!=(tmp*tmp-10*tmp+28)/4){
                play((tmp*tmp-10*tmp+28)/4,1);
                return 1;
            }
            play((-tmp*tmp+10*tmp+4)/4,1);
            play(i=get_input(),2);
            if(i!=3-tmp%6){
                play(3-tmp%6,1);
            }
            else{
                play(5+tmp%6,1);
            }
            play(i=get_input(),2);
        }
        else if(i==tmp){///TODO

        }
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
    if(style==1){
        printf("\033[19;1H\033[Kpress enter for computer play: ");
        getchar();
        getchar();
    }
    board.play(pos, style);
    list.push_back(pos);
    if(style==1)list_1.push_back(pos);
    else list_2.push_back(pos);
}
bool Game::is_over(int &player,std::vector<int> list1,std::vector<int> list2){
    
    return 0;
}