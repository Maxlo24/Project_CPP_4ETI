#ifndef ALGORITHM_H
#define ALGORITHM_H
#include "cell.hpp"
#include <vector>
using std::vector;

class Algorithm
{
public:
    Algorithm(cell sp);
private:
    cell startPoint;
    vector<cell*> visitedCell;
};

#endif // ALGORITHM_H
