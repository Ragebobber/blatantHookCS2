#include "valveImpl.h"

CacheEnt::CacheEnt()
{
}

CacheEnt::~CacheEnt()
{
}

void CacheEnt::cacheCurrentEntities()
{
	if (!I::gEngineClient->IsInGame())
		return;

	if (!I::gEntitySystem)
		return;


	int highestIndex = I::gEntitySystem->GetHighestEntityIndex();

	for (int i = 1; i <= highestIndex; ++i) {
		C_BaseEntity* pEntity = I::gEntitySystem->Get(i);

		if (!pEntity) continue;

		onAddEntity(pEntity, pEntity->GetRefEHandle());
	}

}

void CacheEnt::onAddEntity(CEntityInstance* pInst, CBaseHandle handle)
{
	auto pEntity = static_cast<C_BaseEntity*>(pInst);
	if (!pEntity || handle.GetEntryIndex() > 0x3FFF) return;

	auto it = std::find_if(gCachedEntities.begin(),gCachedEntities.end(),
		[handle](const Entity_t& i) {
			return i.hEnt.GetEntryIndex() ==
				handle.GetEntryIndex();
		});

	if (it == gCachedEntities.end()) {
		Entity_t cachedEntity{};
		cachedEntity.hEnt = handle;
		cachedEntity.type = CacheEnt::getEntityType(pEntity);
		if (cachedEntity.type != EEntityType::UNKNOWN)
			gCachedEntities.emplace_back(cachedEntity);
	}
	else {
		it->hEnt = handle;
		it->type = CacheEnt::getEntityType(pEntity);
	}
}

EEntityType CacheEnt::getEntityType(C_BaseEntity* pEntity) {
	if (pEntity->IsBasePlayerController())
		return EEntityType::PLAYER_CONTROLLER;
	/*else if (pEntity->IsBasePlayerWeapon())
		return EEntityType::BASE_WEAPON;
	else if (pEntity->IsChicken())
		return EEntityType::CHICKEN;
	else if (pEntity->IsPlantedC4())
		return EEntityType::PLANTED_C4;*/

	return EEntityType::UNKNOWN;
}

void CacheEnt::onRemoveEntity(CEntityInstance* pInst, CBaseHandle handle) {
	C_BaseEntity* pEntity = static_cast<C_BaseEntity*>(pInst);

	if (!pEntity || handle.GetEntryIndex() > 0x3FFF) return;

	auto it = std::find_if(
		gCachedEntities.begin(), gCachedEntities.end(),
		[handle](const Entity_t& i) { return i.hEnt == handle; });

	if (it == gCachedEntities.end()) return;

	//it->shouldDrawEsp = false;
	it->type = EEntityType::UNKNOWN;
}