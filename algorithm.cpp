#include "algorithm.hpp"

Algorithm::Algorithm(cell sp)
{
    this->startPoint = sp;
    this->visitedCell.push_back(&(this->startPoint));
}
