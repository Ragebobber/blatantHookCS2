#include "sdk.h"
#include "CS2LocalPlayerController.h"

CS2LocalPlayerController::CS2LocalPlayerController()
{
	
}

CS2LocalPlayerController::~CS2LocalPlayerController()
{
}

C_CSPlayerPawn* CS2LocalPlayerController::getLocalPawn()
{
	CCSPlayerController* playerController = reinterpret_cast<CCSPlayerController*>(this);
	if (playerController == nullptr)
		return nullptr;

	C_CSPlayerPawn* localPawn = static_cast<C_CSPlayerPawn*>(playerController->m_hPawn().Get());
	if (localPawn != nullptr){
		return localPawn;
	}
	
	return nullptr;
}

int CS2LocalPlayerController::getLocalHealth()
{
	auto pawn = getLocalPawn();
	return pawn->m_iHealth();
}

int CS2LocalPlayerController::getLocalTeam()
{
	auto pawn = getLocalPawn();
	return pawn->m_iTeamNum();
}

