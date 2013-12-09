#include <stdlib.h>
#include <iostream>

#include "ckinectread.h"
bool isRecord = false;
int databaseCount = 0;

CKinectRead::CKinectRead(QWidget *parent, Qt::WFlags flags)
	: QMainWindow(parent, flags)
{
	ui.setupUi(this);
}

CKinectRead::~CKinectRead()
{
	//delete  kReader;
	//delete myItem;
}

void CKinectRead::startRecord(){
	isRecord = true;
}

void CKinectRead::stopRecord(){
	isRecord = false;
}

void CKinectRead::showGrade(){
	qScene.addText("showgrade");
	ui.OpenGLView->setScene(&qScene);
}

void CKinectRead::insert(){
	
	databaseCount++;
	
	qScene.clear();

	if(databaseCount == 1){
		qScene.addText("1");
	}
	else if(databaseCount == 2){
		qScene.addText("2");
	}
	else{
		qScene.addText("more");
	}

	qScene.addText((QString) databaseCount);
	
	ui.OpenGLView->setScene(&qScene);
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