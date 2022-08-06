#include "node.h"


/*This constructor generates a random distribution of grass, flowers, apples, a black knight
and a white knight*/

//Alert Node::alerts;
int Node::rowIncrement;
int Node::colIncrement;
std::string Node::errorMsgs = "";
int Node::biggestId = -1;

Node::Node(){
    id = biggestId + 1;
    biggestId = id;
    randomBoard();

    father = nullptr;      
    playerInTurn = whitesTurn;
    wPoints = 0;
    bPoints = 0;

    depth = 0;
    motherOp = (direction) -1;

    offspring = 0;
    receivedUtilities = 0;

    testInitialSet();
}

Node::Node(Node* dad, int newBoard[N][N], int whitePoints, int blackPoints, direction dir){
    id = biggestId + 1;
    biggestId = id;
    father = dad;

    int remFood = 0;
    for (int row = 0; row < N; row++){
        for (int col = 0; col < N; col++){
            board[row][col] = newBoard[row][col];
            if (board[row][col] == 6){
                wKnightPos[0] = row;
                wKnightPos[1] = col;
            }else if (board[row][col] == 7){
                bKnightPos[0] = row;
                bKnightPos[1] = col;
            }else if(board[row][col] > 0){
                remFood++;
            }
        }
    }
    remainingFood = remFood;

    playerInTurn =  (turn) !(dad->getPlayerInTurn());
    wPoints = whitePoints;
    bPoints = blackPoints;
    
    depth = 1 + dad->getDepth();
    motherOp = dir;

    offspring = 0;
    receivedUtilities = 0;
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
void Node::sendAlert(std::string al){
    errorMsgs += al + "\n";
}

void Node::randomBoard(){
    int grassAmount = initialGrassAmount;
    int flowersAmount = initialFlowersAmount;
    int applesAmount = initialApplesAmount;
    int wKnightAmount = 1;
    int bKnightAmount = 1;
    int randSquare[2];
    int remFood = 0;

    for (int r = 0; r < N; r++){
        for (int c = 0; c < N; c++){
            board[r][c] = 0;
        }   
    }
    
    //random distribution of grass
    this->randPutItem(grass, grassAmount);
    
    //random distribution of flowers
    this->randPutItem(flower, flowersAmount);

    //random distribution of apples
    this->randPutItem(apple, applesAmount);

    //random square for the white knight
    this->randPutItem(whiteK, wKnightAmount);
    
    //random square for the black knight
    this->randPutItem(blackK, bKnightAmount);
    
    for (int r = 0; r < N; r++){
        for (int c = 0; c < N; c++){
            if (board[r][c] == 6){
                wKnightPos[0] = r;
                wKnightPos[1] = c;
            }else if (board[r][c] == 7){
                bKnightPos[0] = r;
                bKnightPos[1] = c;
            }else if(board[r][c] > 0){
                remFood++;
            }
        }   
    }

    remainingFood = remFood;
}

void Node::randPutItem(items it, int amount){
    int randSquare[2];
    while (amount > 0){
        randSquare[0] = randomLine();
        randSquare[1] = randomLine(); 

        //occupied square
        if ( board[randSquare[0]] [randSquare[1]] > 0 ){
            continue;
        } else { //free square
            board[randSquare[0]] [randSquare[1]] = it;
            amount--;
        }
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

int Node::countInBoard(items it){
    int count = 0;
    for (int col = 0; col < N; col++){
        for (int row = 0; row < N; row++){
            if (board[row][col] == it)
                count++;
        }
    }
    return count;
}

void Node::testInitialSet(){
    testOccurrencesOnBoard(grass, 14);
    testOccurrencesOnBoard(flower, 5);
    testOccurrencesOnBoard(apple, 2);
    testOccurrencesOnBoard(whiteK, 1);
    testOccurrencesOnBoard(blackK, 1);
    testOccurrencesOnBoard(freeSquare, 41);
}

int Node::getDepth(){
    return depth;
}

Node* Node::getFather(){
    return father;
}

Node* Node::getFavoriteSon(){
    return favoriteSon;
}

int Node::getId(){
    return id;
}

direction Node::getMotherOp(){
    return motherOp;
}

int Node::getN(){
    return N;
}

turn Node::getPlayerInTurn(){
    return playerInTurn;
}

int Node::getRemainingFood(){
    return remainingFood;
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

bool Node::isPossible(direction dir){
    int row;
    int col;

    if (playerInTurn == whitesTurn){
        row = wKnightPos[0];
        col = wKnightPos[1];
    } else {
        row = bKnightPos[0];
        col = bKnightPos[1];
    }

    
    if ( (row < 0) || (col < 0) || (row > 7) || (col > 7)  ){
        /*alerts.add("Node::isPossible() - Impossible position received: (" + std::to_string(row) 
                + ", " + std::to_string(col));*/
        errorMsgs += "Invalid direction received: Node::isPossible(" + std::to_string(row) 
                + ", " + std::to_string(col) + ", " + std::to_string(dir) +")\n";
        return false;
    }else if( (board[row][col] != whiteK) && (board[row][col] != blackK) ){
        errorMsgs += "No knight in the position: Node::isPossible(" + std::to_string(row) 
                + ", " + std::to_string(col) + ", " + std::to_string(dir) +")\n";
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
        errorMsgs += "direction not detected: Node::isPossible(" + std::to_string(row) 
                + ", " + std::to_string(col) + ", " + std::to_string(dir) +")\n";
        return false;
        break;
    }


    if (   (row + rowIncrement > 7 ) || (row + rowIncrement < 0 )
        || (col + colIncrement > 7 ) || (col + colIncrement < 0)
        || ((board[row][col] == whiteK) && (board[row + rowIncrement][col + colIncrement] == blackK) ) 
        || ((board[row][col] == blackK) && (board[row + rowIncrement][col + colIncrement] == whiteK) ) )
    {
        std::cout << "is not possible: {" << row << ", " << col << "} dir: " << dir << std::endl; 
        return false;
    } else {
        std::cout << "is possible: {" << row << ", " << col << "} dir: " << dir << std::endl;
        return true;
    }
}


Node Node::partialExpansion(direction dir){
    int origin[2];
    int sonsWhitePoints = wPoints;
    int sonsBlackPoints = bPoints;

    if (playerInTurn == whitesTurn){
        origin[0] = wKnightPos[0];
        origin[1] = wKnightPos[1];
        //std::cout << "origin: {" << origin[0] << ", " << origin[1] << "}" << std::endl; 
        sonsWhitePoints += board[origin[0] + rowIncrement] [origin[1] + colIncrement];
    }else{
        origin[0] = bKnightPos[0];
        origin[1] = bKnightPos[1];
        //std::cout << "origin: {" << origin[0] << ", " << origin[1] << "}" << std::endl;
        sonsBlackPoints += board[origin[0] + rowIncrement] [origin[1] + colIncrement];
    }

    if (! this->isPossible(dir)){
        errorMsgs += "ERROR: IMPOSSIBLE DIRECION IN: partialExpansion(" + std::to_string(dir)
            + ");" ;
            Node nod = Node();
            return nod;
    }

    int sonsBoard[N][N];

    for (int row = 0; row < N; row++){
        for (int col = 0; col < N; col++){
            sonsBoard[row][col] = board[row][col];
        }
    }

    sonsBoard[origin[0] + rowIncrement][origin[1] + colIncrement] = board[origin[0]] [origin[1]];
    sonsBoard[origin[0]] [origin[1]] = 0;

    offspring += 1;
    Node nod(this, sonsBoard, sonsWhitePoints, sonsBlackPoints, dir);
    return nod;
}


int Node::leafUtility(){
    int utility;
    if (playerInTurn == whitesTurn){
        utility = wPoints - bPoints;
    }else {
        utility = bPoints - wPoints;
    }
    return utility;
}


void Node::receiveOpponentsUtility(int opUt, Node* son){
    int ut = -opUt;
    if (receivedUtilities == 0){
        max = ut;
        favoriteSon = son;
    }else{
        if (ut > max){
            max = ut;
            favoriteSon = son;
        }
    }
    receivedUtilities++;

    if ( (receivedUtilities == offspring) && (offspring > 0) ){
        this->getFather()->receiveOpponentsUtility( this->leafUtility(), this );
    }else if (offspring == 0){
        errorMsgs += "ERROR. receiveOpponentsUtility invoked from a Node with no offspring. id = " + id;
    } else if (receivedUtilities > offspring){
        std::cout << "last receiveOpponentsUtility for id = " << id << std::endl;
    }

}

int Node::getMax(){
    if(receivedUtilities != offspring){
        errorMsgs += "WARNING: receivedUtilities != offspring in Node::getMax()";
        errorMsgs += "id = " + id;
    }
    return max;
}


