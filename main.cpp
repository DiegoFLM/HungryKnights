#include "node.h"
#include "handler.h"
#include <iterator>
#include <list>
#include <vector>

int main(){
    Handler hand = Handler();
    /*enum difficulty{
    novice = 2, amateur = 4, expert = 6
    };*/
    hand.newGameConsole(novice);
    hand.showAlerts();

    return 0;
}









