/*
Archive: food.h
Author: Diego Fabián Ledesma Motta
email: diego.ledesma@correounivalle.edu.co
*/


#include "item.h"


#ifndef FOOD_HH
#define FOOD_HH


enum foodType {
    grass = 1,
    flower = 3,
    apple = 5
};

class Food : public Item{
   
    private:
    foodType type;

    public:
    Food(line row, line col, foodType _type);

    foodType getType();
    void eaten();
};

#else
class Food;
#endif