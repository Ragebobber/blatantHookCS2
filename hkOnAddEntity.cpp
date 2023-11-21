#include "sdk.h"


CEntityInstance* __fastcall hooks::hkOnAddEntity(void* rcx, CEntityInstance* pInstance, CBaseHandle hHandle)
{
    valve::gCacheEnt->onAddEntity(pInstance, hHandle);
    return sdk::pointers->fpOnAddEntity(rcx, pInstance, hHandle);
}
