#include "sdk.h"

CGameResourceService*	I::gResourceService;
CGameEntitySystem*		I::gEntitySystem;
CEngineClient*			I::gEngineClient;
CSchemaSystem* I::gSchemaSystem;

std::unique_ptr<CacheEnt> valve::gCacheEnt(new CacheEnt);
std::unique_ptr<CSchemaManager> valve::gSchemaManager(new CSchemaManager);