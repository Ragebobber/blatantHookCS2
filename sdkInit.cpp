#include "sdk.h"

Init::Init()
{

}

Init::~Init()
{
}

void Init::startService()
{
	if (!sdk::factory->initializePointers())
		return;

	if (!sdk::factory->initializeInterfaces())
		return;

	if (!sdk::factory->initializeHooks())
		return;

	if (!sdk::factory->initializeValveFunctions())
		return;
}
