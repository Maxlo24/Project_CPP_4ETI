#include <QPainter>
#include <QMouseEvent>
#include <QLabel>
#include <QStyle>
#include <QCursor>

#include "render_area.hpp"

#include <iostream>


render_area::render_area(QWidget *parent)
    :QWidget(parent),point_sets(),mouse_point(),is_left_clicked(),is_right_clicked()
{
    //std::cout<<parent->size().width()<<" "<<parent->size().height();
    //setBackgroundRole(QPalette::Base);
    //setAutoFillBackground(true);

    this->width = this->size().width();
    this->height = this->size().height();

    this->graph_size_select = 1;
    this->graph_brush_type = 1;
    this->graph_brush_size = 1;

    vector<int> s = {0,0};
    this->start_point = s;
    this->end_point = s;

    init_fig();
}

render_area::~render_area()
{

}

void render_area::fillNeighbors() {
    int x = this->graph.size()[0];
    int y = this->graph.size()[1];

    for(int i = 0 ; i < x;i++) {
        for(int j = 0; j< y ; j++) {
            if(j != 0){
                this->graph(i,j).Neighbors.push_back(&(this->graph(i,j-1)));
            }
            else if (i != 0) {
                this->graph(i,j).Neighbors.push_back(&(this->graph(i-1,j)));
            }
            else if (i != x-1) {
                this->graph(i,j).Neighbors.push_back(&(this->graph(i+1,j)));
            }
            else if (j != y-1) {
                this->graph(i,j).Neighbors.push_back(&(this->graph(i,j+1)));
            }
            // TODO Refaire avec une méthode de construction (private dans cell) de Neighbors
            // TODO eventuellement transformer le vector en map
            // TODO eventuellement reflechir à map pour graph car sinon mémoire contigue.
        }
    }
}

void render_area::init_fig()
{
    std::cout<<"Init graph ..."<<std::endl;



    switch (this->graph_size_select) {
        case 1:
                this->graph = graph2D<cell>(12,9);
                break;
        case 2:
                this->graph = graph2D<cell>(20,15);
                break;
        case 3:
                this->graph = graph2D<cell>(40,30);
                break;
        case 4:
                this->graph = graph2D<cell>(80,60);
                break;
    }

    this->fillNeighbors();

    std::cout<<"Taille de la grille : "<<this->graph.size()[0]<<"x"<<this->graph.size()[1]<<std::endl;


    this->dx = this->width / this->graph.size()[0];
    this->dy = this->height / this->graph.size()[1];


    this->setCursor(Qt::CrossCursor);

    std::cout<<"Init OK"<<std::endl;

}


void render_area::paintEvent(QPaintEvent*)
{

    //Initialize painters
    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing, true);

    QBrush brush = painter.brush();
    brush.setColor(Qt::white);
    brush.setStyle(Qt::SolidPattern);
    painter.setBrush(brush);

    QPen pen;

    pen.setWidth(1.0);
    pen.setColor(Qt::gray);
    painter.setPen(pen);

    vector<int> test = {1,2};


    int x = this->graph.size()[0];
    int y = this->graph.size()[1];


    for(int i = 0 ; i < x;i++){
        for(int j = 0; j< y ; j++){

            switch (this->graph(i,j).infos()) {
                case 0:brush.setColor(Qt::white);break;
                case 1:brush.setColor(Qt::black);break;
                case 2:brush.setColor(QColor(181,230,29,255));break;
                case 3:brush.setColor(QColor(250,201,14,255));break;
            }

            painter.setBrush(brush);
            painter.drawRect(i*dx,j*dy,i*dx+dx,j*dy+dy);
        }
    }

}


void render_area::mouseMoveEvent(QMouseEvent *event)
{
    mouse_point=vec2(event->x(),event->y());

    paint();
    repaint();
}

void render_area::mousePressEvent(QMouseEvent *event)
{
    mouse_point=vec2(event->x(),event->y());

    if(event->button() == Qt::LeftButton){
        is_left_clicked=true;
    }
    if (event->button() == Qt::RightButton){
        is_right_clicked=true;
    }
    paint();
    repaint();
}

void render_area::mouseReleaseEvent(QMouseEvent*)
{
    is_left_clicked=false;
    is_right_clicked=false;
    repaint();
}

void render_area::update_grid_size(int i){

    this->graph_size_select = i;
    init_fig();
    repaint();
}

void render_area::update_brush_type(int type){
    this->graph_brush_type = type;
}

void render_area::update_brush_size(int size){

    this->graph_brush_size = size;
}

void render_area::reset_grid(){
    init_fig();
    repaint();
}

void render_area::paint(){
    int i = mouse_point.x/dx;
    int j = mouse_point.y/dy;

    if( i>=0 && i < this->graph.size()[0] && j >= 0 &&  j < this->graph.size()[1]){
        if(is_left_clicked){
            if(this->graph_brush_type == 2){
                brush_paint_cell(this->start_point[0],this->start_point[1],0);
                this->start_point[0]=i;
                this->start_point[1]=j;
            }
            if(this->graph_brush_type == 3){
                brush_paint_cell(this->end_point[0],this->end_point[1],0);
                this->end_point[0]=i;
                this->end_point[1]=j;
            }
            brush_paint_cell(i,j,this->graph_brush_type);
        }
        if (is_right_clicked){
            brush_paint_cell(i,j,0);
        }
    }
}


void render_area::brush_paint_cell(int i, int j, int color){
    int brushSize = this->graph_brush_size;
    if(this->graph_brush_type == 2 || this->graph_brush_type == 3){
        brushSize = 1;
    }
    switch (brushSize) {
        case 3:
            if(i+2 < this->graph.size()[0])
                this->graph(i+2,j).infos() = color;
            if(i-2 >= 0)
                this->graph(i-2,j).infos() = color;
            if(j+2 < this->graph.size()[1])
                this->graph(i,j+2).infos() = color;
            if(j-2 >= 0)
                this->graph(i,j-2).infos() = color;

            if(i+1 < this->graph.size()[0] && j+1 < this->graph.size()[1])
                this->graph(i+1,j+1).infos() = color;
            if(i-1 >= 0 && j+1 < this->graph.size()[1])
                this->graph(i-1,j+1).infos() = color;
            if(i+1 < this->graph.size()[0] && j-1 >= 0)
                this->graph(i+1,j-1).infos() = color;
            if(i-1 >= 0 && j-1 >= 0)
                this->graph(i-1,j-1).infos() = color;

        case 2:
            if(i+1 < this->graph.size()[0])
                this->graph(i+1,j).infos() = color;
            if(i-1 >= 0)
                this->graph(i-1,j).infos() = color;
            if(j+1 < this->graph.size()[1])
                this->graph(i,j+1).infos() = color;
            if(j-1 >= 0)
                this->graph(i,j-1).infos() = color;

        case 1:
            this->graph(i,j).infos() = color;
            break;
    }
}
