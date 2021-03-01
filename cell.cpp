#include "cell.hpp"

cell::cell(int etat)
{
    this->information = etat;
}

int cell::etat() const{
    return this->information;
}

int& cell::etat(){
    return this->information;
}
