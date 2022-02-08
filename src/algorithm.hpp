#ifndef ALGORITHM_H
#define ALGORITHM_H
#include "cell.hpp"
#include <cstdlib>
#include <vector>
#include <queue>
#include <stack>
using std::abs;
using std::vector;
using std::queue;
using std::stack;
using std::priority_queue;

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

protected:
    cell *startPoint;

};

#endif // ALGORITHM_H
