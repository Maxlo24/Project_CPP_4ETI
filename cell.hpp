#ifndef CELL_H
#define CELL_H
#include<map>
#include<string>
#include <iostream>
using std::map;
using std::string;

enum states {clear , start, end , obstacle , visited, perfect_path, border};

class cell
{
public:
    cell();
    cell(states etat);

    //~cell(); // TODO faire les destructeurs et gestion memoire

    states infos() const;
    void setInfos(states s);

    map<string,cell*> fourN() const;

    const cell* parent() const;
    cell*& parent();

private:

    states state;
    map<string,cell*> Neighbors; // Haut droite gauche bas

    cell *cell_parent;

    friend class render_area;
    states& type();
    void addNeighbors(string direction, cell* ptrC);
};



#endif // CELL_H
