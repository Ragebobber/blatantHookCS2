#include "sdk.h"

static bool init = false;
static bool toDraw = true;
static ID3D11Device* pDevice = nullptr;
static ID3D11DeviceContext* pContext = nullptr;
static ID3D11RenderTargetView* mainRenderTargetView = nullptr;

HRESULT __stdcall hooks::hkPresent(IDXGISwapChain* pSwapChain, UINT SyncInterval, UINT Flags)
{
    if (!init) {
        auto getDevice = pSwapChain->GetDevice(__uuidof(ID3D11Device), reinterpret_cast<void**>(&pDevice));
		if (FAILED(getDevice))
			return sdk::pointers->fpD3D11Present(pSwapChain, SyncInterval, Flags);

		pDevice->GetImmediateContext(&pContext);
		DXGI_SWAP_CHAIN_DESC sd;
		pSwapChain->GetDesc(&sd);

		ID3D11Texture2D* pBackBuffer;
		auto getBuff = pSwapChain->GetBuffer(0, __uuidof(ID3D11Texture2D), (LPVOID*)&pBackBuffer);
		if (FAILED(getBuff))
			return sdk::pointers->fpD3D11Present(pSwapChain, SyncInterval, Flags);

		auto createRender = pDevice->CreateRenderTargetView(pBackBuffer, NULL, &mainRenderTargetView);
		if (FAILED(createRender))
			return sdk::pointers->fpD3D11Present(pSwapChain, SyncInterval, Flags);

		pBackBuffer->Release();

		sdk::pointers->fpWinProc = SetWindowLongPtr(sd.OutputWindow, GWLP_WNDPROC, (LONG_PTR)hooks::hkWndProc);

		ImGui::CreateContext();
		ImGuiIO& io = ImGui::GetIO();
		io.ConfigWindowsMoveFromTitleBarOnly = true;
		//io.MouseDrawCursor = true;
		//ImGui::StyleColorsDark();

		ImGuiStyle& style = ImGui::GetStyle();
		style.WindowTitleAlign = { 0.5f, 0.5f };

		ImGui_ImplWin32_Init(sd.OutputWindow);
		ImGui_ImplDX11_Init(pDevice, pContext);

		init = true;

    }
	if (toDraw) {
		// Start the Dear ImGui frame
		ImGui_ImplDX11_NewFrame();
		ImGui_ImplWin32_NewFrame();
		ImGui::NewFrame();

		cheat::visuals->start(ImGui::GetBackgroundDrawList());
		cheat::menu->draw();
		// Rendering
		ImGui::Render();
		pContext->OMSetRenderTargets(1, &mainRenderTargetView, nullptr);
		ImGui_ImplDX11_RenderDrawData(ImGui::GetDrawData());
		toDraw = false;
	}
	else
		toDraw = true;
	

	return sdk::pointers->fpD3D11Present(pSwapChain, SyncInterval, Flags);
}

