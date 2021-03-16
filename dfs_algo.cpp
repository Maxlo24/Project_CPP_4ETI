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
        currentCell->infos() = states::visited;
    }

    map<string,cell*> neighbors = currentCell->fourN();
    for (auto const& [key, val] : neighbors) // C++ 17 !
    {

        if(val->infos() == states::clear){
            val->parent() = currentCell;
            this->algo_stack.push(val);
        }

        if(val->infos() == states::end){ // TODO pas rigoureusement profond mais gagne énormement de temps et ne casse pas gravement l'algorithme
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
        actual_cell->infos() = states::perfect_path;
        actual_cell = actual_cell->parent();
    }
}
