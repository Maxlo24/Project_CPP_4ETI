#ifndef RENDER_AREA_HPP
#define RENDER_AREA_HPP


#include <QWidget>
#include <QTimer>
#include <QTime>
#include <list>

#include "graph2d.hpp"
#include "zone.hpp"
#include "vec2.hpp"

//forward declaration of QLabel
class QLabel;



class render_area : public QWidget
{
    Q_OBJECT
public:

    render_area(QWidget *parent = 0);
    ~render_area();

    void init_fig();


protected:
    /** Actual drawing function */
    void paintEvent(QPaintEvent *event);

    /** Function called when the mouse is pressed */
    void mousePressEvent(QMouseEvent *event);
    /** Function called when the mouse is moved */
    void mouseMoveEvent(QMouseEvent *event);
    /** Function called when the mouse is released */
    void mouseReleaseEvent(QMouseEvent *event);

private slots:
    void update_grid_size(int i);
    void reset_grid();


private: //attributes

    graph2D<zone> graph;

    int longueur;
    int largeur;

    int graph_size_select;

    int dx;
    int dy;

    /** Storage for all the discrete vertices of the objets that we use to draw them */
    std::vector<std::vector<vec2> > point_sets;

    /** The current position of the click of the mouse */
    vec2 mouse_point;
    /** Indicates if the mouse is currently clicked or not */
    bool is_clicked;

};
#endif // RENDER_AREA_HPP
