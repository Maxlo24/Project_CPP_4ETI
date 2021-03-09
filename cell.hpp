#ifndef CELL_H
#define CELL_H
#include<map>
#include<string>
using std::map;
using std::string;

class cell
{
public:
    cell();
    cell(int etat);

    int infos() const;

    map<string,cell*> fourN() const;

private:
    int state;
    map<string,cell*> Neighbors; // Haut gauche droite bas

    int& infos();
    void addNeighbors(string direction, cell* ptrC);

    friend class render_area;
};

#endif // CELL_H
