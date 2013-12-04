#include "CSkelItem.h"

QSqlDatabase dbconn=QSqlDatabase::addDatabase("QSQLITE"); //add database driver

void CSkelItem::UpdateSkeleton(int count,int frame){
		// read the 3D position in real world
		fid = count;   //frame id
		fre = frame;   //frame number
		XnPoint3D	JointsReal[15];
		JointsReal[ 0] = GetSkeletonPos( XN_SKEL_HEAD			);
		JointsReal[ 1] = GetSkeletonPos( XN_SKEL_NECK			);
		JointsReal[ 2] = GetSkeletonPos( XN_SKEL_LEFT_HAND			);
		JointsReal[ 3] = GetSkeletonPos( XN_SKEL_LEFT_ELBOW	);
		JointsReal[ 4] = GetSkeletonPos( XN_SKEL_LEFT_SHOULDER 	);
		JointsReal[ 5] = GetSkeletonPos( XN_SKEL_RIGHT_HAND		);
		JointsReal[ 6] = GetSkeletonPos( XN_SKEL_RIGHT_ELBOW	);
		JointsReal[ 7] = GetSkeletonPos( XN_SKEL_RIGHT_SHOULDER 	);
		JointsReal[ 8] = GetSkeletonPos( XN_SKEL_TORSO		);
		JointsReal[ 9] = GetSkeletonPos( XN_SKEL_LEFT_HIP		);
		JointsReal[10] = GetSkeletonPos( XN_SKEL_LEFT_KNEE		);
		JointsReal[11] = GetSkeletonPos( XN_SKEL_LEFT_FOOT		);
		JointsReal[12] = GetSkeletonPos( XN_SKEL_RIGHT_HIP		);
		JointsReal[13] = GetSkeletonPos( XN_SKEL_RIGHT_KNEE		);
		JointsReal[14] = GetSkeletonPos( XN_SKEL_RIGHT_FOOT		);

		if(isRecord){
			
			dbconn.setDatabaseName("RecordSet.db");  //find database file 

			dbconn.open();

			dbconn.transaction();

			startRecordToDatabase(JointsReal, fid, fre);

			dbconn.commit();

			dbconn.close();
		}
		
		// convert form real world to projective
		m_OpenNI.GetDepthGenerator().ConvertRealWorldToProjective( 15, JointsReal, m_aJoints );	
		
}

