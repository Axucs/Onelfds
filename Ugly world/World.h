//----------------------------------------------------------
// заголовок тут (c)
//----------------------------------------------------------

#pragma once

#include <list>
#include <tinyxml2.h>

class Character;

//----------------------------------------------------------
enum class AreaId
{
	r1Z1 = 1,
	r1Z2,
	r1Z3,
	r1Z4,
	r2Z1,
	r2Z2,
	r2Z3,
	r2Z4,
	r3Z1,
	r3Z2,
	r3Z3,
	r3Z4,
	r4Z1,
	r4Z2,
	r4Z3,
	r4Z4
};
//----------------------------------------------------------
class Area
{
private:
	AreaId ID;
public:
	Area(AreaId id);
	bool SerializeFromXML(const tinyxml2::XMLElement* node);
	void Tick();
};
//----------------------------------------------------------
class World
{
private:
	std::list<Area*> Areas;
	std::list<Character*> Characters;
public:
	World();
	void addArea(Area* X);
	void addCharacter(Character* X);
	void Tick();
};
//----------------------------------------------------------

