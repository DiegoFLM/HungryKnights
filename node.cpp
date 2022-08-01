#include "node.h"


/*This constructor generates a random distribution of grass, flowers, apples, a black knight
and a white knight*/

//Alert Node::alerts;
std::string Node::errorMsgs = "";

Node::Node(){
    errorMsgs = "";

    randomBoard();
    printBoard();

    father = nullptr;      
    playerInTurn = whitesTurn;
    wPoints = 0;
    bPoints = 0;

    depth = 0;
    motherOp = (direction) -1;

    testInitialSet();
}


//PRIVATE METHODS:

/*
    enum items {
        grass = 1,
        flower = 3,
        apple = 5,
        whiteK = 6,
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
            board[randSquare[0]] [randSquare[1]] = whiteK;
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
            board[randSquare[0]] [randSquare[1]] = blackK;
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

        /*alerts.add("FAILED: testOccurrencesOnBoard(" + std::to_string(it) 
            + ", " + std::to_string(expectedOcc));

        alerts.add("occurrences: " + std::to_string(occurrences));*/

    }
}


//PUBLIC METHODS:

void Node::showAlerts(){
    std::cout << errorMsgs << std::endl;
}

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
    testOccurrencesOnBoard(grass, 14);
    testOccurrencesOnBoard(flower, 5);
    testOccurrencesOnBoard(apple, 2);
    testOccurrencesOnBoard(whiteK, 1);
    testOccurrencesOnBoard(blackK, 1);
    testOccurrencesOnBoard(freeSquare, 41);
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
    int row = initPos[0];
    int col = initPos[1];
    int rowIncrement;
    int colIncrement;
    if ( (row < 0) || (col < 0) || (row > 7) || (col > 7)  ){
        /*alerts.add("Node::isPossible() - Impossible position received: (" + std::to_string(initPos[0]) 
                + ", " + std::to_string(initPos[1]));*/
        errorMsgs += "Invalid direction received: Node::isPossible(" + std::to_string(initPos[0]) 
                + ", " + std::to_string(initPos[1]) + ", " + std::to_string(dir) +")\n";
        return false;
    }else if( (board[row][col] != whiteK) && (board[row][col] != blackK) ){
        errorMsgs += "No knight in the position: Node::isPossible(" + std::to_string(initPos[0]) 
                + ", " + std::to_string(initPos[1]) + ", " + std::to_string(dir) +")\n";
        return false;
    }


    switch (dir)
    {
    case NNE:
        rowIncrement = -2;
        colIncrement = 1;
        break;

    case NEE:
        rowIncrement = -1;
        colIncrement = 2;
        break;

    case SEE:
        rowIncrement = 1;
        colIncrement = 2;
        break;

    case SSE:
        rowIncrement = 2;
        colIncrement = 1;
        break;

    case SSW:
        rowIncrement = 2;
        colIncrement = -1;
        break;

    case SWW:
        rowIncrement = 1;
        colIncrement = -2;
        break;

    case NWW:
        rowIncrement = -1;
        colIncrement = -2;
        break;

    case NNW:
        rowIncrement = -2;
        colIncrement = -1;
        break;
    
    default:
        errorMsgs += "direction not detected: Node::isPossible(" + std::to_string(initPos[0]) 
                + ", " + std::to_string(initPos[1]) + ", " + std::to_string(dir) +")\n";
        return false;
        break;
    }

    if (   (row + rowIncrement > 7 ) || (row + rowIncrement < 0 )
        || (col + colIncrement > 7 ) || (col + colIncrement < 0)
        || ((board[row][col] == whiteK) && (board[row + rowIncrement][col + colIncrement] == blackK) ) 
        || ((board[row][col] == blackK) && (board[row + rowIncrement][col + colIncrement] == whiteK) ) )
    {
        return false;
    } else {
        return true;
    }
}

