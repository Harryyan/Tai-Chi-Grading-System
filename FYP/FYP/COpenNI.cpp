#include "COpenNI.h"

// Standard C++ header
#include <iostream>

using namespace std;

COpenNI::~COpenNI(){
	m_Context.Release();
}

bool COpenNI::Initial(){
	// Initial OpenNI Context
		m_eResult = m_Context.Init();
		if( CheckError( "Context Initial failed" ) )
			return false;

		// create image node
		m_eResult = m_Image.Create( m_Context );
		if( CheckError( "Create Image Generator Error" ) )
			return false;

		// create depth node
		m_eResult = m_Depth.Create( m_Context );
		if( CheckError( "Create Depth Generator Error" ) )
			return false;

		// create user node
		m_eResult = m_User.Create( m_Context );
		if( CheckError( "Create User Generator Error" ) )
			return false;

		// set nodes
		m_eResult = m_Depth.GetAlternativeViewPointCap().SetViewPoint( m_Image );
		CheckError( "Can't set the alternative view point on depth generator" );

		XnCallbackHandle hUserCB;
		m_User.RegisterUserCallbacks( CB_NewUser, NULL, NULL, hUserCB );

		m_User.GetSkeletonCap().SetSkeletonProfile( XN_SKEL_PROFILE_ALL );
		XnCallbackHandle hCalibCB;
		m_User.GetSkeletonCap().RegisterToCalibrationComplete( CB_CalibrationComplete, &m_User, hCalibCB );

		XnCallbackHandle hPoseCB;
		m_User.GetPoseDetectionCap().RegisterToPoseDetected( CB_PoseDetected, &m_User, hPoseCB );

		return true;
}

bool COpenNI::Start(){
	m_eResult = m_Context.StartGeneratingAll();
	return !CheckError( "Start Generating" );
}

bool COpenNI::UpdateData(){
	// update
	//m_eResult = m_Context.WaitNoneUpdateAll();
	m_eResult = m_Context.WaitAndUpdateAll();
	if( CheckError( "Update Data" ) )
		return false;

	// get new data
	m_Depth.GetMetaData( m_DepthMD );
	m_Image.GetMetaData( m_ImageMD );

	return true;
}

bool COpenNI::CheckError(const char* sError){
	if( m_eResult != XN_STATUS_OK )
	{
	  cerr << sError << ": " << xnGetStatusString( m_eResult ) << endl;
	  return true;
	}
	return false;
}