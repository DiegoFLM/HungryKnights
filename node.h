/*
Archive: node.h
Author: Diego Fabián Ledesma Motta
email: diego.ledesma@correounivalle.edu.co
*/

#ifndef NODE_HH
#define NODE_HH


//#include <stdlib.h>
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
    white, black
};

enum foodType {
    grass = 1,
    flower = 3,
    apple = 5
};

class Node {
    private:
        //variables
        static const int  N = 8;
        static const int grassAmount = 14;
        static const int flowersAmount = 5;
        static const int applesAmount = 2;
        
        int wKnightPos[2];
        int bKnightPos[2];
        int board[N][N];
        turn playerInTurn;
        int wPoints;
        int bPoints;



        //methods
        void randomBoard();

    public:
        Node();
        Node(int board[N][N], turn whoIsPlaying, int whitePoints, int blackPoints);

        bool isPossible(int knightPos[2], direction dir);
        void move(int knightPos[2], direction dir);
        turn getPlayerInTurn();
        int getN();
};

#else
class Node;
#endif
