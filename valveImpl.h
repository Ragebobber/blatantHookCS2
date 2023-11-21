#pragma once
#include "sdk.h"

#include "bbox.h"
#include "basehandle.h"
#include "CSchemaSystem.h"
#include "CSchemaManager.h"
#include "centityinstance.h"
#include "c_baseentity.h"
#include "cgameentitysystem.h"
#include "cgameresourceservice.h"
#include "cengineclient.h"
#include "cacheent.h"

#include "cheat.h"
#include "hooks.h"


namespace valve {
	extern std::unique_ptr<CacheEnt>		gCacheEnt;
	extern std::unique_ptr<CSchemaManager>	gSchemaManager;
};

namespace I {
	extern CGameResourceService*	gResourceService;
	extern CGameEntitySystem*		gEntitySystem;
	extern CEngineClient*			gEngineClient;
	extern CSchemaSystem*			gSchemaSystem;
}

