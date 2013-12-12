#include "GradingRules.h"

double totalscore=10;//QiShi
double max_left=0;
double max_right=0;
double min_left=0;
double min_right=0;

double baihe_max; //YeMaFenZong
double baihe_min;


double GradingRules::QiShi(){
	
	NODE head,neck,torso;
	NODE hand_right,elbow_right,shoulder_right,hip_right,knee_right,foot_right;
	NODE hand_left,elbow_left,shoulder_left,hip_left,knee_left,foot_left;
	NODE prehand_left,prehand_right,prehip_left,prehip_right;

	bool one="false";
	bool two="false";
	bool three="false";
	bool four="false";
	bool five="false";

	qishi_rule11 = 0;
	qishi_rule22 = 0;
	qishi_rule33 = 0;
	qishi_rule44 = 0;
	qishi_rule55 = 0;

	QSqlDatabase dbconn=QSqlDatabase::addDatabase("QSQLITE"); //add database driver
	dbconn.setDatabaseName("test.db");
	
	dbconn.open();

	QSqlQuery query;

	double x,y,z;
	
	//rule1
	query.exec("SELECT * FROM tab1 where Position='leftshoulder' or Position='rightshoulder' or Position='leftfoot' or Position='rightfoot'");

	while(query.next()){
		
		//leftshoulder
		x = query.value(3).toDouble();
		y = query.value(4).toDouble();
		z = query.value(5).toDouble();
		shoulder_left.X=x;
		shoulder_left.Y=y;
		shoulder_left.Z=z;

		query.next();

		//rightshoulder
		x = query.value(3).toDouble();
		y = query.value(4).toDouble();
		z = query.value(5).toDouble();
		shoulder_right.X=x;
		shoulder_right.Y=y;
		shoulder_right.Z=z;

		query.next();

		//leftfoot
		x = query.value(3).toDouble();
		y = query.value(4).toDouble();
		z = query.value(5).toDouble();

		foot_left.X=x;
		foot_left.Y=y;
		foot_left.Z=z;

		query.next();

		//rightfoot
		x = query.value(3).toDouble();
		y = query.value(4).toDouble();
		z = query.value(5).toDouble();

		foot_right.X=x;
		foot_right.Y=y;
		foot_right.Z=z;

		query.next();

		if(qishi_rule1(foot_left,shoulder_left)||qishi_rule1(foot_right,shoulder_right))
		{
				one=true;
		}

	}

	dbconn.close();


	//rule2
	dbconn.open();

	query.exec("SELECT * FROM tab1 where Position='lefthand' or Position='leftshoulder' or Position='righthand' or Position='rightshoulder'");


	while(query.next()){

		//lefthand
		x = query.value(3).toDouble();
		y = query.value(4).toDouble();
		z = query.value(5).toDouble();
		hand_left.X=x;
		hand_left.Y=y;
		hand_left.Z=z;

		query.next();

		//leftshoulder
		x = query.value(3).toDouble();
		y = query.value(4).toDouble();
		z = query.value(5).toDouble();
		shoulder_left.X=x;
		shoulder_left.Y=y;
		shoulder_left.Z=z;

		query.next();

		//righthand
		x = query.value(3).toDouble();
		y = query.value(4).toDouble();
		z = query.value(5).toDouble();
		hand_right.X=x;
		hand_right.X=y;
		hand_right.X=z;

		query.next();

		//rightshoulder
		x = query.value(3).toDouble();
		y = query.value(4).toDouble();
		z = query.value(5).toDouble();
		shoulder_right.X=x;
		shoulder_right.Y=y;
		shoulder_right.Z=z;

		query.next();

		if(qishi_rule2(hand_left,shoulder_left)||qishi_rule1(hand_right,shoulder_right))
			{
				two=true;
			}
	}

	dbconn.close();

	//rule3
	dbconn.open();
	query.exec("SELECT * FROM tab1 where Position='lefthand' or Position='leftelbow' or Position='leftshoulder' or Position='righthand'or Position='rightelbow' or Position='rightshoulder'");

	while(query.next()){

		//lefthand
		x = query.value(3).toDouble();
		y = query.value(4).toDouble();
		z = query.value(5).toDouble();
		hand_left.X=x;
		hand_left.Y=y;
		hand_left.Z=z;

		query.next();

		//leftelbow
		x = query.value(3).toDouble();
		y = query.value(4).toDouble();
		z = query.value(5).toDouble();
		elbow_left.X=x;
		elbow_left.Y=y;
		elbow_left.Z=z;

		query.next();

		//leftshoulder
		x = query.value(3).toDouble();
		y = query.value(4).toDouble();
		z = query.value(5).toDouble();
		shoulder_left.X=x;
		shoulder_left.Y=y;
		shoulder_left.Z=z;

		query.next();

		//righthand
		x = query.value(3).toDouble();
		y = query.value(4).toDouble();
		z = query.value(5).toDouble();
		hand_right.X=x;
		hand_right.Y=y;
		hand_right.Z=z;

		query.next();

		//rightelbow
		x = query.value(3).toDouble();
		y = query.value(4).toDouble();
		z = query.value(5).toDouble();
		elbow_right.X=x;
		elbow_right.Y=y;
		elbow_right.Z=z;

		query.next();

		//rightshoulder
		x = query.value(3).toDouble();
		y = query.value(4).toDouble();
		z = query.value(5).toDouble();
		shoulder_right.X=x;
		shoulder_right.Y=y;
		shoulder_right.Z=z;

		query.next();

		if(qishi_rule3(hand_left,elbow_left,shoulder_left)||qishi_rule3(hand_right,elbow_right,shoulder_right))
			{
				three=true;
			}
	}

	dbconn.close();

	//rule4
	dbconn.open();
	query.exec("SELECT * FROM tab1 where Position='neck' or Position='torso' or Position='lefthip' or Position='righthip'");

	while(query.next()){

		//neck
		x = query.value(3).toDouble();
		y = query.value(4).toDouble();
		z = query.value(5).toDouble();
		neck.X=x;
		neck.Y=y;
		neck.Z=z;

		query.next();

		//torso
		x = query.value(3).toDouble();
		y = query.value(4).toDouble();
		z = query.value(5).toDouble();
		torso.X=x;
		torso.Y=y;
		torso.Z=z;

		query.next();

		//lefthip
		x = query.value(3).toDouble();
		y = query.value(4).toDouble();
		z = query.value(5).toDouble();
		hip_left.X=x;
		hip_left.Y=y;
		hip_left.Z=z;

		query.next();

		//righthip
		x = query.value(3).toDouble();
		y = query.value(4).toDouble();
		z = query.value(5).toDouble();
		hip_right.X=x;
		hip_right.Y=y;
		hip_right.Z=z;

		query.next();

		if(qishi_rule4(hip_left,hip_right,torso,neck))
			{
				four=true;
			}
	}

	dbconn.close();

	//rule5
	dbconn.open();
	int frame_id;
	query.exec("select min(Frame) from tab1");
	while(query.next()){
		frame_id = query.value(0).toInt();
	}

	query.prepare("SELECT * FROM tab1 where (Frame_num= ?) and (Position='lefthand' or Position='righthand' or Position='lefthip' or Position='righthip'");
	query.addBindValue(frame_id);
	query.exec();

	while(query.next()){

		//prehand left
		x = query.value(3).toDouble();
		y = query.value(4).toDouble();
		z = query.value(5).toDouble();
		prehand_left.X=x;
		prehand_left.Y=y;
		prehand_left.Z=z;

		query.next();

		//prehand right
		x = query.value(3).toDouble();
		y = query.value(4).toDouble();
		z = query.value(5).toDouble();
		prehand_right.X=x;
		prehand_right.Y=y;
		prehand_right.Z=z;

		query.next();

		//prehip left
		x = query.value(3).toDouble();
		y = query.value(4).toDouble();
		z = query.value(5).toDouble();
		prehip_left.X=x;
		prehip_left.Y=y;
		prehip_left.Z=z;

		query.next();

		//prehip right
		x = query.value(3).toDouble();
		y = query.value(4).toDouble();
		z = query.value(5).toDouble();
		prehip_right.X=x;
		prehip_right.Y=y;
		prehip_right.Z=z;
		query.next();
	}
	
	dbconn.close();

	dbconn.open();

	query.exec("SELECT * FROM tab1 where Position='lefthand' or Position='righthand' or Position='lefthip' or Position='righthip'");

	while(query.next()){

		//left hand
		x = query.value(3).toDouble();
		y = query.value(4).toDouble();
		z = query.value(5).toDouble();
		hand_left.X=x;
		hand_left.Y=y;
		hand_left.Z=z;

		query.next();

		//righthand
		x = query.value(3).toDouble();
		y = query.value(4).toDouble();
		z = query.value(5).toDouble();
		hand_right.X=x;
		hand_right.Y=y;
		hand_right.Z=z;

		query.next();

		//lefthip
		x = query.value(3).toDouble();
		y = query.value(4).toDouble();
		z = query.value(5).toDouble();
		hip_left.X=x;
		hip_left.Y=y;
		hip_left.Z=z;

		query.next();

		//righthip
		x = query.value(3).toDouble();
		y = query.value(4).toDouble();
		z = query.value(5).toDouble();
		hip_right.X=x;
		hip_right.Y=y;
		hip_right.Z=z;

		query.next();

		if(qishi_rule5(prehand_left,hand_left,prehand_right,hand_right,prehip_left,hip_left,prehip_right,hip_right))
			{
				five=true;
			}
		prehand_left.X=hand_left.X;
		prehand_left.Y=hand_left.Y;
		prehand_left.Z=hand_left.Z;

		prehand_right.X=hand_right.X;
		prehand_right.Y=hand_right.Y;
		prehand_right.Z=hand_right.Z;

		prehip_left.X=hip_left.X;
		prehip_left.Y=hip_left.Y;
		prehip_left.Z=hip_left.Z;

		prehip_right.X=hip_right.X;
		prehip_right.Y=hip_right.Y;
		prehip_right.Z=hip_right.Z;
	}

	dbconn.close();


	double score;

	score = qishi_grading(one,two,three,four,five);

	totalscore = 10;

	return score;
}


