#include "algorithm.hpp"

Algorithm::Algorithm(cell *sp)
{
    this->startPoint = sp;
<<<<<<< Updated upstream
    this->visitedCell.push_back(&(this->startPoint));
=======
    this->visitedCell.push_back(this->startPoint);
}

Algorithm::~Algorithm(){

>>>>>>> Stashed changes
}
