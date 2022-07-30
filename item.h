/*
Archive: item.h
Author: Diego Fabián Ledesma Motta
email: diego.ledesma@correounivalle.edu.co
*/

#include <iostream>

#ifndef ITEM_HH
#define ITEM_HH


enum line {
    a, b, c, d, e, f, g, h
};


class Item {
    private:
        line position[2];
        bool onBoard;

    protected:
        //horse
        void setRow(line r);
        void setCol(line c);

        //food
        void takeOut();

    public:
        Item(line row, line col);

        int getRow();
        int getCol();
        bool isOnBoard();

};

#else
class Item;
#endif
