//----------------------------------------------------------
// заголовок тут (c)
//----------------------------------------------------------

#include <stdio.h>
#include <Windows.h>
#include "World.h"
#include "XMLs.h"
#include "character/EnumState.h"

//----------------------------------------------------------
void main()
{
	ESS->init();

	if (!XML::LoadFactions("factions.xml"))
	{
		printf("ERROR: Can't load factions\n");
		return;
	}
	World* world1 = XML::LoadWorld("world.xml");
	if (!world1)
	{
		printf("ERROR: Can't load world\n");
		return;
	}
	if (!XML::LoadCharacters("characters.xml", world1))
	{
		printf("ERROR: Can't load chars\n");
		return;
	}

	for (int n = 0;; n++)
	{
		Sleep(1000);
		printf("Tick number %u\n", n);
		world1->Tick();
	}
}
//----------------------------------------------------------

