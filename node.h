/*
Archive: node.h
Author: Diego Fabián Ledesma Motta
email: diego.ledesma@correounivalle.edu.co
*/



#ifndef NODE_HH
#define NODE_HH


class Node {
    private:
    int position[2];

    public:
    Node(int row, int col);
    Node();

    int getPosition0();
    int getPosition1();

    int say1();

};

#else
class Node;
#endif
