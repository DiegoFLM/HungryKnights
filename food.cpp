/*
Archive: food.cpp
Author: Diego Fabián Ledesma Motta
email: diego.ledesma@correounivalle.edu.co
*/

#include "food.h"


Food::Food(line row, line col, foodType _type):Item(row, col){
    type = _type;
}

foodType Food::getType(){
    return type;
}

void Food::eaten(){
    this->takeOut();
}
