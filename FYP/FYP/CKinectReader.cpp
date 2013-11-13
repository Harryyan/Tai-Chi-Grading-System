#include "CKinectReader.h"

CKinectReader::~CKinectReader(){
	m_Scene.removeItem( m_pItemImage );
	m_Scene.removeItem( m_pItemDepth );
	delete [] m_pDepthARGB;
}

bool CKinectReader::Start(int iInterval){
	m_OpenNI.Start();

	// add an empty Image to scene
	m_pItemImage = m_Scene.addPixmap( QPixmap() );
	m_pItemImage->setZValue( 1 );

	// add an empty Depth to scene
	m_pItemDepth = m_Scene.addPixmap( QPixmap() );
	m_pItemDepth->setZValue( 2 );

	// update first to get the depth map size
	m_OpenNI.UpdateData();
	m_pDepthARGB = new uchar[4*m_OpenNI.m_DepthMD.XRes()*m_OpenNI.m_DepthMD.YRes()];

	startTimer( iInterval );
	return true;
}

void CKinectReader::timerEvent(QTimerEvent *event){
	// Read OpenNI data
		m_OpenNI.UpdateData();

		// Read Image
		{
			// convert to RGBA format
			const XnDepthPixel*  pDepth = m_OpenNI.m_DepthMD.Data();
			unsigned int iSize=m_OpenNI.m_DepthMD.XRes()*m_OpenNI.m_DepthMD.YRes();

			// fin the max value
			XnDepthPixel tMax = *pDepth;
			for( unsigned int i = 1; i < iSize; ++ i )
			{
				if( pDepth[i] > tMax )
					tMax = pDepth[i];
			}

			// redistribute data to 0-255
			int idx = 0;
			for( unsigned int i = 1; i < iSize; ++ i )
			{
				if( (*pDepth) != 0 )
				{
					m_pDepthARGB[ idx++ ] = 0;									// Blue
					m_pDepthARGB[ idx++ ] = 255 * ( tMax - *pDepth ) / tMax;		// Green
					m_pDepthARGB[ idx++ ] = 255 * *pDepth / tMax;				// Red
					m_pDepthARGB[ idx++ ] = 255 * ( tMax - *pDepth ) / tMax;		// Alpha
				}
				else
				{
					m_pDepthARGB[ idx++ ] = 0;
					m_pDepthARGB[ idx++ ] = 0;
					m_pDepthARGB[ idx++ ] = 0;
					m_pDepthARGB[ idx++ ] = 0;
				}
				++pDepth;
			}

			// Update Depth data
			m_pItemDepth->setPixmap( QPixmap::fromImage( QImage( m_pDepthARGB, m_OpenNI.m_DepthMD.XRes(), m_OpenNI.m_DepthMD.YRes(), QImage::Format_ARGB32 ) ) );

			// Update Image data
			m_pItemImage->setPixmap( QPixmap::fromImage( QImage( m_OpenNI.m_ImageMD.Data(), m_OpenNI.m_ImageMD.XRes(), m_OpenNI.m_ImageMD.YRes(), QImage::Format_RGB888 ) ) );
		}

		// Read Skeleton
		xn::UserGenerator& rUser = m_OpenNI.GetUserGenerator();
		XnUInt16 nUsers = rUser.GetNumberOfUsers();
		if( nUsers > 0 )
		{
			// get user id
			XnUserID* aUserID = new XnUserID[nUsers];
			rUser.GetUsers( aUserID, nUsers );

			// get skeleton for each user
			unsigned int counter = 0;
			xn::SkeletonCapability& rSC = rUser.GetSkeletonCap();
			for( int i = 0; i < nUsers; ++i )
			{
				// if is tracking skeleton
				if( rSC.IsTracking( aUserID[i] ) )
				{
					++counter;
					if( counter > m_vSkeleton.size() )
					{
						// create new skeleton item
						CSkelItem* pSkeleton = new CSkelItem( aUserID[i], m_OpenNI );
						m_Scene.addItem( pSkeleton );
						m_vSkeleton.push_back( pSkeleton );
						pSkeleton->setZValue( 10 );
					}
					else
						m_vSkeleton[ counter-1 ]->m_UserID = aUserID[i];

					// update skeleton item data
					m_vSkeleton[ counter-1 ]->UpdateSkeleton();
					m_vSkeleton[ counter-1 ]->setVisible( true );
				}
			}
			// hide un-used skeleton items
			for( unsigned int i = counter; i < m_vSkeleton.size(); ++ i )
				m_vSkeleton[i]->setVisible( false );

			// release user id area
			delete [] aUserID;
		}
}