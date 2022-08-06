#include "handler.h"



Handler::Handler(){ 
    numberOfExpansions = 0;
    gameInProgress = true;
}


void Handler::expandNode(Node* expandingNode){
    numberOfExpansions++;

    if (expandingNode->getRemainingFood() == 0){ //someone won
        //std::cout << "Handler::expandNode(), line: 23" << std::endl;
        expandingNode->getFather()->receiveOpponentsUtility( expandingNode->leafUtility(), expandingNode );
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
        //std::cout << "Handler::expandNode(), line: 36" << std::endl;
        expandingNode->getFather()->receiveOpponentsUtility( expandingNode->leafUtility(), expandingNode );
    }
    
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

       
void Handler::printL(){
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
    
}

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
            while ( (!l.empty()) && ((l.front()->getDepth() - history.back()->getDepth() ) <= mode) ){
                this->expandNode( l.front() );
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
    return chosenDir;
}


Node* Handler::getLastPlay(){
    return history.back();
}

void Handler::blackPlay(direction dir){
    if ( history.back()->isPossible(dir) ){
        nodeRegistry.push_back( history.back()->partialExpansion(dir) );
        history.push_back( & nodeRegistry.back() );
        if ( history.back()->getRemainingFood() == 0 ){
            gameInProgress = false;
        }
    }else{
        nodeRegistry.back().sendAlert("Error: impossible black play in Handler::blackPlay(" 
            + std::to_string(dir) + ")\n");
    }
}


void Handler::newGame(difficulty mod){
    //reset
    mode = mod;
    nodeRegistry.clear();
    history.clear();
    l.clear();
    numberOfExpansions = 0;
    chosenPlay = (direction) -1;
    gameInProgress = true;


    Node nod0 = Node();
    nod0.resetErrorMsgs();
    nodeRegistry.push_back( nod0 );
    history.push_back(&nodeRegistry.back());
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






void Handler::showAlerts(){
    nodeRegistry.front().showAlerts();
}





