#ifndef ALGORITHM_H
#define ALGORITHM_H
#include "cell.hpp"
#include <queue>
#include <stack>
using std::queue;
using std::stack;

// Mother class for all algorithm
class Algorithm
{
public:

    //constructor
    Algorithm()=default;
    Algorithm(cell *startPoint);
    ~Algorithm();

    // pure virtual methodes
    virtual bool next()  =0;
    // TODO interruption

protected:
    cell *startPoint;

};

#endif // ALGORITHM_H
