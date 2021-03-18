#include "render_area.hpp"

render_area::render_area(QWidget *parent)
    :QWidget(parent),point_sets(),mouse_point(),is_left_clicked(),is_right_clicked()
{
    this->width = this->size().width();
    this->height = this->size().height();

    this->graph_size_select = 1;
    this->graph_brush_type = states::obstacle;
    this->graph_brush_size = 1;


    this->running = false;
    this->algo_select = 0;
    this->algo_delay = 0;

    init_fig();
}

render_area::~render_area()
{

}

void render_area::init_fig()
{
    std::cout<<"Init graph ..."<<std::endl;

    vector<int> s = {0,0};
    this->start_point = s;

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
    cell border_cell = cell(states::border);
    this->graph.border() = border_cell;
    std::cout<<"Taille de la grille : "<<this->graph.size()[0]<<"x"<<this->graph.size()[1]<<std::endl;


    this->dx = this->width / this->graph.size()[0];
    this->dy = this->height / this->graph.size()[1];

    this->graph(0,0).type() = states::start;
    this->graph(graph.size()[0]-1,graph.size()[1]-1) = states::end;
    this->end_point = {graph.size()[0]-1,graph.size()[1]-1};

    this->fillNeighbors();

    this->setCursor(Qt::CrossCursor);

    std::cout<<"Init OK"<<std::endl;

}

void render_area::fillNeighbors() {
    int x = this->graph.size()[0];
    int y = this->graph.size()[1];

    for(int i = 0 ; i < x;i++) {
        for(int j = 0; j< y ; j++) {
            if(j != 0){
                this->graph(i,j).addNeighbors("top", &(this->graph(i,j-1)));
            }
            else{
                this->graph(i,j).addNeighbors("top", &(this->graph.border()));
            }
            if (i != 0) {
                this->graph(i,j).addNeighbors("left", &(this->graph(i-1,j)));
            }
            else{
                this->graph(i,j).addNeighbors("left", &(this->graph.border()));
            }
            if (i != x-1) {
                this->graph(i,j).addNeighbors("right", &(this->graph(i+1,j)));
            }
            else{
                this->graph(i,j).addNeighbors("right", &(this->graph.border()));
            }
            if (j != y-1) {
                this->graph(i,j).addNeighbors("bot", &(this->graph(i,j+1)));
            }
            else{
                this->graph(i,j).addNeighbors("bot", &(this->graph.border()));
            }
        }
    }

//    map<string,cell*> neighbors = this->graph(x-1,y-1).fourN();
//    std::cout<<neighbors["left"]->Neighbors["right"]->state<<std::endl;
//    for (auto const& [key, val] : neighbors) // C++ 17 !
//    {
//        std::cout<<key<<" "<<val->state<<std::endl;
//    }
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

    int x = this->graph.size()[0];
    int y = this->graph.size()[1];

    for(int i = 0; i < x; i++){
        for(int j = 0; j< y; j++){
            switch (this->graph(i,j).infos()) {
                case states::clear :brush.setColor(Qt::white);break;
                case states::obstacle :brush.setColor(Qt::black);break;
                case states::start :brush.setColor(QColor(181,230,29,255));break;
                case states::end :brush.setColor(QColor(255,91,91,255));break;
                case states::visited :brush.setColor(QColor(200,200,200,255));break;
                case states::perfect_path :brush.setColor(QColor(153,217,234,255));break;
                case states::border :break;
            }

            painter.setBrush(brush);
            painter.drawRect(i*dx,j*dy,i*dx+dx,j*dy+dy);
        }
    }
}

void render_area::generateMaze()
{ // TODO generate maze (and counter)
    int x_size = this->graph.size()[0];
    int y_size = this->graph.size()[1];
    for(int i = 0; i < x_size; i++){
        for(int j = 0; j< y_size; j++){
            this->graph(i,j).type()  = states::obstacle;
        }
    }
    int x_rand = rand() %x_size;
    int y_rand = rand() %y_size;

//    x_rand = 11;
//    y_rand = 7;


    std::cout<<x_rand<<" ; "<<y_rand<<std::endl;

    this->graph(x_rand,y_rand).type() = states::start;
    this->start_point = {x_rand,y_rand};
    maze_generator maze = maze_generator(&(this->graph(start_point[0],start_point[1])));
    maze.generate();

    repaint();
}

void render_area::cleanGrid() {
    int x_size = this->graph.size()[0];
    int y_size = this->graph.size()[1];

    for(int i = 0; i < x_size; i++){
        for(int j = 0; j< y_size; j++){
            if(this->graph(i,j).infos() == states::visited || this->graph(i,j).infos() == states::perfect_path){
               this->graph(i,j).type()  = states::clear;
            }
        }
    }
    repaint();
}

