#include "item.h"

//public
Item::Item(int row, int col){
    int position[2];
    position[0] = row;
    position[1] = col;
    onBoard = true;
}

int Item::getRow(){
    return position[0];
}

int Item::getCol(){
    return position[1];
}

bool Item::isOnBoard(){
    return onBoard;
}

//protected

void Item::setRow(int row){
    position[0] = row;
}

void Item::setCol(int col){
    position[0] = col;
}