#include "glwidget.h"
#include <vector>

GLWidget::GLWidget(QGLWidget *parent) :
  QGLWidget(parent)
{
}

void GLWidget::paintGL() {
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

  drawModel();

  glBegin(GL_PROJECTION_MATRIX);
  glLoadIdentity();
  //glOrtho(-0.5,0.5,-0.5,0.5,0.5,10000);
  glFrustum(-0.5,0.5,-0.5,0.5,0.5,8);
  glTranslated(0,0,-7);
  glRotated(180,0,1,0);
  glRotated(-30,1,0,0);
  glEnd();

  //glBegin(GL_MODELVIEW_MATRIX);
  glRotated(15,0,1,0);
  glEnd();
}

void GLWidget::resizeGL(int w, int h) {
  int size = qMax(w,h);
  glViewport(-(size-w)/2,-(size-h)/2,size,size);
}

void GLWidget::initializeGL() {
  glClearColor(0,0,0,1);
  glEnable(GL_DEPTH_TEST);
}

void GLWidget::drawModel()
{
  for (unsigned int i = 0; i < faces.size(); i++) {
      Vertice v1 = faces.at(i).vertice[0];
      Vertice v2 = faces.at(i).vertice[1];
      Vertice v3 = faces.at(i).vertice[2];

      glBegin(GL_LINE_LOOP);
      glColor3f(0.4941,0.6156,0.9294);
      glVertex3f(v1.coord[0], v1.coord[1], v1.coord[2]);
      glVertex3f(v2.coord[0], v2.coord[1], v2.coord[2]);
      glVertex3f(v3.coord[0], v3.coord[1], v3.coord[2]);
      glEnd();
  }
}
