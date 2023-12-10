#include "pch.h"
#include "functions.h"

namespace script
{
	Detour *s_pCommon_GetFunction = nullptr;
    std::unordered_map<std::string, game::BuiltinFunctionDef> function::registered_functions;

    void function::add(const char* name, void(*f)())
    {
        if (find(name) != nullptr)
            return;

        registered_functions[name];
        auto itr = registered_functions.find(name);

        itr->second.actionString = name;
        itr->second.type = 0;
        itr->second.actionFunc = f;
    }

    game::BuiltinFunctionDef* function::find(const std::string& name)
    {
        auto itr = registered_functions.find(name);
        if (itr != registered_functions.end())
            return &itr->second;

        return nullptr;
    }

    void(*Common_GetFunction(const char** pName, int* type))()
    {
		if (pName != nullptr)
		{
			auto func = script::function::find(*pName);

			if (func != nullptr)
			{
				*pName = func->actionString;
				*type = func->type;
                game::Scr_RegisterFunction(func->actionFunc, *pName);
				return func->actionFunc;
			}
		}
		return s_pCommon_GetFunction->GetOriginal<decltype(&Common_GetFunction)>()(pName,type);
    }

    void function::init()
    {
	   s_pCommon_GetFunction = new Detour(0x8224D450, Common_GetFunction);
    }
}