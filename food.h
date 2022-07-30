/*
Archive: food.h
Author: Diego Fabián Ledesma Motta
email: diego.ledesma@correounivalle.edu.co
*/


#include "item.h"


#ifndef FOOD_HH
#define FOOD_HH


enum FoodType {
    grass = 1,
    flower = 3,
    apple = 5
};

class Food : public Item{
   
    private:
    FoodType type;

    public:
    Food(int row, int col, FoodType _type);

    FoodType getType();
};

#else
class Food;
#endif