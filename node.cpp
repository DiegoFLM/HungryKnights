#include "node.h"


Node::Node(int board[N][N], turn whoIsPlaying, int whitePoints, int blackPoints){


}

Node::Node(){


    for (int r = 0; r < N; r++){
        for (int c = 0; c < N; c++){
            board[r][c] = 0;
        }   
    }




    board[0][1] = 8;


    int wKnightPos[2];


    int bKnightPos[2];
    
    turn playerInTurn;
    int wPoints;
    int bPoints;
}


/*
Node(int board[N][N], turn whoIsPlaying, int whitePoints, int blackPoints);

bool isPossible(int knightPos[2], direction dir);
void move(int knightPos[2], direction dir);

turn getPlayerInTurn();
int getN();*/

