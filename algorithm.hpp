#ifndef ALGORITHM_H
#define ALGORITHM_H
#include "cell.hpp"
#include <vector>
using std::vector;

class Algorithm
{
public:
<<<<<<< Updated upstream
    Algorithm(cell sp);
private:
    cell startPoint;
=======

    //constructor
    Algorithm()=default;
    Algorithm(cell *startPoint);
    ~Algorithm();

    // pure virtual methodes
    virtual bool next()  =0;

protected:
    cell *startPoint;
>>>>>>> Stashed changes
    vector<cell*> visitedCell;
};

#endif // ALGORITHM_H
