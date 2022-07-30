/*
Archive: horse.h
Author: Diego Fabián Ledesma Motta
email: diego.ledesma@correounivalle.edu.co
*/


#include "item.h"


#ifndef HORSE_HH
#define HORSE_HH


class Horse : public Item{
   
    public:
    Horse(int row, int col);

    void setPosition(int r, int c);

};

#else
class Horse;
#endif