bool GradingRules::qishi_rule1(NODE foot, NODE shoulder){

	if(foot.Z>shoulder.Z)
		{
			//totalscore = totalscore-0.1;
			if((foot.Z-shoulder.Z)>122.89)
			{
				return true;
			}
		}
		else if(foot.Z<shoulder.Z)
		{
			if((shoulder.Z-foot.Z)>122.89)
			{
				return true;
			}
		}
}

bool GradingRules::qishi_rule2(NODE hand, NODE shoulder){

	if((hand.Y-shoulder.Y)>301.02)
		{
			//totalscore = totalscore-0.1;
			return true;
		}
}

bool GradingRules::qishi_rule3(NODE hand, NODE elbow, NODE shoulder){

	if(((elbow.X-hand.X)/(shoulder.X-hand.X))==((elbow.Y-hand.Y)/(shoulder.Y-hand.Y))&&((elbow.Y-hand.Y)/(shoulder.Y-hand.Y))==((elbow.Z-hand.Z)/(shoulder.Z-hand.Z)))
		{
			//totalscore = totalscore-0.1;
			return true;
		}
}

bool GradingRules::qishi_rule4(NODE hip_left,NODE hip_right, NODE torso, NODE neck){

	if((hip_left.Z-torso.Z)>31.89)
		{
			//totalscore = totalscore-0.1;
			return true;
		}
		else if((hip_right.Z-torso.Z)>23.85)
		{
			return true;
		}
		else if((torso.Z-neck.Z)>32.33)
		{
			return true;
		}
}

