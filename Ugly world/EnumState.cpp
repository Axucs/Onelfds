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

	addState(eThems::Politics, "Politics");
	addState(eThems::Fauna, "Fauna");
	addState(eThems::History, "History");
	addState(eThems::Architecture, "Architecture");
	addState(eThems::Handicraft, "Handicraft");
	addState(eThems::Medicine, "Medicine");
	addState(eThems::Theology, "Theology");
	addState(eThems::Weather, "Weather");
	addState(eThems::Society, "Society");
	addState(eThems::Warfare, "Warfare");
	addState(eThems::Economy, "Economy");
	addState(eThems::Flora, "Flora");
	addState(eThems::Entertainment, "Entertainment");
	addState(eThems::Culture, "Culture");
	addState(eThems::Law, "Law");
	addState(eThems::Family, "Family");
	addState(eThems::Rumors, "Rumors");
	addState(eThems::News, "News");

	addState(eTraits::Honest, "Honest");
	addState(eTraits::Deceptive, "Deceptive");
	addState(eTraits::Generous, "Generous");
	addState(eTraits::Greedy, "Greedy");
	addState(eTraits::Lonely, "Lonely");
	addState(eTraits::Sociable, "Sociable");
	addState(eTraits::Gambler, "Gambler");
	addState(eTraits::ColdBlooded, "ColdBlooded");
	addState(eTraits::Responsible, "Responsible");
	addState(eTraits::Irresponsible, "Irresponsible");
	addState(eTraits::Attentive, "Attentive");
	addState(eTraits::Absentminded, "Absentminded");
	addState(eTraits::Careful, "Careful");
	addState(eTraits::Sloppy, "Sloppy");
	addState(eTraits::Delicate, "Delicate");
	addState(eTraits::Rough, "Rough");
	addState(eTraits::Conceited, "Conceited");
	addState(eTraits::SelfSufficient, "SelfSufficient");
	addState(eTraits::Rasper, "Rasper");
	addState(eTraits::Flexible, "Flexible");
	addState(eTraits::Farsighted, "Farsighted");
	addState(eTraits::Myopic, "Myopic");
	addState(eTraits::Endurant, "Endurant");
	addState(eTraits::Individualist, "Individualist");
	addState(eTraits::Collectivist, "Collectivist");
	addState(eTraits::Cynical, "Cynical");
	addState(eTraits::Sentimental, "Sentimental");
	addState(eTraits::Cunning, "Cunning");
	addState(eTraits::Guileless, "Guileless");
	addState(eTraits::Calm, "Calm");
	addState(eTraits::Dynamic, "Dynamic");
	addState(eTraits::Ambitious, "Ambitious");
	addState(eTraits::Frivolous, "Frivolous");
	addState(eTraits::Unpredictable, "Unpredictable");
	addState(eTraits::Stable, "Stable");
	addState(eTraits::Unstable, "Unstable");
	addState(eTraits::Proud, "Proud");
	addState(eTraits::Humble, "Humble");
	addState(eTraits::Demanding, "Demanding");
	addState(eTraits::Witty, "Witty");
	addState(eTraits::Melancholy, "Melancholy");
	addState(eTraits::Dedicated, "Dedicated");
	addState(eTraits::Independent, "Independent");
	addState(eTraits::Opinionated, "Opinionated");
	addState(eTraits::Diplomatic, "Diplomatic");
	addState(eTraits::Conflicting, "Conflicting");

	mInited = true;
}
//----------------------------------------------------------
