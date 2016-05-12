//----------------------------------------------------------
// заголовок тут (c)
//----------------------------------------------------------

#pragma once

#include "CharEnums.h"

class AttribBase {
protected:
	int value;
public:
};
class CAttrib_P : public AttribBase {
private: 
	Attrib_P type;
public:
	CAttrib_P(Attrib_P T, int X) {
		value = X;
		type = T;
	}
	int valueChange(int Change) {
		int min = 15;
		//if (type == empty1) { min = 0;}
		if (value <= min) { value = min; }
		if (value >= min) { value = value + Change; }
		//if (type == Strength, value >= 50) { Attrib_P::Endurance, Attrib_P::Agility; }
		//if (type == Agility, value >= 50) { Attrib_P::Strength, Attrib_P::Endurance; }
		//if (type == Endurance, value >= 50) { Attrib_P::Agility, Attrib_P::Strength; }
	}


};
class CAttrib_PM : public AttribBase {
private:
	Attrib_PM type;
public:
	CAttrib_PM(Attrib_PM T, int X) {
		value = X;
		type = T;
	}
};
class CAttrib_M : public AttribBase {
private:
	Attrib_M type;
public:
	CAttrib_M(Attrib_M T, int X) {
		value = X;
		type = T;
	}
};