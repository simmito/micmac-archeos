/*Header-MicMac-eLiSe-25/06/2007

MicMac : Multi Image Correspondances par Methodes Automatiques de Correlation
eLiSe  : ELements of an Image Software Environnement

www.micmac.ign.fr


Copyright : Institut Geographique National
Author : Marc Pierrot Deseilligny
Contributors : Gregoire Maillet, Didier Boldo.

[1] M. Pierrot-Deseilligny, N. Paparoditis.
"A multiresolution and optimization-based image matching approach:
An application to surface reconstruction from SPOT5-HRS stereo imagery."
In IAPRS vol XXXVI-1/W41 in ISPRS Workshop On Topographic Mapping From Space
(With Special Emphasis on Small Satellites), Ankara, Turquie, 02-2006.

[2] M. Pierrot-Deseilligny, "MicMac, un lociel de mise en correspondance
d'images, adapte au contexte geograhique" to appears in
Bulletin d'information de l'Institut Geographique National, 2007.

Francais :

MicMac est un logiciel de mise en correspondance d'image adapte
au contexte de recherche en information geographique. Il s'appuie sur
la bibliotheque de manipulation d'image eLiSe. Il est distibue sous la
licences Cecill-B.  Voir en bas de fichier et  http://www.cecill.info.


English :

MicMac is an open source software specialized in image matching
for research in geographic information. MicMac is built on the
eLiSe image library. MicMac is governed by the  "Cecill-B licence".
See below and http://www.cecill.info.

Header-MicMac-eLiSe-25/06/2007*/



#include "StdAfx.h"


/**************************************************************/
/*                                                            */
/*               Dico Camera                                  */
/*                                                            */
/**************************************************************/

static    std::string  DEFBayPatt = "RGGB";

static std::map<std::string,cCameraEntry> * statTheDicCam = 0;

void  DC_Add(std::map<std::string,cCameraEntry> * aDico,const cMMCameraDataBase & aDB)
{
	for 
		(
		std::list<cCameraEntry>::const_iterator itL=aDB.CameraEntry().begin();
	itL!=aDB.CameraEntry().end();
	itL++
		)
	{
		// std::cout << "--WWWert [" << itL->Name() << "]\n";
		//  std::map<std::string,cCameraEntry>::iterator it = aDico->find(itL->Name());
		if (aDico->find(itL->Name()) == aDico->end())
		{
			(*aDico)[itL->Name()] = *itL;
		}
	}

}

void  DC_Add(const cMMCameraDataBase & aDB)
{
	if (statTheDicCam==0)
	{
		statTheDicCam = new std::map<std::string,cCameraEntry>;
	}
	DC_Add(statTheDicCam,aDB);
}


void  DC_Add(std::map<std::string,cCameraEntry> * aDico,const std::string & aFile)
{
	if (! ELISE_fp::exist_file(aFile))
		return;


	cMMCameraDataBase aDB  = StdGetObjFromFile<cMMCameraDataBase>
		(
		aFile,
		StdGetFileXMLSpec("ParamChantierPhotogram.xml"),
		"MMCameraDataBase",
		"MMCameraDataBase"
		);

	DC_Add(aDico,aDB);

}








cCameraEntry *  CamOfName(const std::string & aName)
{
	if (statTheDicCam==0)
	{
		statTheDicCam = new std::map<std::string,cCameraEntry>;
         DC_Add(statTheDicCam,MMDir()+"include"+ELISE_CAR_DIR+"XML_User"+ELISE_CAR_DIR+"DicoCamera.xml");
         DC_Add(statTheDicCam,MMDir()+"include"+ELISE_CAR_DIR+"XML_MicMac"+ELISE_CAR_DIR+"DicoCamera.xml");
	}
	std::map<std::string,cCameraEntry>::iterator iT = statTheDicCam->find(aName);
	if (iT==statTheDicCam->end())
		return 0;
	return &(iT->second);
}


void WarnNo35(const std::string aName)
{
	static std::set<std::string> aSetDeja;

	if (aSetDeja.find(aName) != aSetDeja.end())
		return;

	aSetDeja.insert(aName);

	std::cout << "WARN  !! , for camera "  << aName << " cannot determine focale equiv-35mm\n";
	std::cout << "          add it in include/XML_User/DicoCamera.xml\n";
}


/**************************************************************/
/*                                                            */
/*               cElHour                                      */
/*                                                            */
/**************************************************************/


cElHour::cElHour
	(
	int aNbHour,
	int aNbMin,
	double aNbSec
	) :
mH  (aNbHour),
	mM  (aNbMin),
	mS  (aNbSec)
{
}

int cElHour::H() const {return mH;}
int cElHour::M() const {return mM;}
double cElHour::S() const {return mS;}

double cElHour::InSec() const
{
	return  3600.0*mH + 60.0*mM + mS;
}

bool cElHour::operator==( const cElHour &i_b ) const
{
	return ( (mH==i_b.mH ) && (mM==i_b.mM) && (mS==i_b.mS) );
}

bool cElHour::operator!=( const cElHour &i_b ) const
{
	return !( *this==i_b );
}

template <>  std::string ToString(const cElHour & aH)
{
	return   ToString(aH.H())+ std::string(":")
		+ ToString(aH.M())+ std::string(":")
		+ ToString(aH.S());

}


/**************************************************************/
/*                                                            */
/*               cElDate                                      */
/*                                                            */
/**************************************************************/

cElDate::cElDate
	(
	int aD,
	int aM,
	int aY,
	const cElHour &  aH
	) :
mD  (aD),
	mM  (aM),
	mY  (aY),
	mH  (aH)
{
}


#define NoDay -100 

const cElDate cElDate::NoDate(NoDay,NoDay,0,cElHour(0,0,0));

bool cElDate::IsNoDate() const
{
	return mD == NoDay;
}




const int cElDate::TheNonBisLengthMonth[12]={31,28,31,30,31,30,
	31,31,30,31,30,31};

int cElDate::TheNonBisLengthMonthCum[12];
int cElDate::TheBisLengthMonthCum[12];
bool  cElDate::mTabuliIsInit = false;

bool cElDate::TheIsBis[3000];
int  cElDate::TheNbDayFromJC[3000];


// Ne prend pas en compte les 13 jours "sautes " au 17e
bool cElDate::PrivIsBissextile(int aY)
{
	if ((aY%400) == 0) return true;
	if ((aY%100) == 0) return false;
	if ((aY%4) == 0)   return true;
	return false;
}

int cElDate::Y() const { return mY;}
int cElDate::M() const { return mM;}
int cElDate::D() const { return mD;}
const cElHour &  cElDate::H() const { return mH; }


template <>  std::string ToString(const cElDate & aD)
{
	return   ToString(aD.D())+ std::string("/")
		+ ToString(aD.M())+ std::string("/")
		+ ToString(aD.Y())+ std::string(" ")
		+ ToString(aD.H());

}