bool GradingRules::qishi_rule5(NODE prehand_left,NODE hand_left,NODE prehand_right, NODE hand_right,NODE prehip_left, NODE hip_left,NODE prehip_right, NODE hip_right){
	
	if((prehand_left.Y-hand_left.Y)>33.96&&(prehand_right.Y-hand_right.Y)>19.57)
		{
			if((prehip_left.Y-hip_left.Y)>16.57&&(prehip_right.Y-hip_right.Y)>17.24)
			{

			}
			else{
				return true;
			}
		}
		else if((prehip_left.Y-hip_left.Y)>16.57&&(prehip_right.Y-hip_right.Y)>17.24)
		{
			return true;
		}
}

void GradingRules::qishi_getMaxandMin(NODE hand_left,NODE hand_right){

		//cause hand_left 
		if(max_left<hand_left.Y||max_left==hand_left.Y)
		{
			max_left=hand_left.Y;
		}
		else
		{
			max_left=max_left;
		}
			
		//
		if(min_left>hand_left.Y||min_left==hand_left.Y)
		{
			min_left=hand_left.Y;
		}
		else
		{
			min_left=min_left;
		}


		//cause hand_right 
		if(max_right<hand_right.Y||max_right==hand_right.Y)
		{
			max_right=hand_right.Y;
		}
		else
		{
			max_right=max_right;
		}
			
		//
		if(min_right>hand_right.Y||min_right==hand_right.Y)
		{
			min_right=hand_right.Y;
		}
		else
		{
			min_right=min_right;
		}
}

double GradingRules::qishi_grading(bool rule1, bool rule2, bool rule3, bool rule4, bool rule5){
	if(rule1)
	{
		totalscore = totalscore-0.1;
		qishi_rule11 = 1;
	}
	if(rule2)
	{
		totalscore = totalscore-0.1;
		qishi_rule22 = 1;
	}
	if(rule3)
	{
		totalscore = totalscore-0.1;
		qishi_rule33 = 1;
	}
	if(rule4)
	{
		totalscore = totalscore-0.1;
		qishi_rule44 = 1;
	}
	if(rule5)
	{
		totalscore = totalscore-0.1;
		qishi_rule55 = 1;
	}
	return totalscore;
}


