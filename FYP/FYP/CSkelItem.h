#include <stdlib.h>
#include <iostream>

#include "COpenNI.h"
#include <QtGui/QApplication>
#include <QtGui/QGraphicsView>
#include <QtGui/QGraphicsScene>
#include <QtGui/QGraphicsPixmapItem>

/* Class for draw skeleton */
class CSkelItem : public QGraphicsItem
{
public:
	/* Constructor */
	CSkelItem( XnUserID& uid, COpenNI& rOpenNI ) : QGraphicsItem(), m_UserID( uid ), m_OpenNI( rOpenNI )
	{
		// build lines connection table
		// body and head
		{
			m_aConnection[0][0] = 0;
			m_aConnection[0][1] = 1;

			m_aConnection[1][0] = 1;
			m_aConnection[1][1] = 2;

			m_aConnection[2][0] = 1;
			m_aConnection[2][1] = 3;
		}
		// left hand
		{
			m_aConnection[3][0] = 1;
			m_aConnection[3][1] = 3;

			m_aConnection[4][0] = 3;
			m_aConnection[4][1] = 4;

			m_aConnection[5][0] = 4;
			m_aConnection[5][1] = 5;
		}
		// right hand
		{
			m_aConnection[6][0] = 1;
			m_aConnection[6][1] = 6;

			m_aConnection[7][0] = 6;
			m_aConnection[7][1] = 7;

			m_aConnection[8][0] = 7;
			m_aConnection[8][1] = 8;
		}
		// left leg
		{
			m_aConnection[9][0] = 2;
			m_aConnection[9][1] = 9;

			m_aConnection[10][0] = 9;
			m_aConnection[10][1] = 10;

			m_aConnection[11][0] = 10;
			m_aConnection[11][1] = 11;
		}
		// right leg
		{
			m_aConnection[12][0] = 2;
			m_aConnection[12][1] = 12;

			m_aConnection[13][0] = 12;
			m_aConnection[13][1] = 13;

			m_aConnection[14][0] = 13;
			m_aConnection[14][1] = 14;
		}
	}

	void UpdateSkeleton();

private:
	QRectF boundingRect() const;

	void paint( QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget );

	XnPoint3D GetSkeletonPos( XnSkeletonJoint eJointName );

public:
	COpenNI&	m_OpenNI;
	XnUserID	m_UserID;
	XnPoint3D	m_aJoints[15];  //Fifteen skeleton points in OpenNI
	int			m_aConnection[15][2];  //Store the joint connection in a table
};