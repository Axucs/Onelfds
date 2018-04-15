//----------------------------------------------------------
// заголовок тут (c)
//----------------------------------------------------------

#pragma once

#include <list>

class World;
class Character;

class XML
{
public:
	static bool LoadFactions(const char* fileName);
	static World* LoadWorld(const char* fileName);
	static bool LoadCharacters(const char* fileName, World* world);
};
