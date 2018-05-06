//----------------------------------------------------------
// заголовок тут (c)
//----------------------------------------------------------

#pragma once

#include <cstdint> // uint32_t
#include <tinyxml2.h>
#include "util/Singleton.h"
#include "util/explicitIntegralID.h"

//----------------------------------------------------------
using tFactionID = ExplicitIntegralID<uint32_t, class FactionIDTag>;
constexpr tFactionID InvalidFactionID(0);
constexpr bool IsValid(const tFactionID id)
{
	return id != InvalidFactionID;
}
//----------------------------------------------------------
class Faction
{
private:
	tFactionID ID = InvalidFactionID;
public:
	Faction() = default;

	bool SerializeFromXML(const tinyxml2::XMLElement* node);
	void Tick();
};
//----------------------------------------------------------
class Factions
{
	friend class Singleton<Factions>;
private:
	Factions() = default;
public:
	static Factions* instance();

	void addFaction(const Faction* faction);
	void Tick();
};
//----------------------------------------------------------
#define FACTIONS Factions::instance()
