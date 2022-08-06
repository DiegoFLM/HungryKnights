#include "handler.h"



Handler::Handler(){ 
    //std::list <Node> nodeRegistry;
    
    Node nod0 = Node();
    nodeRegistry.push_back( nod0 );
    history.push_back(&nodeRegistry.back());
    //l.push_back(&nodeRegistry.front());
    //currentRoot = & nodeRegistry.back();

    victory = false;
    numberOfExpansions = 0;
    gameInProgress = true;
}


void Handler::expandNode(Node* expandingNode){
    numberOfExpansions++;

    if (expandingNode->getRemainingFood() == 0){ //someone won
        expandingNode->getFather()->receiveOpponentsUtility( expandingNode->leafUtility(), expandingNode );
            return;
    }

    for (int integerDir = NNE; integerDir <= NNW;  integerDir++){
        if( (expandingNode->getDepth() - history.back()->getDepth() ) < mode ){
            if ( expandingNode->isPossible((direction)integerDir) ){
                nodeRegistry.push_back( expandingNode->partialExpansion( (direction)integerDir ) );
                l.push_back(& nodeRegistry.back());
            }
        } else {
            expandingNode->getFather()->receiveOpponentsUtility( expandingNode->leafUtility(), expandingNode );
        }
    }
    l.remove(expandingNode);
}

void Handler::expandFirstL(){
    this->expandNode(l.front());
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


direction Handler::minimax(){ //This method applies minimax and changes the value of Handler::mode
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
    return chosenDir;
}


void Handler::setMode(difficulty mod){
    mode = mod;
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
    
    //currentRoot = history.back();
}








