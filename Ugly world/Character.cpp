﻿//----------------------------------------------------------
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
void Character::setRace(const Race x) {
	RACE = x;
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
void Character::setMain_task(Main_task X) {
	MAIN_TASK = X;
}
//----------------------------------------------------------
void Character::setMoment_task(Moment_task X) {
	MOMENT_TASK = X;
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
	const tinyxml2::XMLAttribute* ageAtt = node->FindAttribute("age");
	if (ageAtt) {
		setAge(ageAtt->IntValue());
	}
	//---------------------------
	const tinyxml2::XMLAttribute* sexAtt = node->FindAttribute("sex");
	if (sexAtt) {
		std::string sexStr = sexAtt->Value();
		if (sexStr == "Male") setSex(Male);
		else if (sexStr == "Female") setSex(Female);
	}
	//---------------------------
	const tinyxml2::XMLAttribute* socialAtt = node->FindAttribute("social");
	if (socialAtt) {
		setSociability(socialAtt->IntValue());
	}
	//---------------------------
	return true;
}
//----------------------------------------------------------
void Character::Tick() {
	//printf("Char\n");
};
//----------------------------------------------------------
