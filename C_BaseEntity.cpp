#include "sdk.h"

/*
26.12.2023 change 144->145
*/
bool C_BaseEntity::IsBasePlayerController()
{
	using OriginalFn = bool(__thiscall*)(void*);
	return sdk::helpers->GetVFunc<OriginalFn>(this, 145)(this);
}

bool C_BaseEntity::CalculateBBoxByCollision(bbox_t& out)
{
	CGameSceneNode* node = m_pGameSceneNode();
	if (!node) return false;

	CCollisionProperty* collision = m_pCollision();
	if (!collision) return false;

	const Vector mins = collision->m_vecMins(), maxs = collision->m_vecMaxs();

	out.Invalidate();

	for (int i = 0; i < 8; ++i) {
		const Vector worldPoint{ i & 1 ? maxs.x : mins.x, i & 2 ? maxs.y : mins.y, i & 4 ? maxs.z : mins.z };

		if (!sdk::math->WorldToScreen(worldPoint.Transform(node->m_nodeToWorld().ToMatrix()), out.m_Vertices[i])) return false;

		out.m_Mins = ImMin(out.m_Mins, out.m_Vertices[i]);
		out.m_Maxs = ImMax(out.m_Maxs, out.m_Vertices[i]);
	}

	return true;
}

bool CCSPlayerController::isValid()
{
	bool ret = false;

	if(m_bPawnIsAlive())
		ret =  true;

	if(m_pGameSceneNode()->m_bDormant())
		ret = false;

	return ret;
}
