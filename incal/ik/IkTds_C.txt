#include "BpDef.h"
#include "BpMultMgr.h"

void V1();
void V2();

void IkTdS(string sVar)
//void IkTdS()
{
	//int var=1;
	//cout<<"IkTdS(): sVar="<<sVar<<" iVar="<<iVar<<endl;
	cout<<"IkTdS(): sVar="<<sVar<<endl;
	if (sVar == "V1") V1();
	else if (sVar == "V2") V2();
	else {
		cout<<"IkTdS(): sVar="<<sVar<<" nicht implementiert"<<endl; exit(1);
	}
	/*switch (iVar) {
	case 1: V1();	break;
	case 2: V2();	break;
	default:
		cout<<"IkTdS(): iVar="<<iVar<<" nicht implementiert"<<endl; exit(1);
	}*/
} // IkTdS()

void V1()
{
	string bC="Wiso.DAX";
	//string BaCo="Wiso.DAX";
	cout<<"IkTds(): V1(): bC="<<bC<<endl;
	//string parM="-10000,-1,200,Bp::kOri,Bp::kSing";
	//string parM="-10000,20170531,200,Bp::kOri,Bp::kMult";
	string parM="-20000,20171231,0,Bp::kOri,Bp::kMult";
	Bp::MultMgr* multMgr=Bp::MultMgr::Create();
	multMgr->SetParams(bC,parM);
	string s1="IkTdS 0 14 1";
	string s2="IkTdS 0 14 2";
	string s3="IkTdS 0 14 3";

	int nbY=0;
	Bp::Def::Set(bC,"Kurse",nbY,"kCandle",0);
	//BpDef::SetDefMap("Kurse::kOhlc",nbY,"Bp::kDots",kBlack);
	//BpDef::SetDefMap("Kurse::kOc",nbY,"Bp::kDots",kMagenta);

	//BpDef::Set(bC,s1,nbY,"Bp::kHist",kRed,0,"s1"); // Supertrend
	//BpDef::Set(bC,s2,nbY,"Bp::kHist",kGreen,0,"s2"); // Supertrend
	Bp::Def::Set(bC,s3,nbY,"kHist",kRed,2,"Obergrenze");
	Bp::Def::Set(bC,s3,nbY,"kHist",kBlue,3,"Untergrenze");
	Bp::Def::Set(bC,s3,nbY,"kHist",kGreen+2,0,"s3=SuperTrend"); 
	nbY++;
	Bp::Def::Set(bC,s3,nbY,"kHist",kBlue,1,"Trd3");
	Bp::Def::Set(bC,"IkQuo 0 0",nbY,"kLine",kBlack);

	//RtMfM* mF=new RtMfM(gClient->GetRoot(),bC,1260,800);
	Rt::Mf* mF=new Rt::Mf(gClient->GetRoot(),bC,1260,800);
} // V1()

void V2()
{
	//string bC="Wiso.T933677";
	string bC="Wiso.T847428";
	cout<<"IkTds(): V2(): bC="<<bC<<endl;
	//string parM="-10000,-1,200,Bp::kOri,Bp::kSing";
	//string parM="-10000,20170531,200,Bp::kOri,Bp::kMult";
	string parM="-10000,20200630,0,Bp::kOri,Bp::kMult";
	Bp::MultMgr* multMgr=Bp::MultMgr::Create();
	multMgr->SetParams(bC,parM);
	string s1="IkTdS 1 14 1";
	string s2="IkTdS 1 14 2";
	string s3="IkTdS 1 14 3";

	int nbY=0;
	Bp::Def::Set(bC,"Kurse",nbY,"kDots",kBlack);

	//BpDef::Set(bC,s1,nbY,"Bp::kHist",kRed,0,"s1"); // Supertrend
	//BpDef::Set(bC,s2,nbY,"Bp::kHist",kGreen,0,"s2"); // Supertrend
	Bp::Def::Set(bC,s3,nbY,"kHist",kRed,2,"Obergrenze");
	Bp::Def::Set(bC,s3,nbY,"kHist",kBlue,3,"Untergrenze");
	Bp::Def::Set(bC,s3,nbY,"kHist",kGreen+2,0,"s3=SuperTrend");
	nbY++;
	Bp::Def::Set(bC,s3,nbY,"kHist",kBlue,1,"Trd3");
	Bp::Def::Set(bC,"IkQuo 0 0",nbY,"kLine",kBlack);

	//RtMfM* mF=new RtMfM(gClient->GetRoot(),bC,1260,800);
	Rt::Mf* mF=new Rt::Mf(gClient->GetRoot(),bC,1260,800);
} // V2()
