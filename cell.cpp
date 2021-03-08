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

vector<cell*> cell::fourN() const{
    auto N = this->Neighbors;
    // gestion droit : ne renvoyer que les voisins autorisés et dans 4N et pas tout Neighbors
    // selon this->state et voisins.state, ne garder dans N que ceux autorisés
    return N;
}
