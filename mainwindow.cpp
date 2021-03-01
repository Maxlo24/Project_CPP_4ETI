
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
    connect(ui->gridSideSlider,SIGNAL(valueChanged(int)),this->render ,SLOT(update_grid_size(int)));
    connect(ui->resetButton,SIGNAL(clicked()), this->render, SLOT(reset_grid()));
}


MainWindow::~MainWindow()
{
    delete ui;
}
