//----------------------------------------------------------
// заголовок тут (c)
//----------------------------------------------------------

#include "EnumState.h"

//----------------------------------------------------------
cEnumStatesStorage::cEnumStatesStorage()
{
	init();
}
//----------------------------------------------------------
cEnumStatesStorage* cEnumStatesStorage::instance()
{
	return Singleton<cEnumStatesStorage>::instance();
}
//----------------------------------------------------------
void cEnumStatesStorage::init()
{
	ESS->addState(eTestState::pf1, "pf1");
	ESS->addState(eTestState::pf2, "pf2");

	auto* ptr = ESS->getState<eTestState>();

	const char* state = ESS->getStateTag(eTestState::pf1);

	ESS->for_each<eTestState>([](const eTestState item) {});
}
//----------------------------------------------------------
