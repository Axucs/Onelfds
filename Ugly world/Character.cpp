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
	RACE(Race::Human),
	AGE(1),
	SEX(Sex::Male),
	SOCIABILITY(Sociability::adf1),
	NEATNESS(Neatness::test),
	SOCIETY_CLASS(SocietyClass::SC8),
	//WORLD_VIEW(World_view::cre_des),
	MAIN_TASK(Main_task::mat6),
	MOMENT_TASK(Moment_task::mot6),
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
void Character::setName(const char* x) {
	NAME = x;
}
//----------------------------------------------------------
void Character::setRace(const Race x) {
	RACE = x;
}
//----------------------------------------------------------
void Character::setAge(int x) {
	AGE = x;
}
//----------------------------------------------------------
void Character::setSex(Sex x) {
	SEX = x;
}
//----------------------------------------------------------
void Character::setSociability(int X) {
	if (X >= 90)      SOCIABILITY = Sociability::adf1;
	else if (X >= 75) SOCIABILITY = Sociability::adf2;
	else if (X >= 50) SOCIABILITY = Sociability::adf3;
	else if (X > 25)  SOCIABILITY = Sociability::adf4;
	else if (X <= 25) SOCIABILITY = Sociability::adf5;
}
//----------------------------------------------------------
void Character::setNeatness(const Neatness x) {
	NEATNESS = x;
}
//----------------------------------------------------------
void Character::setSociety_class(const SocietyClass X) {
	SOCIETY_CLASS = X;
}
//----------------------------------------------------------
void Character::setWorld_view(const World_view X) {
	//std::list<World_view, CW_V> = X;
}
//----------------------------------------------------------
void Character::setMain_task(const Main_task X) {
	MAIN_TASK = X;
}
//----------------------------------------------------------
void Character::setMoment_task(const Moment_task X) {
	MOMENT_TASK = X;
}
//----------------------------------------------------------
void Character::setAttrib_P(unsigned int x0, unsigned int x1, unsigned int x2, unsigned int x3) {
	ATTRIB_P[0] = x0;
	ATTRIB_P[1] = x1;
	ATTRIB_P[2] = x2;
	ATTRIB_P[3] = x3;
}
//----------------------------------------------------------
void Character::setAttrib_PM(unsigned int x0, unsigned int x1, unsigned int x2, unsigned int x3) {
	ATTRIB_PM[0] = x0;
	ATTRIB_PM[1] = x1;
	ATTRIB_PM[2] = x2;
	ATTRIB_PM[3] = x3;
}
//----------------------------------------------------------
void Character::setAttrib_M(unsigned int x0, unsigned int x1, unsigned int x2, unsigned int x3) {
	ATTRIB_M[0] = x0;
	ATTRIB_M[1] = x1;
	ATTRIB_M[2] = x2;
	ATTRIB_M[3] = x3;
}
//----------------------------------------------------------
void Character::setPF(Physical_Fatigue X) {
	PHYSICAL_FATIGUE = X;
}
//----------------------------------------------------------
void Character::setMF(Mental_Fatigue X) {
	MENTAL_FATIGUE = X;
}
//----------------------------------------------------------
void Character::setThems(Thems N, Them* X) {
	THEMS.insert(std::make_pair(N, X));
}
//----------------------------------------------------------
bool Character::SerializeFromXML(const tinyxml2::XMLElement* node) {
	//---------------------------
	const tinyxml2::XMLAttribute* nameAtt = node->FindAttribute("name");
	if (nameAtt) {
		setName(nameAtt->Value());
	}
	//---------------------------
	const tinyxml2::XMLAttribute* raceAtt = node->FindAttribute("race");
	if (raceAtt) {
		std::string raceStr = raceAtt->Value();
		if (raceStr == "Human") setRace(Race::Human);
		else if (raceStr == "Orc") setRace(Race::Orc);
		else if (raceStr == "Elf") setRace(Race::Elf);
		else if (raceStr == "Dwarf") setRace(Race::Dwarf);
	}
	//---------------------------
	const tinyxml2::XMLAttribute* ageAtt = node->FindAttribute("age");
	if (ageAtt) {
		setAge(ageAtt->IntValue());
	}
	//---------------------------
	const tinyxml2::XMLAttribute* sexAtt = node->FindAttribute("sex");
	if (sexAtt) {
		std::string sexStr = sexAtt->Value();
		if (sexStr == "Male") setSex(Sex::Male);
		else if (sexStr == "Female") setSex(Sex::Female);
	}
	//---------------------------
	const tinyxml2::XMLAttribute* socialAtt = node->FindAttribute("social");
	if (socialAtt) {
		setSociability(socialAtt->IntValue());
	}
	//---------------------------
	const tinyxml2::XMLAttribute* neatnessAtt = node->FindAttribute("neatness");
	if (neatnessAtt) {
		std::string neatnessStr = neatnessAtt->Value();
		if (neatnessStr == "test") setNeatness(Neatness::test);
	}
	//---------------------------
	const tinyxml2::XMLAttribute* society_classlAtt = node->FindAttribute("society_class");
	if (society_classlAtt) {
		std::string society_classStr = society_classlAtt->Value();
		if (society_classStr == "SC1") setSociety_class(SocietyClass::SC1);
		else if (society_classStr == "SC2") setSociety_class(SocietyClass::SC2);
		else if (society_classStr == "SC3") setSociety_class(SocietyClass::SC3);
		else if (society_classStr == "SC4") setSociety_class(SocietyClass::SC4);
		else if (society_classStr == "SC5") setSociety_class(SocietyClass::SC5);
		else if (society_classStr == "SC6") setSociety_class(SocietyClass::SC6);
		else if (society_classStr == "SC7") setSociety_class(SocietyClass::SC7);
		else if (society_classStr == "SC8") setSociety_class(SocietyClass::SC8);
		else if (society_classStr == "SC9") setSociety_class(SocietyClass::SC9);
	}
	//---------------------------
	//faction = ""
	const tinyxml2::XMLAttribute* factionAtt = node->FindAttribute("faction");
	if (factionAtt) {
		//TODO
	}
	//---------------------------
	//main_task = "mat1"
	const tinyxml2::XMLAttribute* main_taskAtt = node->FindAttribute("main_task");
	if (main_taskAtt) {
		//TODO
	}
	//---------------------------
	//moment_task = "mot1"
	const tinyxml2::XMLAttribute* moment_taskAtt = node->FindAttribute("moment_task");
	if (moment_taskAtt) {
		//TODO
	}
	//---------------------------
	//status = ""
	const tinyxml2::XMLAttribute* statusAtt = node->FindAttribute("status");
	if (statusAtt) {
		//TODO
	}
	//---------------------------
	//p_fatigue = "pf1"
	const tinyxml2::XMLAttribute* p_fatigueAtt = node->FindAttribute("p_fatigue");
	if (p_fatigueAtt) {
		//TODO
	}
	//---------------------------
	//m_fatigue = "mf1"
	const tinyxml2::XMLAttribute* m_fatigueAtt = node->FindAttribute("m_fatigue");
	if (m_fatigueAtt) {
		//TODO
	}
	//---------------------------
	//mood = "m1"
	const tinyxml2::XMLAttribute* moodAtt = node->FindAttribute("mood");
	if (moodAtt) {
		//TODO
	}
	//---------------------------
	const tinyxml2::XMLElement* att_p_Node = node->FirstChildElement("attrib_p");
	if (att_p_Node) {
		if (!ATTRIB_P.SerializeFromXML(att_p_Node)) {
			printf("ERROR: Problems in attrin_p");
		}
	}
	const tinyxml2::XMLElement* att_pm_Node = node->FirstChildElement("attrib_pm");
	if (att_pm_Node) {
		if (!ATTRIB_PM.SerializeFromXML(att_pm_Node)) {
			printf("ERROR: Problems in attrin_pm");
		}
	}
	const tinyxml2::XMLElement* att_m_Node = node->FirstChildElement("attrib_m");
	if (att_m_Node) {
		if (!ATTRIB_M.SerializeFromXML(att_m_Node)) {
			printf("ERROR: Problems in attrin_m");
		}
	}
	//---------------------------
	return true;
}
//----------------------------------------------------------
void Character::Tick() {
	//printf("Char\n");
};
//----------------------------------------------------------
