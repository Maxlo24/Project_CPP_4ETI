#ifndef BFS_ALGO_HPP
#define BFS_ALGO_HPP
#include "algorithm.hpp"

class BFS_algo : public Algorithm
{
public:
    BFS_algo()= default;
    BFS_algo(cell *startPoint);

    //inherited methodes
    bool next();

private :
    queue<cell*> algo_queue;
//    map<string,cell*> currentCell_neighbors;

};

#endif // BFS_ALGO_HPP
