#include "sdk.h"

int CGameEntitySystem::GetHighestEntityIndex()
{
    return *reinterpret_cast<int*>(reinterpret_cast<std::uintptr_t>(this) + 0x1510);
}

C_BaseEntity* CGameEntitySystem::GetLocalPlayer()
{
    return Get(I::gEngineClient->GetLocalPlayerIndex());
}

C_BaseEntity* CGameEntitySystem::GetClientEntity(int entnum)
{
    // #STR: "(missing),", "(missing)", "Ent %3d: %s class %s name %s\n"
    /* do
    {
        BaseEntity = CGameEntitySystem::GetBaseEntity(g_pGameEntitySystem, nIndex); 
        v3 = BaseEntity;
   */
    using templateFn = C_BaseEntity * (__thiscall*)(void*, int);
    auto pCall = reinterpret_cast<templateFn>(sdk::pointers->pGetEntByIdx);
    return pCall(this,entnum);
}
