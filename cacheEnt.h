#pragma once

enum EEntityType {
    UNKNOWN = -1,
    PLAYER_CONTROLLER,
    BASE_WEAPON,
    CHICKEN,
    PLANTED_C4,
};

struct Entity_t
{
    CBaseHandle hEnt;
    EEntityType type;
   // bool shouldDrawEsp;
    //bbox_t bbox;
};

class CacheEnt {
public:
    CacheEnt();
    ~CacheEnt();

	void cacheCurrentEntities();
    void onRemoveEntity(CEntityInstance* pInst, CBaseHandle handle);
	void onAddEntity(CEntityInstance* pInst, CBaseHandle handle);

    EEntityType getEntityType(C_BaseEntity* pEntity);

     auto& getEntities() { return gCachedEntities; }

private:
    std::vector<Entity_t> gCachedEntities;
};