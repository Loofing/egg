#include "pch.h"
#include "methods.h"

namespace script
{
	Detour *s_pPlayer_GetMethod = nullptr;
    std::unordered_map<std::string, BuiltinMethodDef> method::registered_methods;

    void PlayerCmd_SetWeaponFlag(scr_entref_t e) 
    {
        if (Scr_GetNumParam() != 1 || Scr_GetType(0) != VAR_INTEGER)
            return;

        auto intValue = Scr_GetInt(0);
        auto entity = game::GetEntity(e);
        entity->client->ps.weapCommon.weapFlags = intValue;
    }
    void PlayerCmd_SetGamertag(scr_entref_t e) 
    {
        if (Scr_GetNumParam() != 1 || Scr_GetType(0) != VAR_STRING)
            return;

        auto stringValue = Scr_GetString(0);
        setGamertag(e,stringValue);
    }
    void PlayerCmd_SetClantag(scr_entref_t e) 
    {
        if (Scr_GetNumParam() != 1 || Scr_GetType(0) != VAR_STRING)
            return;

        auto stringValue = Scr_GetString(0);
        setClantag(e,stringValue);
    }
    void PlayerCmd_XShowKeyboardUI(scr_entref_t e)
    {
        if (Scr_GetNumParam() != 3 || Scr_GetType(0) != VAR_STRING)
             return;

         if (Scr_GetType(0) != VAR_STRING || Scr_GetType(1) != VAR_STRING)
             return;

         if (Scr_GetType(2) != VAR_INTEGER)
             return;

         XKeyboardProperties* p = new XKeyboardProperties();
         p->noti = Scr_GetString(0);
         p->desc = Scr_GetString(1);
         p->lenght = Scr_GetInt(2);
         p->entity = e;

         CreateThread(NULL, NULL, XShowKeyboard, p, NULL, NULL);

    }

    void method::add(const char* name, void(*f)(scr_entref_t))
    {
        if (find(name) != nullptr)
            return;

        registered_methods[name];

        auto itr = registered_methods.find(name);
        itr->second.actionString = name;
        itr->second.type = 0; 
        itr->second.actionFunc = f;	
    }
    BuiltinMethodDef* method::find(const std::string& name)
    {
        auto itr = registered_methods.find(name);
        if (itr != registered_methods.end())
            return &itr->second;

        return nullptr;
	}
    void(*Player_GetMethod(const char** pName))(scr_entref_t)
    {
        if (pName != nullptr)
        {
            auto method = script::method::find(*pName);

            if (method != nullptr)
            {
                *pName = method->actionString;
                game::Scr_RegisterFunction(method->actionFunc, *pName);
                return method->actionFunc;
            }
        }
        return s_pPlayer_GetMethod->GetOriginal<decltype(&Player_GetMethod)>()(pName);
    }
    void method::init()
    {
	   s_pPlayer_GetMethod = new Detour(0x82224B30, Player_GetMethod);
       add("setweaponflag", PlayerCmd_SetWeaponFlag);
       add("setgamertag", PlayerCmd_SetGamertag);
       add("setclantag", PlayerCmd_SetClantag);
       add("xshowkeyboardui", PlayerCmd_XShowKeyboardUI);
    }
}