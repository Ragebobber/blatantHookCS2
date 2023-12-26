#pragma once
//#include "sdk.h"



namespace valve {
	extern std::unique_ptr<CacheEnt>		gCacheEnt;
	extern std::unique_ptr<CSchemaManager>	gSchemaManager;
};

namespace I {
	extern CGameResourceService*	gResourceService;
	extern CGameEntitySystem*		gEntitySystem;
	extern CEngineClient*			gEngineClient;
	extern CSchemaSystem*			gSchemaSystem;
	extern CCSGOInput*				gInput;
	extern CUserCmd*				gUserCmd;
}

