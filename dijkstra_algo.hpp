#ifndef DIJKSTRA_ALGO_HPP
#define DIJKSTRA_ALGO_HPP
#include "algorithm.hpp"
#include <iostream>
#include <vector>

struct Compare {
  bool operator()(cell*a,cell*b) {
      return a->id() > b->id();
  }
};

class Dijkstra_algo : public Algorithm
{
public:
    Dijkstra_algo();
    Dijkstra_algo(cell *startPoint);

    //inherited methodes
    bool next();


private:

    std::priority_queue<cell*, std::vector<cell*>,Compare> algo_queue;
    void perfect_path(cell *last);
};

#endif // DIJKSTRA_ALGO_HPP
