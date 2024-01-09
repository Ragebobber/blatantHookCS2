#include "cheat.h"

void Menu::draw()
{
	if (!cheat::vars->menu.open)
		return;

	ImGui::SetNextWindowSize({ 1000,600 });
	ImGui::Begin("Blatant Hook", nullptr, ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoScrollbar | ImGuiWindowFlags_NoCollapse | ImGuiWindowFlags_NoSavedSettings);
	auto mainWindowsSize = ImGui::GetContentRegionAvail();
	ImGui::BeginChild("#tabsChild", { mainWindowsSize.x - 800,mainWindowsSize.y }, true);
	auto mainTabsSize = ImGui::GetContentRegionAvail();

	if (ImGui::Button("Aimbot", { mainTabsSize.x,70.f })) {
		tabs = 0;
	}
	if (ImGui::Button("Visuals", { mainTabsSize.x,70.f })) {
		tabs = 1;
	}
	ImGui::EndChild();
	ImGui::SameLine();
	ImGui::BeginChild("#funcChils", { 0.f,0.f }, true);

	switch (tabs)
	{
	case 0:
		drawAimbot();
		break;
	case 1:
		drawVisuals();
		break;
	default:
		break;
	}

	ImGui::EndChild();
	ImGui::End();
}

void Menu::drawAimbot()
{
}

void Menu::drawVisuals()
{
	ImGui::Checkbox("Enable visuals", &cheat::vars->visuals.bEnable);
	ImGui::Separator();
	ImGui::Checkbox("Enable ESP", &cheat::vars->visuals.bEsp);
	ImGui::Checkbox("Team ESP", &cheat::vars->visuals.bTeamEsp);
}
