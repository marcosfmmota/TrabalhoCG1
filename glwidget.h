#ifndef GLWIDGET_H
#define GLWIDGET_H

#include <QGLWidget>
#include <vector>
#include "face.h"

using namespace std;

class GLWidget : public QGLWidget
{
  Q_OBJECT
public:
  explicit GLWidget(QGLWidget *parent = 0);

  vector<Face> faces;

  void paintGL();
  void resizeGL(int w, int h);
  void initializeGL();

  void drawModel();

signals:

public slots:

};

#endif // GLWIDGET_H
