#include "cheat.h"

void Menu::draw()
{
	if (!cheat::vars->menu.open)
		return;

	ImGui::SetNextWindowSize({ 1000,600 });
	ImGui::Begin("Blatant Hook", nullptr, ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoScrollbar | ImGuiWindowFlags_NoCollapse | ImGuiWindowFlags_NoSavedSettings);
	auto mainWindowsSize = ImGui::GetContentRegionAvail();
	ImGui::BeginChild("#tabsChild", { mainWindowsSize.x - 800.f,mainWindowsSize.y }, true, ImGuiWindowFlags_NoScrollbar);
	auto mainTabsSize = ImGui::GetContentRegionAvail();

	if (ImGui::Button("Aimbot", { mainTabsSize.x,70.f })) {
		tabs = 0;
	}
	if (ImGui::Button("Visuals", { mainTabsSize.x,70.f })) {
		tabs = 1;
	}
	
	//Config bottom
	ImGui::SetCursorPosY(mainTabsSize.y - ImGui::GetTextLineHeight() - 30.f);
	ImGui::Separator();
	ImGui::SetNextItemWidth(mainTabsSize.x);
	ImGui::Combo("##CFG", &cheat::vars->menu.currentConfig, "Off\0\rMM\0\Legit1\0\rLegit2\0\rConfig1",-1);
	if (ImGui::Button(("Load"), { mainTabsSize.x / 2.f - 2.f,20.f }) ){
		cheat::config->load();
	}
	ImGui::SameLine();
	if (ImGui::Button(("Save"), { mainTabsSize.x / 2.f - 2.f,20.f })) {
		cheat::config->save();
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
