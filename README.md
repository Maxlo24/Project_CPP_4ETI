# Maze Solver C++ Qt
This project is done during our Master degree at CPE Lyon. The goal was to implement different map exploration's algorithms with C++ and a Qt GUI. In our case, by giving the exploration algorithms a starting point, they must find the end and give the shortest path to get there on a grid with obstacles.   
This experience was very enriching, allowing us to implement the various concepts seen in development so far, including OOP and its principles. All of this in a low level language that is powerful and very interesting to handle.

![Our program interface](ExploAlgoMaze.png)

## Installation
*Compilation have been successfully tested on Windows 10 x64 using our .pro file with MinGW64 8.1, Qt5.15.2 & C++17.*   
With QtCreator, you just need to click on the .pro file and select the right Qt version.    
**Must be compiled with QT5 & C++17**

## Implemented algorithms    
- BFS Algorithm    
- DFS Algorithm  
- A* Algorithm    
- Dijkstra Algorithm  

## Files
```
algorithm.cpp  
algorithm.hpp  
astar_algo.cpp  
astar_algo.hpp  
bfs_algo.cpp  
bfs_algo.hpp  
cell.cpp  
cell.hpp  
dfs_algo.cpp  
dfs_algo.hpp  
dijkstra_algo.cpp  
dijkstra_algo.hpp  
graph2d.hpp  
main.cpp  
mainwindow.cpp  
mainwindow.hpp  
mainwindow.ui  
maze_generator.cpp  
maze_generator.hpp  
Project_CPP_4ETI.pro   
README.md  
render_area.cpp  
render_area.hpp  
vec2.cpp  
vec2.hpp
```

## Usage
Set a start and end point (or use default) create a maze, or just draw some obstacles.  
Right Clic to delete a cell.  
Choose an algorithm, add some delay if you want. Launch the algorithm.  
You can relaunch algorithms without clearing the grid.

