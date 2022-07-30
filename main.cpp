#include <iostream>
#include "node.h"
#include "item.h"
#include "horse.h"
#include "food.h"


/*En item.h:
enum line {
    a, b, c, d, e, f, g, h
};





*/
int main(){
    //Node nod(2, 7);

    Node nod0;

    Knight bKnight = Knight(a, e);

    std::cout << "nod0.say1() = " << std::endl;

    std::cout << "Knight position: (" << bKnight.getRow() << ", " 
        << bKnight.getCol() << ")" << std::endl;

    std::cout << "Knight.isOnBoard() = " << bKnight.isOnBoard() << std::endl;

    return 0;
}







