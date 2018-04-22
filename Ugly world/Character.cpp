//----------------------------------------------------------
// заголовок тут (c)
//----------------------------------------------------------

#include <string>
#include <tinyxml2.h>
#include "Character.h"

//----------------------------------------------------------
Character::Character() : 
	//mWorldView(World_view::cre_des),
	mAttribP(4, eAttrib::Strength, eAttrib::Agility, eAttrib::Endurance, eAttrib::Empty),
	mAttribPM(5, eAttrib::Will, eAttrib::Perception, eAttrib::Reflex, eAttrib::Dexterity, eAttrib::Empty),
	mAttribM(6, eAttrib::Intellect, eAttrib::Mind, eAttrib::Logics, eAttrib::Charisma, eAttrib::Memory, eAttrib::Empty)
{
}
//----------------------------------------------------------
void Character::setId(tCharID id)
{
	mCharID = id;
}
//----------------------------------------------------------
void Character::setName(const char* x)
{
	mName = x;
}
//----------------------------------------------------------
void Character::setRace(const eRace x)
{
	mRace = x;
}
//----------------------------------------------------------
void Character::setAge(int x)
{
	mAge = x;
}
//----------------------------------------------------------
void Character::setGender(eGender x)
{
	mGender = x;
}
//----------------------------------------------------------
void Character::setSociability(const tSociability x)
{
	mSociability = x;
}
//----------------------------------------------------------
void Character::setNeatness(const tNeatness x)
{
	mNeatness = x;
}
//----------------------------------------------------------
void Character::setSocietyClass(const eSocietyClass x)
{
	mSocietyClass = x;
}
void Character::setFaction(const tFactionID id)
{
	mFactionID = id;
}
//----------------------------------------------------------
void Character::setWorldView(const World_view x)
{
	//std::list<World_view, CW_V> = x;
}
//----------------------------------------------------------
void Character::setMainTask(const tMainTask x)
{
	mMainTask = x;
}
//----------------------------------------------------------
void Character::setMomentTask(const tMomentTask x)
{
	mMomentTask = x;
}
//----------------------------------------------------------
void Character::setStatus(const tStatus x)
{
	mStatus = x;
}
//----------------------------------------------------------
void Character::setAttrib_P(unsigned int x0, unsigned int x1, unsigned int x2, unsigned int x3)
{
	mAttribP[0] = x0;
	mAttribP[1] = x1;
	mAttribP[2] = x2;
	mAttribP[3] = x3;
}
//----------------------------------------------------------
void Character::setAttrib_PM(unsigned int x0, unsigned int x1, unsigned int x2, unsigned int x3)
{
	mAttribPM[0] = x0;
	mAttribPM[1] = x1;
	mAttribPM[2] = x2;
	mAttribPM[3] = x3;
}
//----------------------------------------------------------
void Character::setAttrib_M(unsigned int x0, unsigned int x1, unsigned int x2, unsigned int x3)
{
	mAttribM[0] = x0;
	mAttribM[1] = x1;
	mAttribM[2] = x2;
	mAttribM[3] = x3;
}
//----------------------------------------------------------
void Character::setPF(ePhysicalFatigue x)
{
	mPhysicalFatigue = x;
}
//----------------------------------------------------------
void Character::setMF(eMentalFatigue x)
{
	mMentalFatigue = x;
}
//----------------------------------------------------------
void Character::setThems(Thems n, Them* x)
{
	mThems.insert(std::make_pair(n, x));
}
//----------------------------------------------------------
bool Character::SerializeFromXML(const tinyxml2::XMLElement* node)
{
	const tinyxml2::XMLAttribute* idAtt = node->FindAttribute("id");
	if (idAtt)
	{
		setId(tCharID(idAtt->IntValue()));
	}
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
		if (raceStr == "Human") setRace(eRace::Human);
		else if (raceStr == "Orc") setRace(eRace::Orc);
		else if (raceStr == "Elf") setRace(eRace::Elf);
		else if (raceStr == "Dwarf") setRace(eRace::Dwarf);
	}
	//---------------------------
	const tinyxml2::XMLAttribute* ageAtt = node->FindAttribute("age");
	if (ageAtt)
	{
		setAge(ageAtt->IntValue());
	}
	//---------------------------
	const tinyxml2::XMLAttribute* genderAtt = node->FindAttribute("gender");
	if (genderAtt)
	{
		std::string genderStr = genderAtt->Value();
		if (genderStr == "Male") setGender(eGender::Male);
		else if (genderStr == "Female") setGender(eGender::Female);
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
	const tinyxml2::XMLAttribute* societyClasslAtt = node->FindAttribute("society_class");
	if (societyClasslAtt)
	{
		std::string societyClassStr = societyClasslAtt->Value();
		if (societyClassStr == "SC1") setSocietyClass(eSocietyClass::SC1);
		else if (societyClassStr == "SC2") setSocietyClass(eSocietyClass::SC2);
		else if (societyClassStr == "SC3") setSocietyClass(eSocietyClass::SC3);
		else if (societyClassStr == "SC4") setSocietyClass(eSocietyClass::SC4);
		else if (societyClassStr == "SC5") setSocietyClass(eSocietyClass::SC5);
		else if (societyClassStr == "SC6") setSocietyClass(eSocietyClass::SC6);
		else if (societyClassStr == "SC7") setSocietyClass(eSocietyClass::SC7);
		else if (societyClassStr == "SC8") setSocietyClass(eSocietyClass::SC8);
		else if (societyClassStr == "SC9") setSocietyClass(eSocietyClass::SC9);
	}
	//---------------------------
	const tinyxml2::XMLAttribute* factionAtt = node->FindAttribute("faction");
	if (factionAtt)
	{
		setFaction(tFactionID(factionAtt->UnsignedValue()));
	}
	//---------------------------
	const tinyxml2::XMLAttribute* main_taskAtt = node->FindAttribute("main_task");
	if (main_taskAtt)
	{
		std::string main_taskStr = main_taskAtt->Value();
		if (main_taskStr == "mat1") setMainTask(tMainTask::mat1);
		else if (main_taskStr == "mat2") setMainTask(tMainTask::mat2);
		else if (main_taskStr == "mat3") setMainTask(tMainTask::mat3);
		else if (main_taskStr == "mat4") setMainTask(tMainTask::mat4);
		else if (main_taskStr == "mat5") setMainTask(tMainTask::mat5);
		else if (main_taskStr == "mat6") setMainTask(tMainTask::mat6);
	}
	//---------------------------
	const tinyxml2::XMLAttribute* moment_taskAtt = node->FindAttribute("moment_task");
	if (moment_taskAtt)
	{
		std::string moment_taskStr = moment_taskAtt->Value();
		if (moment_taskStr == "mot1") setMomentTask(tMomentTask::mot1);
		else if (moment_taskStr == "mot2") setMomentTask(tMomentTask::mot2);
		else if (moment_taskStr == "mot3") setMomentTask(tMomentTask::mot3);
		else if (moment_taskStr == "mot4") setMomentTask(tMomentTask::mot4);
		else if (moment_taskStr == "mot5") setMomentTask(tMomentTask::mot5);
		else if (moment_taskStr == "mot6") setMomentTask(tMomentTask::mot6);
	}
	//---------------------------
	const tinyxml2::XMLAttribute* statusAtt = node->FindAttribute("status");
	if (statusAtt)
	{
		std::string statusStr = statusAtt->Value();
		if (statusStr == "status0") setStatus(tStatus::status0);
		else if (statusStr == "status1") setStatus(tStatus::status0);
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
		if (!mAttribP.SerializeFromXML(att_p_Node))
		{
			printf("ERROR: Problems in attrin_p");
		}
	}
	//---------------------------
	const tinyxml2::XMLElement* att_pm_Node = node->FirstChildElement("attrib_pm");
	if (att_pm_Node)
	{
		if (!mAttribPM.SerializeFromXML(att_pm_Node))
		{
			printf("ERROR: Problems in attrin_pm");
		}
	}
	//---------------------------
	const tinyxml2::XMLElement* att_m_Node = node->FirstChildElement("attrib_m");
	if (att_m_Node)
	{
		if (!mAttribM.SerializeFromXML(att_m_Node))
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
