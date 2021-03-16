#include "dfs_algo.hpp"

DFS_algo::DFS_algo(cell *startPoint) :Algorithm(startPoint)
{
    this->algo_stack.push(this->startPoint);
}


bool DFS_algo::next(){
    bool ret = false;

    cell *currentCell = this->algo_stack.top();
    this->algo_stack.pop();

    if(currentCell->infos() == states::clear){
        currentCell->setInfos(states::visited);
    }

    map<string,cell*> neighbors = currentCell->fourN();
    for (auto const& [key, val] : neighbors) // C++ 17 !
    {

        if(val->infos() == states::clear){
            val->parent() = currentCell;
            this->algo_stack.push(val);
        }

        if(val->infos() == states::end){
            val->parent() = currentCell;
            ret = true;
            perfect_path(val->parent());
        }

    }
    if(this->algo_stack.size()==0)
        ret = true;

    return ret;
}

void DFS_algo::perfect_path(cell *last){

    cell *actual_cell = last;

    while (actual_cell->infos() != states::start) {
        actual_cell->setInfos(states::perfect_path);
        actual_cell = actual_cell->parent();
    }
}
