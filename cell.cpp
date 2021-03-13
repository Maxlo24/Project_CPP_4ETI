#include "cell.hpp"

cell::cell(states etat)
{
    this->state = etat;
}

cell::cell()
{
    this->state = states::clear;
}

states cell::infos() const{
    std::cout << "const const" << std::endl;
    return this->state;
}

states& cell::infos() {
    //std::cout << "normal" << std::endl;
    /*if ((this->state != states::clear) && (this->state != states::visited)) {
        std::cerr << "An algorithm try to cheat" << std::endl;
        throw;
    }*/
    return this->state;
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
