#include "bfs_algo.hpp"

BFS_algo::BFS_algo(cell *startPoint) :Algorithm(startPoint)
{
    this->algo_queue.push(this->startPoint);
}


bool BFS_algo::next(){
    bool ret = false;

    cell *currentCell = this->algo_queue.front();
    this->algo_queue.pop();

    map<string,cell*> neighbors = currentCell->fourN();
    for (auto const& [key, val] : neighbors) // C++ 17 !
    {

        if(val->infos() == states::clear){
            val->parent() = currentCell;
            this->algo_queue.push(val);
            val->setInfos(states::visited);
        }

        if(val->infos() == states::end){
            val->parent() = currentCell;
            ret = true;
            perfect_path(val->parent());
        }

    }
    if(this->algo_queue.size()==0)
        ret = true;

    return ret;
}

void BFS_algo::perfect_path(cell *last){

    cell *actual_cell = last;

    while (actual_cell->infos() != states::start) {
        actual_cell->setInfos(states::perfect_path);
        actual_cell = actual_cell->parent();
    }
}
