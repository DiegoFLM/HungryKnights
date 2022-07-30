#include "item.h"

//public
Item::Item(line row, line col){
    position[0] = row;
    position[1] = col;
    onBoard = true;
}


//protected

//horse:
void Item::setRow(line row){
    position[0] = row;
}

void Item::setCol(line col){
    position[0] = col;
}


//food:
void Item::takeOut(){
    onBoard = false;
}



//public

int Item::getRow(){
    return position[0];
}

int Item::getCol(){
    return position[1];
}

bool Item::isOnBoard(){
    return onBoard;
}