cElDate cElDate::FromString(const std::string & aStr)
{
	int D,M,Y,h,m;
	double s;
	int aNb= sscanf(aStr.c_str(),"%d/%d/%d %d:%d:%lf",&D,&M,&Y,&h,&m,&s);
	ELISE_ASSERT(aNb==6,"cElDate::FromString");
	return cElDate(D,M,Y,cElHour(h,m,s));
}

void cElDate::InitTabul()
{
	if (mTabuliIsInit)
		return;
	mTabuliIsInit = true;
	TheNonBisLengthMonthCum[0] = TheBisLengthMonthCum[0] = 0;

	for (int aM=1 ; aM<12 ; aM++)
	{
		TheNonBisLengthMonthCum[aM] =    TheNonBisLengthMonth[aM-1]
		+  TheNonBisLengthMonthCum[aM-1];
		TheBisLengthMonthCum[aM] =       TheNonBisLengthMonth[aM-1]
		+  TheBisLengthMonthCum[aM-1];
		if (aM==2) // Donc Mars
			TheBisLengthMonthCum[aM]++;
	}

	TheNbDayFromJC[0] = 0;
	for (int aY=0 ; aY<3000 ; aY++)
	{
		TheIsBis[aY] = PrivIsBissextile(aY);
		if (aY>0)
		{
			TheNbDayFromJC[aY] = TheNbDayFromJC[aY-1]
			+ (TheIsBis[aY-1] ? 366 : 365);
		}
	}
}


int cElDate::NbDayFrom1erJ() const
{
	InitTabul();
	return   (TheIsBis[mY] ? TheBisLengthMonthCum[mM-1] : TheNonBisLengthMonthCum[mM-1])
		+ mD-1 ;
}

int cElDate::NbDayFromJC() const
{
	InitTabul();
	return   NbDayFrom1erJ()
		+ TheNbDayFromJC[mY-1];
}

bool operator < (const cElDate & aD1, const cElDate & aD2)
{
	int aDD = aD1.DifInDay(aD2);
	if (aDD < 0) return true;
	if (aDD > 0) return false;

	double aDS = aD1.DifInSec(aD2);
	return aDS  < 0;
}


bool cElDate::operator ==( const cElDate &i_b ) const
{
	return ( (mD==i_b.mD ) && (mM==i_b.mM) && (mY==i_b.mY) && (mH==i_b.mH) );
}

bool cElDate::operator !=( const cElDate &i_b ) const
{
	return !( *this==i_b );
}

int  cElDate::DifInDay(const cElDate& aD2) const
{
	InitTabul();
	return NbDayFromJC() -  aD2.NbDayFromJC();
}

double  cElDate::DifInSec(const cElDate& aD2) const
{
	InitTabul();

	return    DifInDay(aD2) * (3600.0*24.0)
		+  (mH.InSec() - aD2.mH.InSec());
}


/************************************************************/
/*                                                          */
/*            cMetaDataPhoto                                */
/*                                                          */
/************************************************************/

std::string ToStrBlkCorr(const std::string & aStr)
{
	return std::string("\"") + aStr +  std::string("\"");
}

const Pt2dr aPRefFullFrame(24,36);


cElRegex * cMetaDataPhoto::mDateRegExiV2=0;
cElRegex * cMetaDataPhoto::mFocRegExiV2=0;
cElRegex * cMetaDataPhoto::mFoc35RegExiV2=0;
cElRegex * cMetaDataPhoto::mExpTimeRegExiV2=0;
cElRegex * cMetaDataPhoto::mDiaphRegExiV2=0;
cElRegex * cMetaDataPhoto::mIsoSpeedRegExiV2=0;
cElRegex * cMetaDataPhoto::mCameraExiV2=0;
cElRegex * cMetaDataPhoto::mSzImExiV2=0;



std::string  cMetaDataPhoto::ExeCom(const std::string & aNameProg,const std::string & aNameFile)
{
	double aTime = ElTimeOfDay();
	aTime = aTime-int(aTime);
	std::string aStrN = ToString(round_ni(aTime*1e6));
	std::string aNameF = 
		"XXX-hkjyur-ToTo" 
		+ NameWithoutDir(aNameFile) 
		+ "_"
		+ aStrN
		+ ".txt";
	std::string aCom = aNameProg + ToStrBlkCorr(aNameFile) + std::string(" > ")+ aNameF;

	int aRes = system_call(aCom.c_str());
	if (aRes%256!=0)  // Pourquoi 256  : ??!?
	{
		std::cout << "COM="<< aCom << "\n";
		ELISE_ASSERT
			(
			aRes==0,
			"Cannot exec cMetaDataPhoto::ExeCom"
			);
	}
	return aNameF;
}







cMetaDataPhoto::cMetaDataPhoto
	(
	const std::string & aNameIm,
	Pt2di aXifSzIm,
	const std::string & aCam,
	cElDate aDate,
	double aFocMm,
	double aFoc35,
	double aExpTime,
	double aDiaph,
	double anIsoSpeed,
	const std::string & aBayPat
	) :
mNameIm    (aNameIm),
	mTifSzIm   (-1,-1),
	mXifSzIm   (aXifSzIm),
	mCam       (aCam),
	mDate      (aDate),
	mFocMm     (aFocMm),
	mFocForced (false),
	mFoc35     (aFoc35),
	mExpTime   (aExpTime),
	mDiaph     (aDiaph),
	mIsoSpeed  (anIsoSpeed),
	mXYZ_Init  (false),
	mTeta_Init (false),
	mBayPat    (aBayPat)
{
	if (mBayPat=="") 
		mBayPat = DEFBayPatt;

	char * CBP = const_cast<char *>(mBayPat.c_str());
	int aKV = 0;
	for (; *CBP  ; CBP++)
	{
		if (*CBP=='G')
		{
			if (aKV==0) 
				*CBP = 'V';
			if (aKV==1) 
				*CBP = 'W';
			aKV ++;
		}
	}
}

const std::string & cMetaDataPhoto::BayPat() const {return mBayPat;}

// template <class Type> void GccUse(const Type & ) {}

double cMetaDataPhoto::MultiplierEqual(const cMetaDataPhoto & aRef,bool * aPtrAllOk) const
{
	double aRes = 1;
	bool AllOk = true;

	if ((mIsoSpeed>0) && (aRef.mIsoSpeed>0))
		aRes *= aRef.mIsoSpeed / mIsoSpeed;
	else
		AllOk = false;


	if ((mExpTime>0) && (aRef.mExpTime>0))
		aRes *= aRef.mExpTime / mExpTime;
	else
		AllOk = false;


	if ((mDiaph>0) && (aRef.mDiaph>0))
		aRes *= ElSquare(mDiaph/aRef.mDiaph);
	else
		AllOk = false;

	if (aPtrAllOk)  
		*aPtrAllOk = true;

	GccUse(AllOk);
	return aRes;
}


bool &  cMetaDataPhoto::FocForced(){return mFocForced;}

