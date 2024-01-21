#pragma once

struct Vars
{
	struct
	{
		bool open = false;
		int currentConfig = 0;
	} menu;

	struct {
		bool bEnable = false;
		bool bEsp = false;
		bool bTeamEsp = false;
		bool bHealth = false;
	} visuals;
};