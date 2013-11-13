#include "CGLWidget.h"
#include <GL/GLU.h>//Ϊ����ʹ��gluPerspective������ӵ�
#include <QKeyEvent>
MyGLWidget::MyGLWidget(QWidget *parent) :
    QGLWidget(parent)
{
    ///////////////////////////////////////////////////////////////
    fullscreen=false;//��ʼ��
}
// ��ʼ������
//����OpenGL��Ⱦ������������ʾ�б�ȡ��ú���ֻ�ڵ�һ�ε���resizeGL()��paintGL()ǰ������һ�Ρ�
void MyGLWidget::initializeGL()
{
    glShadeModel(GL_SMOOTH);
    //������Ӱƽ������������ʹɫ�ʺ͹��ո���ϸ�塣
    glClearColor(0.0,0.0,0.0,0.0);
    //�����Ļʱʹ�õ���ɫ������Ϊ��ɫ��  �����������������Ļ�Ļ� ���һ�����ù���
    glClearDepth(1.0);
    //������Ȼ��档
    glEnable(GL_DEPTH_TEST);
    //������Ȳ��ԣ�������¼ͼ������Ļ�ڵ����ֵ��
    glDepthFunc( GL_LEQUAL );
    //������Ȳ��Ե����͡�
//    ���������б��������ǹ���depth buffer����Ȼ��棩�ġ�����Ȼ�������Ϊ��
//    Ļ����Ĳ㡣��Ȼ��治�ϵĶ����������Ļ�ڲ��ж�����и��١����Ǳ��ڵ�
//    ������ʵû������ʹ����Ȼ��棬��������������Ļ����ʾ3D����OpenGL��
//    ��ʹ����Ȼ��档������������Ǹ������Ȼ����������Ͳ��Ὣһ��Բ�κ���
//    �������λ���Բ����������Ȼ�����OpenGLʮ����Ҫ�Ĳ��֡�
    glHint( GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST );
//    ������ϸ��͸����������һ�и���OpenGL����ϣ��������õ�͸�����������
//    ʮ����΢��Ӱ�����ܡ���ʹ��͸��ͼ��������һ�㡣
}
// �����ӿڴ�С
//����OpenGL���ӿڡ�ͶӰ�ȡ�ÿ�β����ı��Сʱ������øú�����
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
    //����ͶӰ��������Ϊ��������͸�ӡ�
    glLoadIdentity();
    //����ͶӰ�����������Խ�ͶӰ����ָ�����ʼ״̬��
    gluPerspective(45.0,(GLfloat)w/(GLfloat)h,0.1,100.0);
    //����͸��ͶӰ�������������ӽ�Ϊ45�ȣ��ݺ��Ϊ���ڵ��ݺ�ȣ�
    //�����λ��Ϊ0.1����Զ��λ��Ϊ100.0��������ֵ�ǳ��������ܻ��Ƶ���ȵ��ٽ�ֵ��
    //���������������۾��ȽϽ��Ķ����������Ƚϴ󣬶��Ƚ�Զ�Ķ����������ͱȽ�С��
    glMatrixMode(GL_MODELVIEW);
    //����ģ����ͼ����
    glLoadIdentity();
    //����ģ����ͼ����
}

// ��Ⱦ����
//��ȾOpenGL������ÿ��������Ҫ����ʱ������øú�����
void MyGLWidget::paintGL()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    //�����Ļ����Ȼ���
    glLoadIdentity();
    //����ģ����ͼ����

    glLoadIdentity();
    //����ģ����ͼ����
//    ��������glLoadIdentity()֮����ʵ���Ͻ���ǰ���Ƶ�����Ļ���ģ�X�������
//    �����ң�Y������������ϣ�Z������������⡣OpenGL��Ļ���ĵ�����ֵ��
//    X��Y���ϵ�0.0�㡣�������������ֵ�Ǹ�ֵ����������ֵ��������Ļ������
//    ��ֵ��������Ļ�׶��Ǹ�ֵ��������Ļ��Ǹ�ֵ���Ƴ���Ļ������ֵ��
    glTranslatef(-2.0,0.0,-6.0);
//    glTranslatef(x, y, z)����  X, Y ��  Z ���ƶ�������ǰ��Ĵ�������Ĵ�������
//    X������1.5����λ��Y�᲻��(0.0)�����������Ļ6.0����λ��ע����
//    glTranslatef(x, y, z)�е����ƶ���ʱ���������������Ļ�����ƶ������������
//    ��ǰ���ڵ���Ļλ�á�
//    ���������Ѿ��Ƶ�����Ļ����벿�֣����ҽ���ͼ������Ļ�����㹻�ľ����Ա�
//    ���ǿ��Կ���ȫ���ĳ��������������Ρ�
    glBegin( GL_TRIANGLES );
//  ��ʼ���������Ρ�
	glColor3f(1.0, 0.0, 0.0);
    glVertex3f(  0.0,  1.0,  0.0 );
//�϶��㡣
	glColor3f(1.0, 0.0, 0.0);
    glVertex3f( -1.0, -1.0,  0.0 );
//���¶��㡣
	glColor3f(1.0, 0.0, 0.0);
    glVertex3f( 1.0, -1.0, 0.0 );
//���¶��㡣
    glEnd();
//�����λ��ƽ�����
}

//���̰����¼� ����translate, xRot, yRot, zRot;ֵ ʵ��ͼ���ƶ�����ת
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
        updateGL(); //�ػ�
        break;
    case Qt::Key_Escape :
        close();//�ر�
        break;
    }
    updateGL();
    QGLWidget::keyPressEvent(event);
}