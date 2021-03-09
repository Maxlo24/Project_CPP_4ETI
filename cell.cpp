#include "cell.hpp"

cell::cell(int etat)
{
    this->state = etat;
}

cell::cell()
{
    this->state = 0;
}

int cell::infos() const{
    return this->state;
}

int& cell::infos(){
    return this->state;
}

void cell::addNeighbors(string direction, cell* ptrC) {
    if (direction == "top" || direction == "left" || direction == "right" || direction == "bot") {
        this->Neighbors[direction] = ptrC;
    }
}

map<std::string,cell*> cell::fourN() const{
    auto N = this->Neighbors;
    // gestion droit : ne renvoyer que les voisins autorisés et dans 4N et pas tout Neighbors
    // selon this->state et voisins.state, ne garder dans N que ceux autorisés
    return N;
}
