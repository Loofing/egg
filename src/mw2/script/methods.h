#pragma once
namespace script
{
	using namespace game;

	class method
	{
		public:
			static void add(const char* name, void(*f)(scr_entref_t));
			static BuiltinMethodDef* find(const std::string& name);
			static void init();

		private:
			static std::unordered_map<std::string, BuiltinMethodDef> registered_methods;
	};
}