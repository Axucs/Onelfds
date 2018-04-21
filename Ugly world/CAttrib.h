//----------------------------------------------------------
// заголовок тут (c)
//----------------------------------------------------------

#pragma once

#include "CharEnums.h"

namespace tinyxml2
{
	class XMLElement;// это сделано что бы не делать #include <tinyxml2.h> сюда.
};

//----------------------------------------------------------
enum class eAttrib
{
	Empty,				 // пустота
	//---------------------
	Strength,			 // Сила
	Agility,			 // Ловкость
	Endurance,			 // Выносливость
	//---------------------
	Will,				 // Воля
	Perception,			 // Восприятие
	Reflex,				 // Рефлекс
	Dexterity,			 // Сноровка
	//---------------------
	Intellect,			 // Интелект
	Mind,				 // Разум
	Logics,				 // Логика
	Charisma,			 // Харизма
	Memory				 // Память
};
//----------------------------------------------------------
// этот класс хранит нужное количество атрибутов одного круга
class MAttrib
{
public:
	typedef unsigned int value_type;
private:
	static const int MAX_NUMBER = 10;
	eAttrib          types[MAX_NUMBER];		// тут типы атрибутов, количество с большим запасом
	value_type       values[MAX_NUMBER];	// тут значения атрибутов, количество с большим запасом
	int              number;				// а это реальное количество атрибутов
public:
	MAttrib(int n, eAttrib t,...);
	unsigned int& operator[](int n)
	{
		return values[n];
	}
	bool setValue(const eAttrib type, value_type value);
	bool SerializeFromXML(const tinyxml2::XMLElement* node);
};
//----------------------------------------------------------
