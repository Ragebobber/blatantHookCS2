#include "cheat.h"

void Config::setupValue(int& value, int def, std::string category, std::string name)
{
	value = def;
	ints.push_back(new ConfigValue<int>(category, name, &value));
}

void Config::setupValue(bool& value, bool def, std::string category, std::string name)
{
	value = def;
	bools.push_back(new ConfigValue<bool>(category, name, &value));
}

void Config::setupValue(float& value, float def, std::string category, std::string name)
{
	value = def;
	floats.push_back(new ConfigValue<float>(category, name, &value));
}

Config::Config()
{
	setUp();
}

Config::~Config()
{
}

void Config::save()
{
	static TCHAR path[MAX_PATH];
	std::string folder, file;
	if (SUCCEEDED(SHGetFolderPath(NULL, CSIDL_APPDATA, NULL, 0, path)))
	{
		folder = std::string(path) + ("\\BlatantHack\\");

		char bufcfg[350];

		switch (cheat::vars->menu.currentConfig)
		{
		case 0:
			sprintf_s(bufcfg, "\\BlatantHack\\Legit1.bh");
			break;
		case 1:
			sprintf_s(bufcfg, "\\BlatantHack\\Legit2.bh");
			break;
		case 2:
			sprintf_s(bufcfg, "\\BlatantHack\\Config1.bh");
			break;
		default:
			sprintf_s(bufcfg, "\\BlatantHack\\Error.bh");
			break;
		}


		file = std::string(path) + bufcfg;
	}

	CreateDirectory(folder.c_str(), NULL);

	for (auto value : ints)
		WritePrivateProfileString(value->category.c_str(), value->name.c_str(), std::to_string(*value->value).c_str(), file.c_str());

	for (auto value : floats)
		WritePrivateProfileString(value->category.c_str(), value->name.c_str(), std::to_string(*value->value).c_str(), file.c_str());

	for (auto value : bools)
		WritePrivateProfileString(value->category.c_str(), value->name.c_str(), *value->value ? "true" : "false", file.c_str());
}

void Config::load()
{
	static TCHAR path[MAX_PATH];
	std::string folder, file;

	if (SUCCEEDED(SHGetFolderPath(NULL, 0x001a, NULL, 0, path)))
	{
		folder = std::string(path) + ("\\BlatantHack\\");

		char bufcfg[350];

		switch (cheat::vars->menu.currentConfig)
		{
		case 0:
			sprintf_s(bufcfg, "\\BlatantHack\\Legit1.bh");
			break;
		case 1:
			sprintf_s(bufcfg, "\\BlatantHack\\Legit2.bh");
			break;
		case 2:
			sprintf_s(bufcfg, "\\BlatantHack\\Config1.bh");
			break;
		default:
			sprintf_s(bufcfg, "\\BlatantHack\\Error.bh");
			break;
		}


		file = std::string(path) + bufcfg;
	}

	CreateDirectory(folder.c_str(), NULL);

	char value_l[32] = { '\0' };

	for (auto value : ints)
	{
		GetPrivateProfileString(value->category.c_str(), value->name.c_str(), "", value_l, 32, file.c_str());
		*value->value = atoi(value_l);
	}

	for (auto value : floats)
	{
		GetPrivateProfileString(value->category.c_str(), value->name.c_str(), "", value_l, 32, file.c_str());
		*value->value = (float)atof(value_l);
	}

	for (auto value : bools)
	{
		GetPrivateProfileString(value->category.c_str(), value->name.c_str(), "", value_l, 32, file.c_str());
		*value->value = !strcmp(value_l, "true");
	}
}

void Config::setUp()
{
	//visuals
	setupValue(cheat::vars->visuals.bEnable, false, ("Visuals"), ("Enabled"));
	setupValue(cheat::vars->visuals.bEsp, false, ("Visuals"), ("bEsp"));
	setupValue(cheat::vars->visuals.bTeamEsp, false, ("Visuals"), ("bTeamEsp"));
	
}
