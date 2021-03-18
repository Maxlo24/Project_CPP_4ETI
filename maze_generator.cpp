#include "maze_generator.hpp"

maze_generator::maze_generator(cell *startPoint)
{
    this->algo_stack.push(startPoint);
}

bool maze_generator::generate(){
    bool ret = false;
    bool end_set = false;

    while (!this->algo_stack.empty()) {
        cell *currentCell = this->algo_stack.top();
        this->algo_stack.pop();

        std::vector<cell*> next_cell;
        map<string,cell*> neighbors = currentCell->Neighborshood();

        for (auto const& [key, val] : neighbors) // C++ 17 !
        {

            if(val->type() == states::obstacle){
                map<string,cell*> neighbor_neighbors = val->Neighborshood();
                if(neighbor_neighbors[key]->type() == states::obstacle){
                    val->type() = states::clear;
                    neighbor_neighbors[key]->type()=states::clear;
                    next_cell.push_back(neighbor_neighbors[key]);
                }
            }
        }
        if(next_cell.size() == 0 && end_set==false){
            currentCell->type() = states::end;
            end_set=true;
        }
        while (next_cell.size() != 0) {
            int dir = rand() %next_cell.size();
            this->algo_stack.push(next_cell[dir]);
            next_cell.erase(next_cell.begin()+dir);
        }
    }

    return ret;
}

