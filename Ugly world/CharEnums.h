﻿//----------------------------------------------------------
// заголовок тут (c)
//----------------------------------------------------------

#pragma once

//----------------------------------------------------------
enum class eRace
{
	Human,
	Orc,
	Elf,
	Dwarf
};
//----------------------------------------------------------
enum class eGender
{
	Male,
	Female
};
//----------------------------------------------------------
using tSociability = int; // Жаждет общения (>= 90), необходимо общение (90 < X >= 75), может общаться (75 < X >= 50), избегает общения (50 < X > 25), максимально избегает общения (X <= 25)
//----------------------------------------------------------
using tNeatness = int; // аккуратность
//----------------------------------------------------------
enum class eSocietyClass
{
	SC1,	//"Сырьевые"
	SC2,	//"Ремеслиники"
	SC3,	//"Духовенство"
	SC4,	//"Торговцы"
	SC5,	//"Стража"
	SC6,	//"Аристократы"
	SC7,	//"Просвищение"
	SC8,	//"Сброд"
	SC9		//"Скрытый"
};
//----------------------------------------------------------
enum class eMainTask
{
	mat1,    //свободен
	mat2,    //практически свободен
	mat3,    //практически занят
	mat4,    //средне занят
	mat5,    //сильно занят
	mat6     //Очень сильно занят
};
//----------------------------------------------------------
enum class eMomentTask
{
	mot1,	//свободен
	mot2,	//практически свободен
	mot3,	//практически занят
	mot4,	//средне занят
	mot5,	//сильно занят
	mot6	//Очень сильно занят
};
//----------------------------------------------------------
enum class eStatus
{
	status0,
	status1
};
//----------------------------------------------------------
enum class ePhysicalFatigue
{
	pf1,	//абсолютно бодрый
	pf2,	//Бодрый
	pf3,	//Чуть бодрый
	pf4,	//Средний
	pf5,	//Чуть уставший
	pf6,	//Уставший
	pf7     //Мёртвый
};
//----------------------------------------------------------
enum class eMentalFatigue
{
	mf1,	//абсолютно бодрый
	mf2,	//Бодрый
	mf3,	//Чють бодры
	mf4,	//Средний
	mf5,	//Чють уставший
	mf6,	//Уставший
	mf7		//Мёртвый
};
//----------------------------------------------------------
enum class eMood
{
	m1,    //Отличное
	m2,    //Хорошое
	m3,    //Чють хорошое
	m4,    //Среднее
	m5,    //Чють плохое
	m6,    //Плохое
	m7,    //Ужасное
};
//----------------------------------------------------------
enum class Skills
{
	Craft,
	Combat
};
//----------------------------------------------------------
enum class eWorldView
{
	cre_des,	//creation-destruction
	mat_men,	//material-mental
	simp_exp	//self_improvement-exploitation
};
//----------------------------------------------------------
enum class eThems
{
	Politics,			//политика
	Fauna,				//фауна
	History,			//История
	Architecture,		//Архитектура
	Handicraft,			//кравт, производство чего лиобо
	Medicine,			//Медицина
	Theology,			//Тиалогия
	Weather,			//климат, погода
	Society,			//Общество 
	Warfare,			//Война
	Economy,			//Экономика
	Flora,				//Флора
	Entertainment,		//Развлечение
	Culture,			//Культура
	Law,				//Законы, порядки
	Family,				//Семья
	Rumors,				//слухи 
	News				//Новости
};
//----------------------------------------------------------
enum class eTraits
{
	Honest,				//Честный
	Deceptive,			//Лживый
	Generous,			//Щедрый
	Greedy,				//Жадный
	Lonely,				//Одинокий
	Sociable,			//Общительный
	Gambler,			//Азартный
	ColdBlooded,		//Хладнокровный
	Responsible,		//Ответственный
	Irresponsible,		//Безответственный
	Attentive,			//Внимательный
	Absentminded,		//рассеянный
	Careful,			//Аккуратный
	Sloppy,				//Неряшливый
	Delicate,			//Деликатный
	Rough,				//Грубый
	Conceited,			//Тщеславный
	SelfSufficient,		//Самодостаточный
	Rasper,				//Резкий
	Flexible,			//Гибкий
	Farsighted,			//Дальновидный
	Myopic,				//Близорукий
	Endurant,			//Терпеливый
	Individualist,		//Индивидуалист
	Collectivist,		//Коллективист
	Cynical,			//Циничный
	Sentimental,		//Сентиментальный
	Cunning,			//Хитрый
	Guileless,			//Простодушный
	Calm,				//Спокойный
	Dynamic,			//Динамичный
	Ambitious,			//Целеустремленный
	Frivolous,			//Легкомысленный
	Unpredictable,		//Непредсказуемый
	Stable,				//Стабильный
	Unstable,			//Непостоянный
	Proud,				//Гордый
	Humble,				//Смиренный
	Demanding,			//Требовательный
	Witty,				//Остроумный
	Melancholy,			//Меланхоличный
	Dedicated,			//Преданный
	Independent,		//Независимый
	Opinionated,		//Упрямый
	Diplomatic,			//Дипломатичный
	Conflicting    		//Конфликтный
};
//----------------------------------------------------------
