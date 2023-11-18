#include "Board.h"
#include <iostream>
Board::Board(){

}
Board::~Board(){

}
void Board::Show(){
    printf("\033[2J\033[1;1H");
    for(int i=0;i<size*3+2;i++){
        printf("\033[%d;%dH#",i+1,2*size+1);
        printf("\033[%d;%dH#",i+1,4*size+2);
        printf("\033[%d;%dH#",size+1,2*i+1);
        printf("\033[%d;%dH#",2*size+2,2*i+1);
    }
    printf("\033[18;1H\n");
}