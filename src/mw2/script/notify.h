#pragma once
namespace script
{
	using namespace game;

	class notify
	{
		public:
			static void init();
			static void send(std::string notifyString,int paramcount);
			static void send(game::gentity_s* entity,std::string notifyString,int paramcount);
			static void send(int entity_num,std::string notifyString,int paramcount);
	};
}