//----------------------------------------------------------
// заголовок тут (c)
//----------------------------------------------------------

#pragma once

#include <string>
#include <map>
#include <list>
#include "CAttrib.h" //классы атрибутов
#include "CChar.h" //классы тем и черт характера
#include "CharEnums.h"

namespace tinyxml2 {
	class XMLElement;
};

enum class Thems {
	Politics,		 //политика
	Fauna,			 //фауна
	History,		 //История
	Architecture,	 //Архитектура
	Handicraft,		 //кравт, производство чего лиобо
	Medicine,		 //Медецына
	Theology,		 //Тиалогия
	Weather,		 //климат, погода
	Society,		 //Общество 
	Warfare,		 //Война
	Economy,		 //Экономика
	Flora,			 //Флора
	Entertainmen,	 //Развлечение
	Culture,		 //Культура
	Law,			 //Законы, порядки
	Family,			 //Семя 
	Rumors,			 //слухи 
	News			 //Новости
};
enum class Traits {
	Honest,//Честный
	Deceptive,//Лживый
	Generous,//Щедрый
	Greedy,//Жадный
	Lonely,//Одинокий
	Sociable,//Общительный
	Gambler,//Азартный
	cold_blooded,//Хладнокровный
	Responsible,//Ответственный
	Irresponsible,//Безответственный
	Attentive,//Внимательный
	Absentminded,//рассеянный
	Careful,//Аккуратный
	sloppy,//Неряшливый
	Delicate,//Деликатный
	Rough,//Грубый
	Conceited,//Тщеславный
	Self_sufficient,//Самодостаточный
	Rasper,//Резкий
	Flexible,//Гибкий
	Farsighted,//Дальновидный
	Myopic,//Близорукий
	Endurant,//Терпеливый
	Individualist,//Индивидуалист
	Collectivist,//Коллективист
	Cynical,//Циничный
	Sentimental,//Сентиментальный
	Cunning,//Хитрый
	Guileless,//Простодушный
	Calm,//Спокойный
	Dynamic,//Динамичный
	Ambitious,//Целеустремленный
	Frivolous,//Легкомысленный
	Unpredictable,//Непредсказуемый
	Stable,//Стабильный
	Unstable,//Непостоянный
	Proud,//Гордый
	Humble,//Смиренный
	Demanding,//Требовательный
	Witty,//Остроумный
	Melancholy,//Меланхоличный
	dedicated,//Преданный
	Independent,//Независимый
	Opinionated,//Упрямый
	Diplomatic,//Дипломатичный
	conflicting    	//Конфликтный
};
//


class Character
{
private:
	std::string CharID;
	std::string NAME;
	Race RACE;
	Age AGE;
	Sex SEX;
	Sociability SOCIABILITY;
	Neatness NEATNESS;
	Society_Class SOCIETY_CLASS;
	//Faction
	Main_task MAIN_TASK;
	Moment_task MOMENT_TASK;
	//Status STATUS;
	//kin list
	//std::map<Skills,    CSlills> SKILLS;
	std::map<Attrib_P, CAttrib_P>  ATTRIB_P;
	std::map<Attrib_PM, CAttrib_PM> ATTRIB_PM;
	std::map<Attrib_PM, CAttrib_PM> ATTRIB_M;
	//Knowledge KNOWLEDGE;
	Mood MOOD;
	Physical_Fatigue PHYSICAL_FATIGUE;
	Mental_Fatigue MENTAL_FATIGUE;
	//Aptitude APTITUDE;
	std::map<Thems, Them*> THEMS;
	
	//std::map<ZoneId, int> RSs;
	//std::map<Traits, Trait*> TRAITS;

public:
	Character() : THEMS() {// default contructor
	}
	Character(const char* ID) : THEMS() {
		NAME;
		RACE = X;
		AGE = ag1;
		SEX = none;
		SOCIABILITY = adf1;
		NEATNESS = test;
		SOCIETY_CLASS = SC8;
		MAIN_TASK = Main_task::mat6;
		MOMENT_TASK = Moment_task::mot6;
		MOOD = m1;
		PHYSICAL_FATIGUE = pf1;
		MENTAL_FATIGUE = mf1;
		std::map<Thems, Them*> THEMS;
	}
	void senName(int X) {
		NAME = X;
	}
	void setAge(int X) {
		if (X <= 14) AGE = ag1;
		else if (X <= 25) AGE = ag2;
		else if (X <= 45) AGE = ag3;
		else AGE = ag4;}
	void setSex(Sex X) {
		SEX = X;}
	void setSociability(int X) {
		if (X >= 90)      SOCIABILITY = adf1;
		else if (X >= 75) SOCIABILITY = adf2;
		else if (X >= 50) SOCIABILITY = adf3;
		else if (X > 25)  SOCIABILITY = adf4;
		else if (X <= 25) SOCIABILITY = adf5;}
	void setNeatness(int X) {
		NEATNESS = test;
	}
	void setSociety_class(Society_Class X) {
		SOCIETY_CLASS = X;
	}
	void setMain_task(Main_task X) {
		MAIN_TASK = X;
	}
	void setMoment_task(Moment_task X) {
		MOMENT_TASK = X;
	}
	void setPF(Physical_Fatigue X) {
		PHYSICAL_FATIGUE = X;
	}
	void setMF(Mental_Fatigue X) {
		MENTAL_FATIGUE = X;
	}
	void setThems(Thems N, Them* X) {
		THEMS.insert(std::make_pair(N, X));
	}

	bool SerializeFromXML(const tinyxml2::XMLElement* node);
	void Tick();

};


