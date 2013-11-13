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
//��д�麯��
public:
    //����OpenGL��Ⱦ������������ʾ�б�ȡ��ú���ֻ�ڵ�һ�ε���resizeGL()��paintGL()ǰ������һ�Ρ�
    void initializeGL();
    //����OpenGL���ӿڡ�ͶӰ�ȡ�ÿ�β����ı��Сʱ������øú�����
    void resizeGL(int w, int h);
    //��ȾOpenGL������ÿ��������Ҫ����ʱ������øú�����
    void paintGL();
    //���̰����¼�
    void keyPressEvent(QKeyEvent *);

private:
    //�Ƿ�ȫ��
    bool fullscreen;
};

#endif // MYGLWIDGET_H