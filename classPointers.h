#pragma once
class CEntityInstance;
class CBaseHandle;


using oOnAddEntity = CEntityInstance * (__fastcall*)(void*, CEntityInstance*, CBaseHandle);
using oOnRemoveEntity = CEntityInstance * (__fastcall*)(void*, CEntityInstance*, CBaseHandle);
using oD3D11Present = HRESULT(__stdcall*)(IDXGISwapChain* pSwapChain, UINT SyncInterval, UINT Flags);
using oMatricesForView = void(__fastcall*)(void*, void*, VMatrix*, VMatrix*, VMatrix*, VMatrix*);

struct ClassPointers
{
	uint8_t* pGetEntByIdx;
	uint8_t* pGetMaxEntIndex;
	void* pGetMatricesForView;

	oOnAddEntity fpOnAddEntity;
	oOnRemoveEntity	fpOnRemoveEntity;
	oD3D11Present fpD3D11Present;
	oMatricesForView fpMatricesForView;
	LONG_PTR  fpWinProc;

	void Initialaize() {

	}

};