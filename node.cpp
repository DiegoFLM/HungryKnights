#include "node.h"


/*This constructor generates a random distribution of grass, flowers, apples, a black knight
and a white knight*/

Node::Node(){
    std::string errorMsgs = "";

    randomBoard();
    printBoard();

    father = nullptr;      
    playerInTurn = whitesTurn;
    wPoints = 0;
    bPoints = 0;

    testInitialSet();
}


//PRIVATE METHODS:

/*
    enum items {
        grass = 1,
        flower = 3,
        apple = 5,
        wKnigh = 6,
        bKnigh = 7
    };  
*/
void Node::randomBoard(){

        int grassAmount = initialGrassAmount;
        int flowersAmount = initialFlowersAmount;
        int applesAmount = initialApplesAmount;
        int wKnightAmount = 1;
        int bKnightAmount = 1;
        int randSquare[2];

    for (int r = 0; r < N; r++){
        for (int c = 0; c < N; c++){
            board[r][c] = 0;
        }   
    }

    //random distribution of grass
    while (grassAmount > 0){
        randSquare[0] = randomLine();
        randSquare[1] = randomLine(); 

        //occupied square
        if ( board[randSquare[0]] [randSquare[1]] > 0 ){
            //errorMsgs += "Collision for grass\n";
            continue;
        } else {
            board[randSquare[0]] [randSquare[1]] = grass;
            grassAmount--;
        }
    }

    //random distribution of flowers
    while (flowersAmount > 0){
        randSquare[0] = randomLine();
        randSquare[1] = randomLine(); 

        //occupied square
        if ( board[randSquare[0]] [randSquare[1]] > 0 ){
            //errorMsgs += "Collision for flower\n";
            continue;
        } else {
            board[randSquare[0]] [randSquare[1]] = flower;
            flowersAmount--;
        }
    }

    //random distribution of apples
    while (applesAmount > 0){
        randSquare[0] = randomLine();
        randSquare[1] = randomLine(); 

        //occupied square
        if ( board[randSquare[0]] [randSquare[1]] > 0 ){
            //errorMsgs += "Collision for apple\n";
            continue;
        } else {
            board[randSquare[0]] [randSquare[1]] = apple;
            applesAmount--;
        }
    }

    //random square for the white knight
    while (wKnightAmount > 0){
        randSquare[0] = randomLine();
        randSquare[1] = randomLine(); 

        //occupied square
        if ( board[randSquare[0]] [randSquare[1]] > 0 ){
            //errorMsgs += "Collision for wKnight\n";
            continue;
        } else {
            board[randSquare[0]] [randSquare[1]] = wKnight;
            wKnightPos[0] = randSquare[0];
            wKnightPos[1] = randSquare[1];
            wKnightAmount--;
        }
    }

        //random square for the black knight
    while (bKnightAmount > 0){
        randSquare[0] = randomLine();
        randSquare[1] = randomLine(); 

        //occupied square
        if ( board[randSquare[0]] [randSquare[1]] > 0 ){
            //errorMsgs += "Collision for bKnight\n";
            continue;
        } else {
            board[randSquare[0]] [randSquare[1]] = bKnight;
            bKnightPos[0] = randSquare[0];
            bKnightPos[1] = randSquare[1];
            bKnightAmount--;
        }
    }
}

void Node::testOccurrencesOnBoard(items it, int expectedOcc){
    int occurrences = 0;

    for (int r = 0; r < N; r++){
        for (int c = 0; c < N; c++){
            if ( board[r][c] == it ){
                occurrences++;
            }
        }
    }

    if (occurrences != expectedOcc){
        errorMsgs += "FAILED: testOccurrencesOnBoard(" + std::to_string(it) 
            + ", " + std::to_string(expectedOcc) + ")\n";
        errorMsgs += "occurrences: " + std::to_string(occurrences);
    }
}


//PUBLIC METHODS:

int Node::randomLine(){
    std::random_device dev;
    std::mt19937 rng(dev());
    std::uniform_int_distribution<std::mt19937::result_type> lineRange(0, N-1); //distribution in range [0, 7]
    return lineRange(rng);
}


void Node::printBoard(){
    for (int r = 0; r < N; r++){
        for (int c = 0; c < N; c++){
            std::cout << board[r][c] << " ";
        }
        std::cout << std::endl;   
    }
}


void Node::testInitialSet(){
    //errorMsgs = "";

    testOccurrencesOnBoard(grass, 14);
    testOccurrencesOnBoard(flower, 5);
    testOccurrencesOnBoard(apple, 2);
    testOccurrencesOnBoard(wKnight, 1);
    testOccurrencesOnBoard(bKnight, 1);
    testOccurrencesOnBoard(freeSquare, 41);
    

    std::cout << errorMsgs << std::endl;
}


turn Node::getPlayerInTurn(){
    return playerInTurn;
}


int Node::getN(){
    return N;
}

int Node::getWRow(){
    return wKnightPos[0];
}

int Node::getWCol(){
    return wKnightPos[1];
}

int Node::getBRow(){
    return bKnightPos[0];
}

int Node::getBCol(){
    return bKnightPos[1];
}

int Node::getWPoints(){
    return wPoints;
}

int Node::getBPoints(){
    return bPoints;
}

int Node::getSquareVal(int row, int col){
    return board[row][col];
}


bool Node::isPossible(int initPos[2], direction dir){
    if ( (initPos[0] < 0) || (initPos[1] < 0) || (initPos[0] > 7) || (initPos[1] > 7)  ){
        return false;
    }

    switch (dir)
    {
    case NNE:
        /* code */
        break;
    
    default:
        break;
    }

/*enum direction {
    NNE, NEE, SEE, SSE, SSW, SWW, NWW, NNW
};*/

}

