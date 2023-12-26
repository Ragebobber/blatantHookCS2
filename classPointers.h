#pragma once
class CEntityInstance;
class CBaseHandle;
class CCSGOInput;


using oOnAddEntity = CEntityInstance * (__fastcall*)(void*, CEntityInstance*, CBaseHandle);
using oOnRemoveEntity = CEntityInstance * (__fastcall*)(void*, CEntityInstance*, CBaseHandle);
using oD3D11Present = HRESULT(__stdcall*)(IDXGISwapChain* pSwapChain, UINT SyncInterval, UINT Flags);
using oMatricesForView = void(__fastcall*)(void*, void*, VMatrix*, VMatrix*, VMatrix*, VMatrix*);
using oCreateMove = bool(__fastcall*)(CCSGOInput* input, const uint32_t  vSlot, const bool active);

struct ClassPointers
{
	uint8_t* pGetEntByIdx;
	uint8_t* pGetMaxEntIndex;
	void* pGetMatricesForView;
	uint8_t* pGetClientInput;

	oOnAddEntity fpOnAddEntity;
	oOnRemoveEntity	fpOnRemoveEntity;
	oD3D11Present fpD3D11Present;
	oMatricesForView fpMatricesForView;
	oCreateMove		fpCreateMove;
	LONG_PTR  fpWinProc;

	void Initialaize() {

	}

};