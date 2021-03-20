#ifndef CELL_H
#define CELL_H
#include<map>
#include<vector>
#include<string>
#include <iostream>
using std::map;
using std::string;
using std::vector;

enum states {clear , start, end , obstacle , visited, perfect_path, border};

class cell
{
public:
    cell();
    cell(states etat);

    //~cell(); // TODO faire les destructeurs et gestion memoire

    int id() const;
    void setId(int id);

    vector<int> relPos() const;
    void setPos(int dx, int dy);
    int normPos(); // norm 1

    states infos() const;
    void setInfos(states s);

    map<string,cell*> fourN() const;

    const cell* parent() const;
    cell*& parent();

private:
    int ID;
    vector<int> relativePosition;
    states state;
    map<string,cell*> Neighbors; // Haut droite gauche bas

    cell *cell_parent;

    friend class render_area;
    friend class maze_generator;
    states& type();
    void addNeighbors(string direction, cell* ptrC);
    map<string,cell*>& Neighborshood();

};



#endif // CELL_H
