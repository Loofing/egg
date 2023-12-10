#include "pch.h"
#include "iw4mp.h"
#include "mw2/hooks.h"
#include "mw2/script/methods.h"
#include "mw2/script/functions.h"
#include "mw2/script/notify.h"
iw4mp::iw4mp()
{
    Sleep(200);
	script::function::init();
	script::method::init();
	script::notify::init();
	hooks::init();

	/*not fully tested*/

	//remove dvar limits
	Memory::Write<short>(0x8230D5B8, 0x4800);
	//remove dvar read-only protection
	Memory::Write<short>(0x8230D664, 0x4800);
	//remove dvar cheat protection
	Memory::Write<short>(0x8230D68C, 0x4800);
}

iw4mp::~iw4mp()
{
}


