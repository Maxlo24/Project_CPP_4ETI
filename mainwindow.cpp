
#include "ui_mainwindow.h"

#include "mainwindow.hpp"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , render(new render_area)
{
    ui->setupUi(this);

    ui->main_Layout->addWidget(render);

}

MainWindow::~MainWindow()
{
    delete ui;
}
