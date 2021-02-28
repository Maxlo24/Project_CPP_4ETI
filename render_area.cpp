#include "render_area.hpp"


#include <QPainter>
#include <QMouseEvent>
#include <QLabel>
#include <QStyle>


#include <iostream>




render_area::render_area(QWidget *parent)
    :QWidget(parent),point_sets(),mouse_point(),is_clicked()
{
    //setBackgroundRole(QPalette::Base);
    //setAutoFillBackground(true);

    init_fig();
}

render_area::~render_area()
{

}


void render_area::init_fig()
{

    std::cout<<"Init geometric figures ..."<<std::endl;


    std::cout<<"Init OK"<<std::endl;

}


void render_area::paintEvent(QPaintEvent*)
{

    //Initialize painters
    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing, true);

    QBrush brush = painter.brush();
    brush.setColor(Qt::red);
    brush.setStyle(Qt::SolidPattern);
    painter.setBrush(brush);

    QPen pen;

    pen.setWidth(1.0);
    pen.setColor(Qt::black);
    painter.setPen(pen);

    painter.drawRect(0,0,200,100);

    painter.drawLine(0,0,mouse_point.x, mouse_point.y);

}




void render_area::mouseMoveEvent(QMouseEvent *event)
{
    mouse_point=vec2(event->x(),event->y());
    repaint();
}

void render_area::mousePressEvent(QMouseEvent *)
{
    is_clicked=true;
    repaint();
}

void render_area::mouseReleaseEvent(QMouseEvent *)
{
    is_clicked=false;
    repaint();
}
