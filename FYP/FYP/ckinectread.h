#ifndef CKINECTREAD_H
#define CKINECTREAD_H

#pragma once
#include <QtGui/QMainWindow>
#include "ui_ckinectread.h"
#include "CGLWidget.h"
#include "CMyItem.h"
#include "CKinectReader.h"

// Qt Header
#include <QApplication>
#include <QGraphicsView>
#include <QGraphicsScene>
#include <QGraphicsPixmapItem>

class CKinectRead : public QMainWindow
{
	Q_OBJECT

public:
	CKinectRead(QWidget *parent = 0, Qt::WFlags flags = 0);
	
	~CKinectRead();

	void initial(COpenNI& rOpenNI, QGraphicsScene& rScene){
		ui.userView->setScene(&rScene);
		kReader = new CKinectReader(rOpenNI, rScene);
		kReader->Start();
	};

	void intialOPenGL();

private:
	Ui::CKinectReadClass ui;
	CKinectReader *kReader;
	CMyItem *myItem;
	QGraphicsScene  qScene;

private slots:
    void startRecord(void);
	void stopRecord(void);
	void insert(void);
	void showGrade(void);
};

#endif // CKINECTREAD_H
