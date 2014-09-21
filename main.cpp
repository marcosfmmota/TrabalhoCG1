#include "mainwindow.h"
#include "arq_tratamento.h"
#include "vertice.h"
#include "face.h"

#include <QApplication>
#include <iostream>
#include <string>
#include <vector>

int main(int argc, char *argv[])
{
  vector<Vertice> vertices;
  vector<Face> faces;

  fileTreatment("/home/marcosf/TrabalhoCG1/mordecai.obj", &vertices, &faces);

  for (unsigned int i = 0; i < faces.size(); i++) {
      cout << i+1 << "\n";
      faces.at(i).vertice[0].print();
      faces.at(i).vertice[1].print();
      faces.at(i).vertice[2].print();
      cout << "\n";
  }

  QApplication a(argc, argv);
  MainWindow w;
  w.w->faces = faces;
  w.show();

  return a.exec();
}