// YEMAFENZONG
double GradingRules::YemaFenZong(){

	NODE head,neck,torso;
	NODE hand_right,elbow_right,shoulder_right,hip_right,knee_right,foot_right;
	NODE hand_left,elbow_left,shoulder_left,hip_left,knee_left,foot_left;
	NODE prehand_left,prehand_right,prehip_left,prehip_right;

	bool one="false";
	bool two="false";
	bool three="false";
	bool four="false";

	yema_rule11 = 0;
	yema_rule22 = 0;
	yema_rule33 = 0;
	yema_rule44 = 0;

	QSqlDatabase dbconn=QSqlDatabase::addDatabase("QSQLITE"); //add database driver
	dbconn.setDatabaseName("test1.db");
	double x,y,z;
	
	//rule1
	dbconn.open();
	QSqlQuery query;
	query.exec("SELECT * FROM tab1 where Position='neck' or Position='torso'");

	while(query.next()){
		
		//neck
		x = query.value(3).toDouble();
		y = query.value(4).toDouble();
		z = query.value(5).toDouble();
		neck.X=x;
		neck.Y=y;
		neck.Z=z;

		query.next();

		//torso
		x = query.value(3).toDouble();
		y = query.value(4).toDouble();
		z = query.value(5).toDouble();
		torso.X=x;
		torso.Y=y;
		torso.Z=z;

		query.next();
		if(yema_incline(neck,torso))
		{
				one=true;
		}
	}

	dbconn.close();


	//rule2
	dbconn.open();
	query.exec("SELECT * FROM tab1 where Position='leftknee' or Position='leftfoot' or Position='rightfoot'");

	while(query.next()){
		//left knee
		x = query.value(3).toDouble();
		y = query.value(4).toDouble();
		z = query.value(5).toDouble();
		knee_left.X=x;
		knee_left.Y=y;
		knee_left.Z=z;

		query.next();

		//left foot
		x = query.value(3).toDouble();
		y = query.value(4).toDouble();
		z = query.value(5).toDouble();
		foot_left.X=x;
		foot_left.Y=y;
		foot_left.Z=z;

		query.next();

		//right foot
		x = query.value(3).toDouble();
		y = query.value(4).toDouble();
		z = query.value(5).toDouble();
		foot_right.X=x;
		foot_right.Y=y;
		foot_right.Z=z;

		query.next();
		if(yema_isLunge(foot_left,foot_right,knee_left))
		{
			two=true;
		}
	}

	dbconn.close();

	//rule 3
	dbconn.open();
	query.exec("SELECT * FROM tab1 where Position='leftknee' or Position='leftfoot'");

	while(query.next()){

		//left knee
		x = query.value(3).toDouble();
		y = query.value(4).toDouble();
		z = query.value(5).toDouble();
		knee_left.X=x;
		knee_left.Y=y;
		knee_left.Z=z;

		query.next();

		//left foot
		x = query.value(3).toDouble();
		y = query.value(4).toDouble();
		z = query.value(5).toDouble();
		foot_left.X=x;
		foot_left.Y=y;
		foot_left.Z=z;

		query.next();
		if(yema_lunge(knee_left,foot_left))
		{
			three=true;
		}
	}

	dbconn.close();

	//rule 4
	dbconn.open();
	query.exec("SELECT * FROM tab1 where Position='lefthand' or Position='leftelbow' or Position='leftshoulder' or Position='righthand' or Position='rightelbow' or Position='rightshoulder'");

	while(query.next()){
		
		//left hand
		x = query.value(3).toDouble();
		y = query.value(4).toDouble();
		z = query.value(5).toDouble();
		hand_left.X=x;
		hand_left.Y=y;
		hand_left.Z=z;

		query.next();

		//left elbow
		x = query.value(3).toDouble();
		y = query.value(4).toDouble();
		z = query.value(5).toDouble();
		elbow_left.X=x;
		elbow_left.Y=y;
		elbow_left.Z=z;

		query.next();

		//left shoulder
		x = query.value(3).toDouble();
		y = query.value(4).toDouble();
		z = query.value(5).toDouble();
		shoulder_left.X=x;
		shoulder_left.Y=y;
		shoulder_left.Z=z;

		query.next();

		//right hand
		x = query.value(3).toDouble();
		y = query.value(4).toDouble();
		z = query.value(5).toDouble();
		hand_right.X=x;
		hand_right.Y=y;
		hand_right.Z=z;

		query.next();

		//right elbow
		x = query.value(3).toDouble();
		y = query.value(4).toDouble();
		z = query.value(5).toDouble();
		elbow_right.X=x;
		elbow_right.Y=y;
		elbow_right.Z=z;

		query.next();

		//right shoulder
		x = query.value(3).toDouble();
		y = query.value(4).toDouble();
		z = query.value(5).toDouble();
		shoulder_right.X=x;
		shoulder_right.Y=y;
		shoulder_right.Z=z;

		query.next();
		if(yema_keepArc(hand_left,elbow_left,shoulder_left,hand_right,elbow_right,shoulder_right))
		{
			four=true;
		}
	}

	dbconn.close();
	
	double score;
	score=yema_grading(one,two,three,four);
	
	totalscore = 10;
	return score;
}


