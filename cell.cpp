#include "cell.hpp"

cell::cell(states etat)
{
    this->state = etat;
}

cell::cell()
{
    this->state = states::clear ;
}

states cell::infos() const{
    return this->state;
}

states& cell::infos(){
    return this->state;
}

void cell::addNeighbors(string direction, cell* ptrC) {
    if (direction == "top" || direction == "left" || direction == "right" || direction == "bot") {
        this->Neighbors[direction] = ptrC;
    }
}

map<string,cell*> cell::fourN() const{
    // auto N(this->Neighbors);
    // gestion droit : ne renvoyer que les voisins autorisés et dans 4N et pas tout Neighbors
    // selon this->state et voisins.state, ne garder dans N que ceux autorisés
    // SI this->infos() est wall ALORS renvoyer vide
    return this->Neighbors;
}
