//----------------------------------------------------------
// заголовок тут (c)
//----------------------------------------------------------

#pragma once

#include <string>
#include <map>
#include <list>
#include "CAttrib.h" //êëàññû àòðèáóòîâ
#include "CChar.h" //êëàññû òåì è ÷åðò õàðàêòåðà













// ëèñò åíóìîâ
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
	adf1,  //Æàæäåò îáùåíèÿ
	adf2,  //íåîáõîäèìî îáùåíèå
	adf3,  //ìîæåò îáùàòüñÿ
	adf4,  //èçáåãàåò îáùåíèÿ
	adf5  //ìàêñèìàëüíî èçáåãàåò îáùåíèÿ
};

enum Age {
	ag1,    //"Îòðîê"
	ag2,    //"Ìîëîäîé"
	ag3,    //"Âçðîñëûé"
	ag4    //"Ñòàðèê"
};

enum Neatness {
	test
};

enum Society_Class {
	SC1,      //"Ñûðüåâûå"
	SC2,      //"Ðåìåñëèíèêè"
	SC3,      //"Äóõîâåíñòâî"
	SC4,      //"Òîðãîâöû"
	SC5,      //"Ñòðàæà"
	SC6,      //"Àðèñòîêðàòû"
	SC7,      //"Ïðîñâèùåíèå"
	SC8,      //"Ñáðîä"
	SC9		  //"Ñêðûòûé"
};
enum Attrib_P {
	Strength,			 //Ñèëà
	Agility,			 //Ëîâêîñòü
	Endurance,			 //Âûíîñëèâîñòü
	empty1,				 //ïóñòîòà 1
};
enum Attrib_PM {
	Will,				 //Âîëÿ
	Perception,			 //Âîñïðèÿòèå
	Reflex,				 //Ðåôëåêñ
	dexterity,			 //Ñíîðîâêà
	empty2,				 //ïóñòîòà 2
};
enum Attrib_M {
	Intellect,			 //Èíòåëåêò
	Mind,				 //Ðàçóì
	Logics,				 //Ëîãèêà
	Charisma,			 //Õàðèçìà
	Memory,				 //Ïàìÿòü
	empty3,				 //Ïóñòîòà 3
};
enum Mood {
	m1,    //Îòëè÷íîå
	m2,    //Õîðîøîå
	m3,    //×þòü õîðîøîå
	m4,    //Ñðåäíåå
	m5,    //×þòü ïëîõîå
	m6,    //Ïëîõîå
	m7,    //Óæàñíîå
};
enum Physical_Fatigue {
	pf1,	 //àáñîëþòíî áîäðûé
	pf2,	 //Áîäðûé
	pf3,	 //×þòü áîäðû
	pf4,	 //Ñðåäíèé
	pf5,	 //×þòü óñòàâøèé
	pf6,	 //Óñòàâøèé
	pf7,	 //Ì¸ðòâûé
};
enum Mental_Fatigue {
	mf1,	 //àáñîëþòíî áîäðûé
	mf2,	 //Áîäðûé
	mf3,	 //×þòü áîäðû
	mf4,	 //Ñðåäíèé
	mf5,	 //×þòü óñòàâøèé
	mf6,	 //Óñòàâøèé
	mf7,	 //Ì¸ðòâûé
};
enum class Main_task {
	mat1,    //ñâîáîäåí
	mat2,    //ïðàêòè÷åñêè ñâîáîäåí
	mat3,    //ïðàêòè÷åñêè çàíÿò
	mat4,    //ñðåäíå çàíÿò
	mat5,    //ñèëüíî çàíÿò
	mat6     //Î÷åíü ñèëüíî çàíÿò
};
enum class Moment_task {
	mot1,   //ñâîáîäåí
	mot2,   //ïðàêòè÷åñêè ñâîáîäå
	mot3,   //ïðàêòè÷åñêè çàíÿò
	mot4,   //ñðåäíå çàíÿò
	mot5,   //ñèëüíî çàíÿò
	mot6    //Î÷åíü ñèëüíî çàíÿò
};

enum Skills {
	Craft,
};					

enum class Thems {
	Politics,		 //ïîëèòèêà
	Fauna,			 //ôàóíà
	History,		 //Èñòîðèÿ
	Architecture,	 //Àðõèòåêòóðà
	Handicraft,		 //êðàâò, ïðîèçâîäñòâî ÷åãî ëèîáî
	Medicine,		 //Ìåäåöûíà
	Theology,		 //Òèàëîãèÿ
	Weather,		 //êëèìàò, ïîãîäà
	Society,		 //Îáùåñòâî 
	Warfare,		 //Âîéíà
	Economy,		 //Ýêîíîìèêà
	Flora,			 //Ôëîðà
	Entertainmen,	 //Ðàçâëå÷åíèå
	Culture,		 //Êóëüòóðà
	Law,			 //Çàêîíû, ïîðÿäêè
	Family,			 //Ñåìÿ 
	Rumors,			 //ñëóõè 
	News			 //Íîâîñòè
};
enum class Traits {
	Honest,//×åñòíûé
	Deceptive,//Ëæèâûé
	Generous,//Ùåäðûé
	Greedy,//Æàäíûé
	Lonely,//Îäèíîêèé
	Sociable,//Îáùèòåëüíûé
	Gambler,//Àçàðòíûé
	cold_blooded,//Õëàäíîêðîâíûé
	Responsible,//Îòâåòñòâåííûé
	Irresponsible,//Áåçîòâåòñòâåííûé
	Attentive,//Âíèìàòåëüíûé
	Absentminded,//ðàññåÿííûé
	Careful,//Àêêóðàòíûé
	sloppy,//Íåðÿøëèâûé
	Delicate,//Äåëèêàòíûé
	Rough,//Ãðóáûé
	Conceited,//Òùåñëàâíûé
	Self_sufficient,//Ñàìîäîñòàòî÷íûé
	Rasper,//Ðåçêèé
	Flexible,//Ãèáêèé
	Farsighted,//Äàëüíîâèäíûé
	Myopic,//Áëèçîðóêèé
	Endurant,//Òåðïåëèâûé
	Individualist,//Èíäèâèäóàëèñò
	Collectivist,//Êîëëåêòèâèñò
	Cynical,//Öèíè÷íûé
	Sentimental,//Ñåíòèìåíòàëüíûé
	Cunning,//Õèòðûé
	Guileless,//Ïðîñòîäóøíûé
	Calm,//Ñïîêîéíûé
	Dynamic,//Äèíàìè÷íûé
	Ambitious,//Öåëåóñòðåìëåííûé
	Frivolous,//Ëåãêîìûñëåííûé
	Unpredictable,//Íåïðåäñêàçóåìûé
	Stable,//Ñòàáèëüíûé
	Unstable,//Íåïîñòîÿííûé
	Proud,//Ãîðäûé
	Humble,//Ñìèðåííûé
	Demanding,//Òðåáîâàòåëüíûé
	Witty,//Îñòðîóìíûé
	Melancholy,//Ìåëàíõîëè÷íûé
	dedicated,//Ïðåäàííûé
	Independent,//Íåçàâèñèìûé
	Opinionated,//Óïðÿìûé
	Diplomatic,//Äèïëîìàòè÷íûé
	conflicting    	//Êîíôëèêòíûé
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
	std::map<Attrib_P,  CAttrib_P>  ATTRIB_P;
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

