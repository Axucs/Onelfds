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

namespace tinyxml2 {
	class XMLElement;// это сделано что бы не делать #include <tinyxml2.h> сюда.
};

//----------------------------------------------------------
class Character {
private:
	int								CharID;
	std::string						NAME;
	Race							RACE;
	Age								AGE;
	Sex								SEX;
	Sociability						SOCIABILITY;
	Neatness						NEATNESS;
	Society_Class					SOCIETY_CLASS;
	//Faction
	Main_task						MAIN_TASK;
	Moment_task						MOMENT_TASK;
	//Status						STATUS;
	//kin list
	//std::map<Skills,CSlills>		SKILLS;
	//std::list<Attrib_P,CAttrib_P>	ATTRIB_P;
	//std::list<Attrib_PM,CAttrib_PM>	ATTRIB_PM;
	//std::list<Attrib_PM,CAttrib_PM>	ATTRIB_M;
	//Knowledge						KNOWLEDGE;
	//std::list<World_view, CW_V>		WORLD_VIEW;
	Mood							MOOD;
	Physical_Fatigue				PHYSICAL_FATIGUE;
	Mental_Fatigue					MENTAL_FATIGUE;
	//Aptitude						APTITUDE;
	std::map<Thems,Them*>			THEMS;
	//std::map<ZoneId,int>			RSs;
	//std::map<Traits,Trait*>		TRAITS;
public:
	Character();
	void setName(const char* X);
	void setAge(int X);
	void setSex(Sex X);
	void setRace(Race X);
	void setSociability(int X);
	void setNeatness(int X);
	void setSociety_class(Society_Class X);
	void setWorld_view(World_view X);
	void setMain_task(Main_task X);
	void setMoment_task(Moment_task X);
	void setAttrib_P(Attrib_P X);
	void setAttrib_PM(Attrib_PM X);
	void setAttrib_M(Attrib_M X);
	void setPF(Physical_Fatigue X);
	void setMF(Mental_Fatigue X);
	void setThems(Thems N, Them* X);

	bool SerializeFromXML(const tinyxml2::XMLElement* node);
	void Tick();
};


