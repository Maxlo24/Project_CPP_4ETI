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
    return this->fourNeighbors;
}
