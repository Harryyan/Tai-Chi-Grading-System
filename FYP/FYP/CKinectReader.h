#pragma once
// Standard C++ header
#include <stdlib.h>
#include <iostream>
#include <vector>
#include "CSkelItem.h"

// Qt Header
#include <QApplication>
#include <QGraphicsView>
#include <QGraphicsScene>
#include <QGraphicsPixmapItem>

#include "COpenNI.h"


// OpenNI Header
#include <XnCppWrapper.h>

using namespace std;

class CKinectReader: public QObject
{
	public:
	/* Constructor */
	CKinectReader( COpenNI& rOpenNI, QGraphicsScene& rScene )
		: m_OpenNI( rOpenNI ), m_Scene( rScene )
	{}

	CKinectReader();

	/* Destructor */
	~CKinectReader();

	bool Start( int iInterval = 33 );


private:
	COpenNI&				m_OpenNI;
	QGraphicsScene&			m_Scene;
	QGraphicsPixmapItem*	m_pItemDepth;
	QGraphicsPixmapItem*	m_pItemImage;
	uchar*					m_pDepthARGB;
	vector<CSkelItem*>		m_vSkeleton;

private:
	void timerEvent( QTimerEvent *event );
};