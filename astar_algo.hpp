#ifndef ASTAR_ALGO_HPP
#define ASTAR_ALGO_HPP
#include "algorithm.hpp"
#include <iostream>

struct Compare2 {
  bool operator()(cell*a,cell*b) {
      if (a->id() < b->id() && a->id() != -1) {
          return false;
      }
      else if (b->id() < a->id() && b->id() != -1) {
          return true;
      }
      else {
          return a->relPos()>b->relPos();
      }
  }
};

class ASTAR_algo : public Algorithm
{
public:
    ASTAR_algo()= default;
    ASTAR_algo(cell *startPoint, vector<int> relPos);

    //inherited methodes
    bool next();


private :
    std::priority_queue<cell*, std::vector<cell*>,Compare2> prioQueue;
    void perfect_path(cell *last);
    int distance(cell* a, cell* b, string direction); // norm 1
};

#endif // ASTAR_ALGO_HPP
