#include "pch.h"
#include "notify.h"

namespace script
{
	Detour *s_pScr_Notify = nullptr;

	void notify::send(std::string notifyString,int paramcount)  
	{
		Scr_NotifyLevel(SL_GetString(notifyString.data(),0),paramcount);
	}
	void notify::send(gentity_s* entity,std::string notifyString,int paramcount) 
	{
		game::Scr_Notify(entity, SL_GetString(notifyString.data(), 0), paramcount);
	}

	void notify::send(int entity_num,std::string notifyString,int paramcount) 
	{
		Scr_NotifyNum(entity_num, 0, SL_GetString(notifyString.data(), 0), paramcount);
	}
	void Scr_Notify(gentity_s *ent, uint16_t stringValue, uint32_t paramcount) 
	{
		s_pScr_Notify->GetOriginal<decltype(&Scr_Notify)>()(ent, stringValue, paramcount);

		/*auto entNum = ent->state.number;
		const char *eventName = SL_ConvertToString(stringValue);
		*/
	}
    void notify::init() 
	{
		s_pScr_Notify = new Detour(0x82259CC0,Scr_Notify);
    }
}