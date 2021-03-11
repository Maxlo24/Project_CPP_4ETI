#ifndef BFS_ALGO_HPP
#define BFS_ALGO_HPP
#include "algorithm.hpp"

class BFS_algo : public Algorithm
{
public:
    BFS_algo()= default;
    BFS_algo(cell startPoint);

    //inherited methodes
    void init_algo();
    bool next();

private :
    queue<cell*> algo_queue;

};

#endif // BFS_ALGO_HPP
