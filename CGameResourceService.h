#pragma once

class CGameResourceManifest;
class CCompressedResourceManifest;

struct CGameResourceService
{
	//size 44
	virtual bool Connect(void* (__cdecl* a2)(const char*, int*)) = 0;
	virtual __int64 Disconnect() = 0;
	virtual void unk_2() = 0;
	virtual __int64 Init() = 0;
	virtual uintptr_t** Shutdown() = 0;
	virtual void unk_5() = 0;
	virtual void unk_6() = 0;
	virtual void unk_7() = 0;
	virtual void unk_8() = 0;
	virtual void unk_9() = 0;
	virtual void unk_10() = 0;
	virtual void unk_11() = 0;
	virtual void unk_12() = 0;
	virtual void unk_13() = 0;
	virtual void unk_14() = 0;
	virtual void unk_15() = 0;
	virtual void unk_16() = 0;
	virtual void unk_17() = 0;
	virtual void unk_18() = 0;
	virtual void unk_19() = 0;
	virtual void unk_20() = 0;
	virtual void unk_21() = 0;
	virtual void unk_22() = 0;
	virtual void unk_23() = 0;
	virtual __int64 LoadGameResourceManifestNamed(const char* a2,int a3,__int64 a4,int a5) = 0;//// #STR: "%s.%s", "CGameResourceService::BuildResourceManifest(start)", "CGameResourceService::BuildResourceManifest(finish)", "vrnmd"
	virtual __int64 LoadGameResourceManifestGroup(const char* a2, int a3, __int64 a4, int a5) = 0;// #STR: "%s.%s", "CGameResourceService::BuildResourceManifest(start)", "CGameResourceService::BuildResourceManifest(finish)", "vrgrp"
	virtual bool LoadGameResourceManifest(__int64 a2) = 0;
	virtual __int64 LoadGameResourceManifest(__int64 a2,__int64 a3,unsigned int a4,__int64 a5,unsigned int a6) = 0;//// #STR: "CGameResourceService::BuildResourceManifest(finish)", "CGameResourceService::BuildResourceManifest(start)"
	virtual void unk_28() = 0;
	virtual void unk_29() = 0;
	virtual void unk_30() = 0;
	virtual void BlockUntilManifestLoaded(__int64 a2) = 0;
	virtual void DestroyResourceManifest(CGameResourceManifest* a2) = 0;
	virtual const char* GetResourceManifestDebugName() = 0;
	virtual bool DoesManifestHaveFutureDependentResources(__int64 a2) = 0;
	virtual void unk_35() = 0;
	virtual void PrecacheEntitiesAndConfirmResourcesAreLoaded(unsigned int a2,unsigned int a3,__int64 a4,__int64 a5) = 0;// #STR: "CGameResourceService::BuildResourceManifest(start)", "CGameResourceService::BuildResourceManifest(finish)", "PrecacheEntitiesAndConfirmResourcesAreLoaded"
	virtual void DescribeContents(__int64 a1, unsigned int a2, __int64 a3) = 0;// #STR: "CGameResourceService::DescribeContents:  manifest handle =
	virtual void unk_38() = 0;
	virtual void unk_39() = 0;
	virtual void unk_40() = 0;
	virtual void AppendToGameResourceManifest(__int64 a2,int a3,char a4,int a5,char a6) = 0;// #STR: "%s appended"
	virtual void BuildCompressedManifest(__int64 a2,CCompressedResourceManifest* a3,char a4) = 0;
	virtual __int64 LockGameResourceManifest(char a2, __int64 a3) = 0;
	virtual char AppendToAndCreateGameResourceManifest(__int64 a2,unsigned int a3,int a4,__int64 a5,__int64 a6) = 0;// #STR: "CGameResourceService::BuildResourceManifest(finish)", "CGameResourceService::BuildResourceManifest(start)"

	CGameEntitySystem* GetGameEntitySystem() {
		return *reinterpret_cast<CGameEntitySystem**>((uintptr_t)(this) + 0x58);
	}
};