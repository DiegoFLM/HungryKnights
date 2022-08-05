/*
Archive: node.h
Author: Diego Fabián Ledesma Motta
email: diego.ledesma@correounivalle.edu.co
*/

#define _GLIBCXX_USE_CXX11_ABI 0
#include <iostream>
#include <string>
#include <random>
#include <ctime>

//#include "alert.h"


#ifndef NODE_HH
#define NODE_HH

/*
0 :=NNE         (North North East)
1 :=NEE         (North East East)
2 :=SEE                ...
3 :=SSE
4 :=SSW
5 :=SWW
6 :=NWW
7 :=NNW
*/
enum direction {
    NNE, NEE, SEE, SSE, SSW, SWW, NWW, NNW
};

enum turn {
    whitesTurn, blacksTurn
};

enum items {
    freeSquare = 0,
    grass = 1,
    flower = 3,
    apple = 5,
    whiteK = 6,
    blackK = 7
};

class Node {
    private:
        //variables
        static const int  N = 8;
        
        static const int initialGrassAmount = 14;
        static const int initialFlowersAmount = 5;
        static const int initialApplesAmount = 2;
        static int rowIncrement;
        static int colIncrement;
        static std::string errorMsgs;
        static int biggestId;
        
        int id;
        Node* father;
        int wKnightPos[2];
        int bKnightPos[2];
        int board[N][N];
        turn playerInTurn;
        int wPoints;
        int bPoints;
        int remainingFood;

        int depth;
        direction motherOp;

        //minMax
        int offspring; //Cuántos nodos lo tienen como padre
        int receivedUtilities; //Cuántos nodos hijos le han reportado su utilidad.
        int max;
        Node* favoriteSon;

        //methods
        void randomBoard();
        void randPutItem(items it, int amount);
        
    public:
        Node();
        Node(Node* father, int newBoard[N][N], int whitePoints, int blackPoints,  direction dir);

        void showAlerts();
        int randomLine();
        void printBoard();
        void testOccurrencesOnBoard(items item, int expectedOcc);
        int countInBoard(items it);
        void testInitialSet();
        int getDepth();
        Node* getFather();
        int getId();
        direction getMotherOp();
        int getN();
        turn getPlayerInTurn();
        int getRemainingFood();
        
        int getWRow();
        int getWCol();
        int getBRow();
        int getBCol();
        int getWPoints();
        int getBPoints();
        int getSquareVal(int row, int col);
        
        bool isPossible(/*int initPos[2], */direction dir);
        Node partialExpansion(direction dir);
        
        //minMax
        int leafUtility();
        int estimatedUtility();/*int offspring; //How many nodes have it as their father.
        int receivedUtilities; revisar que sean iguales:*/
        void receiveOpponentsUtility(int ut, Node* son);
        int getMax();
        Node getNewNode();
        
        
};

#else
class Node;
#endif