const std::string & cMetaDataPhoto::Cam(bool Svp) const 
{ 
	ELISE_ASSERT(Svp || (mCam!=""),"cMetaDataPhoto::Cam UnInit");
	return mCam; 
}
const cElDate & cMetaDataPhoto::Date(bool Svp) const 
{ 
	ELISE_ASSERT(Svp || (!mDate.IsNoDate()) ,"cMetaDataPhoto::Date UnInit");
	return mDate; 
}
double  cMetaDataPhoto::FocMm(bool Svp) const 
{ 
	ELISE_ASSERT(Svp || (mFocMm>0) ,"cMetaDataPhoto::Foc");
	return mFocMm; 
}
double  cMetaDataPhoto::Foc35(bool Svp) const 
{ 
	ELISE_ASSERT(Svp || (mFoc35>0) ,"cMetaDataPhoto::Foc35 UnInit");
	return mFoc35; 
}
double  cMetaDataPhoto::ExpTime(bool Svp) const 
{ 
	ELISE_ASSERT(Svp || (mExpTime>0) ,"cMetaDataPhoto::Date UnInit");
	return mExpTime; 
}
double  cMetaDataPhoto::Diaph(bool Svp) const 
{ 
	ELISE_ASSERT(Svp || (mDiaph>0) ,"cMetaDataPhoto::Date UnInit");
	return mDiaph;
}
double  cMetaDataPhoto::IsoSpeed(bool Svp) const 
{ 
	ELISE_ASSERT(Svp || (mIsoSpeed>0) ,"cMetaDataPhoto::Date UnInit");
	return mIsoSpeed; 
}

Pt2di  cMetaDataPhoto::XifSzIm(bool Svp) const 
{ 
	ELISE_ASSERT(Svp || (mXifSzIm.x>0) ,"cMetaDataPhoto::Date UnInit");
	return mXifSzIm; 
}

double  cMetaDataPhoto::FocPix() const
{
    return Foc35()   *  (euclid(XifSzIm()) / euclid(aPRefFullFrame));
}


Pt2di  cMetaDataPhoto::TifSzIm(bool Svp) const 
{ 
	// ELISE_ASSERT(Svp || (mXifSzIm.x>0) ,"cMetaDataPhoto::Date UnInit");
	if (mTifSzIm.x<0)
	{
		Tiff_Im aTF = Tiff_Im::StdConvGen(mNameIm,1,true,true);
		mTifSzIm = aTF.sz();
	}
	return mTifSzIm; 
}

Pt2di  cMetaDataPhoto::SzImTifOrXif(bool Svp) const
{
  Pt2di aSz = XifSzIm(Svp);
  if (aSz.x>0) return aSz;
  aSz = TifSzIm(Svp);
  ELISE_ASSERT(Svp || (aSz.x>0) ,"cMetaDataPhoto::Date UnInit");
  return aSz;
}


/*
std::cout << "AAAAAAkklMMMmpp \n"; getchar();
*/


static std::map<std::string,cMetaDataPhoto *>  TheDicoMDP;




const cMetaDataPhoto & cMetaDataPhoto::CreateExiv2(const std::string & aNameFile)
{
	std::map<std::string,cMetaDataPhoto*>::iterator itT = TheDicoMDP.find(aNameFile);
	if (itT != TheDicoMDP.end())
		return *(itT->second);

	cMetaDataPhoto * aMDP = new cMetaDataPhoto(CreateNewExiv2(aNameFile));
	TheDicoMDP[aNameFile] = aMDP;


	cInterfChantierNameManipulateur *aGICNM = cInterfChantierNameManipulateur::Glob();
	if (aGICNM)
	{
		std::string aStrF = aGICNM->Assoc1To1("NKS-Assoc-STD-FOC",NameWithoutDir(aNameFile),true);
		// std::string aStrF = aGICNM->Assoc1To1("NKS-Assoc-STD-FOC",aNameFile,true);
		double aF; 
		FromString(aF,aStrF);

		/// std::cout << "JJJJJJJJJj " << aF << "\n";
		if (aF>0)
		{
			if (aMDP->FocMm(true)>0)
			{
				cElWarning::FocInxifAndMM.AddWarn("Cam="+aNameFile,__LINE__,__FILE__);
			}
			aMDP->SetFocal(aF);
			aMDP->FocForced() = true;
		}
	}

	// if ((aMDP->Cam(true)=="") && aGICNM)
	if (aGICNM)  // On donne priorite a la focale
	{
		std::string aStrCam =  aGICNM->Assoc1To1("NKS-Assoc-STD-CAM",NameWithoutDir(aNameFile),true);
		// std::string aStrCam =  aGICNM->Assoc1To1("NKS-Assoc-STD-CAM",aNameFile,true);
		if (aStrCam!="NO-CAM")
		{
			if (aMDP->Cam(true)!="")
			{
				cElWarning::CamInxifAndMM.AddWarn("Cam="+aNameFile,__LINE__,__FILE__);
			}
			aMDP->SetCam(aStrCam);
		}
	}

	if (aGICNM)  // On donne priorite a la focale
	{
		std::pair<std::string,std::string>  aPair =  aGICNM->Assoc2To1("NKS-Assoc-STD-SZ",NameWithoutDir(aNameFile),true);
		if (aPair.first!="NO-SZ")
		{
			Pt2di aSz;
			FromString(aSz.x,aPair.first);
			FromString(aSz.y,aPair.second);
			aMDP->SetSz(aSz);
		}
	}




	double aF35 = aMDP->Foc35(true);
	bool  aFForced  = aMDP->FocForced();

	if ((aF35<=0) || (aFForced))
	{
           std::string aNameCam = aMDP->Cam(true);
           if (aNameCam!="")
           {
		cCameraEntry *  aCE = CamOfName(aMDP->Cam());
		if (aCE)
		{
			double aLambda = euclid(aPRefFullFrame) / euclid(aCE->SzCaptMm());
			aMDP->SetFoc35(aMDP->FocMm() * aLambda);

		}
		else
		{
			WarnNo35(aMDP->Cam());
		}
           }
	}
	return *(TheDicoMDP[aNameFile]);
}

double GetFocalMmDefined(const std::string & aNameFile)
{
	const cMetaDataPhoto &  aMDP = cMetaDataPhoto::CreateExiv2(aNameFile);
	if (aMDP.FocMm() <= 0)
	{
		std::cout << "For file = " << aNameFile << "\n";
		ELISE_ASSERT(false,"Cannot get required focal from xif files ");
	}
	return aMDP.FocMm();
}


const cMetaDataPhoto  cMetaDataPhoto::TheNoMTD;
cMetaDataPhoto::cMetaDataPhoto() :
mDate(cElDate::NoDate)
{}

bool cMetaDataPhoto::IsNoMTD() const
{
	return mDate.IsNoDate();
}

//===================================================

// GERALD 
#if (ELISE_windows)
const std::string STRLANG="";
#else
const std::string STRLANG="LANG=C LANGUAGE=C ";
#endif




