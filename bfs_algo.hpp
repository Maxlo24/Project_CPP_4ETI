#ifndef BFS_ALGO_HPP
#define BFS_ALGO_HPP
#include "algorithm.hpp"
#include <iostream>

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
    void perfect_path(cell *last);
};

#endif // BFS_ALGO_HPP
