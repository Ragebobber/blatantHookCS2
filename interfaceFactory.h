#pragma once

enum InterfaceType {
    INTERFACE_RESOURCE_SERVICE,
    INTERFACE_ENTITY_SYSTEM,
    INTERFACE_ENGINE_CLIENT,
    INTERFACE_SCHEMA_SYSTEM
};

enum PoinerType {
    POINTER_GET_ENT_BY_INDEX,
    POINTER_GET_MAX_ENT_INDEX,
    POINER_GET_MATRIX_FOR_VIEW,
};

enum HookType {
	HOOK_ON_ADD_ENT,
	HOOK_ON_REMOVE_ENT,
    HOOK_D3D11_PRESENT,
	HOOK_MATRICES_FOR_VIEW,
};

class IFactory {
public:
	IFactory();
	~IFactory();
    bool  initializeInterfaces();
	bool  initializePointers();
    bool  initializeHooks();
    bool  initializeValveFunctions();
private:
    std::map<InterfaceType, std::pair<const char*, const char*>> interfaceMap;
    std::map<InterfaceType, void*> interfaceObjects;
    std::map<PoinerType, std::pair<const char*, const char*>> poinetObjects;
    std::vector<HookType> hookObjects;
};