std::string BasicGenerateId()
{
	double aTime = ElTimeOfDay();
	aTime = aTime-int(aTime);
	return ToString(round_ni(aTime*1e6) + (round_ni(aTime*1e9)%1000));
}
std::string GenerateId()
{
	static std::string  aStr0 =BasicGenerateId();

	return aStr0 + BasicGenerateId();
}

std::string GenerateNameUnique(const std::string & aNF,const std::string Post)
{
	return "XXXX_" +  NameWithoutDir(aNF) + "_" + GenerateId()  + "_" + Post;
}








class cXifDecoder
{
public :
	static const std::vector<cXifDecoder *>  &  TheVect();
	static cMetaDataPhoto GetMTDIm(const std::string & aNameIm);
private  :
	void GenerateTxtFile(const std::string & aNameIm);
	void  GetOneDouble(cElRegex * & anAutom,bool & aGot,double & aVal);

	void  GetOneAngle(cElRegex * & anAutom,bool & aGot,double & aVal);

	cXifDecoder
		(
		const std::string & aStrExe,
		const std::string & aStrTmp,
		const std::string & aStrDate,
		const std::string & aOrderDate,
		const std::string & aStrFocal,
		const std::string & aStrF35,
		const std::string & aStrExpo,
		const std::string & aStrOuv,
		const std::string & aStrISO,
		const std::string & aStrNameCam,
		const std::string & aStrSz,
		const std::string & aStrGPSLat,
		const std::string & aStrGPSLong,
		const std::string & aStrGPSAlt,
		const std::string & aStrBayPattern
		) :
	mStrExe             (aStrExe + " "),
		mStrLangE           (STRLANG+ mStrExe),
		mStrTmp             (aStrTmp),
		mAutomDate          (new cElRegex(aStrDate,15)),
		mOrderDate          (aOrderDate),
		mAutomFoc           (new cElRegex(aStrFocal,15)),
		mAutomF35           (new cElRegex(aStrF35,15)),
		mHasF35             (aStrF35 !=""),
		mAutomExpo          (new cElRegex(aStrExpo,15)),
		mAutomOuv           (new cElRegex(aStrOuv,15)),
		mAutomISO           (new cElRegex(aStrISO,15)),
		mAutomCam           (new cElRegex(aStrNameCam,15)),
		mAutomSz            (new cElRegex(aStrSz,15)),
		mAutomGPSLat        (new cElRegex(aStrGPSLat,15)),
		mAutomGPSLong       (new cElRegex(aStrGPSLong,15)),
		mAutomGPSAlt        (new cElRegex(aStrGPSAlt,15)),
		mHasGPS             ((aStrGPSLat!="") && (aStrGPSLong!="") && (aStrGPSAlt!="")),
		mAutomBayerPattern   (new cElRegex(aStrBayPattern,15)),
		mHasBayPattern       (aStrBayPattern!="")
	{
	}

	std::string         mStrExe;
	std::string         mStrLangE;
	std::string         mStrTmp;
	std::string         mFileTxt;
	cElRegex *          mAutomDate;
	std::string         mOrderDate;
	cElRegex *          mAutomFoc;
	cElRegex *          mAutomF35;
	bool                mHasF35;
	cElRegex *          mAutomExpo;
	cElRegex *          mAutomOuv;
	cElRegex *          mAutomISO;
	cElRegex *          mAutomCam;
	cElRegex *          mAutomSz;
	cElRegex *          mAutomGPSLat;
	cElRegex *          mAutomGPSLong;
	cElRegex *          mAutomGPSAlt;
	bool                mHasGPS;
	cElRegex *          mAutomBayerPattern;
	bool                mHasBayPattern;

};


int SigneOfSize(const std::string & aSz)
{
	if ((aSz=="N") || (aSz=="E"))
		return 1;

	if ((aSz=="N") || (aSz=="E"))
		return -1;

	ELISE_ASSERT(false,"Bas size inaMincXifDecoder::GetOneAngle");
	return 0;
}

void  cXifDecoder::GetOneAngle(cElRegex * & anAutom,bool & aGot,double & aVal)
{
	if (! aGot)
	{
		int aNbMatch;
		std::string aStr=GetStringFromLineExprReg(anAutom,mFileTxt,"","$0",&aNbMatch);

		// std::cout << "STR = [" << aStr << "]\n";
		if (aStr=="")
			return;

		aGot = true;

		anAutom->Match(aStr);
		double aTeta = anAutom->VNumKIemeExprPar(1);
		double aMin = anAutom->VNumKIemeExprPar(2);
		double aSec = anAutom->VNumKIemeExprPar(3);
		std::string  aSz = anAutom->KIemeExprPar(4);

		aVal = (aTeta + aMin/60.0 + aSec / 3600.0) * SigneOfSize(aSz) ;

		aVal *= PI/180.0;

		// printf("ANGL %lf\n",aVal);
	}

	// 22.463295
	// 22.463294
	// std::cout << "AAANgle" <<  int (aRes) << " " << aRes - int (aRes) << "\n";
}

void cXifDecoder::GenerateTxtFile(const std::string & aFullName)
{
	std::string aDir,aNSsDir;

	SplitDirAndFile(aDir,aNSsDir,aFullName);

	mFileTxt = aDir + GenerateNameUnique(aNSsDir,mStrTmp);
	std::string aCom = mStrLangE + QUOTE(aFullName) + " > " + mFileTxt;
	int aRes = system_call(aCom.c_str());



	//GERALD
#if (ELISE_windows)

#else
	//const std::string STRLANG="LANG=C LANGUAGE=C ";
	if ((aRes%256) !=0)  // ?? En fait convetion ElDcraw
	{
		std::cout << "COM="<< aCom << " RES = " << aRes << "\n";
		ELISE_ASSERT
			(
			aRes==0,
			"Cannot exec cXifDecoder::GenerateTxtFile"
			);
	}
#endif
	
}

void  cXifDecoder::GetOneDouble(cElRegex * & anAutom,bool & aGot,double & aVal)
{
	int aNbMatch;
	if (!aGot)
	{
		std::vector<double> aVec = 
			GetValsNumFromLineExprReg(anAutom,mFileTxt,"", "1", &aNbMatch);
		double aVTest = VAtDef(aVec,0,-1.0);
		if (aVTest >0)
		{
			aVal = aVTest;
			aGot = true;
		}
	}
}



