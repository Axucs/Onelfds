//----------------------------------------------------------
// заголовок тут (c)
//----------------------------------------------------------

#include <string>
#include <tinyxml2.h>
#include "Character.h"

//----------------------------------------------------------
Character::Character() : 
	CharID(0),
	NAME(),
	RACE(tRace::Human),
	AGE(1),
	SEX(tSex::Male),
	SOCIABILITY(0),
	NEATNESS(0),
	SOCIETY_CLASS(tSocietyClass::SC8),
	//WORLD_VIEW(World_view::cre_des),
	MAIN_TASK(tMainTask::mat6),
	MOMENT_TASK(tMomentTask::mot6),
	ATTRIB_P(4, eAttrib::Strength, eAttrib::Agility, eAttrib::Endurance, eAttrib::Empty),
	ATTRIB_PM(5, eAttrib::Will, eAttrib::Perception, eAttrib::Reflex, eAttrib::Dexterity, eAttrib::Empty),
	ATTRIB_M(6, eAttrib::Intellect, eAttrib::Mind, eAttrib::Logics, eAttrib::Charisma, eAttrib::Memory, eAttrib::Empty),
	MOOD(Mood::m1),
	PHYSICAL_FATIGUE(Physical_Fatigue::pf1),
	MENTAL_FATIGUE(Mental_Fatigue::mf1),
	THEMS()
{
}
//----------------------------------------------------------
void Character::setName(const char* x)
{
	NAME = x;
}
//----------------------------------------------------------
void Character::setRace(const tRace x)
{
	RACE = x;
}
//----------------------------------------------------------
void Character::setAge(int x)
{
	AGE = x;
}
//----------------------------------------------------------
void Character::setSex(tSex x)
{
	SEX = x;
}
//----------------------------------------------------------
void Character::setSociability(const tSociability x)
{
	SOCIABILITY = x;
}
//----------------------------------------------------------
void Character::setNeatness(const tNeatness x)
{
	NEATNESS = x;
}
//----------------------------------------------------------
void Character::setSociety_class(const tSocietyClass x)
{
	SOCIETY_CLASS = x;
}
void Character::setFaction(const FactionID id)
{
	factionID = id;
}
//----------------------------------------------------------
void Character::setWorld_view(const World_view x)
{
	//std::list<World_view, CW_V> = x;
}
//----------------------------------------------------------
void Character::setMainTask(const tMainTask x)
{
	MAIN_TASK = x;
}
//----------------------------------------------------------
void Character::setMomentTask(const tMomentTask x)
{
	MOMENT_TASK = x;
}
//----------------------------------------------------------
void Character::setAttrib_P(unsigned int x0, unsigned int x1, unsigned int x2, unsigned int x3)
{
	ATTRIB_P[0] = x0;
	ATTRIB_P[1] = x1;
	ATTRIB_P[2] = x2;
	ATTRIB_P[3] = x3;
}
//----------------------------------------------------------
void Character::setAttrib_PM(unsigned int x0, unsigned int x1, unsigned int x2, unsigned int x3)
{
	ATTRIB_PM[0] = x0;
	ATTRIB_PM[1] = x1;
	ATTRIB_PM[2] = x2;
	ATTRIB_PM[3] = x3;
}
//----------------------------------------------------------
void Character::setAttrib_M(unsigned int x0, unsigned int x1, unsigned int x2, unsigned int x3)
{
	ATTRIB_M[0] = x0;
	ATTRIB_M[1] = x1;
	ATTRIB_M[2] = x2;
	ATTRIB_M[3] = x3;
}
//----------------------------------------------------------
void Character::setPF(Physical_Fatigue x)
{
	PHYSICAL_FATIGUE = x;
}
//----------------------------------------------------------
void Character::setMF(Mental_Fatigue x)
{
	MENTAL_FATIGUE = x;
}
//----------------------------------------------------------
void Character::setThems(Thems n, Them* x)
{
	THEMS.insert(std::make_pair(n, x));
}
//----------------------------------------------------------
bool Character::SerializeFromXML(const tinyxml2::XMLElement* node)
{
	//---------------------------
	const tinyxml2::XMLAttribute* nameAtt = node->FindAttribute("name");
	if (nameAtt)
	{
		setName(nameAtt->Value());
	}
	//---------------------------
	const tinyxml2::XMLAttribute* raceAtt = node->FindAttribute("race");
	if (raceAtt)
	{
		std::string raceStr = raceAtt->Value();
		if (raceStr == "Human") setRace(tRace::Human);
		else if (raceStr == "Orc") setRace(tRace::Orc);
		else if (raceStr == "Elf") setRace(tRace::Elf);
		else if (raceStr == "Dwarf") setRace(tRace::Dwarf);
	}
	//---------------------------
	const tinyxml2::XMLAttribute* ageAtt = node->FindAttribute("age");
	if (ageAtt)
	{
		setAge(ageAtt->IntValue());
	}
	//---------------------------
	const tinyxml2::XMLAttribute* sexAtt = node->FindAttribute("sex");
	if (sexAtt)
	{
		std::string sexStr = sexAtt->Value();
		if (sexStr == "Male") setSex(tSex::Male);
		else if (sexStr == "Female") setSex(tSex::Female);
	}
	//---------------------------
	const tinyxml2::XMLAttribute* socialAtt = node->FindAttribute("social");
	if (socialAtt)
	{
		setSociability(socialAtt->IntValue());
	}
	//---------------------------
	const tinyxml2::XMLAttribute* neatnessAtt = node->FindAttribute("neatness");
	if (neatnessAtt)
	{
		setNeatness(neatnessAtt->IntValue());
	}
	//---------------------------
	const tinyxml2::XMLAttribute* society_classlAtt = node->FindAttribute("society_class");
	if (society_classlAtt)
	{
		std::string society_classStr = society_classlAtt->Value();
		if (society_classStr == "SC1") setSociety_class(tSocietyClass::SC1);
		else if (society_classStr == "SC2") setSociety_class(tSocietyClass::SC2);
		else if (society_classStr == "SC3") setSociety_class(tSocietyClass::SC3);
		else if (society_classStr == "SC4") setSociety_class(tSocietyClass::SC4);
		else if (society_classStr == "SC5") setSociety_class(tSocietyClass::SC5);
		else if (society_classStr == "SC6") setSociety_class(tSocietyClass::SC6);
		else if (society_classStr == "SC7") setSociety_class(tSocietyClass::SC7);
		else if (society_classStr == "SC8") setSociety_class(tSocietyClass::SC8);
		else if (society_classStr == "SC9") setSociety_class(tSocietyClass::SC9);
	}
	//---------------------------
	const tinyxml2::XMLAttribute* factionAtt = node->FindAttribute("faction");
	if (factionAtt)
	{
		setFaction(FactionID(factionAtt->UnsignedValue()));
	}
	//---------------------------
	//main_task = "mat1"
	const tinyxml2::XMLAttribute* main_taskAtt = node->FindAttribute("main_task");
	if (main_taskAtt)
	{
		//TODO
	}
	//---------------------------
	//moment_task = "mot1"
	const tinyxml2::XMLAttribute* moment_taskAtt = node->FindAttribute("moment_task");
	if (moment_taskAtt)
	{
		//TODO
	}
	//---------------------------
	//status = ""
	const tinyxml2::XMLAttribute* statusAtt = node->FindAttribute("status");
	if (statusAtt)
	{
		//TODO
	}
	//---------------------------
	//p_fatigue = "pf1"
	const tinyxml2::XMLAttribute* p_fatigueAtt = node->FindAttribute("p_fatigue");
	if (p_fatigueAtt)
	{
		//TODO
	}
	//---------------------------
	//m_fatigue = "mf1"
	const tinyxml2::XMLAttribute* m_fatigueAtt = node->FindAttribute("m_fatigue");
	if (m_fatigueAtt)
	{
		//TODO
	}
	//---------------------------
	//mood = "m1"
	const tinyxml2::XMLAttribute* moodAtt = node->FindAttribute("mood");
	if (moodAtt)
	{
		//TODO
	}
	//---------------------------
	const tinyxml2::XMLElement* att_p_Node = node->FirstChildElement("attrib_p");
	if (att_p_Node)
	{
		if (!ATTRIB_P.SerializeFromXML(att_p_Node))
		{
			printf("ERROR: Problems in attrin_p");
		}
	}
	const tinyxml2::XMLElement* att_pm_Node = node->FirstChildElement("attrib_pm");
	if (att_pm_Node)
	{
		if (!ATTRIB_PM.SerializeFromXML(att_pm_Node))
		{
			printf("ERROR: Problems in attrin_pm");
		}
	}
	const tinyxml2::XMLElement* att_m_Node = node->FirstChildElement("attrib_m");
	if (att_m_Node) {
		if (!ATTRIB_M.SerializeFromXML(att_m_Node))
		{
			printf("ERROR: Problems in attrin_m");
		}
	}
	//---------------------------
	return true;
}
//----------------------------------------------------------
void Character::Tick()
{
	//printf("Char\n");
};
//----------------------------------------------------------
