//----------------------------------------------------------
// заголовок тут (c)
//----------------------------------------------------------

#include "EnumState.h"
#include "CharEnums.h"

//----------------------------------------------------------
cEnumStatesStorage::cEnumStatesStorage()
{
	init();
}
//----------------------------------------------------------
cEnumStatesStorage* cEnumStatesStorage::instance()
{
	return Singleton<cEnumStatesStorage>::instance();
}
//----------------------------------------------------------
void cEnumStatesStorage::init()
{
	if (mInited)
	{
		return;
	}

	addState(eRace::Human, "Human");
	addState(eRace::Orc, "Orc");
	addState(eRace::Elf, "Elf");
	addState(eRace::Dwarf, "Dwarf");

	addState(eGender::Male, "Male");
	addState(eGender::Female, "Female");

	addState(eSocietyClass::SC1, "SC1");
	addState(eSocietyClass::SC2, "SC2");
	addState(eSocietyClass::SC3, "SC3");
	addState(eSocietyClass::SC4, "SC4");
	addState(eSocietyClass::SC5, "SC5");
	addState(eSocietyClass::SC6, "SC6");
	addState(eSocietyClass::SC7, "SC7");
	addState(eSocietyClass::SC8, "SC8");
	addState(eSocietyClass::SC9, "SC9");

	mInited = true;
}
//----------------------------------------------------------
