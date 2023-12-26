#include "sdk.h"

IFactory::IFactory()
{
    interfaceMap = {
       {INTERFACE_RESOURCE_SERVICE, {"engine2.dll", "GameResourceServiceClientV001"}},
       {INTERFACE_ENTITY_SYSTEM, {"engine2.dll", nullptr}},
       {INTERFACE_ENGINE_CLIENT, {"engine2.dll", "Source2EngineToClient001"}},
       {INTERFACE_SCHEMA_SYSTEM, {"schemasystem.dll", "SchemaSystem_001"}},
       {INTERFACE_CSGOINPUT,{}},
    };
    
    poinetObjects = {
        {POINER_GET_MATRIX_FOR_VIEW,{"client.dll", "40 53 48 81 EC ? ? ? ? 49 8B C1"}},
        {POINTER_GET_ENT_BY_INDEX,{"client.dll", "81 FA ? ? ? ? 77 36"}},
        {POINTER_GET_MAX_ENT_INDEX,{"client.dll", "E8 ? ? ? ? 33 DB 39 5C 24 40"}},
		{POINTER_GET_CLIENT_INPUT,{"client.dll", "48 8B 0D ? ? ? ? 48 8B 01 FF 50 ? 8B DF"}}
    };

    hookObjects = {
        {HOOK_ON_ADD_ENT},
        {HOOK_ON_REMOVE_ENT},
        {HOOK_D3D11_PRESENT},
        {HOOK_MATRICES_FOR_VIEW},
        {HOOK_CREATE_MOVE},
    };
}



IFactory::~IFactory()
{
}

bool IFactory::initializeInterfaces()
{
        for (const auto& entry : interfaceMap) {
            switch (entry.first) {
            case INTERFACE_RESOURCE_SERVICE:     
                I::gResourceService = sdk::helpers->getInterface<CGameResourceService>(entry.second.first, entry.second.second);
                if (!I::gResourceService)
                    return false;
                break;
            case INTERFACE_ENTITY_SYSTEM:
                I::gEntitySystem = I::gResourceService->GetGameEntitySystem();
                if (!I::gEntitySystem)
                    return false;
                break;
            case INTERFACE_ENGINE_CLIENT:
                I::gEngineClient = sdk::helpers->getInterface<CEngineClient>(entry.second.first, entry.second.second);
                if (!I::gEngineClient)
                    return false;
                break;          
            case INTERFACE_SCHEMA_SYSTEM:
                I::gSchemaSystem = sdk::helpers->getInterface<CSchemaSystem>(entry.second.first, entry.second.second);
                if (!I::gSchemaSystem)
                    return false;
                break; 
            case INTERFACE_CSGOINPUT:
                I::gInput = *reinterpret_cast<CCSGOInput**>(sdk::pointers->pGetClientInput);
                if (!I::gInput)
                    return false;
                break;
            default:
                return false;
            }
        }
        return true;
}

bool IFactory::initializePointers()
{
    for (const auto& entry : poinetObjects) {
        auto data = sdk::helpers->patternScan(entry.second.first, entry.second.second);
        if (!data)
            return false;

        switch (entry.first)
        { 
            case POINER_GET_MATRIX_FOR_VIEW:
				sdk::pointers->pGetMatricesForView = data;
                break;
            case POINTER_GET_ENT_BY_INDEX:
                sdk::pointers->pGetEntByIdx = data;
                break;
			case POINTER_GET_MAX_ENT_INDEX:
                sdk::pointers->pGetMaxEntIndex = data;
                break;
            case POINTER_GET_CLIENT_INPUT:
                sdk::pointers->pGetClientInput = sdk::helpers->getAbsolute(data,3,7);
                break;
            default:
                return false;    
        }
    }
	return true;
}

bool IFactory::initializeHooks()
{
    MH_STATUS init = MH_Initialize();
    void** ptrD3D11Table = sdk::helpers->getSwapChain();
  
    for (const auto& entry : hookObjects) {
        MH_STATUS hookStatus = MH_OK;
        switch (entry)
        {
        case HOOK_ON_ADD_ENT:
            hookStatus = MH_CreateHook(sdk::helpers->GetVMethod(14, I::gEntitySystem), &hooks::hkOnAddEntity, reinterpret_cast<LPVOID*>(&sdk::pointers->fpOnAddEntity));
            break;
        case HOOK_ON_REMOVE_ENT:
            hookStatus = MH_CreateHook(sdk::helpers->GetVMethod(15, I::gEntitySystem), &hooks::hkOnRemoveEntity, reinterpret_cast<LPVOID*>(&sdk::pointers->fpOnRemoveEntity));
            break;
        case HOOK_D3D11_PRESENT:
            hookStatus = MH_CreateHook(ptrD3D11Table[8], &hooks::hkPresent, reinterpret_cast<LPVOID*>(&sdk::pointers->fpD3D11Present));
            break;
        case HOOK_MATRICES_FOR_VIEW:
            hookStatus = MH_CreateHook(sdk::pointers->pGetMatricesForView, &hooks::hkMatricesForView, reinterpret_cast<LPVOID*>(&sdk::pointers->fpMatricesForView));
            break;
        case HOOK_CREATE_MOVE:
            hookStatus = MH_CreateHook(sdk::helpers->GetVMethod(5, I::gInput),&hooks::hkCreateMove,reinterpret_cast<LPVOID*>(&sdk::pointers->fpCreateMove));
            break;
        default:
            return false;
        }
        //SOME HOOK error
        if (hookStatus != MH_OK) {
            return false;
        }
    }

    return  MH_EnableHook(MH_ALL_HOOKS) == MH_OK;
}

bool IFactory::initializeValveFunctions()
{
    //Volve 
    valve::gCacheEnt->cacheCurrentEntities();
    return true;
}
