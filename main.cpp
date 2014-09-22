#include "mainwindow.h"
#include "objeto.h"
#include "arq_tratamento.h"
#include <QApplication>
#include <iostream>
#include <string>
#include <vector>

int main(int argc, char *argv[])
{

  vector<Objeto> objetos;
  vector<Vertice> vertices;

  fileTreatment("/home/marcosf/TrabalhoCG1/mordecai.obj", &objetos, &vertices);

  QApplication a(argc, argv);
  MainWindow w;
  w.w->objetos = objetos;
  w.show();

  return a.exec();
}
