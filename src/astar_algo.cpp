#include "astar_algo.hpp"

ASTAR_algo::ASTAR_algo(cell *startPoint, vector<int> relPos) :Algorithm(startPoint)
{
    this->prioQueue.push(this->startPoint);
    startPoint->setId(0+abs(relPos[0])+abs(relPos[1]));
}

bool ASTAR_algo::next(){
    bool ret = false;

    cell *currentCell = this->prioQueue.top();
    this->prioQueue.pop();

    if(currentCell->infos() == states::clear){
        currentCell->setInfos(states::visited);
    }

    map<string,cell*> neighbors = currentCell->fourN();
    for (auto const& [key, val] : neighbors) // C++ 17 !
    {
        if(val->infos() == states::end){
            val->parent() = currentCell;
            ret = true;
            perfect_path(currentCell);
            break;
        }
        int dist = this->distance(currentCell,val,key);
        int id_val = currentCell->id()-currentCell->normPos()+1+dist;
        if (val->infos() != states::obstacle && val->infos() != states::visited && (id_val < val->id() || val->id() == -1)){
            val->setId(id_val);
            val->parent() = currentCell;
            this->prioQueue.push(val);
        }


    }
    if(this->prioQueue.size()==0)
        ret = true;

    return ret;
}

int ASTAR_algo::distance(cell* a, cell* b, string direction) {
    int dx; int dy;
    if (direction == "top") { dx = 0; dy = -1; }
    else if (direction == "left") { dx = -1; dy = 0; }
    else if (direction == "right") { dx = 1; dy = 0; }
    else { dx = 0; dy = 1; }

    b->setPos(a->relPos()[0]-dx,a->relPos()[1]-dy);

    return abs(b->relPos()[0])+abs(b->relPos()[1]);
}

void ASTAR_algo::perfect_path(cell *last){
    cell *actual_cell = last;

    while (actual_cell->infos() != states::start) {
        actual_cell->setInfos(states::perfect_path);
        actual_cell = actual_cell->parent();
    }
}
