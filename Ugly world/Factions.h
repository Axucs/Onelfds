//----------------------------------------------------------
// заголовок тут (c)
//----------------------------------------------------------

#pragma once

#include <cstdint> // uint32_t
#include "Singleton.h"
#include "explicitIntegralID.h"

namespace tinyxml2
{
	class XMLElement; // это сделано что бы не делать #include <tinyxml2.h> сюда.
};

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
class Factions : public Singleton<Factions>
{
	friend Singleton<Factions>;
private:
	Factions() = default;
public:
	void addFaction(const Faction* faction);
	void Tick();
};
//----------------------------------------------------------
#define FACTIONS Factions::instance()
