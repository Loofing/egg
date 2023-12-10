#include "pch.h"
#include "hooks.h"
#include "mw2\iw4mp.h"
//#include "mw2\game\notifys.h"
#include "mw2\script\methods.h"

namespace hooks
{
#ifdef __DBUG
	Detour *s_pCom_PrintMessage = nullptr;
#endif //__DBUG
#ifdef __DBUG
	//watson print
	void Com_PrintMessage(int channel, const char *msg, int error)
	{
		if(msg != nullptr)
			DbgPrint(" ] %s",msg);

		s_pCom_PrintMessage->GetOriginal<decltype(&Com_PrintMessage)>()(channel, msg, error);
	}
#endif //__DBUG
	void init()
	{
#ifdef __DBUG
		s_pCom_PrintMessage = new Detour(0x8227F370, Com_PrintMessage);
#endif //__DBUG
	}
}
