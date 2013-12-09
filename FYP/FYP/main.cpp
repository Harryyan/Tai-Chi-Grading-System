#include "ckinectread.h"
#include <QtGui/QApplication>

int main(int argc, char *argv[])
{
	/*COpenNI mOpenNI;
	bool bStatus = true;
	if( !mOpenNI.Initial() )
		return 1;*/

	// Qt Application
	QApplication a(argc, argv);

	//QTextCodec *tc=QTextCodec::codecForName("utf-8");
   // QTextCodec::setCodecForTr(tc);

	//QSplashScreen *splash = new QSplashScreen;  
	//splash->setPixmap(QPixmap("C:/Users/Administrator/Desktop/taichi.jpg"));  
	//splash->show();  

	//for(int i=0;i<360;i++)  
	//{  
   //    splash->repaint();  
	//}

	//splash->showMessage(QObject::tr("hahaha.正在启动中...."),
   // Qt::AlignLeft|Qt::AlignBottom,Qt::green);


	//QGraphicsScene  qScene;

	CKinectRead readKinect;
	readKinect.show();
	//readKinect.initial(mOpenNI,qScene); //User Skeleton
	//readKinect.intialOPenGL(); // Draw the track of one skeleton point
	//splash->finish(&readKinect);  
    //delete splash;  
	return a.exec();
}
