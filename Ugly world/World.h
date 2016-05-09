//----------------------------------------------------------
// заголовок тут (c)
//----------------------------------------------------------

#pragma once

#include <list>

class Character;

enum class ZoneId {
	r1Z1 = 1,          //1 ðåãèîí 1 çîíà
	r1Z2,              //1 ðåãèîí 2 çîíà
	r1Z3,              //1 ðåãèîí 3 çîíà
	r1Z4,              //1 ðåãèîí 4 çîíà
	r2Z1,              //2 ðåãèîí 1 çîíà
	r2Z2,              //2 ðåãèîí 2 çîíà
	r2Z3,              //2 ðåãèîí 3 çîíà
	r2Z4,              //2 ðåãèîí 4 çîíà
	r3Z1,              //3 ðåãèîí 1 çîíà
	r3Z2,              //3 ðåãèîí 2 çîíà
	r3Z3,              //3 ðåãèîí 3 çîíà
	r3Z4,              //3 ðåãèîí 4 çîíà
	r4Z1,              //4 ðåãèîí 1 çîíà
	r4Z2,			   //4 ðåãèîí 2 çîíà
	r4Z3,			   //4 ðåãèîí 3 çîíà
	r4Z4 			   //4 ðåãèîí 4 çîíà
};
class Zone
{
private:
	ZoneId ID;
public:

	Zone(ZoneId id) {
		ID = id;
	}
	void Tick();
};

class World {
private:
	std::list<Zone*> Zones;
	std::list<Character*> Characters;
public:

	World();
	void addZone(Zone* X);
	void addCharacter(Character* X);
	void Tick();
};















