#include "knight.h"


Knight::Knight(line row, line col) : Item(row, col){}


void Knight::setPosition(line row, line col){
    setRow(row);
    setCol(col);
    std::cout << "knight position: (" << this->getRow() << ", " 
        << this->getCol() << ")" << std::endl;
}





