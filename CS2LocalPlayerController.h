#pragma once


class CS2LocalPlayerController : public CCSPlayerController {
public:
	CS2LocalPlayerController();
	~CS2LocalPlayerController();

	C_CSPlayerPawn* getLocalPawn();
	int getLocalHealth();
	int getLocalTeam();
public:
};