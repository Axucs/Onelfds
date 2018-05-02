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

	addState(eMainTask::mat1, "mat1");
	addState(eMainTask::mat2, "mat2");
	addState(eMainTask::mat3, "mat3");
	addState(eMainTask::mat4, "mat4");
	addState(eMainTask::mat5, "mat5");
	addState(eMainTask::mat6, "mat6");

	addState(eMomentTask::mot1, "mot1");
	addState(eMomentTask::mot2, "mot2");
	addState(eMomentTask::mot3, "mot3");
	addState(eMomentTask::mot4, "mot4");
	addState(eMomentTask::mot5, "mot5");
	addState(eMomentTask::mot6, "mot6");

	addState(eStatus::status0, "status0");
	addState(eStatus::status1, "status1");

	addState(ePhysicalFatigue::pf1, "pf1");
	addState(ePhysicalFatigue::pf2, "pf2");
	addState(ePhysicalFatigue::pf3, "pf3");
	addState(ePhysicalFatigue::pf4, "pf4");
	addState(ePhysicalFatigue::pf5, "pf5");
	addState(ePhysicalFatigue::pf6, "pf6");
	addState(ePhysicalFatigue::pf7, "pf7");

	addState(eMentalFatigue::mf1, "mf1");
	addState(eMentalFatigue::mf2, "mf2");
	addState(eMentalFatigue::mf3, "mf3");
	addState(eMentalFatigue::mf4, "mf4");
	addState(eMentalFatigue::mf5, "mf5");
	addState(eMentalFatigue::mf6, "mf6");
	addState(eMentalFatigue::mf7, "mf7");

	addState(eMood::m1, "m1");
	addState(eMood::m2, "m2");
	addState(eMood::m3, "m3");
	addState(eMood::m4, "m4");
	addState(eMood::m5, "m5");
	addState(eMood::m6, "m6");
	addState(eMood::m7, "m7");

	addState(Skills::Craft, "Craft");
	addState(Skills::Combat, "Combat");

	addState(eWorldView::cre_des, "cre_des");
	addState(eWorldView::mat_men, "mat_men");
	addState(eWorldView::simp_exp, "simp_exp");

	mInited = true;
}
//----------------------------------------------------------
