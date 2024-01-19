#pragma once

class Menu {
public:
	void draw();
private:
	int tabs = 0;
	std::string path = "\\";
private:
	void drawAimbot();
	void drawVisuals();
};