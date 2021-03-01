#ifndef CELL_H
#define CELL_H
#include<vector>
using std::vector;

class cell
{
public:
    cell()=default;
    cell(int etat);

    int etat() const;
    int& etat();

private:
    int information;
    //vector<cell> fourNeighbors; // TODO
};

#endif // CELL_H
