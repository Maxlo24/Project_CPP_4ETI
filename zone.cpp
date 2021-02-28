#include "zone.hpp"

zone::zone(int etat)
{
    this->information = etat;
}

int zone::etat() const{
    return this->information;
}

int& zone::etat(){
    return this->information;
}
