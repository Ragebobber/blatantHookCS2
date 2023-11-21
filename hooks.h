#pragma once


namespace hooks {
	extern CEntityInstance* __fastcall hkOnAddEntity(void* rcx, CEntityInstance* pInstance, CBaseHandle hHandle);
	extern CEntityInstance* __fastcall hkOnRemoveEntity(void* rcx, CEntityInstance* pInstance, CBaseHandle hHandle);

	extern HRESULT __stdcall hkPresent(IDXGISwapChain* pSwapChain, UINT SyncInterval, UINT Flags);
	extern LRESULT __stdcall hkWndProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam);
	extern void		__fastcall hkMatricesForView(void* rcx, void* view,VMatrix* pWorldToView,VMatrix* pViewToProjection,VMatrix* pWorldToProjection,VMatrix* pWorldToPixels);
};