//----------------------------------------------------------
// заголовок тут (c)
//----------------------------------------------------------

#include "Factions.h"
#include <tinyxml2.h>

//----------------------------------------------------------
bool Faction::SerializeFromXML(const tinyxml2::XMLElement* node)
{
	const tinyxml2::XMLAttribute* idAtt = node->FindAttribute("name");
	if (idAtt)
	{
		ID = tFactionID(idAtt->UnsignedValue());
	}
	return true;
}
//----------------------------------------------------------
void Faction::Tick()
{
}
//----------------------------------------------------------
void Factions::addFaction(const Faction* faction)
{
}
//----------------------------------------------------------
void Factions::Tick()
{
}
//----------------------------------------------------------
