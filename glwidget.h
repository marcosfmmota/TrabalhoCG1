#ifndef GLWIDGET_H
#define GLWIDGET_H

#define WHEEL_COEF = 100;

#include <QGLWidget>
#include <QMouseEvent>
#include <QWheelEvent>
#include <QPoint>
#include <QDebug>
#include <QKeyEvent>
#include <vector>
#include <cmath>
#include "transformationLibrary.h"
#include "objeto.h"

using namespace std;

class GLWidget : public QGLWidget
{
  Q_OBJECT
public:
  explicit GLWidget(QGLWidget *parent = 0);

  vector<Objeto> objetos;
  int width,height;

  Vertice centro;

  void paintGL();
  void resizeGL(int w, int h);
  void initializeGL();

  void mousePressEvent(QMouseEvent *event);
  void mouseMoveEvent(QMouseEvent *event);
  void mouseReleaseEvent(QMouseEvent *event);
  void wheelEvent(QWheelEvent *event);
  void keyPressEvent(QKeyEvent *event);

  void drawModel();
  void refresh();

  void calcular_centro();

  float grab = 0;

  float move[2];
  bool ortho = false;
  bool left_pressed = false;
  bool right_pressed = false;
  bool mid_pressed = false;
signals:

public slots:

};

#endif // GLWIDGET_H
