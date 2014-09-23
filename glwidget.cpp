#include "glwidget.h"

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
  if(ortho) glOrtho(-0.5,0.5,-0.5,0.5,0.5,1000000);
  if(!ortho) glFrustum(-0.5,0.5,-0.5,0.5,0.5,1000000);
  glEnd();
}

void GLWidget::resizeGL(int w, int h) {
  qDebug() << "resize";
  width = w;
  height = h;
  int size = qMax(w,h);
  glViewport(-(size-w)/2,-(size-h)/2,size,size);
}

void GLWidget::initializeGL() {
  glClearColor(0,0,0,1);
  glEnable(GL_DEPTH_TEST);
}

void GLWidget::keyPressEvent(QKeyEvent *event) {
  cout << event->key();
  if (event->key() == Qt::Key_O) {
    ortho = true;
    cout << "o";
  }
  if (event->key() == Qt::Key_P) {
    ortho = false;
    cout << "p";
  }
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
  float x,y;
  if (abs(event->pos().x()-move[0]) >= 50)
    x = (event->pos().x() - move[0])/abs(event->pos().x() - move[0]);
  else x = 0;

  if (abs(event->pos().y() - move[1]) >= 50)
    y = (-1)*(event->pos().y() - move[1])/abs(event->pos().y() - move[1]);
  else y = 0;
  cout << x << "," << y;

  if (left_pressed) {
    cout << " TRANSLATE" << endl;    
    transfTranslate(x/100,y/100,0,&objetos);
  }
  if (right_pressed) {
    cout << " ROTATE" << endl;
    calcular_centro();
    transfTranslate(-centro.coord[0],-centro.coord[1],-centro.coord[2],&objetos);
    transfRotate(0.001*y,1,0,0,&objetos);
    transfRotate(-0.001*x,0,1,0,&objetos);
    transfTranslate(centro.coord[0],centro.coord[1],centro.coord[2],&objetos);
  }
  if (mid_pressed) {
    cout << " SCALE" << endl;
    calcular_centro();
    transfTranslate(-centro.coord[0],-centro.coord[1],-centro.coord[2],&objetos);
    transfRotate(0.001*y,0,0,1,&objetos);
    transfTranslate(centro.coord[0],centro.coord[1],centro.coord[2],&objetos);
  }
  refresh();
}

void GLWidget::mouseReleaseEvent(QMouseEvent *event)
{
  left_pressed = right_pressed = mid_pressed = false;
  cout << "Released" << endl;
  refresh();
}

void GLWidget::wheelEvent(QWheelEvent *event)
{
  event->accept();
  grab = event->delta()/100.0f;
  cout << grab << endl;

  if (grab > 0) {
      transfScale(grab,grab,1,&objetos);
  } else {
      grab = -1/grab;
      transfScale(grab,grab,1,&objetos);
  }

  transfScale(grab,grab,grab,&objetos);
  refresh();
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

void GLWidget::refresh()
{
  updateGL();
  paintGL();
  resizeGL(width, height);
}

void GLWidget::calcular_centro()
{
  float x = 0, y = 0, z = 0;
  for (int i = 0; i < objetos.size(); i++) {
    Vertice v = objetos.at(i).calcular_centro();
    x = v.coord[0];
    y = v.coord[1];
    z = v.coord[2];
  }
  centro.coord[0] = x/objetos.size();
  centro.coord[1] = y/objetos.size();
  centro.coord[2] = z/objetos.size();
}
