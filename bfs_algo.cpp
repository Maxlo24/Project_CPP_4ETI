#include "bfs_algo.hpp"

BFS_algo::BFS_algo(cell startPoint) :Algorithm(startPoint)
{
    algo_queue.empty();
}

void BFS_algo::init_algo(){
    this->algo_queue.push(this->startPoint);
}

bool BFS_algo::next(){
    bool ret = false;

    cell *currentCell = this->algo_queue.front();
    this->algo_queue.pop();

    map<string,cell*> neighbors = currentCell->fourN();

//    map<string,cell*> neighbors = currentCell->fourN();
//    for (auto const& [key, val] : neighbors)
//    {
//        if(val->infos()== states::clear){
//            this->algo_queue.push(val);
//        }
//        val->infos()= states::visited;
//    }

    return ret;
}
