/*
Archive: item.h
Author: Diego Fabián Ledesma Motta
email: diego.ledesma@correounivalle.edu.co
*/



#ifndef ITEM_HH
#define ITEM_HH


class Item {
    private:
        int position[2];
        bool onBoard;

    protected:
        void setRow(int r);
        void setCol(int c);

    public:
        Item(int row, int col);

        int getRow();
        int getCol();
        bool isOnBoard();

};

#else
class Item;
#endif
