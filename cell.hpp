#ifndef CELL_H
#define CELL_H
#include<vector>
using std::vector;

class cell
{
public:
    cell()=default;
    cell(int etat);

    int infos() const;
    int& infos();

private:
    int state;

    //bool initEnd;
    //vector<cell> fourNeighbors; // TODO
};

#endif // CELL_H