bool GradingRules::yema_incline(NODE neck, NODE torso_center){
	double cos;
	cos=((neck.Y-torso_center.Y)*1)/(sqrt(pow(neck.X-torso_center.X,2)+pow(neck.Y-torso_center.Y,2)+pow(neck.Z-torso_center.Z,2))*1);
		if(cos<=0.966)
		{
			return true;
			//totalscore = totalscore-0.1;
		}
		return false;
}

bool GradingRules::yema_isLunge(NODE foot_left, NODE foot_right, NODE knee_left){
	double dist,cos;
	dist = sqrt(pow(foot_left.X-foot_right.X,2)+pow(foot_left.Y-foot_right.Y,2));
		cos = ((knee_left.Y-foot_left.Y)*1)/(sqrt(pow(knee_left.X-foot_left.X,2)+pow(knee_left.Y-foot_left.Y,2)+pow(knee_left.Z-foot_left.Z,2))*1);
		if(dist>=1000)
		{
			if(cos>=0.965)
			{
				return yema_noAttach(foot_right);
			}
		}
}

bool GradingRules::yema_noAttach(NODE foot_right){

		if(foot_right.Y<470)
		{
			return true;
			//totalscore = totalscore-0.1;
		}
		return false;
}

bool GradingRules::yema_lunge(NODE knee_left, NODE foot_left){
	double cos;
	cos = ((knee_left.Y-foot_left.Y)*1)/(sqrt(pow(knee_left.X-foot_left.X,2)+pow(knee_left.Y-foot_left.Y,2)+pow(knee_left.Z-foot_left.Z,2))*1);
		if(cos<0.965)
		{
			return true;
			//totalscore = totalscore-0.1;
		}
		return false;
}

bool GradingRules::yema_keepArc(NODE hand_left, NODE elbow_left, NODE shoulder_left, NODE hand_right, NODE elbow_right, NODE shoulder_right){
	double tl,tr;
	double qlx, qly, qlz, qrx, qry, qrz;//平面与连线的交点
	double dl, dr;//交点与ELBOW节点的距离

	tl=-((shoulder_left.X-hand_left.X)*(hand_left.X-elbow_left.X)+(shoulder_left.Y-hand_left.Y)*(hand_left.Y-elbow_left.Y)+(shoulder_left.Z-hand_left.Z)*(hand_left.Z-elbow_left.Z))/(pow(shoulder_left.X-hand_left.X,2)+pow(shoulder_left.Y-hand_left.Y,2)+pow(shoulder_left.Z-hand_left.Z,2));
		tr=-((shoulder_right.X-hand_right.X)*(hand_right.X-elbow_right.X)+(shoulder_right.Y-hand_right.Y)*(hand_right.Y-elbow_right.Y)+(shoulder_right.Z-hand_right.Z)*(hand_right.Z-elbow_right.Z))/(pow(shoulder_right.X-hand_right.X,2)+pow(shoulder_right.Y-hand_right.Y,2)+pow(shoulder_right.Z-hand_right.Z,2));
		
		qlx=hand_left.X+(shoulder_left.X-hand_left.X)*tl;
		qly=hand_left.Y+(shoulder_left.Y-hand_left.Y)*tl;
		qlz=hand_left.Z+(shoulder_left.Z-hand_left.Z)*tl;

		qrx=hand_right.X+(shoulder_right.X-hand_right.X)*tr;
		qry=hand_right.Y+(shoulder_right.Y-hand_right.Y)*tr;
		qrz=hand_right.Z+(shoulder_right.Z-hand_right.Z)*tr;

		dl=sqrt(pow(elbow_left.X-qlx,2)+pow(elbow_left.Y-qly,2)+pow(elbow_left.Z-qlz,2));
		dr=sqrt(pow(elbow_right.X-qrx,2)+pow(elbow_right.Y-qry,2)+pow(elbow_right.Z-qrz,2));

		if(dl<100||dr<100)
		{
			return true;
			//totalscore = totalscore-0.1;
		}
		return false;
}

