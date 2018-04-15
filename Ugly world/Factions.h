//----------------------------------------------------------
// заголовок тут (c)
//----------------------------------------------------------

#pragma once

#include "Singleton.h"
#include "explicitIntegralID.h"

//----------------------------------------------------------
using FactionID = ExplicitIntegralID<uint32_t, class FactionIDTag>;
constexpr FactionID InvalidFactionID(0);
constexpr bool IsValid(const FactionID id)
{
	return id != InvalidFactionID;
}
//----------------------------------------------------------
class Faction
{
private:
	FactionID ID = InvalidFactionID;
public:
	Faction() {};

	bool SerializeFromXML(const tinyxml2::XMLElement* node) { return true; };
	void Tick() {};
};
//----------------------------------------------------------
class Factions : public Singleton<Factions>
{
	friend Singleton<Factions>;
private:
	Factions() {};
public:
	void addFaction(const Faction* faction) {};
	void Tick() {};
};
//----------------------------------------------------------
#define FACTIONS Factions::instance()
