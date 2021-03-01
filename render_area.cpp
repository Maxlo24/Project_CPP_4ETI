#include <QPainter>
#include <QMouseEvent>
#include <QLabel>
#include <QStyle>
#include <QCursor>

#include "render_area.hpp"



#include <iostream>




render_area::render_area(QWidget *parent)
    :QWidget(parent),point_sets(),mouse_point(),is_clicked()
{
    //std::cout<<parent->size().width()<<" "<<parent->size().height();
    //setBackgroundRole(QPalette::Base);
    //setAutoFillBackground(true);

    this->longueur = this->size().width();
    this->largeur = this->size().height();

    this->graph_size_select = 1;

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
    }



    this->dx = this->longueur / this->graph.size()[0];
    this->dy = this->largeur / this->graph.size()[1];



    std::cout<<this->longueur<<" "<<this->largeur<<std::endl;

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

            if(this->graph(i,j).etat() == 0){
                brush.setColor(Qt::white);
            }
            if(this->graph(i,j).etat() == 1){
                brush.setColor(Qt::black);
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

    if(i < this->graph.size()[0] &&  j < this->graph.size()[1])
        this->graph(i,j).etat() = 1;

    repaint();
}

void render_area::mousePressEvent(QMouseEvent*)
{
    is_clicked=true;
    repaint();
}

void render_area::mouseReleaseEvent(QMouseEvent*)
{
    is_clicked=false;
    repaint();
}

void render_area::update_grid_size(int i){

    this->graph_size_select = i;
    init_fig();
    repaint();
}

void render_area::reset_grid(){
    init_fig();
    repaint();
}