double GradingRules::yema_grading(bool rule1, bool rule2, bool rule3, bool rule4){

	if(rule1)
	{
		totalscore = totalscore-0.1;
		yema_rule11 = 1;
	}
	if(rule2)
	{
		totalscore = totalscore-0.1;
		yema_rule22 = 1;
	}
	if(rule3)
	{
		totalscore = totalscore-0.1;
		yema_rule33 = 1;
	}
	if(rule4)
	{
		totalscore = totalscore-0.1;
		yema_rule44 = 1;
	}
	return totalscore;
}





//BAIHELIANGCHI
double GradingRules::BaiHeLiangChi(){

	NODE head,neck,torso;
	NODE hand_right,elbow_right,shoulder_right,hip_right,knee_right,foot_right;
	NODE hand_left,elbow_left,shoulder_left,hip_left,knee_left,foot_left;

	bool one=false;
	bool two=false;
	bool three=false;
	bool four=false;
	bool five=false;
	bool six=false;
	bool seven=false;
	bool eight=false;

	baihe_rule11 = 0;
	baihe_rule22 = 0;
	baihe_rule33 = 0;
	baihe_rule44 = 0;
	baihe_rule55 = 0;
	baihe_rule66 = 0;
	baihe_rule77 = 0;
	baihe_rule88 = 0;

	QSqlDatabase dbconn=QSqlDatabase::addDatabase("QSQLITE"); //add database driver
	dbconn.setDatabaseName("test2.db");
	double x,y,z;
	int frame_num;

	//rule1
	dbconn.open();
	QSqlQuery query;
	query.exec("SELECT * FROM tab1 where Position='lefthand' or Position='leftelbow' or Position='leftshoulder' or Position='righthand' or Position='rightelbow' or Position='rightshoulder'");

	while(query.next())   //point to the first one and then do next operation auto
	{
		//hand_left
		x = query.value(3).toDouble();
		y = query.value(4).toDouble();
		z = query.value(5).toDouble();
		
		hand_left.X=x;
		hand_left.Y=y;
		hand_left.Z=z;
		query.next();

		//elbow_left
		x = query.value(3).toDouble();
		y = query.value(4).toDouble();
		z = query.value(5).toDouble();
		elbow_left.X=x;
		elbow_left.Y=y;
		elbow_left.Z=z;
		query.next();

		//shoulder_left
		x = query.value(3).toDouble();
		y = query.value(4).toDouble();
		z = query.value(5).toDouble();
		
		shoulder_left.X=x;
		shoulder_left.Y=y;
		shoulder_left.Z=z;
		
		//apply rule one
		if(baihe_collineation(hand_left,elbow_left,shoulder_left))
		{
			one=true;
		}
		
		query.next();

		//hand_right
		x = query.value(3).toDouble();
		y = query.value(4).toDouble();
		z = query.value(5).toDouble();
		
		hand_right.X=x;
		hand_right.Y=y;
		hand_right.Z=z;
		query.next();

		//elbow_right
		x = query.value(3).toDouble();
		y = query.value(4).toDouble();
		z = query.value(5).toDouble();
		
		elbow_right.X=x;
		elbow_right.Y=y;
		elbow_right.Z=z;
		query.next();

		//shoulder_right
		x = query.value(3).toDouble();
		y = query.value(4).toDouble();
		z = query.value(5).toDouble();
		
		shoulder_right.X=x;
		shoulder_right.Y=y;
		shoulder_right.Z=z;
		
		if(baihe_collineation(hand_right,elbow_right,shoulder_right))
		{
			one=true;
		}
		query.next();
	}

	dbconn.close();

	//Rule Two
	dbconn.open();

	int frame_id;
	query.exec("select min(Frame) from tab1");
	while(query.next()){
		frame_id = query.value(0).toInt();
	}

	query.prepare("SELECT * FROM tab1 where (Frame_num= ?) and (Position='leftknee' or Position='leftfoot')");
	query.addBindValue(frame_id);
	query.exec();

	while(query.next())
	{
		x = query.value(3).toDouble();
		y = query.value(4).toDouble();
		z = query.value(5).toDouble();
		
		knee_left.X=x;
		knee_left.Y=y;
		knee_left.Z=z;
		query.next();

		x = query.value(3).toDouble();
		y = query.value(4).toDouble();
		z = query.value(5).toDouble();
		
		foot_left.X=x;
		foot_left.Y=y;
		foot_left.Z=z;
		if(baihe_lunge(knee_left,foot_left))
		{
			two=true;
		}
		query.next();
	}
	dbconn.close();

	//Rule Three
	dbconn.open();
	NODE pretorso;
	query.exec("SELECT * FROM tab1 where Position='torso'");
	while(query.next())
	{
		frame_num = query.value(1).toInt();
		x = query.value(3).toDouble();
		y = query.value(4).toDouble();
		z = query.value(5).toDouble();

		if(frame_num == frame_id)
		{
			pretorso.X=x;
			pretorso.Y=y;
			pretorso.Z=z;
		}
		torso.X=x;
		torso.Y=y;
		torso.Z=z;
		if(baihe_keeplevel(pretorso,torso))
		{
			three=true;
		}

		pretorso.X=torso.X;
		pretorso.Y=torso.Y;
		pretorso.Z=torso.Z;

		query.next();
	}
	dbconn.close();

	//Rule Four
	dbconn.open();
	query.exec("SELECT * FROM tab1 where Position='rightfoot'");
	while(query.next())
	{
		x = query.value(3).toDouble();
		y = query.value(4).toDouble();
		z = query.value(5).toDouble();
		
		foot_right.X=x;
		foot_right.Y=y;
		foot_right.Z=z;
		baihe_getMaxandMin(foot_right);
		query.next();
	}
	dbconn.close();

	dbconn.open();
	query.exec("SELECT * FROM tab1 where Position='rightfoot'");
	while(query.next())
	{
		x = query.value(3).toDouble();
		y = query.value(4).toDouble();
		z = query.value(5).toDouble();
		
		foot_right.X=x;
		foot_right.Y=y;
		foot_right.Z=z;
		if(baihe_noAttach(foot_right))
		{
			four=true;
		}
		query.next();
	}
	dbconn.close();

	//Rule Six
	dbconn.open();
	NODE prehead;
	int frameNum;
	query.exec("SELECT * FROM tab1 where Position='head'");
	while(query.next())
	{
		frameNum = query.value(1).toDouble();
		x = query.value(3).toDouble();
		y = query.value(4).toDouble();
		z = query.value(5).toDouble();

		if(frameNum == frame_id)
		{
			prehead.X=x;
			prehead.Y=y;
			prehead.Z=z;
		}
		head.X=x;
		head.Y=y;
		head.Z=z;
		if(baihe_falldown(prehead,head))
		{
			three=true;
		}

		prehead.X=head.X;
		prehead.Y=head.Y;
		prehead.Z=head.Z;

		query.next();
	}
	dbconn.close();

	//Rule Seven
	dbconn.open();
	query.exec("SELECT * FROM tab1 where Position='rightfoot' or Position='leftfoot'");
	while(query.next())
	{
		x = query.value(3).toDouble();
		y = query.value(4).toDouble();
		z = query.value(5).toDouble();
		
		foot_left.X=x;
		foot_left.Y=y;
		foot_left.Z=z;
		query.next();

		x = query.value(3).toDouble();
		y = query.value(4).toDouble();
		z = query.value(5).toDouble();
		
		foot_right.X=x;
		foot_right.Y=y;
		foot_right.Z=z;
		query.next();
	}
	//The final frame
	if(baihe_onTiptoe(foot_right,foot_left))
	{
		seven=true;
	}
	dbconn.close();

	//Rule Eight
	dbconn.open();
	query.exec("SELECT * FROM tab1 where Position='rightfoot' or Position='rightknee' or Position='righthip' or Position='rightshoulder'");
	while(query.next())
	{
		//shoulder_right
		x = query.value(3).toDouble();
		y = query.value(4).toDouble();
		z = query.value(5).toDouble();
		
		shoulder_right.X=x;
		shoulder_right.Y=y;
		shoulder_right.Z=z;
		query.next();
		
		//hip_right
		x = query.value(3).toDouble();
		y = query.value(4).toDouble();
		z = query.value(5).toDouble();
		
		hip_right.X=x;
		hip_right.Y=y;
		hip_right.Z=z;
		query.next();
		
		//knee_right
		x = query.value(3).toDouble();
		y = query.value(4).toDouble();
		z = query.value(5).toDouble();
		
		knee_right.X=x;
		knee_right.Y=y;
		knee_right.Z=z;
		query.next();
		
		//foot_right
		x = query.value(3).toDouble();
		y = query.value(4).toDouble();
		z = query.value(5).toDouble();
		
		foot_right.X=x;
		foot_right.Y=y;
		foot_right.Z=z;
		query.next();
	}
	if(baihe_checkCenterofGravity(foot_right,knee_right,hip_right,shoulder_right))
	{
		eight=true;
	}
	
	dbconn.close();

	double score;

	score = baihe_grading(one,two,three,four,five,six,seven,eight);

	totalscore = 10;
	return score;
}



