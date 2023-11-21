#pragma once

class CCollisionProperty {
public:
	SCHEMA(Vector, m_vecMins, "CCollisionProperty", "m_vecMins");
	SCHEMA(Vector, m_vecMaxs, "CCollisionProperty", "m_vecMaxs");
};

class CGameSceneNode {
public:
	SCHEMA(Vector, m_vecAbsOrigin, "CGameSceneNode", "m_vecAbsOrigin");
	SCHEMA(CTransform, m_nodeToWorld, "CGameSceneNode", "m_nodeToWorld");
	SCHEMA(bool, m_bDormant, "CGameSceneNode", "m_bDormant");
};

class C_BaseEntity : public CEntityInstance {
public:
	bool IsBasePlayerController();
	bool CalculateBBoxByCollision(bbox_t& out);

	SCHEMA(CGameSceneNode*, m_pGameSceneNode, "C_BaseEntity", "m_pGameSceneNode");
	SCHEMA(CBaseHandle, m_hOwnerEntity, "C_BaseEntity", "m_hOwnerEntity");
	SCHEMA(CCollisionProperty*, m_pCollision, "C_BaseEntity", "m_pCollision");
	SCHEMA(uint8_t, m_iTeamNum, "C_BaseEntity", "m_iTeamNum");
	SCHEMA(int32_t, m_iHealth, "C_BaseEntity", "m_iHealth");
};

class C_BaseModelEntity : public C_BaseEntity {
public:
};

class C_BasePlayerPawn : public C_BaseModelEntity {
public:
};

class C_CSPlayerPawnBase : public C_BasePlayerPawn {
public:

};

class C_CSPlayerPawn :public C_CSPlayerPawnBase {
public:
};

class CBasePlayerController :public C_BaseModelEntity
{
public:
	SCHEMA(CBaseHandle, m_hPawn, "CBasePlayerController", "m_hPawn");
	SCHEMA(bool, m_bIsLocalPlayerController, "CBasePlayerController", "m_bIsLocalPlayerController ");
};




class CCSPlayerController : public CBasePlayerController {
public:
	bool isValid();
public:
	SCHEMA(bool, m_bPawnIsAlive, "CCSPlayerController", "m_bPawnIsAlive");
	SCHEMA(const char*, m_sSanitizedPlayerName, "CCSPlayerController", "m_sSanitizedPlayerName");

};

