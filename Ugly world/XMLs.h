//----------------------------------------------------------
// заголовок тут (c)
//----------------------------------------------------------

#pragma once

#include <list>

class World;
class Character;

class XML {
public:
	static World* LoadWorld(const char* fileName);
	static bool LoadCharacters(const char* fileName, World* world);
};