cMetaDataPhoto cXifDecoder::GetMTDIm(const std::string & aNameIm)
{
	const std::vector<cXifDecoder *>  &  aV =  TheVect();

	bool  GotDate = false;
	cElDate aDate = cElDate::NoDate;

	bool  GotFocal = false;
	double aFocal = -1;

	bool  GotF35 = false;
	double aF35 = -1;

	bool  GotExpo = false;
	double anExpo = -1;

	bool  GotOuv = false;
	double anOuv = -1;

	bool   GotISO = false;
	double anISO = -1;

	bool   GotCam = false;
	std::string aCam;

	bool GotGPSLat = false;
	double aLat = -1;
	bool GotGPSLong = false;
	double aLong = -1;
	bool GotGPSAlt = false;
	double anAlt = -1;

	bool GotSz = false;
	Pt2di aSz(-1,-1);

	bool GotBayPattern = false;
	std::string  BayPatt = DEFBayPatt;

	for (int aKX=0 ; aKX<int(aV.size()) ; aKX++)
	{
		cXifDecoder & aXifDec = *(aV[aKX]);
		aXifDec.GenerateTxtFile(aNameIm);
		int aNbMatch;

		if (! GotDate)
		{
			std::vector<double> aVDate =
				GetValsNumFromLineExprReg(aXifDec.mAutomDate,aXifDec.mFileTxt, "",aXifDec.mOrderDate, &aNbMatch);

			if (aNbMatch==1)
			{
				aDate = cElDate
					(
					round_ni(aVDate[2]),round_ni(aVDate[1]),round_ni(aVDate[0]),
					cElHour(round_ni(aVDate[3]),round_ni(aVDate[4]),round_ni(aVDate[5]))
					);
				GotDate = true;
			}
		}

		aXifDec.GetOneDouble(aXifDec.mAutomFoc, GotFocal,aFocal);

		if (aXifDec.mHasF35)
			aXifDec.GetOneDouble(aXifDec.mAutomF35, GotF35,aF35);


		aXifDec.GetOneDouble(aXifDec.mAutomExpo, GotExpo,anExpo);
		aXifDec.GetOneDouble(aXifDec.mAutomOuv, GotOuv,anOuv);
		aXifDec.GetOneDouble(aXifDec.mAutomISO, GotISO,anISO);

		if (!GotCam)
		{
// std::cout << "TRY CAM " << aXifDec.mStrExe << "\n";
			std::string aC=GetStringFromLineExprReg(aXifDec.mAutomCam, aXifDec.mFileTxt,"","$1",&aNbMatch);

			if (aNbMatch== 1)
			{
// std::cout << "    GOT  CAM " << aC << "\n";
				aCam = aC;
				GotCam = true;
			}
		}

		if ( !GotSz)
		{
			// GetValsNumFromLineExprReg(anAutom,mFileTxt,"", "1", &aNbMatch);
			std::vector<double> aVSz =
				GetValsNumFromLineExprReg ( aXifDec.mAutomSz, aXifDec.mFileTxt, "", "12", &aNbMatch);
			if (aNbMatch==1)
			{
				aSz = Pt2di(round_ni(VAtDef(aVSz,0,-1.0)),round_ni(VAtDef(aVSz,1,-1.0)));
				GotSz = true;
			}
		}

		if (aXifDec.mHasGPS)
		{
			if (!GotGPSLat)
				aXifDec.GetOneAngle(aXifDec.mAutomGPSLat,GotGPSLat,aLat);
			if (!GotGPSLong)
				aXifDec.GetOneAngle(aXifDec.mAutomGPSLong,GotGPSLong,aLong);
			if (!GotGPSAlt)
				aXifDec.GetOneDouble(aXifDec.mAutomGPSAlt,GotGPSAlt,anAlt);
		}

		if (!GotBayPattern)
		{
			if (aXifDec.mHasBayPattern)
			{
				std::string aPat=GetStringFromLineExprReg(aXifDec.mAutomBayerPattern, aXifDec.mFileTxt,"","$1$2$3$4",&aNbMatch);
				if (aNbMatch == 1)
				{
					BayPatt= aPat;
					GotBayPattern = true;
				}
				// std::cout << "BAYER[" << aNameIm << "]=" << aNbMatch << "," << aPat << " For" << aXifDec.mStrExe<< "\n";
			}
		}



		if (1)
		{
			ELISE_fp::RmFile(aXifDec.mFileTxt);
		}
	}

	return cMetaDataPhoto  (aNameIm,aSz,aCam,aDate,aFocal,aF35,anExpo,anOuv,anISO,BayPatt);

}

void TestXD(const std::string & aNameIm)
{
	cXifDecoder::GetMTDIm(aNameIm);
}


const std::vector<cXifDecoder *> &  cXifDecoder::TheVect()
{
	static  std::vector<cXifDecoder *> aRes;

	if (aRes.size() == 0)
	{


		aRes.push_back
			(
			new cXifDecoder
			(
              MM3dBinFile("ElDcraw")+" -i -v ",
			"ELDCRAW.txt",
			"Timestamp: .* (...)  ?([0-9]{1,2})  ?([0-9]{1,2}):([0-9]{2}):([0-9]{2}) ([0-9]{4})",
			"612345" ,
			"Focal length: ([0-9]*\\.?[0-9]*) mm",
			"Focal Equi35: (-?[0-9]*\\.?[0-9]*) mm",
			"Shutter: ((1/)?[0-9]*\\.?[0-9]*) sec" ,
			"Aperture: f/(([0-9]*\\.?[0-9]*)|(inf))" ,
			"ISO speed: ([0-9]*\\.?[0-9]*)" ,
			"Camera: (.*)", 
			"Full size:[ ]+([0-9]+) x ([0-9]+)",
			"",
			"",
			"",
			"Filter pattern: ([RGB])([RGB])([RGB])([RGB]).*"
			)
			);
		
		if ( !g_externalToolHandler.get("exiv2").isCallable() )
			cerr << "WARNING: exiv2 not found" << endl;
		else aRes.push_back(
			new cXifDecoder
			(
			string(" ")+g_externalToolHandler.get("exiv2").callName()+" ",
			"EXIV2.txt",
			"Image timestamp : ([0-9]{4}):([0-9]{2}):([0-9]{2}) ([0-9]{2}):([0-9]{2}):([0-9]{2})",
			"123456",
			"Focal length    : ([0-9]*\\.?[0-9]*) mm",
			"",
			"Exposure time   : ((1/)?[0-9]*\\.?[0-9]*) s",
			"Aperture        : F([0-9]*\\.?[0-9]*)",
			"ISO speed       : ([0-9]*\\.?[0-9]*)",
			"Camera model    : (.*)",
			"Image size      :[ ]+([0-9]+) x ([0-9]+)",
			"",
			"",
			"",
			""
			)
			);

		if ( !g_externalToolHandler.get("exiftool").isCallable() )
			cerr << "WARNING: exiftool not found" << endl;
		else aRes.push_back(
			new cXifDecoder
			(
			string(" ")+g_externalToolHandler.get("exiftool").callName()+" ",
			"EXIFTOOL.txt",
			"Create Date *: ([0-9]{4}):([0-9]{2}):([0-9]{2}) ([0-9]{2}):([0-9]{2}):([0-9]{2})",
			"123456",
			"Focal Length  *: *([0-9]*\\.?[0-9]*) *mm",
			"Focal Length  *: *[0-9]*\\.?[0-9]* *mm *\\(35 *mm *equivalent: *([0-9]*\\.?[0-9]*) *mm\\)",
			"Exposure Time   *: *((1/)?[0-9]*\\.?[0-9]*)",
			"Aperture *: ([0-9]*\\.?[0-9]*)",
			"ISO *: *([0-9]*\\.?[0-9]*)",
			"Camera Model Name *: *(.*)",
			"Image Size *: ([0-9]+)x([0-9]+)",
			"GPS Latitude *: ([0-9]*\\.?[0-9]*) deg ([0-9]*\\.?[0-9]*)\' ([0-9]*\\.?[0-9]*)\" ([SN])",
			"GPS Longitude *: ([0-9]*\\.?[0-9]*) deg ([0-9]*\\.?[0-9]*)\' ([0-9]*\\.?[0-9]*)\" ([EW])",
			"GPS Altitude *: ([0-9]*\\.?[0-9]*).*",
			"CFA Pattern                     : \\[([RGB]).*\\,([RGB]).*\\]\\[([RGB]).*\\,([RGB]).*\\]"
			)
			);
	}

	return aRes;
}




