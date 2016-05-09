#pragma once

#include <string>
#include <map>
#include <list>
#include "CAttrib.h" //������ ���������
#include "CChar.h" //������ ��� � ���� ���������













// ���� ������
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
	adf1,  //������ �������
	adf2,  //���������� �������
	adf3,  //����� ��������
	adf4,  //�������� �������
	adf5  //����������� �������� �������
};

enum Age {
	ag1,    //"�����"
	ag2,    //"�������"
	ag3,    //"��������"
	ag4    //"������"
};

enum Neatness {
	test
};

enum Society_Class {
	SC1,      //"��������"
	SC2,      //"�����������"
	SC3,      //"�����������"
	SC4,      //"��������"
	SC5,      //"������"
	SC6,      //"�����������"
	SC7,      //"�����������"
	SC8,      //"�����"
	SC9		  //"�������"
};
enum Attrib_P {
	Strength,			 //����
	Agility,			 //��������
	Endurance,			 //������������
	empty1,				 //������� 1
};
enum Attrib_PM {
	Will,				 //����
	Perception,			 //����������
	Reflex,				 //�������
	dexterity,			 //��������
	empty2,				 //������� 2
};
enum Attrib_M {
	Intellect,			 //��������
	Mind,				 //�����
	Logics,				 //������
	Charisma,			 //�������
	Memory,				 //������
	empty3,				 //������� 3
};
enum Mood {
	m1,    //��������
	m2,    //�������
	m3,    //���� �������
	m4,    //�������
	m5,    //���� ������
	m6,    //������
	m7,    //�������
};
enum Physical_Fatigue {
	pf1,	 //��������� ������
	pf2,	 //������
	pf3,	 //���� �����
	pf4,	 //�������
	pf5,	 //���� ��������
	pf6,	 //��������
	pf7,	 //̸�����
};
enum Mental_Fatigue {
	mf1,	 //��������� ������
	mf2,	 //������
	mf3,	 //���� �����
	mf4,	 //�������
	mf5,	 //���� ��������
	mf6,	 //��������
	mf7,	 //̸�����
};
enum class Main_task {
	mat1,    //��������
	mat2,    //����������� ��������
	mat3,    //����������� �����
	mat4,    //������ �����
	mat5,    //������ �����
	mat6     //����� ������ �����
};
enum class Moment_task {
	mot1,   //��������
	mot2,   //����������� �������
	mot3,   //����������� �����
	mot4,   //������ �����
	mot5,   //������ �����
	mot6    //����� ������ �����
};

enum Skills {
	Craft,
};					

enum class Thems {
	Politics,		 //��������
	Fauna,			 //�����
	History,		 //�������
	Architecture,	 //�����������
	Handicraft,		 //�����, ������������ ���� �����
	Medicine,		 //��������
	Theology,		 //��������
	Weather,		 //������, ������
	Society,		 //�������� 
	Warfare,		 //�����
	Economy,		 //���������
	Flora,			 //�����
	Entertainmen,	 //�����������
	Culture,		 //��������
	Law,			 //������, �������
	Family,			 //���� 
	Rumors,			 //����� 
	News			 //�������
};
enum class Traits {
	Honest,//�������
	Deceptive,//������
	Generous,//������
	Greedy,//������
	Lonely,//��������
	Sociable,//�����������
	Gambler,//��������
	cold_blooded,//�������������
	Responsible,//�������������
	Irresponsible,//����������������
	Attentive,//������������
	Absentminded,//����������
	Careful,//����������
	sloppy,//����������
	Delicate,//����������
	Rough,//������
	Conceited,//����������
	Self_sufficient,//���������������
	Rasper,//������
	Flexible,//������
	Farsighted,//������������
	Myopic,//����������
	Endurant,//����������
	Individualist,//�������������
	Collectivist,//������������
	Cynical,//��������
	Sentimental,//���������������
	Cunning,//������
	Guileless,//������������
	Calm,//���������
	Dynamic,//����������
	Ambitious,//����������������
	Frivolous,//��������������
	Unpredictable,//���������������
	Stable,//����������
	Unstable,//������������
	Proud,//������
	Humble,//���������
	Demanding,//��������������
	Witty,//����������
	Melancholy,//�������������
	dedicated,//���������
	Independent,//�����������
	Opinionated,//�������
	Diplomatic,//�������������
	conflicting    	//�����������
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

