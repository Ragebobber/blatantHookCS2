#include "sdk.h"

CUserCmd* CCSGOInput::getUserCmd(CCSGOInput* input, uint32_t  vSlot)
{
    /*
	PSEUDO from 48 63 DA 4C 69 F3 ? ? ? ? 
      v6 = 0x5F78i64 * (int)input;
      v158 = v6;
      v7 = *(_DWORD *)((char *)this + v6 + 0x6034);
      v154 = v7;
      v8 = (char *)this + 0xA0 * (v7 % 0x96) + v6 + 0x250;
      *((_DWORD *)v8 + 4) |= 1u;
    */
    int64_t v6 = 0x5F78 * vSlot;
    int64_t v7 = *reinterpret_cast<std::int64_t*>(reinterpret_cast<std::uintptr_t>(input) + v6 + 0x6034);
    int64_t v8 = (0xA0 * vSlot + v7 % 0x96) + reinterpret_cast<std::uintptr_t>(input);
    uint64_t splitScreen = v8 + 4;

    return  reinterpret_cast<CUserCmd*>(splitScreen);
}
