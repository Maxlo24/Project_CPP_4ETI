#ifndef GRAPH2D_HPP
#define GRAPH2D_HPP
#include <iostream>
#include <vector>

using std::vector;

template<typename T = float>
class graph2D
{
public:
    //constructeur
    graph2D()=default;
    graph2D(int x, int y);

    //Prototypes
    const T& operator()(int i, int j) const;
    T& operator()(int i, int j);

    vector<int> size() const;

private:
   int width;
   int height;
   vector<vector<T>> tableau;

};

template<typename T>
graph2D<T>::graph2D(int x, int y){
    this->width = x;
    this->height = y;

    for(int i = 0; i<this->width; i++)
    {
        vector<T> ligne;
        for(int j = 0; j<this->height; j++)
        {
            T element;
            ligne.push_back(element);
        }
        this->tableau.push_back(ligne);
    }
}

template<typename T>
const T& graph2D<T>::operator()(int i, int j) const{
    if(i<0 || i >= this->width || j<0 || j >= this->height)
        throw std::exception();
    return this->tableau[i][j];
}

template<typename T>
T& graph2D<T>::operator()(int i, int j){
    if(i<0 || i >= this->width || j<0 || j >= this->height)
        throw std::exception();
    return this->tableau[i][j];
}
template<typename T>
vector<int> graph2D<T>::size() const{
    vector<int> vec = {this->width,this->height };
    return vec;
}





#endif // GRAPH2D_HPP
