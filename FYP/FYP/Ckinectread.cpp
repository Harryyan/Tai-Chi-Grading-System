#include <stdlib.h>
#include <iostream>

#include "ckinectread.h"
bool isRecord = false;

CKinectRead::CKinectRead(QWidget *parent, Qt::WFlags flags)
	: QMainWindow(parent, flags)
{
	ui.setupUi(this);
}

CKinectRead::~CKinectRead()
{
	delete  kReader;
	//delete myItem;
}

void CKinectRead::startRecord(){
	isRecord = true;
}

void CKinectRead::stopRecord(){
	isRecord = false;
}

void CKinectRead::intialOPenGL(){

	//myGLwidget->resizeGL(100,100);
	//qScene.addWidget(myGLwidget);
	//ui.OpenGLView->setScene(&qScene);
	//ui.OpenGLView->setViewport(myGLwidget);
	//ui.OpenGLView->setViewportUpdateMode(QGraphicsView::FullViewportUpdate);
	//myGLwidget->show();
	//ui.Qwidget = myGLwidget;
	//ui.Qwidget->show();
	//ui.OpenGLView->show();

	myItem = new CMyItem(0,0);
	qScene.addItem(myItem);
	ui.OpenGLView->setScene(&qScene);
	ui.OpenGLView->show();
}