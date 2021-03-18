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

    int id() const;
    void setId(int id);

    states infos() const;
    void setInfos(states s);

    map<string,cell*> fourN() const;

    const cell* parent() const;
    cell*& parent();

private:
    int ID;
    states state;
    map<string,cell*> Neighbors; // Haut droite gauche bas

    cell *cell_parent;

    friend class render_area;
    friend class maze_generator;
    states& type();
    void addNeighbors(string direction, cell* ptrC);
};



#endif // CELL_H
