//----------------------------------------------------------
// заголовок тут (c)
//----------------------------------------------------------

#pragma once

#include <stdarg.h>

#include "CharEnums.h"

//----------------------------------------------------------
enum class eAttrib {
	Empty,				 //пустота
	//---------------------
	Strength,			 //Сила
	Agility,			 //Ловкость
	Endurance,			 //Выносливость
	//---------------------
	Will,				 //Воля
	Perception,			 //Восприятие
	Reflex,				 //Рефлекс
	Dexterity,			 //Сноровка
	//---------------------
	Intellect,			 //Интелект
	Mind,				 //Разум
	Logics,				 //Логика
	Charisma,			 //Харизма
	Memory				 //Память
};
//----------------------------------------------------------
// этот класс хранит нужное количество атрибутов одного круга
class MAttrib {
private:
	static const int MAX_NUMBER = 10;
	eAttrib          types[MAX_NUMBER];		// тут типы атрибутов, количество с большим запасом
	unsigned int     values[MAX_NUMBER];	// тут значения атрибутов, количество с большим запасом
	unsigned int     number;				// а это реальное количество атрибутов
public:
	MAttrib(unsigned int n, eAttrib t,...) {
		number = n;
		va_list ap;
		va_start(ap, n);
		for (unsigned int  j = 0; j < number; j++) {
			types[j] = va_arg(ap, eAttrib);
			values[j] = 0;
		}
		va_end(ap);
	};
	unsigned int& operator[](int n) {
		return values[n];
	}
};
//----------------------------------------------------------