cMetaDataPhoto cMetaDataPhoto::CreateNewExiv2(const std::string & aNameFile) // ,const char *  aNameTest)
{

	return cXifDecoder::GetMTDIm(aNameFile);
}

#if (0)
{
	bool aModeDCRaw = true;


	const char * aNameFileTMP;
	std::string aStrTMP;

	/*
	if (aNameTest)
	{
	aNameFileTMP = aNameTest;
	if (sizeofile(aNameTest)==0)
	{
	return TheNoMTD;
	}
	}
	else
	*/
	{
		// std::string aStrCom = aModeDCRaw ? "LANG=C dcraw -i -v " : "exiv2 ";
		bool OK = false;
		for (int aKTest=0 ; (aKTest<2) && (! OK)  ; aKTest++)
		{
			aModeDCRaw  = (aKTest==0);
          std::string aStrCom = aModeDCRaw ? (STRLANG+MMDir()+"bin"+ELISE_CAR_DIR+"ElDcraw -i -v ") : (STRLANG+ " exiv2 ");
			aStrTMP = ExeCom(aStrCom,aNameFile);
			aNameFileTMP = aStrTMP.c_str();
			if (sizeofile(aNameFileTMP ) != 0)
			{
				OK = true;
			}
			else
			{
				if ( ELISE_fp::exist_file(aNameFileTMP))
					ELISE_fp::RmFile(aNameFileTMP);
			}
		}
		if (!OK)
		{
			if (Tiff_Im::IsTiff(aNameFile.c_str()))
			{
				cMetaDataPhoto  aMDP = Tiff_Im(aNameFile.c_str()).MDP();

				if (aMDP.FocMm() >=0)
					return aMDP;
			}

			std::cout << "For file " << aNameFile << " Cannot get xif data\n";
			ELISE_ASSERT(false,"Nor dcraw nor exiv2 can create xif data");
		}
	}

	std::string aStrDate = aModeDCRaw ?
		"Timestamp: .* (...)  ?([0-9]{1,2})  ?([0-9]{1,2}):([0-9]{2}):([0-9]{2}) ([0-9]{4})"            :
	"Image timestamp : ([0-9]{4}):([0-9]{2}):([0-9]{2}) ([0-9]{2}):([0-9]{2}):([0-9]{2})";

	std::string aOrdreDate = aModeDCRaw ? "612345" : "123456";

	std::string aStrFoc = aModeDCRaw ? "Focal length: ([0-9]*\\.?[0-9]*) mm" : "Focal length    : ([0-9]*\\.?[0-9]*) mm";

	std::string aStrTime = aModeDCRaw ? "Shutter: ((1/)?[0-9]*\\.?[0-9]*) sec" : "Exposure time   : ((1/)?[0-9]*\\.?[0-9]*) s";

	std::string aStrOuv = aModeDCRaw ? "Aperture: f/(([0-9]*\\.?[0-9]*)|(inf))" : "Aperture        : F([0-9]*\\.?[0-9]*)";
	std::string aStrIso = aModeDCRaw ? "ISO speed: ([0-9]*\\.?[0-9]*)" :"ISO speed       : ([0-9]*\\.?[0-9]*)";


	std::string aStrCam = aModeDCRaw ? "Camera: (.*)" : "Camera model    : (.*)";


	//Modif de Greg suite a des pb avec des photos 640 x 480 (on a 4 espaces plutot que 3 apres les ':', sans doute parce qu'on a 3 chiffres au lieu des 4 habituels) 
	//std::string aStrSz = aModeDCRaw ? "Full size:   ([0-9]+) x ([0-9]+)" : "Image size      : ([0-9]+) x ([0-9]+)";
	std::string aStrSz = aModeDCRaw ? "Full size:[ ]+([0-9]+) x ([0-9]+)" : "Image size      :[ ]+([0-9]+) x ([0-9]+)";

	std::string aNameTmp = aNameFileTMP;

	//   std::cout << "11111111111111111 [" << aStrIso << "]\n";

	int aNbMatch;
	std::vector<double> aVDate =
		GetValsNumFromLineExprReg
		(
		mDateRegExiV2,
		aNameTmp,
		aStrDate,
		aOrdreDate,
		&aNbMatch
		);

	//   std::cout << "22222222222222 [" << aStrIso << "]\n";
	cElDate aDate = cElDate::NoDate;

	if (aNbMatch==1)
	{
		aDate = cElDate
			(
			round_ni(aVDate[2]),round_ni(aVDate[1]),round_ni(aVDate[0]),
			cElHour(round_ni(aVDate[3]),round_ni(aVDate[4]),round_ni(aVDate[5]))
			);
	}

	//   std::cout << "3333333333333333 [" << aStrIso << "]\n";

	std::vector<double> aVFoc =
		GetValsNumFromLineExprReg
		(
		mFocRegExiV2,
		aNameTmp,
		aStrFoc,
		"1",
		&aNbMatch
		);
	double aFoc = VAtDef(aVFoc,0,-1.0);


	//   std::cout << "44444444444444444 [" << aStrIso << "]\n";
	std::vector<double> aVExpTime =
		GetValsNumFromLineExprReg
		(
		mExpTimeRegExiV2,
		aNameTmp,
		aStrTime,
		"1",
		&aNbMatch
		);
	double aExpTime = VAtDef(aVExpTime,0,-1.0);

	//   std::cout << "55555555555555555 [" << aStrIso << "]\n";
	std::vector<double> aVDiaph =
		GetValsNumFromLineExprReg
		(
		mDiaphRegExiV2,
		aNameTmp,
		aStrOuv,
		"1",
		&aNbMatch
		);
	double aDiaph = VAtDef(aVDiaph,0,-1.0);

	//   std::cout << "AAAAAAAAAA [" << aStrIso << "]\n";
	std::vector<double> aVIsoSpeed =
		GetValsNumFromLineExprReg
		(
		mIsoSpeedRegExiV2,
		aNameTmp,
		aStrIso,
		"1",
		&aNbMatch
		);
	//   std::cout << "BBBBBBBB\n";
	double anIsoSpeed = VAtDef(aVIsoSpeed,0,-1.0);

	std::vector<double> aVSz =
		GetValsNumFromLineExprReg
		(
		mSzImExiV2,
		aNameTmp,
		aStrSz,
		"12",
		&aNbMatch
		);
	Pt2di  aSz(round_ni(VAtDef(aVSz,0,-1.0)),round_ni(VAtDef(aVSz,1,-1.0)));


	std::string aCam=GetStringFromLineExprReg(mCameraExiV2,aNameTmp,aStrCam,"$1",&aNbMatch);

	// std::cout << "CAM = " << 


	double aFoc35 = -1;
	if (aModeDCRaw)
	{
		std::string aStrFoc35 = "Focal Equi35: (-?[0-9]*\\.?[0-9]*) mm";
		std::vector<double> aVFoc35 =
			GetValsNumFromLineExprReg
			(
			mFoc35RegExiV2,
			aNameTmp,
			aStrFoc35,
			"1"
			);
		aFoc35  = aVFoc35[0];
	}
	
	ELISE_fp::RmFile(aNameTmp);

	return cMetaDataPhoto(aSz,aCam,aDate,aFoc,aFoc35,aExpTime,aDiaph,anIsoSpeed);
}
#endif

