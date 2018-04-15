//----------------------------------------------------------
// заголовок тут (c)
//----------------------------------------------------------

#pragma once

#include <string>
#include <map>
#include <list>
#include "CAttrib.h"	//классы атрибутов
#include "CChar.h"		//классы тем и черт характера
#include "CharEnums.h"
#include "Factions.h"

namespace tinyxml2
{
	class XMLElement; // это сделано что бы не делать #include <tinyxml2.h> сюда.
};

//----------------------------------------------------------
class Character
{
private:
	int								CharID;
	std::string						NAME;
	tRace							RACE;
	int								AGE;
	tSex							SEX;
	tSociability					SOCIABILITY;
	tNeatness						NEATNESS;
	tSocietyClass					SOCIETY_CLASS;
	FactionID                       factionID = InvalidFactionID;
	tMainTask						MAIN_TASK;
	tMomentTask						MOMENT_TASK;
	//Status						STATUS;
	//kin list
	//std::map<Skills,CSlills>		SKILLS;
	MAttrib							ATTRIB_P;
	MAttrib							ATTRIB_PM;
	MAttrib							ATTRIB_M;
	//Knowledge						KNOWLEDGE;
	//std::list<World_view, CW_V>	WORLD_VIEW;
	Mood							MOOD;
	Physical_Fatigue				PHYSICAL_FATIGUE;
	Mental_Fatigue					MENTAL_FATIGUE;
	//Aptitude						APTITUDE;
	std::map<Thems,Them*>			THEMS;
	//std::map<AreaId,int>			RSs;
	//std::map<Traits,Trait*>		TRAITS;
public:
	Character();
	void setName(const char* x);
	void setAge(const int x);
	void setSex(const tSex x);
	void setRace(const tRace x);
	void setSociability(const tSociability x);
	void setNeatness(const tNeatness x);
	void setSociety_class(const tSocietyClass x);
	void setWorld_view(const World_view x);
	void setMainTask(const tMainTask x);
	void setMomentTask(const tMomentTask x);
	void setAttrib_P(unsigned int x0, unsigned int x1, unsigned int x2, unsigned int x3);
	void setAttrib_PM(unsigned int x0, unsigned int x1, unsigned int x2, unsigned int x3);
	void setAttrib_M(unsigned int x0, unsigned int x1, unsigned int x2, unsigned int x3);
	void setPF(Physical_Fatigue x);
	void setMF(Mental_Fatigue x);
	void setThems(Thems n, Them* x);

	bool SerializeFromXML(const tinyxml2::XMLElement* node);
	void Tick();
};


