/*
Archive: node.h
Author: Diego Fabián Ledesma Motta
email: diego.ledesma@correounivalle.edu.co
*/

#ifndef NODE_HH
#define NODE_HH

#define _GLIBCXX_USE_CXX11_ABI 0
#include <iostream>
#include <string>
#include <random>
#include <ctime>


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
    wKnight = 6,
    bKnight = 7
};

class Node {
    private:
        //variables
        static const int  N = 8;
        
        static const int initialGrassAmount = 14;
        static const int initialFlowersAmount = 5;
        static const int initialApplesAmount = 2;
        
        Node* father;
        int wKnightPos[2];
        int bKnightPos[2];
        int board[N][N];
        turn playerInTurn;
        int wPoints;
        int bPoints;
        
        std::string errorMsgs;


        //methods
        void randomBoard();
        void testOccurrencesOnBoard(items item, int expectedOcc);

    public:
        Node();
        //Node(Node* father, int board[N][N], turn whoIsPlaying, int whitePoints, int blackPoints);


        int randomLine();
        void printBoard();
        void testInitialSet();
        turn getPlayerInTurn();
        int getN();
        int getWRow();
        int getWCol();
        int getBRow();
        int getBCol();
        int getWPoints();
        int getBPoints();
        int getSquareVal(int row, int col);
        
        bool isPossible(int initPos[2], direction dir);
        Node partialExpansion(direction dir);
        

        
};

#else
class Node;
#endif
