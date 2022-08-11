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
#include <iterator>
#include <list>
#include <algorithm>

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
        float wPoints;
        float bPoints;
        int remainingFood;
        

        int depth;
        direction motherOp;

        //minMax
        int offspring; //How many nodes have this one as father.
        int receivedUtilities; //How many child nodes have reported their utility.
        float max;
        Node* favoriteSon;
        //pruning
        std::list <Node *> offspringInL;
        bool beenInformed;
        bool mustBePruned;
        bool inHistory;


        //methods
        void randomBoard();
        void randPutItem(items it, int amount);
        
    public:
        Node();
        Node(Node* father, int newBoard[N][N], float whitePoints, float blackPoints,  direction dir);

        void sendAlert(std::string al);
        void showAlerts();
        int randomLine();
        void printBoard();
        void testOccurrencesOnBoard(items item, int expectedOcc);
        int countInBoard(items it);
        void testInitialSet();
        int getDepth();
        Node* getFather();
        Node* getFavoriteSon();
        int getId();
        direction getMotherOp();
        int getN();
        turn getPlayerInTurn();
        int getRemainingFood();
        
        int getWRow();
        int getWCol();
        int getBRow();
        int getBCol();
        float getWPoints();
        float getBPoints();
        float getSquareVal(int row, int col);
        
        bool isPossible(direction dir);
        Node partialExpansion(direction dir);

        void resetErrorMsgs();
        
        //minMax
        float getFlatUtility();
        void receiveOpponentsUtility(float ut, Node* son);
        float getMax();

        //pruning
        void addSon(Node* son);
        void dropSon(Node* son);
        Node* getFrontSon();
        bool getBeenInformed();
        bool getMustBePruned();
        void setMustBePruned(); //Prunes all descendence in L, not just sons.
        void checkForBranchPruning();
        void checkForLeafPruning();
        float h();
        int getRowInc(direction dir);
        int getColInc(direction dir);
        void setInHistory();
        bool getInHistory();
};

#else
class Node;
#endif
