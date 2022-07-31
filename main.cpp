#include "node.h"


/*En node.h

enum direction {
    NNE, NEE, SEE, SSE, SSW, SWW, NWW, NNW
};

enum turn {
    whitesTurn, blacksTurn
};

enum items {
    grass = 1,
    flower = 3,
    apple = 5,
    blackK = 6,
    whiteK = 7
};


*/


int myFunk(int player);

int main(){

    Node nod0;
    Node nod1 = nod0;



    ///int sfp = myFunk(whitesTurn);
    //std::cout << "myFunk(black) = " << myFunk(black) << std::endl;
    //std::cout << "rand() = " << std::rand() % 8 << std::endl;


    return 0;
}

int myFunk(int player){
    int result = player + 2;
    return result;
};







