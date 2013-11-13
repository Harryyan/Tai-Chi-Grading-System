#pragma once
// Standard C++ header
#include <stdlib.h>
#include <iostream>

// OpenNI Header
#include <XnCppWrapper.h>

using namespace std;

class COpenNI
{
public:
	/* Destructor */
	~COpenNI();

	/* Initial OpenNI context and create nodes. */
	bool Initial();

	/* Start to get the data from device */
	bool Start();

	/* Update / Get new data */
	bool UpdateData();

	/* Get User generator */
	xn::UserGenerator& GetUserGenerator()
	{
		return m_User;
	}

	/* Get Depth generator */
	xn::DepthGenerator& GetDepthGenerator()
	{
		return m_Depth;
	}

public:
	xn::DepthMetaData	m_DepthMD;
	xn::ImageMetaData	m_ImageMD;

private:
  /* Check return status m_eResult.
   * return false if the value is XN_STATUS_OK, true for error */
  bool CheckError( const char* sError );


private:
	static void XN_CALLBACK_TYPE CB_NewUser( xn::UserGenerator& generator, XnUserID user, void* pCookie )
	{
		cout << "New user identified: " << user << endl;
		generator.GetPoseDetectionCap().StartPoseDetection("Psi", user);
	}

	static void XN_CALLBACK_TYPE CB_CalibrationComplete( xn::SkeletonCapability& skeleton, XnUserID user, XnCalibrationStatus calibrationError, void* pCookie )
	{
		cout << "Calibration complete for user " <<  user << ", ";
		if( calibrationError == XN_CALIBRATION_STATUS_OK )
		{
			cout << "Success" << endl;
			skeleton.StartTracking( user );
		}
		else
		{
			cout << "Failure" << endl;
			xn::UserGenerator* pUser = (xn::UserGenerator*)pCookie;
			pUser->GetPoseDetectionCap().StartPoseDetection( "Psi", user );
		}
	}

	static void XN_CALLBACK_TYPE CB_PoseDetected( xn::PoseDetectionCapability& poseDetection, const XnChar* strPose, XnUserID user, void* pCookie)
	{
		cout << "Pose " << strPose << " detected for user " <<  user << endl;
		xn::UserGenerator* pUser = (xn::UserGenerator*)pCookie;
		pUser->GetSkeletonCap().RequestCalibration( user, FALSE );
		poseDetection.StopPoseDetection( user );
	}


private:
	XnStatus			m_eResult;
	xn::Context			m_Context;
	xn::DepthGenerator	m_Depth;
	xn::ImageGenerator	m_Image;
	xn::UserGenerator	m_User;
};
