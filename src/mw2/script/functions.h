#pragma once

namespace script
{
	class function
	{
	public:
		static void add(const char* name, void(*f)());
		static game::BuiltinFunctionDef* find(const std::string& name);
		static void init();

	private:
		static std::unordered_map<std::string, game::BuiltinFunctionDef> registered_functions;
	};
}