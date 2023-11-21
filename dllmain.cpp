#include "sdk.h"

BOOL APIENTRY DllMain(HMODULE hModule,
    DWORD  ul_reason_for_call,
    LPVOID lpReserved
)
{
    static std::thread th;
    switch (ul_reason_for_call)
    {
    case DLL_PROCESS_ATTACH:
        th = std::thread(&Init::startService, sdk::init.get());
        th.detach();
        break;
    case DLL_THREAD_ATTACH:
    case DLL_THREAD_DETACH:
    case DLL_PROCESS_DETACH:
        break;
    }
    return TRUE;
}
