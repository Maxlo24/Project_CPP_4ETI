#ifndef CELL_H
#define CELL_H
#include<map>
#include<string>
using std::map;
using std::string;

enum states {clear , start, end , obstacle , visited, perfect_path, border};

class cell
{
public:
    cell();
    cell(states etat);

    //static int ID;

    states infos() const;
    states& infos();

    map<string,cell*> fourN() const;

    void addNeighbors(string direction, cell* ptrC);

    const cell* parent() const;
    cell*& parent();

private:

    states state;
    map<string,cell*> Neighbors; // Haut gauche droite bas

    cell *cell_parent;


//    friend class render_area;
};



#endif // CELL_H
