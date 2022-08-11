#include "handler.h"



Handler::Handler(){ 
    numberOfExpansions = 0;
    gameInProgress = true;
}


void Handler::expandNode(Node* expandingNode){
    numberOfExpansions++;

    if (expandingNode->getRemainingFood() == 0){ //someone won
        expandingNode->getFather()->receiveOpponentsUtility( expandingNode->getFlatUtility(), expandingNode );
        l.remove(expandingNode);    
        return;
    }

    if( (expandingNode->getDepth() - history.back()->getDepth() ) < mode ){
        for (int integerDir = NNE; integerDir <= NNW;  integerDir++){
            if ( expandingNode->isPossible((direction)integerDir) ){
                nodeRegistry.push_back( expandingNode->partialExpansion( (direction)integerDir ) );
                l.push_back(& nodeRegistry.back());
            }
        }
    } else {
        expandingNode->getFather()->receiveOpponentsUtility( expandingNode->getFlatUtility(), expandingNode );
    }
    l.remove(expandingNode);
}

//This method does pruning.
void Handler::expandNode1(Node* expandingNode){
    numberOfExpansions++;
    if (expandingNode->getMustBePruned()){
        //expandingNode->getFather()->dropSon(expandingNode); This is done in Node::setMustBePruned()
        l.remove(expandingNode);    
        return;
    }
    if (expandingNode->getRemainingFood() == 0){ //someone won
        expandingNode->getFather()->receiveOpponentsUtility( expandingNode->getFlatUtility(), expandingNode );
        //expandingNode->getFather()->dropSon(expandingNode);
        l.remove(expandingNode);    
        return;
    }
    if( (expandingNode->getDepth() - history.back()->getDepth() ) < mode ){
        for (int integerDir = NNE; integerDir <= NNW;  integerDir++){
            if ( expandingNode->isPossible((direction)integerDir) ){
                nodeRegistry.push_back( expandingNode->partialExpansion( (direction)integerDir ) );
                l.push_front(& nodeRegistry.back());
                expandingNode->addSon(& nodeRegistry.back());
            }
        }
    } else {
        expandingNode->checkForLeafPruning();
        expandingNode->getFather()->receiveOpponentsUtility( expandingNode->getFlatUtility(), expandingNode );
        
    }
    //expandingNode->getFather()->dropSon(expandingNode);
    l.remove(expandingNode);
}



void Handler::expandFirstL(){
    this->expandNode(l.front());
}

void Handler::printCurrentPosition(){
    std::cout << std::endl << "printCurrentPositions()" << std::endl;
    history.back()->printBoard();
    std::cout << "White points: " << history.back()->getWPoints() << std::endl;
    std::cout << "Black points: " << history.back()->getBPoints() << std::endl;
}


void Handler::printNodeRegistry(){
    std::cout << std::endl << "printNodeRegistry():" << std::endl;
    std::cout << "nodeRegistry.size():" << nodeRegistry.size() << std::endl;
    std::list<Node>::iterator it;
    for(it = nodeRegistry.begin(); it != nodeRegistry.end(); ++it){
        std::cout << std::endl << "it->getId(): " << it->getId() << std::endl;
        std::cout << "it->getPlayerInTurn() = " << it->getPlayerInTurn() << std::endl;
        std::cout << "it->getWPoints() = " << it->getWPoints() << std::endl;
        std::cout << "it->getBPoints() = " << it->getBPoints() << std::endl;
        it->printBoard();
    }
}

       
/*void Handler::printL(){
    std::cout << std::endl << "printL():" << std::endl;
    std::cout << "l.size():" << l.size() << std::endl;
    std::list<Node *>::iterator it;
    for(it = l.begin(); it != l.end(); ++it){
        std::cout << std::endl << "(*it)->getId(): " << (*it)->getId() << std::endl;
        std::cout << "(*it)->getPlayerInTurn() = " << (*it)->getPlayerInTurn() << std::endl;
        std::cout << "(*it)->getWPoints() = " << (*it)->getWPoints() << std::endl;
        std::cout << "(*it)->getBPoints() = " << (*it)->getBPoints() << std::endl;
        (*it)->printBoard();
    }
    
}*/

