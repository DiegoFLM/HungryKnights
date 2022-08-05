#include "handler.h"



Handler::Handler(){ 
    //std::list <Node> nodeRegistry;
    
    Node nod0 = Node();
    nodeRegistry.push_back( nod0 );

    l.push_back(&nodeRegistry.front());

    victory = false;
    numberOfExpansions = 0;
}


Node* Handler::getNodeRegistryFront(){
    Node* nodePtr =& (nodeRegistry.front());
    return nodePtr;
}


void Handler::expandNode(Node* expandingNode){
    numberOfExpansions++;

    if (expandingNode->getRemainingFood() == 0){ //someone won
        expandingNode->getFather()->receiveOpponentsUtility( expandingNode->leafUtility(), expandingNode );
            return;
    }

    for (int integerDir = NNE; integerDir <= NNW;  integerDir++){
        if ( expandingNode->isPossible((direction)integerDir) ){
            nodeRegistry.push_back( expandingNode->partialExpansion( (direction)integerDir ) );
            l.push_back(& nodeRegistry.back());
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





