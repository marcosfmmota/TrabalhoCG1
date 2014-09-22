#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "glwidget.h"

MainWindow::MainWindow(QWidget *parent) :
  QMainWindow(parent),
  ui(new Ui::MainWindow)
{
  ui->setupUi(this);

  w = new GLWidget();
  setCentralWidget(w);

  w->setMouseTracking(false);
}

MainWindow::~MainWindow()
{
  delete ui;
}
