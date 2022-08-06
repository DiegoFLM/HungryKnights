#include "node.h"
#include "handler.h"
#include <iterator>
#include <list>
#include <vector>



int myFunk(int player);

int main(){


    /*
    Node nod0 = Node();
    int board[8][8];
    for (int r = 0; r < 8; r++){
        for (int c = 0; c < 8; c++){
            board[r][c] = nod0.getSquareVal(r, c);
        }
    }*/

    //Node nod1(&nod0, board, nod0.getWPoints(), nod0.getBPoints(), NNE);
    

    
    Handler hand = Handler();
    std::cout << std::endl << "HAND: " << std::endl;
    std::cout << std::endl << "main: 19 " << std::endl;
    hand.getNodeRegistryFront()->printBoard();
    
    
    std::cout << std::endl << "hand.getFront()->getPlayerInTurn() = " 
        << (int) hand.getNodeRegistryFront()->getPlayerInTurn() << std::endl << std::endl;
    
    //hand.expandFirstL();
    //hand.expandFirstL();
    hand.printL();

    return 0;
}

int myFunk(int player){
    int result = player + 2;
    return result;
};







