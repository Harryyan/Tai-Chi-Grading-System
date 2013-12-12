#include <stdlib.h>
#include <iostream>

#include "ckinectread.h"
bool isRecord = false;
int databaseCount = 0;

bool qishi_rule1;
bool qishi_rule2;
bool qishi_rule3;
bool qishi_rule4;
bool qishi_rule5;

CKinectRead::CKinectRead(QWidget *parent, Qt::WFlags flags)
	: QMainWindow(parent, flags)
{
	ui.setupUi(this);
	standardItemModel = new QStandardItemModel(this);
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

	double first = grading.QiShi();
	double second = grading.YemaFenZong();
	double third = grading.BaiHeLiangChi();
	double result =  first + second + third - 20.0;

	QStringList list;
	QString str = "The qishi score " + QString("%1").arg(first);
	QString str1 ="The yemafenzong is  " + QString("%1").arg(second);
	QString str2 = "The baiheliangchi is  " +QString("%1").arg(third);
	QString final = "The final score is  " + QString("%1").arg(result);
	
	QStandardItem *item1 = new QStandardItem(str);
	QStandardItem *item2 = new QStandardItem(str1); 
	QStandardItem *item3 = new QStandardItem(str2); 
	QStandardItem *item4 = new QStandardItem(final); 
	standardItemModel->appendRow(item1);
	standardItemModel->appendRow(item2);
	standardItemModel->appendRow(item3);
	standardItemModel->appendRow(item4);
	ui.GradeView->setModel(standardItemModel);
	connect(ui.GradeView,SIGNAL(clicked(QModelIndex)),this,SLOT(itemClicked(QModelIndex)));  
	
	qScene.addText("showgrade");
	ui.OpenGLView->setScene(&qScene);
}

void CKinectRead::itemClicked(QModelIndex index){
	ui.Grade->clear();
	QString str;
	if (index.row() == 0){
		str = index.data().toString() + "\n" + "qishi_rule 1: " + QString("%1").arg(grading.getqishiRule1()) + "  qishi_rule 2: "+ QString("%1").arg(grading.getqishiRule2()) + "  qishi_rule 3: "+ QString("%1").arg(grading.getqishiRule3())\
		+ "\n"+ "qishi_rule 4: "+ QString("%1").arg(grading.getqishiRule4()) + "  qishi_rule 5: "+ QString("%1").arg(grading.getqishiRule5());
	}
	else if(index.row() == 1){
		str = index.data().toString() + "\n" + "yema_rule1: " + QString("%1").arg(grading.getyemaRule1()) + "  yema_rule 2: "+ QString("%1").arg(grading.getyemaRule2()) + "  yema_rule 3: "+ QString("%1").arg(grading.getyemaRule3())\
		+ "  yema_rule 4: "+ QString("%1").arg(grading.getyemaRule4());
	}
	else if( index.row() == 2){

		str = index.data().toString() + "\n" + "baihe_rule 1: " + QString("%1").arg(grading.getbaiheRule1()) + "  baihe_rule 2: "+ QString("%1").arg(grading.getbaiheRule2()) + "  baihe_rule 3: "+ QString("%1").arg(grading.getbaiheRule3())\
		+ "  baihe_rule 4: "+ QString("%1").arg(grading.getbaiheRule4()) + "\n" + "baihe_rule 5: "+ QString("%1").arg(grading.getbaiheRule5())+ "  baihe_rule 6: "+ QString("%1").arg(grading.getbaiheRule6())+ "  baihe_rule 7: "+ QString("%1").arg(grading.getbaiheRule7())+ "  baihe_rule 8: "+ QString("%1").arg(grading.getbaiheRule8());
	}
	else{
		str = "Good";
	}
	QPalette palette = ui.Grade->palette();
	QFont ft;
	ft.setPointSize(16);
	ui.Grade->setFont(ft);

	palette.setColor(QPalette::WindowText,Qt::red);
	ui.Grade->setPalette(palette);
	ui.Grade->setText(str);
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