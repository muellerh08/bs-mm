/** Test BpIkZz.
13.01.17
*/
//#include "Bp.h"
#include "BpDef.h"
//#include "BpIk.h"
//#include "BpIkMa.h"
//#include "BpIkMtZz.h"
#include "BpMultMgr.h"
//#include "BpTaLib.h"
//#include "RtMf.h"
string fParM="-10000,20161231,0,Bp::kOri,Bp::kMult";
//string fParM="-10000,20201231,0,Bp::kOri,Bp::kMult";
int nbY=0;
void V1();
void V2();

void IkZz(int var)
//void IkZz()
{
	//int var=2;
	cout<<"IkZz(): var="<<var<<endl;
	//multMgr->SetParams(fBc,fParM);
	//Bp::Def::Set(fBc,"Kurse",nbY,"Bp::kDots",kBlack);
	//Bp::Def::Set(fBc,"Kurse",nbY,"Bp::kCandle",kBlack);

	switch (var) {
	case 1: V1();	break;
	case 2: V2();	break;
		//case 3: V3();	break;
	default:
		cout<<"IkZz(): var="<<var<<" nicht implementiert"<<endl; exit(1);
	}
} // IkZz()

/** Rechnung für DAX. */
void V1()
{
  string fBc="Wiso.DAX";
	string fParM="-10000,20161231,0,Bp::kOri,Bp::kMult";
	Bp::MultMgr::Create()->SetParams(fBc,fParM);
  
	string sAtr="ATR 14";
	//string sZz="IkZz 0 3 1",sZz1="IkZz 1 3 1";
	string sZz="IkZz 0 1.5:"+sAtr, sZz1="IkZz 1 1.5:"+sAtr;
	string sQuo="IkQuo 0 0";

  Bp::Def::Set(fBc,"Kurse",nbY,"kCandle",kBlack);
	Bp::Def::Set(fBc,"Kurse",nbY,"kDots",kBlack);
	//Bp::Def::Set(fBc,"Kurse",nbY,"Bp::kIoBar",0);
  //Bp::Def::SetMap("Kurse",nbY,"Bp::kTest");
  //Bp::Def::SetMap("Kurse",nbY,"Bp::kHist");
	
	Bp::Def::Set(fBc,sZz,nbY,"kHist",kBlue,0,"GD");
	//Bp::Def::Set(fBc,sZz1,nbY,"kHist",kRed,0,"GD");
	Bp::Def::Set(fBc,sZz,nbY,"kLine",kCyan+1,5,"Int");
	Bp::Def::Set(fBc,sZz,nbY,"kLine",kCyan,3,"ValL");
	Bp::Def::Set(fBc,sZz,nbY,"kLine",kCyan+2,4,"ValH");

	nbY++;
	Bp::Def::Set(fBc,sZz,nbY,"kHist",kBlue,1,"Mom");
	//Bp::Def::Set(fBc,sZz1,nbY,"kHist",kRed,1,"Mom");
	Bp::Def::Set(fBc,sQuo,nbY,"kLine",kBlack);

	nbY++;
	Bp::Def::Set(fBc,sZz,nbY,"kHist",kBlue,2,"trend123");
	//Bp::Def::Set(fBc,sZz1,nbY,"kHist",kRed,2,"trend123");
	Bp::Def::Set(fBc,sQuo,nbY,"kLine",kBlack);

	Rt::Mf* mF=new Rt::Mf(gClient->GetRoot(),fBc,1260,800);
} // IkZz()

/** Rechnung Fond. */
void V2()
{
	
	//string fBc="Wiso.T933677";
	string fBc="Wiso.T847428";
	string fParM="-10000,20201231,0,kOri,kMult";
	Bp::MultMgr::Create()->SetParams(fBc,fParM);

	//string sAtr="ATR 13";
	string sSd="STDDEV 14 1";
	//string sSd1="STDDEV 34 1";
	//string sMt="IkMt 3 .5;"+sAtr;
	//string sZz="IkZz 1 3 1;"+sAtr;
	string sZz="IkZz 0 3 1:"+sSd;
	//string sZz1="IkZz 1 3 1;"+sSd1;
	//string sZz2="IkZz 1 4 1;"+sSd;
	//string sMt="IkMt 5 2.5";
	//string sZz="IkZz 1 3 1";
	string sQuo="IkQuo 0 0";

	Bp::Def::Set(fBc,"Kurse",nbY,"kDots",kBlack);
	Bp::Def::Set(fBc,sZz,nbY,"Bp::kHist",kBlue,0,"GD");
	//Bp::Def::Set(fBc,sZz2,nbY,"Bp::kHist",kRed,0,"GD");
	Bp::Def::Set(fBc,sZz,nbY,"Bp::kLine",kCyan+1,5,"Int");
	Bp::Def::Set(fBc,sZz,nbY,"Bp::kLine",kCyan,3,"ValL");
	Bp::Def::Set(fBc,sZz,nbY,"Bp::kLine",kCyan+2,4,"ValH");
	Bp::Def::Set(fBc,sZz,nbY,"Bp::k123",kBlack);
	
	nbY++;
	Bp::Def::Set(fBc,sZz,nbY,"Bp::kHist",kBlue,1,"Mom");
	//Bp::Def::Set(fBc,sZz2,nbY,"Bp::kHist",kRed,1,"Mom");
	Bp::Def::Set(fBc,sQuo,nbY,"Bp::kLine",kBlack);

	nbY++;
	Bp::Def::Set(fBc,sZz,nbY,"Bp::kHist",kBlue,2,"trend123");
	Bp::Def::Set(fBc,sQuo,nbY,"Bp::kLine",kBlack);

	Rt::Mf* mF=new Rt::Mf(gClient->GetRoot(),fBc,1260,800);
} // V2()
