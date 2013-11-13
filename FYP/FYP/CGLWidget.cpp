#include "CGLWidget.h"
#include <GL/GLU.h>//为了能使用gluPerspective函数添加的
#include <QKeyEvent>
MyGLWidget::MyGLWidget(QWidget *parent) :
    QGLWidget(parent)
{
    ///////////////////////////////////////////////////////////////
    fullscreen=false;//初始化
}
// 初始化环境
//设置OpenGL渲染环境，定义显示列表等。该函数只在第一次调用resizeGL()或paintGL()前被调用一次。
void MyGLWidget::initializeGL()
{
    glShadeModel(GL_SMOOTH);
    //设置阴影平滑，这样可以使色彩和光照更加细腻。
    glClearColor(0.0,0.0,0.0,0.0);
    //清除屏幕时使用的颜色，这里为黑色。  当我们用其来清除屏幕的话 最后一个不用关心
    glClearDepth(1.0);
    //设置深度缓存。
    glEnable(GL_DEPTH_TEST);
    //启用深度测试，用来记录图形在屏幕内的深度值。
    glDepthFunc( GL_LEQUAL );
    //所作深度测试的类型。
//    上面这三行必须做的是关于depth buffer（深度缓存）的。将深度缓存设想为屏
//    幕后面的层。深度缓存不断的对物体进入屏幕内部有多深进行跟踪。我们本节的
//    程序其实没有真正使用深度缓存，但几乎所有在屏幕上显示3D场景OpenGL程
//    序都使用深度缓存。它的排序决定那个物体先画。这样您就不会将一个圆形后面
//    的正方形画到圆形上来。深度缓存是OpenGL十分重要的部分。
    glHint( GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST );
//    真正精细的透视修正。这一行告诉OpenGL我们希望进行最好的透视修正。这会
//    十分轻微的影响性能。但使得透视图看起来好一点。
}
// 调整视口大小
//设置OpenGL的视口、投影等。每次部件改变大小时都会调用该函数。
void MyGLWidget::resizeGL(int w, int h)
{

	GLdouble width = GLdouble( w );
    GLdouble height = GLdouble( h );
    static GLdouble s_AspectRatio = 16.0 / 9.0;
    GLdouble aspectRatio = width / height;

    if ( aspectRatio < s_AspectRatio )
    {
        GLint smallHeight = GLint( width / s_AspectRatio );
        GLint heightBlank = ( GLint( height ) - smallHeight ) / 2;
        glViewport( 0, heightBlank, GLint( width ), smallHeight );
    }
    else
    {
        GLint smallWidth = GLint( height * s_AspectRatio );
        GLint widthBlank = ( GLint( width ) - smallWidth ) / 2;
        glViewport( widthBlank, 0, smallWidth, GLint( height ) );
    }

    glMatrixMode(GL_PROJECTION);
    //设置投影矩阵，用来为场景增加透视。
    glLoadIdentity();
    //重置投影矩阵，这样可以将投影矩阵恢复到初始状态。
    gluPerspective(45.0,(GLfloat)w/(GLfloat)h,0.1,100.0);
    //设置透视投影矩阵，这里设置视角为45度，纵横比为窗口的纵横比，
    //最近的位置为0.1，最远的位置为100.0，这两个值是场景中所能绘制的深度的临界值。
    //可以想象，离我们眼睛比较近的东西看起来比较大，而比较远的东西看起来就比较小。
    glMatrixMode(GL_MODELVIEW);
    //设置模型视图矩阵。
    glLoadIdentity();
    //重置模型视图矩阵
}

// 渲染场景
//渲染OpenGL场景。每当部件需要更新时都会调用该函数。
void MyGLWidget::paintGL()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    //清除屏幕和深度缓存
    glLoadIdentity();
    //重置模型视图矩阵

    glLoadIdentity();
    //重置模型视图矩阵
//    当您调用glLoadIdentity()之后，您实际上将当前点移到了屏幕中心，X坐标轴从
//    左至右，Y坐标轴从下至上，Z坐标轴从里至外。OpenGL屏幕中心的坐标值是
//    X和Y轴上的0.0点。中心左面的坐标值是负值，右面是正值。移向屏幕顶端是
//    正值，移向屏幕底端是负值。移入屏幕深处是负值，移出屏幕则是正值。
    glTranslatef(-2.0,0.0,-6.0);
//    glTranslatef(x, y, z)沿着  X, Y 和  Z 轴移动。根据前面的次序，下面的代码沿着
//    X轴左移1.5个单位，Y轴不动(0.0)，最后移入屏幕6.0个单位。注意在
//    glTranslatef(x, y, z)中当您移动的时候，您并不是相对屏幕中心移动，而是相对与
//    当前所在的屏幕位置。
//    现在我们已经移到了屏幕的左半部分，并且将视图推入屏幕背后足够的距离以便
//    我们可以看见全部的场景－创建三角形。
    glBegin( GL_TRIANGLES );
//  开始绘制三角形。
	glColor3f(1.0, 0.0, 0.0);
    glVertex3f(  0.0,  1.0,  0.0 );
//上顶点。
	glColor3f(1.0, 0.0, 0.0);
    glVertex3f( -1.0, -1.0,  0.0 );
//左下顶点。
	glColor3f(1.0, 0.0, 0.0);
    glVertex3f( 1.0, -1.0, 0.0 );
//右下顶点。
    glEnd();
//三角形绘制结束。
}

//键盘按下事件 更改translate, xRot, yRot, zRot;值 实现图形移动与旋转
void MyGLWidget::keyPressEvent(QKeyEvent *event)
{
    switch (event->key())
    {
    case Qt::Key_F2 :
        fullscreen = !fullscreen;
        if ( fullscreen )
        {
          showFullScreen();
        }
        else
        {
          showNormal();
          setGeometry( 300, 200, 640, 480 );
        }
        updateGL(); //重绘
        break;
    case Qt::Key_Escape :
        close();//关闭
        break;
    }
    updateGL();
    QGLWidget::keyPressEvent(event);
}