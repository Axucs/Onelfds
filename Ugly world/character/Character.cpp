//----------------------------------------------------------
// заголовок тут (c)
//----------------------------------------------------------

#include "Character.h"
#include "EnumState.h"

//----------------------------------------------------------
Character::Character() : 
	mAttribP(4, eAttrib::Strength, eAttrib::Agility, eAttrib::Endurance, eAttrib::Empty),
	mAttribPM(5, eAttrib::Will, eAttrib::Perception, eAttrib::Reflex, eAttrib::Dexterity, eAttrib::Empty),
	mAttribM(6, eAttrib::Intellect, eAttrib::Mind, eAttrib::Logics, eAttrib::Charisma, eAttrib::Memory, eAttrib::Empty)
{
}
//----------------------------------------------------------
void Character::setWorldView(const eWorldView type, const tWorldViewPos pos)
{
	auto it = mWorldView.find(type);
	if (it == mWorldView.end())
	{
		mWorldView.insert(std::make_pair(type, pos));
	}
	else
	{
		it->second = pos;
	}
}
//----------------------------------------------------------
void Character::setAttrib_P(unsigned int x0, unsigned int x1, unsigned int x2, unsigned int x3)
{
	mAttribP[0] = x0;
	mAttribP[1] = x1;
	mAttribP[2] = x2;
	mAttribP[3] = x3;
}
//----------------------------------------------------------
void Character::setAttrib_PM(unsigned int x0, unsigned int x1, unsigned int x2, unsigned int x3)
{
	mAttribPM[0] = x0;
	mAttribPM[1] = x1;
	mAttribPM[2] = x2;
	mAttribPM[3] = x3;
}
//----------------------------------------------------------
void Character::setAttrib_M(unsigned int x0, unsigned int x1, unsigned int x2, unsigned int x3)
{
	mAttribM[0] = x0;
	mAttribM[1] = x1;
	mAttribM[2] = x2;
	mAttribM[3] = x3;
}
//----------------------------------------------------------
bool Character::SerializeFromXML(const tinyxml2::XMLElement* node)
{
	const tinyxml2::XMLAttribute* attribute = node->FindAttribute("id");
	if (attribute)
	{
		mCharID = tCharID(attribute->IntValue());
	}
	//---------------------------
	attribute = node->FindAttribute("name");
	if (attribute)
	{
		mName = attribute->Value();
	}
	//---------------------------
	attribute = node->FindAttribute("race");
	if (attribute)
	{
		mRace = ESS->getStateByTag<eRace>(attribute->Value());
	}
	//---------------------------
	attribute = node->FindAttribute("age");
	if (attribute)
	{
		mAge = attribute->IntValue();
	}
	//---------------------------
	attribute = node->FindAttribute("gender");
	if (attribute)
	{
		mGender = ESS->getStateByTag<eGender>(attribute->Value());
	}
	//---------------------------
	attribute = node->FindAttribute("social");
	if (attribute)
	{
		mSociability = attribute->IntValue();
	}
	//---------------------------
	attribute = node->FindAttribute("neatness");
	if (attribute)
	{
		mNeatness = attribute->IntValue();
	}
	//---------------------------
	attribute = node->FindAttribute("society_class");
	if (attribute)
	{
		mSocietyClass = ESS->getStateByTag<eSocietyClass>(attribute->Value());
	}
	//---------------------------
	attribute = node->FindAttribute("faction");
	if (attribute)
	{
		mFactionID = tFactionID(attribute->UnsignedValue());
	}
	//---------------------------
	attribute = node->FindAttribute("main_task");
	if (attribute)
	{
		mMainTask = ESS->getStateByTag<eMainTask>(attribute->Value());
	}
	//---------------------------
	attribute = node->FindAttribute("moment_task");
	if (attribute)
	{
		mMomentTask = ESS->getStateByTag<eMomentTask>(attribute->Value());
	}
	//---------------------------
	attribute = node->FindAttribute("status");
	if (attribute)
	{
		mStatus = ESS->getStateByTag<eStatus>(attribute->Value());
	}
	//---------------------------
	attribute = node->FindAttribute("p_fatigue");
	if (attribute)
	{
		mPhysicalFatigue = ESS->getStateByTag<ePhysicalFatigue>(attribute->Value());
	}
	//---------------------------
	attribute = node->FindAttribute("m_fatigue");
	if (attribute)
	{
		mMentalFatigue = ESS->getStateByTag<eMentalFatigue>(attribute->Value());
	}
	//---------------------------
	attribute = node->FindAttribute("mood");
	if (attribute)
	{
		mMood = ESS->getStateByTag<eMood>(attribute->Value());
	}
	//---------------------------
	const tinyxml2::XMLElement* att_p_Node = node->FirstChildElement("attrib_p");
	if (att_p_Node)
	{
		if (!mAttribP.SerializeFromXML(att_p_Node))
		{
			printf("ERROR: Problems in attrin_p");
		}
	}
	//---------------------------
	const tinyxml2::XMLElement* att_pm_Node = node->FirstChildElement("attrib_pm");
	if (att_pm_Node)
	{
		if (!mAttribPM.SerializeFromXML(att_pm_Node))
		{
			printf("ERROR: Problems in attrin_pm");
		}
	}
	//---------------------------
	const tinyxml2::XMLElement* att_m_Node = node->FirstChildElement("attrib_m");
	if (att_m_Node)
	{
		if (!mAttribM.SerializeFromXML(att_m_Node))
		{
			printf("ERROR: Problems in attrin_m");
		}
	}
	//---------------------------
	const tinyxml2::XMLElement* worldViewNode = node->FirstChildElement("world_view");
	if (worldViewNode)
	{
		const tinyxml2::XMLAttribute* creationDestructionAtt = worldViewNode->FindAttribute("creation-destruction");
		if (creationDestructionAtt)
		{
			tWorldViewPos val(creationDestructionAtt->IntValue());
			setWorldView(eWorldView::cre_des, val);
		}
		const tinyxml2::XMLAttribute* materialMentalAtt = worldViewNode->FindAttribute("material-mental");
		if (materialMentalAtt)
		{
			tWorldViewPos val(materialMentalAtt->IntValue());
			setWorldView(eWorldView::mat_men, val);
		}
		const tinyxml2::XMLAttribute* selfImprovementExploitationAtt = worldViewNode->FindAttribute("self_improvement-exploitation");
		if (selfImprovementExploitationAtt)
		{
			tWorldViewPos val(selfImprovementExploitationAtt->IntValue());
			setWorldView(eWorldView::simp_exp, val);
		}
	}
	//---------------------------
	return true;
}
//----------------------------------------------------------
void Character::Tick()
{
	//printf("Char\n");
};
//----------------------------------------------------------
