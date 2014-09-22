#include "glwidget.h"
#include <QMouseEvent>
#include <vector>

GLWidget::GLWidget(QGLWidget *parent) :
  QGLWidget(parent)
{
  move[0] = move[1] = 0;
  left_pressed = right_pressed = mid_pressed = false;
}

void GLWidget::paintGL() {
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

  drawModel();

  qDebug() << "paint";

  glBegin(GL_PROJECTION_MATRIX);
  glLoadIdentity();
  glFrustum(-0.5,0.5,-0.5,0.5,0.5,10000);
  glTranslated(0,grab,0);
  glEnd();
}

void GLWidget::resizeGL(int w, int h) {
  qDebug() << "resize";
  int size = qMax(w,h);
  glViewport(-(size-w)/2,-(size-h)/2,size,size);
}

void GLWidget::initializeGL() {
  glClearColor(0,0,0,1);
  glEnable(GL_DEPTH_TEST);
}

void GLWidget::mousePressEvent(QMouseEvent *event)
{
  move[0] = event->pos().x();
  move[1] = event->pos().y();
  if (event->button() == Qt::LeftButton) {
    cout << "Left" << endl;
    left_pressed = true;
  }
  if (event->button() == Qt::RightButton) {
    cout << "Right" << endl;
    right_pressed = true;
  }
  if (event->button() == Qt::MidButton) {
    cout << "Middle" << endl;
    mid_pressed = true;
  }
  event->accept();
}

void GLWidget::mouseMoveEvent(QMouseEvent *event)
{
  int x,y;
  if (event->pos().x()-move[0] != 0)
    x = (event->pos().x() - move[0])/abs(event->pos().x() - move[0]);
  else x = 0;

  if (event->pos().y() - move[1])
    y = (-1)*(event->pos().y() - move[1])/abs(event->pos().y() - move[1]);
  else y = 0;
  cout << x << "," << y;

  if (left_pressed) {
    cout << " TRANSLATE" << endl;
  }
  if (right_pressed) {
    cout << " ROTATE" << endl;
  }
  if (mid_pressed) {
    cout << " SCALE" << endl;
  }
  paintGL();
}

void GLWidget::mouseReleaseEvent(QMouseEvent *event)
{
  left_pressed = right_pressed = mid_pressed = false;
  cout << "Released" << endl;
}

void GLWidget::wheelEvent(QWheelEvent *event)
{
  event->accept();
  grab = event->delta()/120.0f;
  cout << grab << endl;
  paintGL();
  grab = 0;
  cout << grab << endl;
}

void GLWidget::drawModel()
{
  for (unsigned int i = 0; i < objetos.size(); i++) {
    Objeto o = objetos.at(i);
    for (unsigned int j = 0; j < o.faces.size(); j++) {
        Vertice v1 = o.faces.at(j).vertice[0];
        Vertice v2 = o.faces.at(j).vertice[1];
        Vertice v3 = o.faces.at(j).vertice[2];

        glBegin(GL_LINE_LOOP);
        glColor3f(0.4941,0.6156,0.9294);
        glVertex3f(v1.coord[0], v1.coord[1], v1.coord[2]);
        glVertex3f(v2.coord[0], v2.coord[1], v2.coord[2]);
        glVertex3f(v3.coord[0], v3.coord[1], v3.coord[2]);
        glEnd();
    }
  }
}
