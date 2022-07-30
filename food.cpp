/*
Archive: food.cpp
Author: Diego Fabián Ledesma Motta
email: diego.ledesma@correounivalle.edu.co
*/

#include "food.h"


Food::Food(int row, int col, FoodType _type):Item(row, col){
    type = _type;
}

FoodType Food::getType(){
    return type;
}