bool GradingRules::baihe_collineation(NODE hand, NODE elbow, NODE shoulder){
	if(((elbow.X-hand.X)/(shoulder.X-hand.X))==((elbow.Y-hand.Y)/(shoulder.Y-hand.Y))&&((elbow.Y-hand.Y)/(shoulder.Y-hand.Y))==((elbow.Z-hand.Z)/(shoulder.Z-hand.Z)))
	{
		//totalscore = totalscore-0.1;
		return true;
	}
}

bool GradingRules::baihe_lunge(NODE knee_left, NODE foot_left){
	double cos;
	cos=((knee_left.Y-foot_left.Y)*foot_left.Y)/(sqrt(pow(knee_left.X-foot_left.X,2)+pow(knee_left.Z-foot_left.Z,2)+pow(knee_left.Y-foot_left.Y,2))*sqrt(pow(foot_left.Y,2)));
	if(cos>0)
	{
		return true;
		//totalscore = totalscore-0.1;
	}
	return false;
}

bool GradingRules::baihe_keeplevel(NODE prehipcenter, NODE nexthipcenter){
	double p = abs(prehipcenter.Y);
	double n = abs(nexthipcenter.Y);
	if(n>=p+20&&n<=p-20)
	{
		return true;
		//totalscore = totalscore-0.1;
	}
	return false;
}

