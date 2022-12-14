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
#include "node.h"


enum difficulty{
    novice = 2, amateur = 4, expert = 8
};

class Handler{
    private: 
        std::list <Node> nodeRegistry;
        std::list <Node *> l;
        std::list <Node *> history;
        int victorysize;
        int numberOfExpansions;

        //Node* currentRoot;
        difficulty mode; //max depth of the minimax decision tree
        direction chosenPlay; 
        bool gameInProgress;
        

    public:
        Handler();
        void expandNode(Node* expandingNode);
        void expandNode1(Node* expandingNode);
        void expandFirstL();
        void printCurrentPosition();
        void printNodeRegistry();
        //void printL();
        
        difficulty getMode();
        Node* getNodeRegistryBack();
        Node* getNodeRegistryFront();    

        direction minimax(); 
        //void setMode(difficulty mod);
        
        Node* getLastPlay();
        void blackPlay(direction dir);
        
        void newGameConsole(difficulty mod);
        void newGameGUI(difficulty mod);
        bool userMove(int destiny[2]);
        void blackPlayGUI(direction dir);
        void whitePlayGUI();
        void endGameGUI();
        bool getGameInProgress();
        turn getTurn();
        bool isPossible(int destiny[2]);

        void showAlerts();
};

#else
class Handler;
#endif