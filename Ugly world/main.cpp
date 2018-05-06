//----------------------------------------------------------
// заголовок тут (c)
//----------------------------------------------------------

#include <Windows.h>
#include "World.h"
#include "XMLs.h"
#include "character/EnumState.h"
#include "console/Console.h"

//----------------------------------------------------------
void main()
{
	ESS->init();

	if (!XML::LoadFactions("factions.xml"))
	{
		Con::Log(LOG_FATAL, "Can't load factions");
		return;
	}
	World* world1 = XML::LoadWorld("world.xml");
	if (!world1)
	{
		Con::Log(LOG_FATAL, "Can't load world");
		return;
	}
	if (!XML::LoadCharacters("characters.xml", world1))
	{
		Con::Log(LOG_FATAL, "Can't load characters");
		return;
	}

	for (int n = 0;; n++)
	{
		Sleep(1000);
		Con::Log(LOG_MESSAGE, "Tick number %u", n);
		world1->Tick();
	}
}
//----------------------------------------------------------

