#include "ckinectread.h"
#include <QtGui/QApplication>

int main(int argc, char *argv[])
{
	COpenNI mOpenNI;
	bool bStatus = true;
	if( !mOpenNI.Initial() )
		return 1;

	// Qt Application
	QApplication a(argc, argv);
	QGraphicsScene  qScene;

	CKinectRead readKinect;
	readKinect.show();
	readKinect.initial(mOpenNI,qScene); //User Skeleton
	readKinect.intialOPenGL(); // Draw the track of one skeleton point
	return a.exec();
}
