#include "bfs_algo.hpp"

BFS_algo::BFS_algo(cell *startPoint) :Algorithm(startPoint)
{
    this->algo_queue.push(this->startPoint);
}


bool BFS_algo::next(){
    bool ret = false;

    cell *currentCell = this->algo_queue.front();
    this->algo_queue.pop();

//    this->currentCell_neighbors = currentCell->fourN();
    map<string,cell*> neighbors = currentCell->fourN();
    for (auto const& [key, val] : neighbors) // C++ 17 !
    {
        if(val->infos()== states::clear){
            this->algo_queue.push(val);
            val->infos()= states::visited;
        }

        if(val->infos()== states::end){
            ret = true;
        }

    }
    if(this->algo_queue.size()==0)
        ret = true;

    return ret;
}
