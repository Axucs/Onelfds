//----------------------------------------------------------
// заголовок тут (c)
//----------------------------------------------------------

#include "World.h"
#include "Character.h"
#include "Factions.h"

//----------------------------------------------------------
Area::Area(AreaId id)
{
	ID = id;
}
//----------------------------------------------------------
bool Area::SerializeFromXML(const tinyxml2::XMLElement* node)
{
	//
	return true;
}
//----------------------------------------------------------
void Area::Tick()
{
	//printf("Area %u\n",ID);
};
//----------------------------------------------------------
World::World() : Areas(), Characters()
{
}
//----------------------------------------------------------
void World::Tick()
{
	FACTIONS->Tick();
	for (auto area : Areas)
	{
		area->Tick();
	};
	for (auto character : Characters)
	{
		character->Tick();
	};
}
//----------------------------------------------------------
void World::addArea(Area* X)
{
	Areas.push_back(X);
}
//----------------------------------------------------------
void World::addCharacter(Character* X)
{
	Characters.push_back(X);
}
//----------------------------------------------------------
