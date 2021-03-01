#ifndef CELL_H
#define CELL_H


class cell
{
public:
    cell()=default;
    cell(int etat);

    int etat() const;
    int& etat();

private:
    int information;
};

#endif // CELL_H
