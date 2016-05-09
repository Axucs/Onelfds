﻿//----------------------------------------------------------
// заголовок тут (c)
//----------------------------------------------------------
#pragma once

#include <string>
#include <map>
#include <list>
#include "CAttrib.h" //классы атрибутов
#include "CChar.h" //классы тем и черт характера



// лист енумов
enum Race {
	Human,
	Orc,
	Elf,
	Dwarf
};
enum Sex {
	Male,
	Female,
	none
};
enum Sociability {
	adf1,  //Жаждет общения
	adf2,  //необходимо общение
	adf3,  //может общаться
	adf4,  //избегает общения
	adf5  //максимально избегает общения
};

enum Age {
	ag1,    //"Отрок"
	ag2,    //"Молодой"
	ag3,    //"Взрослый"
	ag4    //"Старик"
};

enum Neatness {
	test
};

enum Society_Class {
	SC1,      //"Сырьевые"
	SC2,      //"Ремеслиники"
	SC3,      //"Духовенство"
	SC4,      //"Торговцы"
	SC5,      //"Стража"
	SC6,      //"Аристократы"
	SC7,      //"Просвищение"
	SC8,      //"Сброд"
	SC9		  //"Скрытый"
};
enum Attrib_P {
	Strength,			 //Сила
	Agility,			 //Ловкость
	Endurance,			 //Выносливость
	empty1,				 //пустота 1
};
enum Attrib_PM {
	Will,				 //Воля
	Perception,			 //Восприятие
	Reflex,				 //Рефлекс
	dexterity,			 //Сноровка
	empty2,				 //пустота 2
};
enum Attrib_M {
	Intellect,			 //Интелект
	Mind,				 //Разум
	Logics,				 //Логика
	Charisma,			 //Харизма
	Memory,				 //Память
	empty3,				 //Пустота 3
};
enum Mood {
	m1,    //Отличное
	m2,    //Хорошое
	m3,    //Чють хорошое
	m4,    //Среднее
	m5,    //Чють плохое
	m6,    //Плохое
	m7,    //Ужасное
};
enum Physical_Fatigue {
	pf1,	 //абсолютно бодрый
	pf2,	 //Бодрый
	pf3,	 //Чють бодры
	pf4,	 //Средний
	pf5,	 //Чють уставший
	pf6,	 //Уставший
	pf7,	 //Мёртвый
};
enum Mental_Fatigue {
	mf1,	 //абсолютно бодрый
	mf2,	 //Бодрый
	mf3,	 //Чють бодры
	mf4,	 //Средний
	mf5,	 //Чють уставший
	mf6,	 //Уставший
	mf7,	 //Мёртвый
};
enum class Main_task {
	mat1,    //свободен
	mat2,    //практически свободен
	mat3,    //практически занят
	mat4,    //средне занят
	mat5,    //сильно занят
	mat6     //Очень сильно занят
};
enum class Moment_task {
	mot1,   //свободен
	mot2,   //практически свободе
	mot3,   //практически занят
	mot4,   //средне занят
	mot5,   //сильно занят
	mot6    //Очень сильно занят
};

enum Skills {
	Craft,
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


