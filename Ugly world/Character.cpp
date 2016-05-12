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
	RACE(Human),
	AGE(ag1),
	SEX(Male),
	SOCIABILITY(adf1),
	NEATNESS(test),
	SOCIETY_CLASS(SC8),
	WORLD_VIEW(World_view::cre_des),
	MAIN_TASK(Main_task::mat6),
	MOMENT_TASK(Moment_task::mot6),
	MOOD(m1),
	PHYSICAL_FATIGUE(pf1),
	MENTAL_FATIGUE(mf1),
	THEMS()
{
}
//----------------------------------------------------------
void Character::setName(const char* X) {
	NAME = X;
}
//----------------------------------------------------------
void Character::setRace(const Race X) {
	RACE = X;
}
//----------------------------------------------------------
void Character::setAge(int X) {
	if (X <= 14) AGE = ag1;
	else if (X <= 25) AGE = ag2;
	else if (X <= 45) AGE = ag3;
	else AGE = ag4;
}
//----------------------------------------------------------
void Character::setSex(Sex X) {
	SEX = X;
}
//----------------------------------------------------------
void Character::setSociability(int X) {
	if (X >= 90)      SOCIABILITY = adf1;
	else if (X >= 75) SOCIABILITY = adf2;
	else if (X >= 50) SOCIABILITY = adf3;
	else if (X > 25)  SOCIABILITY = adf4;
	else if (X <= 25) SOCIABILITY = adf5;
}
//----------------------------------------------------------
void Character::setNeatness(int X) {
	NEATNESS = test;
}
//----------------------------------------------------------
void Character::setSociety_class(Society_Class X) {
	SOCIETY_CLASS = X;
}
//----------------------------------------------------------
void Character::setWorld_view(World_view X) {
	std::list<World_view, CW_V> = X;
}
//----------------------------------------------------------
void Character::setMain_task(Main_task X) {
	MAIN_TASK = X;
}
//----------------------------------------------------------
void Character::setMoment_task(Moment_task X) {
	MOMENT_TASK = X;
}
//----------------------------------------------------------
void Character::setAttrib_P(Attrib_P X) {
	std::list<Attrib_P, CAttrib_P> = X;
}
//----------------------------------------------------------
void Character::setAttrib_PM(Attrib_PM X) {
	std::list<Attrib_PM, CAttrib_PM> = X;
}
//----------------------------------------------------------
void Character::setAttrib_M(Attrib_M X) {
	std::list<Attrib_PM, CAttrib_PM> = X;
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
		if (raceStr == "Human") setRace(Human);
		else if (raceStr == "Orc") setRace(Orc);
		else if (raceStr == "Elf") setRace(Elf);
		else if (raceStr == "Dwarf") setRace(Dwarf);
	}
	//---------------------------
	//
	//---------------------------
	return true;
}
//----------------------------------------------------------
void Character::Tick() {
	//printf("Char\n");
};
//----------------------------------------------------------
