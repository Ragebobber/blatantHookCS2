#include "cheat.h"

void Visuals::start(ImDrawList* drawList)
{
	if (!cheat::vars->visuals.bEnable)
		return;

	if (!I::gEngineClient->IsConnected() || !I::gEngineClient->IsInGame())
		return;

	this->drawList = drawList;

	for (const auto& it : valve::gCacheEnt->getEntities()) {
		const auto pEntity = it.hEnt.Get();

		if (!pEntity)
			continue;
	
		switch (it.type)
		{
		case EEntityType::PLAYER_CONTROLLER: {
			auto controller = reinterpret_cast<CCSPlayerController*>(pEntity);
			if (!controller)
				break;

			if(!controller->m_bPawnIsAlive())
				break;

			drawPlayerEsp(controller);
			break;
		}
		default:
			break;
		}
	}
}


void Visuals::drawPlayerEsp(CCSPlayerController* pPlayerController) {
	if (!cheat::vars->visuals.bEsp)
		return;

	const auto pawn = reinterpret_cast<C_CSPlayerPawn*>(pPlayerController->m_hPawn().Get());
	if (!pawn)
		return;

	if (!pawn->CalculateBBoxByCollision(bbox))
		return;

	if (pawn->m_pGameSceneNode()->m_bDormant())
		return;


	const auto min = bbox.m_Mins;
	const auto max = bbox.m_Maxs;

	drawList->AddRect(
		min - ImVec2{ 1.f, 1.f }, max + ImVec2{ 1.f, 1.f }, IM_COL32(0, 0, 0, 255));
	drawList->AddRect(
		min + ImVec2{ 1.f, 1.f }, max - ImVec2{ 1.f, 1.f }, IM_COL32(0, 0, 0, 255));
	drawList->AddRect(min, max, IM_COL32(255, 0, 0, 255));
}