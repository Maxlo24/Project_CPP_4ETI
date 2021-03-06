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
    this->graph_brush_size = 1;

    vector<int> s = {0,0};
    this->start_point = s;
    this->end_point = s;

    init_fig();
}

render_area::~render_area()
{

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

    std::cout<<"Taille de la grille : "<<this->graph.size()[0]<<"x"<<this->graph.size()[1]<<std::endl;

//    this->end_point = this->graph.size();

//    this->end_point[0] = this->graph.size()[0];
//    this->end_point[1] = this->graph.size()[1];

    this->graph(start_point[0],start_point[1]).infos() = 2;
    this->graph(end_point[0],end_point[1]).infos() = 3;


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
    //painter.drawRect(0,0,dx,dy);


    //painter.drawRect(0,0,200,200);

    //painter.drawLine(0,0,mouse_point.x, mouse_point.y);


}



void render_area::mouseMoveEvent(QMouseEvent *event)
{
    mouse_point=vec2(event->x(),event->y());

    int i = mouse_point.x/dx;
    int j = mouse_point.y/dy;

    if( i>=0 && i < this->graph.size()[0] && j >= 0 &&  j < this->graph.size()[1]){
        if(is_left_clicked){
            brush_paint_cell(i,j,1);
        }
        if (is_right_clicked){
            brush_paint_cell(i,j,0);
        }
    }
    repaint();
}

void render_area::mousePressEvent(QMouseEvent *event)
{
    if(event->button() == Qt::LeftButton){
        is_left_clicked=true;
    }
    if (event->button() == Qt::RightButton){
        is_right_clicked=true;
    }
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

void render_area::update_brush_size(int size){

    this->graph_brush_size = size;
}

void render_area::reset_grid(){
    init_fig();
    repaint();
}

void render_area::brush_paint_cell(int i, int j, int color){
    switch (this->graph_brush_size) {
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