difficulty Handler::getMode(){
    return mode;
}

Node* Handler::getNodeRegistryBack(){
    return & nodeRegistry.back();
}

Node* Handler::getNodeRegistryFront(){
    return & nodeRegistry.front();
}


direction Handler::minimax(){ //This method applies minimax and introduces the best play into Handler::history.
    l.clear();
    if ( history.back()->getPlayerInTurn() == whitesTurn ){
        if ( history.back()->getRemainingFood() > 0) {
            l.push_back( history.back() );
            while ( (!l.empty()) ){
                this->expandNode1( l.front() );
            }
        }else{
            gameInProgress = false;
            return (direction)-1;
        }
    }else{
        nodeRegistry.back().sendAlert("Error: minimax invoked in blacksTurn\n");
        return (direction)-1;
    }
    direction chosenDir = history.back()->getFavoriteSon()->getMotherOp();

    nodeRegistry.push_back( history.back()->partialExpansion(chosenDir) );
    history.push_back( &nodeRegistry.back() );
    history.back()->setInHistory();
    if ( history.back()->getRemainingFood() == 0 )
            gameInProgress = false;
    return chosenDir;
}


Node* Handler::getLastPlay(){
    return history.back();
}

void Handler::blackPlay(direction dir){
    if ( history.back()->isPossible(dir) ){
        nodeRegistry.push_back( history.back()->partialExpansion(dir) );
        history.push_back( & nodeRegistry.back() );
        history.back()->setInHistory();
        if ( history.back()->getRemainingFood() == 0 ){
            gameInProgress = false;
        }
    }else{
        nodeRegistry.back().sendAlert("Error: impossible black play in Handler::blackPlay(" 
            + std::to_string(dir) + ")\n");
    }
}


void Handler::newGameConsole(difficulty mod){
    //reset
    mode = mod;
    nodeRegistry.clear();
    history.clear();
    l.clear();
    numberOfExpansions = 0;
    chosenPlay = (direction) -1;
    gameInProgress = true;


    Node* nod0 = new Node();
    nod0->resetErrorMsgs();
    nodeRegistry.push_back( *nod0 );
    history.push_back(&nodeRegistry.back());
    history.back()->setInHistory();
    std::cout << "Starting position: " << std::endl;
    printCurrentPosition();

    
    //match
    while (gameInProgress){
        minimax();
        printCurrentPosition();
        if (!gameInProgress) break;
                
        int userPlay;
        std::cout << "Your turn: " << std::endl;
        std::cin >> userPlay;
        while(!history.back()->isPossible((direction)userPlay)){
            std::cout << "Please make a valid play: " << std::endl;
            std::cin >> userPlay;
        }
        
        direction blacksMove = (direction)userPlay;
        blackPlay(blacksMove);
        printCurrentPosition();
    }
    std::cout << "GAME OVER. WINNER: ";
    if (history.back()->getWPoints() > history.back()->getBPoints()){
        std::cout << "WHITE." << std::endl;
    }else{
        std::cout << "BLACK." << std::endl;
    }
    std::cout << "White points: " << history.back()->getWPoints() << std::endl;
    std::cout << "Black points: " << history.back()->getBPoints() << std::endl;
}

void Handler::newGameGUI(difficulty mod){
    mode = mod;
    nodeRegistry.clear();
    history.clear();
    l.clear();
    numberOfExpansions = 0;
    chosenPlay = (direction) -1;
    gameInProgress = true;


    Node* nod0 = new Node();
    nod0->resetErrorMsgs();
    nodeRegistry.push_back( *nod0 );
    history.push_back(&nodeRegistry.back());
    history.back()->setInHistory();
    std::cout << "Starting position: " << std::endl;
    printCurrentPosition();

    whitePlayGUI();
}

