#include "CSkelItem.h"


void CSkelItem::UpdateSkeleton(){
	// read the 3D position in real world
		XnPoint3D	JointsReal[15];
		JointsReal[ 0] = GetSkeletonPos( XN_SKEL_HEAD			);
		JointsReal[ 1] = GetSkeletonPos( XN_SKEL_NECK			);
		JointsReal[ 2] = GetSkeletonPos( XN_SKEL_TORSO			);
		JointsReal[ 3] = GetSkeletonPos( XN_SKEL_LEFT_SHOULDER	);
		JointsReal[ 4] = GetSkeletonPos( XN_SKEL_LEFT_ELBOW		);
		JointsReal[ 5] = GetSkeletonPos( XN_SKEL_LEFT_HAND		);
		JointsReal[ 6] = GetSkeletonPos( XN_SKEL_RIGHT_SHOULDER	);
		JointsReal[ 7] = GetSkeletonPos( XN_SKEL_RIGHT_ELBOW	);
		JointsReal[ 8] = GetSkeletonPos( XN_SKEL_RIGHT_HAND		);
		JointsReal[ 9] = GetSkeletonPos( XN_SKEL_LEFT_HIP		);
		JointsReal[10] = GetSkeletonPos( XN_SKEL_LEFT_KNEE		);
		JointsReal[11] = GetSkeletonPos( XN_SKEL_LEFT_FOOT		);
		JointsReal[12] = GetSkeletonPos( XN_SKEL_RIGHT_HIP		);
		JointsReal[13] = GetSkeletonPos( XN_SKEL_RIGHT_KNEE		);
		JointsReal[14] = GetSkeletonPos( XN_SKEL_RIGHT_FOOT		);

		// convert form real world to projective
		m_OpenNI.GetDepthGenerator().ConvertRealWorldToProjective( 15, JointsReal, m_aJoints );
}

QRectF CSkelItem::boundingRect() const{
	QRectF qRect( m_aJoints[0].X, m_aJoints[0].Y, 0, 0 );  //a point
		for( unsigned int i = 1; i < 15; ++ i )
		{
			if( m_aJoints[i].X < qRect.left() )
				qRect.setLeft( m_aJoints[i].X );
			if( m_aJoints[i].X > qRect.right() )
				qRect.setRight( m_aJoints[i].X );

			if( m_aJoints[i].Y < qRect.top() )
				qRect.setTop( m_aJoints[i].Y );
			if( m_aJoints[i].Y > qRect.bottom() )
				qRect.setBottom( m_aJoints[i].Y );
		}
		return qRect;
}

void CSkelItem::paint( QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget ){
	// set pen for drawing
		QPen pen( QColor::fromRgb( 0, 0, 255 ) );
		pen.setWidth( 3 );
		painter->setPen( pen );
		
		// draw lines
		for( unsigned int i = 0; i < 15; ++ i )
		{
			XnPoint3D	&p1 = m_aJoints[ m_aConnection[i][0] ],
						&p2 = m_aJoints[ m_aConnection[i][1] ];

			painter->drawLine( p1.X, p1.Y, p2.X, p2.Y );
		}
		
		// draw joints
		for( unsigned int i = 0; i < 15; ++ i )
			painter->drawEllipse( QPointF( m_aJoints[i].X, m_aJoints[i].Y ), 5, 5 );
}

XnPoint3D CSkelItem::GetSkeletonPos( XnSkeletonJoint eJointName ){
		// get position
		XnSkeletonJointPosition mPos;
		m_OpenNI.GetUserGenerator().GetSkeletonCap().GetSkeletonJointPosition( m_UserID, eJointName, mPos );

		// convert to XnPoint3D
		return xnCreatePoint3D( mPos.position.X, mPos.position.Y, mPos.position.Z );
}