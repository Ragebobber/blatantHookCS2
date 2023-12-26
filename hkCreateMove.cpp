#include "sdk.h"

bool __fastcall hooks::hkCreateMove(CCSGOInput* input, const uint32_t  vSlot, const bool active) {
	 sdk::pointers->fpCreateMove(input, vSlot, active);
	 // func code ----------------------------------------------------------------
	 CUserCmd* cmd = input->getUserCmd(input, vSlot);

	 if (!cmd)
	 {
		 return  sdk::pointers->fpCreateMove(input, vSlot, active);
	 }


	 // func code ----------------------------------------------------------------
	 return false;
}


