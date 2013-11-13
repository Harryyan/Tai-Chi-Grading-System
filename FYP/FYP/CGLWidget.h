#ifndef MYGLWIDGET_H
#define MYGLWIDGET_H

#include <QGLWidget>

class MyGLWidget : public QGLWidget
{
    Q_OBJECT
public:
    explicit MyGLWidget(QWidget *parent = 0);
    
signals:
    
public slots:
//重写虚函数
public:
    //设置OpenGL渲染环境，定义显示列表等。该函数只在第一次调用resizeGL()或paintGL()前被调用一次。
    void initializeGL();
    //设置OpenGL的视口、投影等。每次部件改变大小时都会调用该函数。
    void resizeGL(int w, int h);
    //渲染OpenGL场景。每当部件需要更新时都会调用该函数。
    void paintGL();
    //键盘按下事件
    void keyPressEvent(QKeyEvent *);

private:
    //是否全屏
    bool fullscreen;
};

#endif // MYGLWIDGET_H