void render_area::launch_algo(){
    this->cleanGrid();

    this->running = true;
    this->setCursor(Qt::ForbiddenCursor);
    std::cout<<"Algo selected : "<<this->algo_select<<std::endl;
    std::cout<<"Searching ..."<<std::endl;

    switch (this->algo_select) {
        case 0:
            {
            BFS_algo algo = BFS_algo(&(this->graph(start_point[0],start_point[1])));
            while (algo.next()==false) {
                repaint();
                Sleep(this->algo_delay);
            }
            break;
            }
        case 1:
            {
            DFS_algo algo2 = DFS_algo(&(this->graph(start_point[0],start_point[1])));
            while (algo2.next()==false) {
                repaint();
                Sleep(this->algo_delay);
            }
            std::cout << algo2.relEnd()[0] << " " << algo2.relEnd()[1] << std::endl;
            if((algo2.relEnd()[0] != 0) || (algo2.relEnd()[1] != 0)) {
                repaint();
                Sleep(2000);
                this->cleanGrid(); // TODO enlever
                std::cout << "A* : " << std::endl;
                ASTAR_algo algo2b = ASTAR_algo(&(this->graph(start_point[0],start_point[1])),algo2.relEnd());
                while (algo2b.next()==false) {
                    repaint();
                    Sleep(this->algo_delay);
                }
            }
            break;
            }
        case 2:{
            Dijkstra_algo algo = Dijkstra_algo(&(this->graph(start_point[0],start_point[1])));
            while (algo.next()==false) {
                repaint();
                Sleep(this->algo_delay);
            }
            break;
        }
    }

    std::cout<<"End"<<std::endl;
    this->running = false;
    this->setCursor(Qt::CrossCursor);
    repaint();
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

void render_area::update_algo_speed(int speed){
    this->algo_delay = 40*(speed-1);
    std::cout<<"Algo delay : "<<this->algo_delay<<std::endl;
}

void render_area::update_brush_type(states type){
    this->graph_brush_type = type;
    std::cout<<"Brush type : "<<this->graph_brush_type<<std::endl;
}

void render_area::update_brush_size(int size){

    this->graph_brush_size = size;
    std::cout<<"Brush size : "<<this->graph_brush_size<<std::endl;
}

void render_area::update_algo_select(int select){
    this->algo_select = select;
    std::cout<<"Algo selected : "<<this->algo_select<<std::endl;
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
            if(this->graph_brush_type == states::start){
                brush_paint_cell(this->start_point[0],this->start_point[1],states::clear);
                this->start_point[0]=i;
                this->start_point[1]=j;
            }
            if(this->graph_brush_type == states::end){
                brush_paint_cell(this->end_point[0],this->end_point[1],states::clear);
                this->end_point[0]=i;
                this->end_point[1]=j;
            }
            brush_paint_cell(i,j,this->graph_brush_type);
        }
        if (is_right_clicked){
            brush_paint_cell(i,j,states::clear);
        }
    }
}


void render_area::brush_paint_cell(int i, int j, states color){
    int brushSize = this->graph_brush_size;
    if(this->graph_brush_type == states::start || this->graph_brush_type == states::end){
        brushSize = 1;
    }
    switch (brushSize) {
        case 3:
            if(i+2 < this->graph.size()[0])
                this->graph(i+2,j).type() = color;
            if(i-2 >= 0)
                this->graph(i-2,j).type() = color;
            if(j+2 < this->graph.size()[1])
                this->graph(i,j+2).type() = color;
            if(j-2 >= 0)
                this->graph(i,j-2).type() = color;

            if(i+1 < this->graph.size()[0] && j+1 < this->graph.size()[1])
                this->graph(i+1,j+1).type() = color;
            if(i-1 >= 0 && j+1 < this->graph.size()[1])
                this->graph(i-1,j+1).type() = color;
            if(i+1 < this->graph.size()[0] && j-1 >= 0)
                this->graph(i+1,j-1).type() = color;
            if(i-1 >= 0 && j-1 >= 0)
                this->graph(i-1,j-1).type() = color;
            [[fallthrough]];
        case 2:
            if(i+1 < this->graph.size()[0])
                this->graph(i+1,j).type() = color;
            if(i-1 >= 0)
                this->graph(i-1,j).type() = color;
            if(j+1 < this->graph.size()[1])
                this->graph(i,j+1).type() = color;
            if(j-1 >= 0)
                this->graph(i,j-1).type() = color;
            [[fallthrough]];
        case 1:
            this->graph(i,j).type() = color;
            break;
    }
}
