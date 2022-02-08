# Created by and for Qt Creator This file was created for editing the project sources only.
# You may attempt to use it for building too, by modifying this file here.

#TARGET = Projet_CPP_4ETI

QT = core gui widgets

HEADERS = \
   $$PWD/src/mainwindow.hpp \
   $$PWD/src/render_area.hpp \
   $$PWD/src/vec2.hpp \
   $$PWD/src/graph2d.hpp \
   $$PWD/src/cell.hpp \
   $$PWD/src/algorithm.hpp \
   $$PWD/src/bfs_algo.hpp \
   $$PWD/src/dfs_algo.hpp \
   $$PWD/src/dijkstra_algo.hpp \
   $$PWD/src/astar_algo.hpp \
   $$PWD/src/maze_generator.hpp


SOURCES = \
   $$PWD/src/main.cpp \
   $$PWD/src/mainwindow.cpp \
   $$PWD/src/render_area.cpp \
   $$PWD/src/vec2.cpp \
   $$PWD/src/cell.cpp \
   $$PWD/src/algorithm.cpp \
   $$PWD/src/bfs_algo.cpp \
   $$PWD/src/dfs_algo.cpp \
   $$PWD/src/dijkstra_algo.cpp \
   $$PWD/src/astar_algo.cpp \
   $$PWD/src/maze_generator.cpp


FORMS += \
    $$PWD/src/mainwindow.ui

CONFIG += \
    c++17
