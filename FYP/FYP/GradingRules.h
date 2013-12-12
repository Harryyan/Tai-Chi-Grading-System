#include "CSkelItem.h"

struct NODE
{
	double X;
	double Y;
	double Z;
};

class GradingRules{

public:
	double QiShi();
	double YemaFenZong();
	double BaiHeLiangChi();

	//QISHI
	bool qishi_rule1(NODE, NODE);
	bool qishi_rule2(NODE,NODE);
	bool qishi_rule3(NODE,NODE,NODE);
	bool qishi_rule4(NODE,NODE,NODE,NODE);
	bool qishi_rule5(NODE,NODE,NODE,NODE,NODE,NODE,NODE,NODE);
	void qishi_getMaxandMin(NODE,NODE);
	double qishi_grading(bool,bool,bool,bool,bool);

	//YEMAFENZONG
	bool yema_incline(NODE,NODE); //rule1
	bool yema_isLunge(NODE,NODE,NODE);//rule2
	bool yema_noAttach(NODE); //rule2
	bool yema_lunge(NODE,NODE); //rule3
	bool yema_keepArc(NODE,NODE,NODE,NODE,NODE,NODE); //rule4
	double yema_grading(bool,bool,bool,bool);

	//BAIHELIANGCHI
	bool baihe_collineation(NODE,NODE,NODE); //rule1
	bool baihe_lunge(NODE,NODE); //rule2
	bool baihe_keeplevel(NODE,NODE); //rule3
	void baihe_getMaxandMin(NODE); //rule4
	bool baihe_noAttach(NODE);   // rule4
	bool baihe_getStraight(NODE,NODE,NODE); //rule5
	bool baihe_falldown(NODE,NODE); //rule6
	bool baihe_onTiptoe(NODE,NODE); //rule7
	bool baihe_checkCenterofGravity(NODE,NODE,NODE,NODE); //rule8
	double baihe_grading(bool,bool,bool,bool,bool,bool,bool,bool);

private:
	bool qishi_rule11;
	bool qishi_rule22;
	bool qishi_rule33;
	bool qishi_rule44;
	bool qishi_rule55;

	bool yema_rule11;
	bool yema_rule22;
	bool yema_rule33;
	bool yema_rule44;

	bool baihe_rule11;
	bool baihe_rule22;
	bool baihe_rule33;
	bool baihe_rule44;
	bool baihe_rule55;
	bool baihe_rule66;
	bool baihe_rule77;
	bool baihe_rule88;

public:

	// qishi result
	bool getqishiRule1(){
		return qishi_rule11;
	}

	bool getqishiRule2(){
		return qishi_rule22;
	}

	bool getqishiRule3(){
		return qishi_rule33;
	}

	bool getqishiRule4(){
		return qishi_rule44;
	}

	bool getqishiRule5(){
		return qishi_rule55;
	}

	//yema result
	bool getyemaRule1(){
		return  yema_rule11;
	}

	bool getyemaRule2(){
		return yema_rule22;
	}

	bool getyemaRule3(){
		return yema_rule33;
	}

	bool getyemaRule4(){
		return yema_rule44;
	}




	//baihelaingchi
	bool getbaiheRule1(){
		return baihe_rule11;
	}

	bool getbaiheRule2(){
		return baihe_rule22;
	}

	bool getbaiheRule3(){
		return baihe_rule33;
	}

	bool getbaiheRule4(){
		return baihe_rule44;
	}

	bool getbaiheRule5(){
		return baihe_rule55;
	}

	bool getbaiheRule6(){
		return baihe_rule66;
	}

	bool getbaiheRule7(){
		return baihe_rule77;
	}

	bool getbaiheRule8(){
		return baihe_rule88;
	}
};