
#include "ui_mainwindow.h"

#include "mainwindow.hpp"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , render(new render_area)
{
    ui->setupUi(this);

    ui->main_Layout->addWidget(render);

    //Connection with signals

    //slider brush size
    connect(ui->brush_Size_Slider,SIGNAL(valueChanged(int)),this->render ,SLOT(update_brush_size(int)));
    //slider grid size
    connect(ui->gridSideSlider,SIGNAL(valueChanged(int)),this->render ,SLOT(update_grid_size(int)));
    //button reset
    connect(ui->resetButton,SIGNAL(clicked()), this->render, SLOT(reset_grid()));

}


MainWindow::~MainWindow()
{
    delete ui;
}
