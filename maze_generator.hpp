#ifndef MAZE_GENERATOR_HPP
#define MAZE_GENERATOR_HPP
#include "cell.hpp"
#include <iostream>
#include <stack>
#include <vector>
#include <stdlib.h>

using std::stack;


class maze_generator
{
public:
    maze_generator()= default;
    maze_generator(cell *startPoint);

    //inherited methodes
    bool generate();


private :
    stack<cell*> algo_stack;
};

#endif // MAZE_GENERATOR_HPP
