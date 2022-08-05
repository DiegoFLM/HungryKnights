/*
Archive: handler.h
Author: Diego Fabián Ledesma Motta
email: diego.ledesma@correounivalle.edu.co
*/

#include "node.h"

#ifndef HANDLER__HH
#define HANDLER__HH

#include <iterator>
#include <list>
#include <vector>
#include "node.h"


enum difficulty{
    novice = 2, amateur = 4, expert = 6
};

class Handler{
    private: 
        std::list <Node> nodeRegistry;
        std::list <Node *> l;
        bool victory;
        std::vector <Node*> solutionPath;
        int victorysize;
        int numberOfExpansions;

        Node* currentRoot;
        difficulty maxDepth;
        direction chosenPlay; 

    public:
        Handler();
        void expandNode(Node* expandingNode);
        void expandFirstL();
        void printNodeRegistry();
        void printL();
        

        Node* whiteMovement();
        void blackMovement(direction dir);
        

        Node* getNodeRegistryFront();


};

#else
class Handler;
#endif