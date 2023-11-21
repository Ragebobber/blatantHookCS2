#include "sdk.h"

Init::Init()
{

}

Init::~Init()
{
}

void Init::startService()
{
	I::gResourceService = sdk::helpers->getInterface<CGameResourceService>("engine2.dll", "GameResourceServiceClientV001");
	I::gEntitySystem = I::gResourceService->GetGameEntitySystem();
	I::gEngineClient = sdk::helpers->getInterface<CEngineClient>("engine2.dll", "Source2EngineToClient001");
	I::gSchemaSystem = sdk::helpers->getInterface<CSchemaSystem>("schemasystem.dll", "SchemaSystem_001");

	sdk::pointers->pGetEntByIdx = sdk::helpers->patternScan("client.dll", "81 FA ? ? ? ? 77 36");
	sdk::pointers->pGetMaxEntIndex = sdk::helpers->patternScan("client.dll", "E8 ? ? ? ? 33 DB 39 5C 24 40");
	sdk::pointers->pGetMatricesForView = sdk::helpers->patternScan("client.dll", "40 53 48 81 EC ? ? ? ? 49 8B C1");

	MH_STATUS init = MH_Initialize();

	void** ptrD3D11Table = sdk::helpers->getSwapChain();

	MH_STATUS hkOnAddEnt = MH_CreateHook(sdk::helpers->GetVMethod(14,I::gEntitySystem), &hooks::hkOnAddEntity, reinterpret_cast<LPVOID*>(&sdk::pointers->fpOnAddEntity));
	MH_STATUS hkOnRemoveEnt = MH_CreateHook(sdk::helpers->GetVMethod(15, I::gEntitySystem), &hooks::hkOnRemoveEntity, reinterpret_cast<LPVOID*>(&sdk::pointers->fpOnRemoveEntity));
	MH_STATUS hkD3D11Present = MH_CreateHook(ptrD3D11Table[8], &hooks::hkPresent, reinterpret_cast<LPVOID*>(&sdk::pointers->fpD3D11Present));
	MH_STATUS hkMatricesForView = MH_CreateHook(sdk::pointers->pGetMatricesForView, &hooks::hkMatricesForView, reinterpret_cast<LPVOID*>(&sdk::pointers->fpMatricesForView));

	MH_STATUS startAll = MH_EnableHook(MH_ALL_HOOKS);

	valve::gCacheEnt->cacheCurrentEntities();

}
