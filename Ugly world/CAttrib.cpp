//----------------------------------------------------------
// заголовок тут (c)
//----------------------------------------------------------

#include <string>
#include <stdarg.h>
#include <tinyxml2.h>
#include "CAttrib.h"

//----------------------------------------------------------
MAttrib::MAttrib(int n, eAttrib t, ...)
{
	number = n;
	if (number >= MAX_NUMBER) number = MAX_NUMBER;
	va_list ap;
	va_start(ap, n);
	for ( auto j = 0; j < number; j++)
	{
		types[j] = va_arg(ap, eAttrib);
		values[j] = 0;
	}
	va_end(ap);
};
//----------------------------------------------------------
bool MAttrib::setValue(const eAttrib type, value_type value)
{
	for (auto n = 0; n < number; n++)
	{
		if (types[n] == type)
		{
			values[n] = value;
			return true;
		}
	}
	printf("ERROR: bad attribute type");
	return false;
}
//----------------------------------------------------------
bool MAttrib::SerializeFromXML(const tinyxml2::XMLElement* node)
{
	const tinyxml2::XMLAttribute* attribute = node->FirstAttribute();
	while (attribute)
	{
		const value_type value = attribute->IntValue();
		std::string name = attribute->Name();
		if (name == "str")
		{
			if (!setValue(eAttrib::Strength, value)) return false;
		}
		else if (name == "agi")
		{
			if (!setValue(eAttrib::Agility, value)) return false;
		}
		else if (name == "end")
		{
			if (!setValue(eAttrib::Endurance, value)) return false;
		}
		else if (name == "wil")
		{
			if (!setValue(eAttrib::Will, value)) return false;
		}
		else if (name == "per")
		{
			if (!setValue(eAttrib::Perception, value)) return false;
		}
		else if (name == "ref")
		{
			if (!setValue(eAttrib::Reflex, value)) return false;
		}
		else if (name == "dex")
		{
			if (!setValue(eAttrib::Dexterity, value)) return false;
		}
		else if (name == "int")
		{
			if (!setValue(eAttrib::Intellect, value)) return false;
		}
		else if (name == "min")
		{
			if (!setValue(eAttrib::Mind, value)) return false;
		}
		else if (name == "log")
		{
			if (!setValue(eAttrib::Logics, value)) return false;
		}
		else if (name == "cha")
		{
			if (!setValue(eAttrib::Charisma, value)) return false;
		}
		else if (name == "mem")
		{
			if (!setValue(eAttrib::Memory, value)) return false;
		}
		else if (name == "emp")
		{
			if (!setValue(eAttrib::Empty, value)) return false;
		}
		attribute = attribute->Next();
	}
	return true;
}
//----------------------------------------------------------
