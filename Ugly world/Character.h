//----------------------------------------------------------
// заголовок тут (c)
//----------------------------------------------------------

#pragma once

#include <cstdint> // uint32_t
#include <string>
#include <map>
#include <list>
#include "CAttrib.h"	//классы атрибутов
#include "CChar.h"		//классы тем и черт характера
#include "CharEnums.h"
#include "Factions.h"
#include "explicitIntegralID.h"

namespace tinyxml2
{
	class XMLElement; // это сделано что бы не делать #include <tinyxml2.h> сюда.
};

//----------------------------------------------------------
using tCharID = ExplicitIntegralID<uint32_t, class CharIDTag>;
constexpr tCharID InvalidCharID(0);
constexpr bool IsValid(const tCharID id)
{
	return id != InvalidCharID;
}
//----------------------------------------------------------
class Character
{
private:
	tCharID								mCharID = InvalidCharID;
	std::string							mName = "";
	eRace								mRace = eRace::Human;
	int									mAge = 1;
	eGender								mGender = eGender::Male;
	tSociability						mSociability = 0;
	tNeatness							mNeatness = 0;
	eSocietyClass						mSocietyClass = eSocietyClass::SC1;
	tFactionID							mFactionID = InvalidFactionID;
	eMainTask							mMainTask = eMainTask::mat1;
	eMomentTask							mMomentTask = eMomentTask::mot1;
	eStatus								mStatus = eStatus::status0;
	ePhysicalFatigue					mPhysicalFatigue = ePhysicalFatigue::pf1;
	eMentalFatigue						mMentalFatigue = eMentalFatigue::mf1;
	eMood								mMood = eMood::m1;
	tMAttrib							mAttribP;
	tMAttrib							mAttribPM;
	tMAttrib							mAttribM;
	std::list<tCharID>					mKinList;
	std::map<Skills,int>				mSkills;
	std::map<eWorldView, tWorldViewPos>	mWorldView;
	std::map<eThems,Them*>				mThems;
	std::map<eTraits,Trait*>			mTraits;
	//Knowledge							mKnowledge;
	//Aptitude							mAptitude;
	//std::map<AreaId,int>				mRSs;
public:
	Character();
	void setId(tCharID id);
	void setName(const char* x);
	void setAge(const int x);
	void setGender(const eGender x);
	void setRace(const eRace x);
	void setSociability(const tSociability x);
	void setNeatness(const tNeatness x);
	void setSocietyClass(const eSocietyClass x);
	void setFaction(const tFactionID id);
	void setWorldView(const eWorldView type, const tWorldViewPos pos);
	void setMainTask(const eMainTask x);
	void setMomentTask(const eMomentTask x);
	void setStatus(const eStatus x);
	void setAttrib_P(unsigned int x0, unsigned int x1, unsigned int x2, unsigned int x3);
	void setAttrib_PM(unsigned int x0, unsigned int x1, unsigned int x2, unsigned int x3);
	void setAttrib_M(unsigned int x0, unsigned int x1, unsigned int x2, unsigned int x3);
	void setPF(ePhysicalFatigue x);
	void setMF(eMentalFatigue x);
	void setThems(eThems n, Them* x);

	bool SerializeFromXML(const tinyxml2::XMLElement* node);
	void Tick();
};


