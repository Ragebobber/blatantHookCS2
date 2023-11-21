#pragma once
class CEntityKeyValues {

};
class CUtlVectorBase {

};

class CGameEntitySystem
{
public:
	//size 22
	virtual void unk_0() = 0;
	virtual C_BaseEntity* BuildResourceManifest(C_BaseEntity* a1, const char* a2, __int64 a3, __int64 a4) = 0;//#STR: "GameSessionManifest.vrgrp"
	virtual CUtlVectorBase* BuildResourceManifest(unsigned int a2,int* a3,BYTE* a4,_int64 a5,__int64 a6) = 0;// #STR: "classname", "prefab_load_dynamic", "point_prefab", "kv 0x%p Release refcount == %d\n", "kv 0x%p AddRef refcount == %d\n"
	virtual void unk_3() = 0;
	virtual void unk_4() = 0;
	virtual void unk_5() = 0;
	virtual void unk_6() = 0;
	virtual void AddRefKeyValues(CEntityKeyValues*) = 0;// #STR: "kv 0x%p AddRef refcount == %d\n"
	virtual void ReleaseKeyValues(CEntityKeyValues*) = 0;// #STR: "kv 0x%p Release refcount == %d\n"
	virtual void unk_9() = 0;
	virtual void unk_10() = 0;
	virtual void ClearEntityDatabase() = 0;
	virtual CEntityInstance* FindEntityProcedural(const char* a2,CEntityInstance* a3,CEntityInstance* a4,CEntityInstance* a5) = 0;
	virtual CEntityInstance* OnEntityParentChanged(CEntityInstance* a3, CEntityInstance* a4) = 0;
	virtual CEntityInstance* OnAddEntity(CEntityInstance* pInstance, CBaseHandle hHandle) = 0;
	virtual CEntityInstance* OnRemoveEntity(CEntityInstance* pInstance, CBaseHandle hHandle) = 0;
	virtual void unk_16() = 0;
	virtual void SortEntities(unsigned int a2, __int64** a3) = 0;// #STR: "Memory trash in SortEntities.. overran the number of entit
	virtual void unk_18() = 0;
	virtual void unk_19() = 0;
	virtual void unk_20() = 0;
	virtual void unk_21() = 0;

public:
	template <typename T = C_BaseEntity>
	T* Get(int nIndex)
	{	
		return nIndex != -1 ? reinterpret_cast<T*>(this->GetClientEntity(nIndex)) : nullptr;
	}
	
	template <typename T = C_BaseEntity>
	T* Get( CBaseHandle hHandle)
	{
		if (!hHandle.IsValid())
			return nullptr;

		return reinterpret_cast<T*>(this->GetClientEntity(hHandle.GetEntryIndex()));
	}

	int GetHighestEntityIndex();
	C_BaseEntity* GetLocalPlayer();
private:
	C_BaseEntity* GetClientEntity(int entnum);

}; 