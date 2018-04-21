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
using CharID = ExplicitIntegralID<uint32_t, class CharIDTag>;
constexpr CharID InvalidCharID(0);
constexpr bool IsValid(const CharID id)
{
	return id != InvalidCharID;
}
//----------------------------------------------------------
class Character
{
private:
	CharID							mCharID = InvalidCharID;
	std::string						NAME = "";
	eRace							RACE = eRace::Human;
	int								AGE = 1;
	eGender							Gender = eGender::Male;
	tSociability					SOCIABILITY = 0;
	tNeatness						NEATNESS = 0;
	eSocietyClass					SOCIETY_CLASS = eSocietyClass::SC1;
	FactionID                       factionID = InvalidFactionID;
	tMainTask						MAIN_TASK = tMainTask::mat1;
	tMomentTask						MOMENT_TASK = tMomentTask::mot1;
	tStatus							STATUS = tStatus::status0;
	ePhysicalFatigue				PHYSICAL_FATIGUE = ePhysicalFatigue::pf1;
	eMentalFatigue					MENTAL_FATIGUE = eMentalFatigue::mf1;
	eMood							MOOD = eMood::m1;
	MAttrib							ATTRIB_P;
	MAttrib							ATTRIB_PM;
	MAttrib							ATTRIB_M;
	//kin list
	//std::map<Skills,CSlills>		SKILLS;
	//Knowledge						KNOWLEDGE;
	//std::list<World_view, CW_V>	WORLD_VIEW;
	//Aptitude						APTITUDE;
	std::map<Thems,Them*>			THEMS;
	//std::map<AreaId,int>			RSs;
	//std::map<Traits,Trait*>		TRAITS;
public:
	Character();
	void setId(CharID id);
	void setName(const char* x);
	void setAge(const int x);
	void setGender(const eGender x);
	void setRace(const eRace x);
	void setSociability(const tSociability x);
	void setNeatness(const tNeatness x);
	void setSocietyClass(const eSocietyClass x);
	void setFaction(const FactionID id);
	void setWorldView(const World_view x);
	void setMainTask(const tMainTask x);
	void setMomentTask(const tMomentTask x);
	void setStatus(const tStatus x);
	void setAttrib_P(unsigned int x0, unsigned int x1, unsigned int x2, unsigned int x3);
	void setAttrib_PM(unsigned int x0, unsigned int x1, unsigned int x2, unsigned int x3);
	void setAttrib_M(unsigned int x0, unsigned int x1, unsigned int x2, unsigned int x3);
	void setPF(ePhysicalFatigue x);
	void setMF(eMentalFatigue x);
	void setThems(Thems n, Them* x);

	bool SerializeFromXML(const tinyxml2::XMLElement* node);
	void Tick();
};