void cMetaDataPhoto::SetXYZTetas(const Pt3dr & aXYZ,const Pt3dr & aTetas)
{
	mXYZ = aXYZ;
	mTetas = aTetas;
	mXYZ_Init = true;
	mTeta_Init = true;
}

bool cMetaDataPhoto::XYZTetasInit() const
{
	return mXYZ_Init  && mTeta_Init;
}


const Pt3dr & cMetaDataPhoto::XYZ() const
{
	ELISE_ASSERT(mXYZ_Init,"cMetaDataPhoto::XYZ");
	return mXYZ;
}

const Pt3dr &  cMetaDataPhoto::Tetas() const
{
	ELISE_ASSERT(mTeta_Init,"cMetaDataPhoto::XYZ");
	return mTetas;
}

void cMetaDataPhoto::SetSz(const Pt2di & aSz)
{
	mXifSzIm = aSz;
	mTifSzIm = aSz;
}

void cMetaDataPhoto::SetCam(const std::string & aNameCam)
{
	mCam = aNameCam;
}

void cMetaDataPhoto::SetFocal(const double & aF)
{
	mFocMm = aF;
}

void cMetaDataPhoto::SetFoc35(const double & aF)
{
	mFoc35 = aF;
}


static std::string EntrePar(const std::string & aStr)
{
	return std::string("(")+aStr+std::string(")");
}

static std::string Optionel(const std::string & aStr)
{
	return EntrePar(aStr)+std::string("?");
}



const std::string & ExprRegEntierPos()
{
	static std::string  aRes = "[0-9]+";
	return aRes;
}

const std::string & ExprRegEntierSigne()
{
	static std::string  aRes = std::string("-?")+ ExprRegEntierPos();
	return aRes;
}

const std::string & ExprFlottant()
{
	static std::string aRes = ExprRegEntierSigne() + Optionel(std::string("\\.")+ExprRegEntierPos());
	return aRes;
}

const std::string & ExprFlottantScient()
{
	static std::string aRes = ExprFlottant() + Optionel("E|e"+ExprRegEntierSigne());
	return aRes;
}

std::string Repeat(int aNb,const std::string & aCh)
{
	std::string aRes ;
	for (int aK=0 ; aK<aNb; aK++)
		aRes = aRes + aCh;
	return aRes;
}


const std::string & ExprMetaUDS()
{
	static  std::string Blanc=" *";
	static  std::string aRes =   
		Blanc
		// + EntrePar("[0-9]{4}_[0-9]{4}")
		+ EntrePar("[0-9]{4}")
		+ Repeat(6,"[ \t]+"+EntrePar(ExprFlottant()))
		+ Blanc;
	// std::cout << "EXPRUDS=["<<aRes<<"]\n";
	return aRes;
}

cElRegex * cElRegex::AutomUDS()
{
	static cElRegex *  aRes = new cElRegex(ExprMetaUDS(),30);
	return aRes;
}
const std::string & ExprMetaSurvey()
{
	static std::string V = ",";
	static std::string aRes =
		EntrePar(ExprRegEntierPos())  // Num
		+ Repeat(6,V +EntrePar(ExprRegEntierPos())) // Y M D H M S (S sur 4 Ch)
		+ Repeat(3,V+ EntrePar(ExprFlottant()))     // Angles
		+ Repeat(2,V +EntrePar(ExprRegEntierPos()))  // X,Y
		+ Repeat(2,V+EntrePar(ExprFlottant()))     // Z1 Z2, a priori redondant
		+ Repeat(1,V +EntrePar(ExprRegEntierPos()))  // ?
		;
	return aRes;
}


cElRegex * cElRegex::AutomSurvey()
{
	static cElRegex *  aRes = new cElRegex(ExprMetaSurvey(),30);
	return aRes;
}


cMetaDataPhoto  MDP_Survey_FromString(const std::string & aCh)
{
	bool aMatch = cElRegex::AutomSurvey()->Match(aCh);
	if (! aMatch)
	{
		std::cout << "For Str=[" << aCh << "]\n";
		ELISE_ASSERT(false,"MDP_Survey_FromString");
	}
	/*
	std::cout << aCh << "\n";
	std::cout  << ExprMetaSurvey() << "\n";

	std::cout << "Match : " <<  AutomSurvey().Match(aCh) << "\n";

	std::cout <<  AutomSurvey().VNumKIemeExprPar(2) << "\n";
	std::cout <<  AutomSurvey().VNumKIemeExprPar(3) << "\n";
	std::cout <<  AutomSurvey().VNumKIemeExprPar(4) << "\n";
	std::cout <<  AutomSurvey().VNumKIemeExprPar(5) << "\n";
	std::cout <<  AutomSurvey().VNumKIemeExprPar(6) << "\n";
	std::cout <<  AutomSurvey().VNumKIemeExprPar(7) << "\n";

	std::cout << " Teta0 " <<  AutomSurvey().VNumKIemeExprPar(8) << "\n";
	std::cout << " Teta1 " <<  AutomSurvey().VNumKIemeExprPar(10) << "\n";
	std::cout << " Teta2 " <<  AutomSurvey().VNumKIemeExprPar(12) << "\n";

	std::cout << " X " <<  (int)AutomSurvey().VNumKIemeExprPar(14) << "\n";
	std::cout << " Y " <<  (int)AutomSurvey().VNumKIemeExprPar(15) << "\n";
	std::cout << " Z " <<  AutomSurvey().VNumKIemeExprPar(16) << "\n";
	*/


	cElHour aH(
		round_ni(cElRegex::AutomSurvey()->VNumKIemeExprPar(5)),
		round_ni(cElRegex::AutomSurvey()->VNumKIemeExprPar(6)),
		round_ni(cElRegex::AutomSurvey()->VNumKIemeExprPar(7)) /100.0
		);
	cElDate aD
		(
		round_ni(cElRegex::AutomSurvey()->VNumKIemeExprPar(4)),
		round_ni(cElRegex::AutomSurvey()->VNumKIemeExprPar(3)),
		round_ni(cElRegex::AutomSurvey()->VNumKIemeExprPar(2)),
		aH
		);

	cMetaDataPhoto aMDP("Unknown Image",Pt2di(0,0),"Unknown Cam",aD,1.0,1.0,0,0,0,DEFBayPatt);
	Pt3dr aTetas
		(
		cElRegex::AutomSurvey()->VNumKIemeExprPar(8),
		cElRegex::AutomSurvey()->VNumKIemeExprPar(10),
		cElRegex::AutomSurvey()->VNumKIemeExprPar(12)
		);
	Pt3dr aXYZ
		(
		cElRegex::AutomSurvey()->VNumKIemeExprPar(14),
		cElRegex::AutomSurvey()->VNumKIemeExprPar(15),
		cElRegex::AutomSurvey()->VNumKIemeExprPar(16)
		);
	aMDP.SetXYZTetas(aXYZ,aTetas);

	// std::cout << ToString(aMDP.Date()) <<  aMDP.XYZ() << aMDP.Tetas() << "\n";
	std::cout
		<<  aMDP.XYZ().z << "   "
		<<  (aMDP.Tetas().x+aMDP.Tetas().z) << "   "
		<<  aMDP.Tetas().y << "   "
		<< "\n";

	return aMDP;
}

