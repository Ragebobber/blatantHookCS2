#pragma once


class Drawer
{
public:
	static void drawBox(const ImVec2& p_min, const ImVec2& p_max, ImU32 col) {
		ImGui::GetBackgroundDrawList()->AddRect(
			p_min - ImVec2{ 1.f, 1.f }, p_max + ImVec2{ 1.f, 1.f }, IM_COL32(0, 0, 0, 255));
		ImGui::GetBackgroundDrawList()->AddRect(
			p_min + ImVec2{ 1.f, 1.f }, p_max - ImVec2{ 1.f, 1.f }, IM_COL32(0, 0, 0, 255));
		ImGui::GetBackgroundDrawList()->AddRect(p_min, p_max, col);
	}

private:

};

