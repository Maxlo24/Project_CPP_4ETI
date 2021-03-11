#ifndef ALGORITHM_H
#define ALGORITHM_H
#include "cell.hpp"
#include <vector>
#include <queue>
using std::vector;
using std::queue;

// Mother class for all algorithm
class Algorithm
{
public:

    //constructor
    Algorithm()=default;
    Algorithm(cell startPoint);
    ~Algorithm();

    // pure virtual methodes
    virtual void init_algo()  =0;
    virtual bool next()  =0;

protected:
    cell *startPoint;
    vector<cell*> visitedCell;

};

#endif // ALGORITHM_H
