#include "cell.hpp"

cell::cell(int etat)
{
    this->state = etat;
    //this->initEnd = false;
}

int cell::infos() const{
    return this->state;
}

int& cell::infos(){
    return this->state;
}
