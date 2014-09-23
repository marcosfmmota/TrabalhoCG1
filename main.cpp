#include "mainwindow.h"
#include "arq_tratamento.h"
#include "objeto.h"

#include <QApplication>
#include <iostream>
#include <string>
#include <vector>

int main(int argc, char *argv[])
{
  vector<Objeto> objetos;
  vector<Vertice> vertices;

  fileTreatment("/home/marcosf/TrabalhoCG1/house.obj", &objetos, &vertices);

  QApplication a(argc, argv);
  MainWindow w;
  w.w->objetos = objetos;
  w.w->setAcceptDrops(true);
  w.setWindowTitle("Mordecai, a Siriema");
  //QIcon icon("favicon.ico");
  //w.setWindowIcon(icon);
  w.show();

  return a.exec();
}
