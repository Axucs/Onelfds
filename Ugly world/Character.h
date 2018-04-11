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

namespace tinyxml2
{
	class XMLElement;// это сделано что бы не делать #include <tinyxml2.h> сюда.
};

//----------------------------------------------------------
class Character
{
private:
	int								CharID;
	std::string						NAME;
	Race							RACE;
	int								AGE;
	Sex								SEX;
	Sociability						SOCIABILITY;
	Neatness						NEATNESS;
	SocietyClass					SOCIETY_CLASS;
	//Faction
	Main_task						MAIN_TASK;
	Moment_task						MOMENT_TASK;
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
	void setSex(const Sex x);
	void setRace(const Race x);
	void setSociability(const int x);
	void setNeatness(const Neatness x);
	void setSociety_class(const SocietyClass x);
	void setWorld_view(const World_view x);
	void setMain_task(const Main_task x);
	void setMoment_task(const Moment_task x);
	void setAttrib_P(unsigned int x0, unsigned int x1, unsigned int x2, unsigned int x3);
	void setAttrib_PM(unsigned int x0, unsigned int x1, unsigned int x2, unsigned int x3);
	void setAttrib_M(unsigned int x0, unsigned int x1, unsigned int x2, unsigned int x3);
	void setPF(Physical_Fatigue x);
	void setMF(Mental_Fatigue x);
	void setThems(Thems n, Them* x);

	bool SerializeFromXML(const tinyxml2::XMLElement* node);
	void Tick();
};