void Handler::whitePlayGUI(){
    if ( !gameInProgress ){
        endGameGUI();
        return;
    }
    minimax();
    printCurrentPosition();
    std::cout << "Your turn: " << std::endl;
    if ( !gameInProgress ){
        endGameGUI();
    }
}

//returns true if the user move is a valid play.
bool Handler::userMove(int destiny[2]){ // with Black Knight
    
    if( (history.back()->getPlayerInTurn() == whitesTurn) || (!gameInProgress) ){
        return false;
    }
    direction chosenDir;
    int rowIncrement = destiny[0] - history.back()->getBRow();
    int colIncrement = destiny[1] - history.back()->getBCol();
    switch (rowIncrement){
        case -2:
            switch(colIncrement){
                case -1:
                    chosenDir = NNW;
                    break;
                case 1:
                    chosenDir = NNE;
                    break;
                default:
                    return false;
            }
            break;
        
        case -1:
            switch(colIncrement){
                case -2:
                    chosenDir = NWW;
                    break;
                case 2:
                    chosenDir = NEE;
                    break;
                default:
                    return false;
            }
            break;
        
        case 1:
            switch(colIncrement){
                case -2:
                    chosenDir = SWW;
                    break;
                case 2:
                    chosenDir = SEE;
                    break;
                default:
                    return false;
            }
            break;
        
        case 2:
            switch(colIncrement){
                case -1:
                    chosenDir = SSW;
                    break;
                case 1:
                    chosenDir = SSE;
                    break;
                default:
                    return false;
            }
            break;

        default:
            return false;
    }
    std::cout << "268: chosenDir: " << chosenDir << std::endl;
    
    //blackPlayGUI(chosenDir);
    blackPlay(chosenDir);
    if (!gameInProgress){
        endGameGUI();
    }
    return true;
}

//not used right now
void Handler::blackPlayGUI(direction dir){
    blackPlay(dir);
    if (!gameInProgress){
        endGameGUI();
    } else {
        whitePlayGUI();
    }
}

void Handler::endGameGUI(){
    std::cout << "GAME OVER. WINNER: ";
    if (history.back()->getWPoints() > history.back()->getBPoints()){
        std::cout << "WHITE." << std::endl;
    }else{
        std::cout << "BLACK." << std::endl;
    }
    std::cout << "White points: " << history.back()->getWPoints() << std::endl;
    std::cout << "Black points: " << history.back()->getBPoints() << std::endl;
}

bool Handler::getGameInProgress(){
    return gameInProgress;
}

turn Handler::getTurn(){
    return history.back()->getPlayerInTurn();
}

bool Handler::isPossible(int destiny[2]){
    if( (history.back()->getPlayerInTurn() == whitesTurn) || (!gameInProgress) ){
        return false; 
    }
    direction chosenDir;
    int rowIncrement = destiny[0] - history.back()->getBRow();
    int colIncrement = destiny[1] - history.back()->getBCol();
    switch (rowIncrement){
        case -2:
            switch(colIncrement){
                case -1:
                    chosenDir = NNW;
                    break;
                case 1:
                    chosenDir = NNE;
                    break;
                default:
                    return false;
            }
            break;
        
        case -1:
            switch(colIncrement){
                case -2:
                    chosenDir = NWW;
                    break;
                case 2:
                    chosenDir = NEE;
                    break;
                default:
                    return false;
            }
            break;
        
        case 1:
            switch(colIncrement){
                case -2:
                    chosenDir = SWW;
                    break;
                case 2:
                    chosenDir = SEE;
                    break;
                default:
                    return false;
            }
            break;
        
        case 2:
            switch(colIncrement){
                case -1:
                    chosenDir = SSW;
                    break;
                case 1:
                    chosenDir = SSE;
                    break;
                default:
                    return false;
            }
            break;

        default:
            return false;
    }
    if (history.back()->isPossible(chosenDir)){
        return true;
    } else {
        return false;
    }

}

void Handler::showAlerts(){
    nodeRegistry.front().showAlerts();
}







