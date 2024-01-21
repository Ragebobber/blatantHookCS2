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
	const auto localController = sdk::globals->localPlayerController;

	if (!pawn || !localController)
		return;

	if (!pawn->CalculateBBoxByCollision(bbox))
		return;

	if (pawn->m_pGameSceneNode()->m_bDormant())
		return;

	const bool isFriend = pawn->m_iTeamNum() == localController->getLocalTeam();
	if (isFriend && !cheat::vars->visuals.bTeamEsp)
		return;

	const auto min = bbox.m_Mins;
	const auto max = bbox.m_Maxs;

	sdk::drawer->drawBox(min, max, cheat::vars->visuals.bTeamEsp && isFriend ? IM_COL32(0, 255, 0, 255) : IM_COL32(255, 0, 0, 255));

	if (cheat::vars->visuals.bHealth) {
		const auto health = pawn->m_iHealth();
		const auto clampedHealth = (health < 100) ? health : 100;
		const ImVec2 barMin = min - ImVec2{ 5, 0 };
		const ImVec2 barMax = ImVec2{ min.x - 2, max.y };
		const float green = clampedHealth * 2.55f;
		const float greenClamped = (green <= 255.f) ? green : 255.f;
		const float red = (510 - green <= 255.f) ? 510 - green : 255.f;
		const float height = ((barMax.y - barMin.y) * clampedHealth) / 100.f;

		drawList->AddRectFilled(
				barMin - ImVec2{ 0, 1 }, barMax + ImVec2{ 0, 1 }, IM_COL32(0, 0, 0, 255));

		char heathString[10] = ""; // 4294967296 is the maximum for Uint32, so 10 characters it is
		sprintf_s(heathString, "%d HP", (long)clampedHealth);

		if (clampedHealth > 0) {
			const float yPos = barMax.y - (1.f > height ? 1.f : height);
			drawList->AddRectFilled(
				ImVec2{ barMin.x + 1, yPos }, ImVec2{ barMax.x - 1, barMax.y },
				IM_COL32(red, greenClamped, 0, 255));
			drawList->AddText(ImVec2{ barMax.x - 20.f,  barMax.y }, IM_COL32(255, 255, 255, 255), (const char*)heathString);
		}
	}


}