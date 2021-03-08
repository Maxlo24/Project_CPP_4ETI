#ifndef CELL_H
#define CELL_H
#include<vector>
using std::vector;

class cell
{
public:
    cell();
    cell(int etat);

    int infos() const;

    vector<cell*> fourN() const;


private:
    int state;
    vector<cell*> fourNeighbors;

    int& infos();
    friend class render_area;
};

#endif // CELL_H
