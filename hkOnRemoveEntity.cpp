#include "sdk.h"


CEntityInstance* __fastcall hooks::hkOnRemoveEntity(void* rcx, CEntityInstance* pInstance, CBaseHandle hHandle)
{
    valve::gCacheEnt->onRemoveEntity(pInstance, hHandle);
    return sdk::pointers->fpOnRemoveEntity(rcx, pInstance, hHandle);
}

