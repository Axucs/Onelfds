﻿//----------------------------------------------------------
// заголовок тут (c)
//----------------------------------------------------------

#include "World.h"
#include "Character.h"

//----------------------------------------------------------
Zone::Zone(ZoneId id) {
	ID = id;
}
//----------------------------------------------------------
bool Zone::SerializeFromXML(const tinyxml2::XMLElement* node) {
	//
	return true;
}
//----------------------------------------------------------
void Zone::Tick() {
	//printf("Zone %u\n",ID);
};
//----------------------------------------------------------
World::World() : Zones(), Characters() {
}
//----------------------------------------------------------
void World::Tick() {
	for (auto zone : Zones) {
		zone->Tick();
	};
	for (auto C : Characters) {
		C->Tick();
	};
}
//----------------------------------------------------------
void World::addZone(Zone* X) {
	Zones.push_back(X);
}
//----------------------------------------------------------
void World::addCharacter(Character* X) {
	Characters.push_back(X);
}
//----------------------------------------------------------









