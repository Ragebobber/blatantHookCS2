#include "sdk.h"


void  __fastcall hooks::hkMatricesForView(void* rcx, void* view,VMatrix* pWorldToView,VMatrix* pViewToProjection,VMatrix* pWorldToProjection,VMatrix* pWorldToPixels) {
	sdk::pointers->fpMatricesForView(rcx, view, pWorldToView, pViewToProjection,
		pWorldToProjection, pWorldToPixels);

	if (!I::gEngineClient->IsConnected() || !I::gEngineClient->IsInGame())
		return;

	sdk::math->updateViewMatrix(pWorldToProjection);
}