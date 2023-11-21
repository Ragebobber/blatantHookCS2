#pragma once


class Drawer
{
public:
	static void  rect(float x, float y, float w, float h, ImColor color) {
		ImGui::GetBackgroundDrawList()->AddRect(ImVec2(x, y), ImVec2(x + w, y + h), color);
	}

private:

};

