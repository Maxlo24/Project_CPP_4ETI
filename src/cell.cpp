#include "cell.hpp"

cell::cell(states etat)
{
    this->state = etat;
    this->relativePosition.push_back(0);
    this->relativePosition.push_back(0);
    this->ID = -1;
}

cell::cell() : cell(states::clear) {}

// Id getter
int cell::id() const{
    return this->ID;
}

// Id setter
void cell::setId(int id){
    this->ID = id;
}

states cell::infos() const{
    return this->state;
}

void cell::setInfos(states s) {
    if ((this->state != states::clear) && (this->state != states::visited)) {
        std::cerr << "An algorithm try to cheat" << std::endl;
        throw;
    }
    if ((s != states::visited) && (s != states::perfect_path)) {
        std::cerr << "Invalid set argument" << std::endl;
        throw;
    }
    this->state = s;
}

vector<int> cell::relPos() const {
    return this->relativePosition;
}

void cell::setPos(int dx, int dy) {
    this->relativePosition[0] = dx;
    this->relativePosition[1] = dy;
}

int cell::normPos() {
    return abs(this->relativePosition[0])+abs(this->relativePosition[1]);
}

void cell::addNeighbors(string direction, cell* ptrC) {
    if (direction == "top" || direction == "left" || direction == "right" || direction == "bot") {
        this->Neighbors[direction] = ptrC;
    }
}

map<string,cell*> cell::fourN() const{
    if (this->state == states::obstacle) {
        std::cerr << "An algorithm try to cheat" << std::endl;
        throw;
    }
    return this->Neighbors;
}

const cell* cell::parent() const{
    return this->cell_parent;
}

cell*& cell::parent(){
    return this->cell_parent;
}

states& cell::type() {
    return this->state;
}

map<string,cell*>& cell::Neighborshood() {
    return this->Neighbors;
}
