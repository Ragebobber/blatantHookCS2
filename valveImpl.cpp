#include "sdk.h"

CGameResourceService*	I::gResourceService;
CGameEntitySystem*		I::gEntitySystem;
CEngineClient*			I::gEngineClient;
CSchemaSystem*			I::gSchemaSystem;
CCSGOInput*				I::gInput;
CUserCmd*				I::gUserCmd;

std::unique_ptr<CacheEnt> valve::gCacheEnt(new CacheEnt);
std::unique_ptr<CSchemaManager> valve::gSchemaManager(new CSchemaManager);