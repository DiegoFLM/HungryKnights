#include "node.h"

Node::Node(int row, int col){
        position[0] = row;
        position[1] = col;
}

Node::Node(){}

int Node::getPosition0(){
    return position[0]; 
}

int Node::getPosition1(){
    return position[1];
}

int Node::say1(){
    return 1;
}