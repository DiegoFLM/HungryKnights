#include <iostream>
#include "node.h"


/*En node.h

enum direction {
    NNE, NEE, SEE, SSE, SSW, SWW, NWW, NNW
};

enum turn {
    white, black
};

enum foodType {
    grass = 1,
    flower = 3,
    apple = 5
};


*/


int myFunk(int player);

int main(){
    //std::srand(std::time(0));


    std::random_device dev;
    std::mt19937 rng(dev());
    std::uniform_int_distribution<std::mt19937::result_type> dist6(1,6); // distribution in range [1, 6]

    std::cout << dist6(rng) << std::endl;


    Node nod0;


    int sfp = myFunk(white);

    //std::cout << "myFunk(black) = " << myFunk(black) << std::endl;
    //std::cout << "rand() = " << std::rand() % 8 << std::endl;



    return 0;
}

int myFunk(int player){
    int result = player + 2;
    return result;
};







