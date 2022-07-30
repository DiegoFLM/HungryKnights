/*
Archive: knight.h
Author: Diego Fabián Ledesma Motta
email: diego.ledesma@correounivalle.edu.co
*/


#include "item.h"


#ifndef KNIGHT_HH
#define KNIGHT_HH


class Knight : public Item{
   
    public:
    Knight(line row, line col);

    void setPosition(line r, line c);
};

#else
class Knight;
#endif