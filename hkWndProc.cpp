#include "sdk.h"

// Forward declare message handler from imgui_impl_win32.cpp
extern IMGUI_IMPL_API LRESULT ImGui_ImplWin32_WndProcHandler(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam);
LRESULT __stdcall hooks::hkWndProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
	if (ImGui_ImplWin32_WndProcHandler(hWnd, uMsg, wParam, lParam))
		return true;

	if (uMsg == WM_KEYDOWN) {
		if (wParam == VK_INSERT)
			cheat::vars->menu.open = !cheat::vars->menu.open;
	}

	return CallWindowProcW((WNDPROC)sdk::pointers->fpWinProc , hWnd, uMsg, wParam, lParam);
}