void CSkelItem::startRecordToDatabase(XnPoint3D *JointsReal, int nRow, int countFrame){

	QSqlQuery   query;
	
	query.prepare("INSERT INTO tab1 (MID, Frame,Position, X,Y,Z) " 
                  "VALUES (:MID, :Frame, :Position, :X, :Y, :Z)"); 
    query.bindValue(":MID",nRow); 
    query.bindValue(":Frame",countFrame);
	query.bindValue(":Position","head");
	query.bindValue(":X",JointsReal[0].X);
	query.bindValue(":Y",JointsReal[0].Y);
	query.bindValue(":Z",JointsReal[0].Z);
	nRow++;
	query.exec();

	query.prepare("INSERT INTO tab1 (MID, Frame,Position, X,Y,Z) " 
                  "VALUES (:MID, :Frame, :Position, :X,:Y,:Z)"); 
    query.bindValue(":MID",nRow); 
    query.bindValue(":Frame",countFrame);
	query.bindValue(":Position","neck");
	query.bindValue(":X",JointsReal[1].X);
	query.bindValue(":Y",JointsReal[1].Y);
	query.bindValue(":Z",JointsReal[1].Z);
	nRow++;
	query.exec();
	
	query.prepare("INSERT INTO tab1 (MID, Frame,Position, X,Y,Z) " 
                  "VALUES (:MID, :Frame, :Position, :X,:Y,:Z)"); 
    query.bindValue(":MID",nRow); 
    query.bindValue(":Frame",countFrame);
	query.bindValue(":Position","lefthand");
	query.bindValue(":X",JointsReal[2].X);
	query.bindValue(":Y",JointsReal[2].Y);
	query.bindValue(":Z",JointsReal[2].Z);
	nRow++;
	query.exec();

	query.prepare("INSERT INTO tab1 (MID, Frame,Position, X,Y,Z) " 
                  "VALUES (:MID, :Frame, :Position, :X,:Y,:Z)"); 
    query.bindValue(":MID",nRow); 
    query.bindValue(":Frame",countFrame);
	query.bindValue(":Position","leftelbow");
	query.bindValue(":X",JointsReal[3].X);
	query.bindValue(":Y",JointsReal[3].Y);
	query.bindValue(":Z",JointsReal[3].Z);
	nRow++;
	query.exec();

	query.prepare("INSERT INTO tab1 (MID, Frame,Position, X,Y,Z) " 
                  "VALUES (:MID, :Frame, :Position, :X,:Y,:Z)"); 
    query.bindValue(":MID",nRow); 
    query.bindValue(":Frame",countFrame);
	query.bindValue(":Position","leftshoulder");
	query.bindValue(":X",JointsReal[4].X);
	query.bindValue(":Y",JointsReal[4].Y);
	query.bindValue(":Z",JointsReal[4].Z);
	nRow++;
	query.exec();

	query.prepare("INSERT INTO tab1 (MID, Frame,Position, X,Y,Z) " 
                  "VALUES (:MID, :Frame, :Position, :X,:Y,:Z)"); 
    query.bindValue(":MID",nRow); 
    query.bindValue(":Frame",countFrame);
	query.bindValue(":Position","righthand");
	query.bindValue(":X",JointsReal[5].X);
	query.bindValue(":Y",JointsReal[5].Y);
	query.bindValue(":Z",JointsReal[5].Z);
	nRow++;
	query.exec();

	query.prepare("INSERT INTO tab1 (MID, Frame,Position, X,Y,Z) " 
                  "VALUES (:MID, :Frame, :Position, :X,:Y,:Z)"); 
    query.bindValue(":MID",nRow); 
    query.bindValue(":Frame",countFrame);
	query.bindValue(":Position","rightelbow");
	query.bindValue(":X",JointsReal[6].X);
	query.bindValue(":Y",JointsReal[6].Y);
	query.bindValue(":Z",JointsReal[6].Z);
	nRow++;
	query.exec();

	query.prepare("INSERT INTO tab1 (MID, Frame,Position, X,Y,Z) " 
                  "VALUES (:MID, :Frame, :Position, :X,:Y,:Z)"); 
    query.bindValue(":MID",nRow); 
    query.bindValue(":Frame",countFrame);
	query.bindValue(":Position","rightshoulder");
	query.bindValue(":X",JointsReal[7].X);
	query.bindValue(":Y",JointsReal[7].Y);
	query.bindValue(":Z",JointsReal[7].Z);
	nRow++;
	query.exec();

	query.prepare("INSERT INTO tab1 (MID, Frame,Position, X,Y,Z) " 
                  "VALUES (:MID, :Frame, :Position, :X,:Y,:Z)"); 
    query.bindValue(":MID",nRow); 
    query.bindValue(":Frame",countFrame);
	query.bindValue(":Position","torso");
	query.bindValue(":X",JointsReal[8].X);
	query.bindValue(":Y",JointsReal[8].Y);
	query.bindValue(":Z",JointsReal[8].Z);
	nRow++;
	query.exec();

	query.prepare("INSERT INTO tab1 (MID, Frame,Position, X,Y,Z) " 
                  "VALUES (:MID, :Frame, :Position, :X,:Y,:Z)"); 
    query.bindValue(":MID",nRow); 
    query.bindValue(":Frame",countFrame);
	query.bindValue(":Position","lefthip");
	query.bindValue(":X",JointsReal[9].X);
	query.bindValue(":Y",JointsReal[9].Y);
	query.bindValue(":Z",JointsReal[9].Z);
	nRow++;
	query.exec();

	query.prepare("INSERT INTO tab1 (MID, Frame,Position, X,Y,Z) " 
                  "VALUES (:MID, :Frame, :Position, :X,:Y,:Z)"); 
    query.bindValue(":MID",nRow); 
    query.bindValue(":Frame",countFrame);
	query.bindValue(":Position","leftknee");
	query.bindValue(":X",JointsReal[10].X);
	query.bindValue(":Y",JointsReal[10].Y);
	query.bindValue(":Z",JointsReal[10].Z);
	nRow++;
	query.exec();

	query.prepare("INSERT INTO tab1 (MID, Frame,Position, X,Y,Z) " 
                  "VALUES (:MID, :Frame, :Position, :X,:Y,:Z)"); 
    query.bindValue(":MID",nRow); 
    query.bindValue(":Frame",countFrame);
	query.bindValue(":Position","leftfoot");
	query.bindValue(":X",JointsReal[11].X);
	query.bindValue(":Y",JointsReal[11].Y);
	query.bindValue(":Z",JointsReal[11].Z);
	nRow++;
	query.exec();

	query.prepare("INSERT INTO tab1 (MID, Frame,Position, X,Y,Z) " 
                  "VALUES (:MID, :Frame, :Position, :X,:Y,:Z)"); 
    query.bindValue(":MID",nRow); 
    query.bindValue(":Frame",countFrame);
	query.bindValue(":Position","righthip");
	query.bindValue(":X",JointsReal[12].X);
	query.bindValue(":Y",JointsReal[12].Y);
	query.bindValue(":Z",JointsReal[12].Z);
	nRow++;
	query.exec();

	query.prepare("INSERT INTO tab1 (MID, Frame,Position, X,Y,Z) " 
                  "VALUES (:MID, :Frame, :Position, :X,:Y,:Z)"); 
    query.bindValue(":MID",nRow); 
    query.bindValue(":Frame",countFrame);
	query.bindValue(":Position","rightknee");
	query.bindValue(":X",JointsReal[13].X);
	query.bindValue(":Y",JointsReal[13].Y);
	query.bindValue(":Z",JointsReal[13].Z);
	nRow++;
	query.exec();

	query.prepare("INSERT INTO tab1 (MID, Frame,Position, X,Y,Z) " 
                  "VALUES (:MID, :Frame, :Position, :X,:Y,:Z)"); 
    query.bindValue(":MID",nRow); 
    query.bindValue(":Frame",countFrame);
	query.bindValue(":Position","rightfoot");
	query.bindValue(":X",JointsReal[14].X);
	query.bindValue(":Y",JointsReal[14].Y);
	query.bindValue(":Z",JointsReal[14].Z);
	nRow++;
	query.exec();

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
		QPen pen( QColor::fromRgb( 0, 255, 0 ) );
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