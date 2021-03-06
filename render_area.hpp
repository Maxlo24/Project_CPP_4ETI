#ifndef RENDER_AREA_HPP
#define RENDER_AREA_HPP


#include <QWidget>
#include <QTimer>
#include <QTime>
#include <list>
#include <vector>

#include "graph2d.hpp"
#include "cell.hpp"
#include "vec2.hpp"

using std::vector;

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

    /** Function called in render_area */
    void brush_paint_cell(int i, int j, int color);

private slots:
    void update_grid_size(int size);
    void update_brush_size(int size);
    void reset_grid();


private: //attributes

    graph2D<cell> graph;

    int width;
    int height;

    vector<int> start_point;
    vector<int> end_point;

    int graph_size_select;
    int graph_brush_size;

    int dx;
    int dy;


    /** Storage for all the discrete vertices of the objets that we use to draw them */
    vector<vector<vec2> > point_sets;

    /** The current position of the click of the mouse */
    vec2 mouse_point;
    /** Indicates if the mouse is currently clicked or not */
    bool is_left_clicked;
    bool is_right_clicked;

};
#endif // RENDER_AREA_HPP