std::list<cMetaDataPhoto>  LMDP_Survey_FromFile(const std::string & aNameFile)
{
	ELISE_fp aFile(aNameFile.c_str(),ELISE_fp::READ);
	std::list<cMetaDataPhoto> aRes;
	bool endof=false;
	string aBuf; // char aBuf[1000]; TEST_OVERFLOW

	while (!endof)
	{
		if ( aFile.fgets(aBuf,endof) )//if (aFile.fgets(aBuf,1000,endof)) TEST_OVERFLOW
		{
			// C'est des fichier texte Windaube, donc gaffe !
			if ( aBuf.length()!=0 ) // if (strlen(aBuf) !=0) TEST_OVERFLOW
				aRes.push_back(MDP_Survey_FromString(aBuf));
		}
	}
	return aRes;
}

void TestSurvey()
{
	LMDP_Survey_FromFile
		(
		"/mnt/data/Archi/Salses/Helico/txt/MetaData_mission2.txt"
		);

	// MDP_Survey_FromString("1,2008,5,14,8,4,5924,0.11,-0.17,-166.00,74770816,5092995,16.71,0.30,8");
}



// =====================   cLine_N_XYZ_WPK

const double cLine_N_XYZ_WPK::TheNoVal = 1e60;

cLine_N_XYZ_WPK::cLine_N_XYZ_WPK(const cElRegex_Ptr & anAutom,int * aNum,const std::string & aLine)
{
	if (! anAutom->Match(aLine))
	{
		mOK = false;
		return;
	}

	mOK = true;

	if (aNum[0] > 0)
		mName =  anAutom->KIemeExprPar(aNum[0]);



	mXYZ.x =  (aNum[1]>0) ? anAutom->VNumKIemeExprPar(aNum[1],true) : TheNoVal;
	mXYZ.y =  (aNum[2]>0) ? anAutom->VNumKIemeExprPar(aNum[2],true) : TheNoVal;
	mXYZ.z =  (aNum[3]>0) ? anAutom->VNumKIemeExprPar(aNum[3],true) : TheNoVal;

	mWPK.x =  (aNum[4]>0) ? anAutom->VNumKIemeExprPar(aNum[4],true) : TheNoVal;
	mWPK.y =  (aNum[5]>0) ? anAutom->VNumKIemeExprPar(aNum[5],true) : TheNoVal;
	mWPK.z =  (aNum[6]>0) ? anAutom->VNumKIemeExprPar(aNum[6],true) : TheNoVal;

	// std::cout << "GHGUJ " <<mXYZ << " " << mWPK << "\n";

}

std::vector<cLine_N_XYZ_WPK> cLine_N_XYZ_WPK::FromFile
	(
	const cElRegex_Ptr & anAutom,
	int *aNum,
	const std::string & aNameFile,
	bool aShowLinNonInterp

	)
{
	ELISE_fp aFile(aNameFile.c_str(),ELISE_fp::READ);
	bool endof=false;
	string aBuf; // char aBuf[1000]; TEST_OVERFLOW

	std::vector<cLine_N_XYZ_WPK> aRes;

	while (!endof)
	{
		if (aFile.fgets(aBuf,endof)) //if (aFile.fgets(aBuf,1000,endof)) TEST_OVERFLOW
		{
			if (!endof)
			{
				cLine_N_XYZ_WPK aV(anAutom,aNum,aBuf);
				if (aV.mOK)
				{

					aRes.push_back(aV);
				}
				else  
				{
					if ( aShowLinNonInterp)
					{
						std::cout << "----------- Ligne Non Interpretee =\n";
						std::cout << "[" << aBuf<< "]" << "\n";
					}
				}
			}
		}
	}
	return aRes;
}



/*
const std::string & ExprFlottant()

static const std::string ExprEntier ="(-?[0-9]*)";
static const std::string ExpFlottant ="(-?[0-9]+(\.[0-9]+)?)";
static const std::string ExpFlottantScient ="(-?[0-9]+(\.[0-9]+)?)";
*/


/*Footer-MicMac-eLiSe-25/06/2007

Ce logiciel est un programme informatique servant à la mise en
correspondances d'images pour la reconstruction du relief.

Ce logiciel est régi par la licence CeCILL-B soumise au droit français et
respectant les principes de diffusion des logiciels libres. Vous pouvez
utiliser, modifier et/ou redistribuer ce programme sous les conditions
de la licence CeCILL-B telle que diffusée par le CEA, le CNRS et l'INRIA
sur le site "http://www.cecill.info".

En contrepartie de l'accessibilité au code source et des droits de copie,
de modification et de redistribution accordés par cette licence, il n'est
offert aux utilisateurs qu'une garantie limitée.  Pour les mêmes raisons,
seule une responsabilité restreinte pèse sur l'auteur du programme,  le
titulaire des droits patrimoniaux et les concédants successifs.

A cet égard  l'attention de l'utilisateur est attirée sur les risques
associés au chargement,  à l'utilisation,  à la modification et/ou au
développement et à la reproduction du logiciel par l'utilisateur étant
donné sa spécificité de logiciel libre, qui peut le rendre complexe à
manipuler et qui le réserve donc à des développeurs et des professionnels
avertis possédant  des  connaissances  informatiques approfondies.  Les
utilisateurs sont donc invités à charger  et  tester  l'adéquation  du
logiciel à leurs besoins dans des conditions permettant d'assurer la
sécurité de leurs systèmes et ou de leurs données et, plus généralement,
à l'utiliser et l'exploiter dans les mêmes conditions de sécurité.

Le fait que vous puissiez accéder à cet en-tête signifie que vous avez
pris connaissance de la licence CeCILL-B, et que vous en avez accepté les
termes.
Footer-MicMac-eLiSe-25/06/2007*/