void GradingRules::baihe_getMaxandMin(NODE foot_right){
	//cause foot_right 
	if(baihe_max < foot_right.X||baihe_max==foot_right.X)
	{
		baihe_max=foot_right.X;
	}
	else
	{
		baihe_max=baihe_max;
	}
			
	//
	if(baihe_min>foot_right.X||baihe_min==foot_right.X)
	{
		baihe_min=foot_right.X;
	}
	else
	{
		baihe_min=baihe_min;
	}

}

bool GradingRules::baihe_noAttach(NODE foot_right){

	if(foot_right.X>=baihe_min&&foot_right.X<=baihe_max)
	{
		if(foot_right.Y==0)
		{
			return true;
		}
		return false;
	}
	return false;
}

bool GradingRules::baihe_getStraight(NODE foot_left, NODE ankle_left, NODE knee_left){

	if(foot_left.Y!=ankle_left.Y||foot_left.Z!=ankle_left.Z)
		{
			return true;
		}
		if(knee_left.X!=ankle_left.X||knee_left.Z!=ankle_left.Z)
		{
			return true;
		}
		return false;
}

bool GradingRules::baihe_falldown(NODE prehead, NODE nexthead){

	double dist = sqrt(pow(prehead.X-nexthead.X,2)+pow(prehead.Y-nexthead.Y,2)+pow(prehead.Z-nexthead.Z,2));
	if(dist>100)
	{
		return true;
		//totalscore = totalscore-0.3;
	}
	return false;
}

bool GradingRules::baihe_onTiptoe(NODE foot_right, NODE foot_left){

	if(foot_right.Y==foot_left.Y)
	{
		return true;
	}
	return false;
}

bool GradingRules::baihe_checkCenterofGravity(NODE foot_right, NODE knee_right, NODE hip_right, NODE shoulder_right){

	if(foot_right.Z!=knee_right.Z||knee_right.Z!=hip_right.Z||hip_right.Z!=shoulder_right.Z)
	{
		return true;
	}
	return false;

}

double GradingRules::baihe_grading(bool rule1, bool rule2, bool rule3, bool rule4, bool rule5, bool rule6, bool rule7, bool rule8){

	if(rule1)
	{
		//printf("1\n");
		totalscore = totalscore-0.1;
		baihe_rule11 = 1;
	}
	if(rule2)
	{
		//printf("2\n");
		totalscore = totalscore-0.1;
		baihe_rule22 = 1;
	}
	if(rule3)
	{
		//printf("3\n");
		totalscore = totalscore-0.1;
		baihe_rule33 = 1;
	}
	if(rule4)
	{
		//printf("4\n");
		totalscore = totalscore-0.1;
		baihe_rule44 = 1;
	}
	if(rule5)
	{
		//printf("5\n");
		totalscore = totalscore-0.1;
		baihe_rule55 = 1;
	}
	if(rule6)
	{
		//printf("6\n");
		totalscore = totalscore-0.3;
		baihe_rule66 = 1;
	}
	if(rule7)
	{
		//printf("7\n");
		totalscore = totalscore-0.1;
		baihe_rule77 = 1;
	}
	if(rule8)
	{
		//printf("8\n");
		totalscore = totalscore-0.1;
		baihe_rule88 = 1;
	}
	return totalscore;
}