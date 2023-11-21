#pragma once

class Visuals {
public:
	void start(ImDrawList* drawList);
	
private:
	void drawPlayerEsp(CCSPlayerController* player);
	bbox_t bbox;
	ImDrawList* drawList;
};