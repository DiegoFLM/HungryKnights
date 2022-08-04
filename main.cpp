#include "node.h"
#include <iterator>
#include <list>
#include <vector>



int myFunk(int player);

int main(){

    Node nod0;
    
    Node nod1 = nod0;

    const int N = 8;
    int tempBoard[N][N];
    for (int row = 0; row < N; row++){
        for (int col = 0; col < N; col++){
            tempBoard[row][col] = nod1.getSquareVal(row, col);
        }
    }
    Node * nodePtr = &nod0;

    std::list <Node> nodeRegistry;

    Node nod2(& nod0, tempBoard, nod0.getWPoints(), nod0.getWPoints(), SWW);
    Node nod3(& nod2, tempBoard, nod2.getWPoints(), nod2.getWPoints(), SSE);

    nodeRegistry.push_back(nod3);

    int origin[2];
    if (nod3.getPlayerInTurn() == whitesTurn){ // whites turn
        origin[0] = nod3.getWRow();
        origin[1] = nod3.getWCol();
    } else {
        origin[0] = nod3.getBRow();
        origin[1] = nod3.getBCol();
    }
    
    std::cout << std::endl << "START" << std::endl;
    nod3.printBoard();
    std::cout << nod3.getWPoints() << std::endl;

    if (nod3.isPossible( origin, NNE)){
        std::cout << std::endl << "possible" << std::endl;
        Node nod4 = nod3.partialExpansion(NNE);
        nodeRegistry.push_back(nod4);
        
    } else {
        std::cout << std::endl << "kimpossible" << std::endl;
    }

    std::cout << std::endl << std::endl;

    nodeRegistry.back().printBoard();
    std::cout << nodeRegistry.back().getWPoints() << std::endl;
    
    nod0.showAlerts();
    
    return 0;
}

int myFunk(int player){
    int result = player + 2;
    return result;
};







