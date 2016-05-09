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
	Skills SKILLS;
	std::map<Attrib_P, CAttrib_P>  ATTRIB_P;
	std::map<Attrib_PM, CAttrib_PM> ATTRIB_PM;
	std::map<Attrib_PM, CAttrib_PM> ATTRIB_M;
	//Knowledge KNOWLEDGE;
	Mood MOOD;
	Physical_Fatigue PHYSICAL_FATIGUE;
	Mental_Fatigue MENTAL_FATIGUE;
	//Aptitude APTITUDE;






	//std::map<Thems, Them*> THEMS;
	//std::map<ZoneId, int> RSs;
	//std::map<Traits, Trait*> TRAITS;

public:
	Character();










































	~Character();
};


