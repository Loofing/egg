#pragma once
namespace game
{
	typedef unsigned int (__cdecl * Scr_GetSelf_t)(unsigned int thread);
	extern Scr_GetSelf_t Scr_GetSelf;

	typedef void (__cdecl * SV_GameSendServerCommand_t)( int index, int type, const char *text );
	extern SV_GameSendServerCommand_t SV_GameSendServerCommand;

	typedef void(__cdecl * Scr_AddInt_t)(int num);
	extern Scr_AddInt_t Scr_AddInt;

	typedef void(__cdecl * Scr_AddFloat_t)(float num);
	extern Scr_AddFloat_t Scr_AddFloat;

	typedef char* (__cdecl * SL_ConvertToString_t)(unsigned int stringValue);
	extern SL_ConvertToString_t SL_ConvertToString;

	typedef int(__cdecl * Scr_ExecThread_t)(int, int);
	extern Scr_ExecThread_t Scr_ExecThread;

	typedef int(__cdecl * Scr_FreeThread_t)(int);
	extern Scr_FreeThread_t Scr_FreeThread;

	typedef void(__cdecl * RemoveRefToObject_t)(unsigned int id);
	extern RemoveRefToObject_t RemoveRefToObject;

	typedef unsigned int(__cdecl * SL_GetString_t)(const char *str, unsigned int user);
	extern SL_GetString_t SL_GetString;

	typedef void(__cdecl * Scr_ClearOutParams_t)();
	extern Scr_ClearOutParams_t Scr_ClearOutParams;

	typedef void(__cdecl * Scr_NotifyNum_t)(int entnum,unsigned int classnum,unsigned int stringValue,unsigned int paramcount);
	extern Scr_NotifyNum_t Scr_NotifyNum;

	typedef int (__cdecl * Scr_GetInt_t)(unsigned int index);
	extern Scr_GetInt_t Scr_GetInt;

	typedef int (__cdecl * Cbuf_AddText_t)(int localClientNum, const char *text);
	extern Cbuf_AddText_t Cbuf_AddText;

	typedef void (__cdecl * Scr_AddString_t)(const char* text);
	extern Scr_AddString_t Scr_AddString;

	typedef unsigned int (__cdecl * FindEntityId_t)(int entnum, unsigned int classnum);
	extern FindEntityId_t FindEntityId;

    typedef char* (__cdecl * Game_VA_t)( const char*, ... );
	extern Game_VA_t Game_VA;

	typedef void(__cdecl * Scr_AddVector_t)( const float* pos);
	extern Scr_AddVector_t Scr_AddVector;

	typedef void(__cdecl * Scr_RegisterFunction_t)( void* func, const char *name);
	extern Scr_RegisterFunction_t Scr_RegisterFunction;

	typedef void(__cdecl * Scr_NotifyLevel_t)( unsigned int stringValue, unsigned int paramcount );
	extern Scr_NotifyLevel_t Scr_NotifyLevel;

	typedef void(__cdecl * Scr_Notify_t)(gentity_s *ent, unsigned int stringValue, unsigned int paramcount);
	extern Scr_Notify_t Scr_Notify;

	typedef void(__cdecl * Scr_AddArray_t)();
	extern Scr_AddArray_t Scr_AddArray;

	typedef void(__cdecl * Scr_MakeArray_t)();
	extern Scr_MakeArray_t Scr_MakeArray;

	typedef void(__cdecl * Scr_AddEntity_t)(gentity_s* ent);
	extern Scr_AddEntity_t Scr_AddEntity;

	typedef void(__cdecl * Scr_AddArrayStringIndexed_t)(unsigned int stringValue);
	extern Scr_AddArrayStringIndexed_t Scr_AddArrayStringIndexed;

	typedef gentity_s* (__cdecl * Scr_GetEntity_t)(unsigned int index);
	extern Scr_GetEntity_t Scr_GetEntity;

	typedef float(__cdecl * Scr_GetFloat_t)(unsigned int index);
	extern Scr_GetFloat_t Scr_GetFloat;

	typedef char* (__cdecl * Scr_GetString_t)(unsigned int index);
	extern Scr_GetString_t Scr_GetString;

	typedef void(__cdecl * Scr_GetVector_t)(unsigned int index,float *vectorValue);
	extern Scr_GetVector_t Scr_GetVector;

	typedef int(__cdecl * BG_GetEquippedWeaponIndex_t)(playerState_s* ps,unsigned int weaponIndex);
	extern BG_GetEquippedWeaponIndex_t BG_GetEquippedWeaponIndex;

	typedef int(__cdecl * Scr_GetNumParam_t)();
	extern Scr_GetNumParam_t Scr_GetNumParam;

	typedef int(__cdecl * Scr_GetType_t)(unsigned int index);
	extern Scr_GetType_t Scr_GetType;

	typedef void(__cdecl* ChangeViewmodelDobj_t)(int localClientNum, playerState_s *ps, unsigned int weaponNum, unsigned int newHands, bool updateClientInfo, bool recreateAnimTrees);
	extern ChangeViewmodelDobj_t ChangeViewmodelDobj;

	typedef XAssetHeader (__cdecl * DB_FindXAssetHeader_t)(XAssetType type, const char* name);
	extern DB_FindXAssetHeader_t DB_FindXAssetHeader;

	typedef void(*DB_EnumXAssets_Internal_t)(XAssetType type, void(*)(XAssetHeader, void*), void* userdata, bool overrides);
	extern DB_EnumXAssets_Internal_t DB_EnumXAssets_Internal;

	typedef const char* (__cdecl * Com_SurfaceTypeToName_t)( int iTypeIndex );
	extern Com_SurfaceTypeToName_t Com_SurfaceTypeToName;

	void iPrintLn(int index, const std::string &text);
	void setGamertag(int index,const char* input);
	void setClantag(int index,const char* input);
	gentity_s *GetEntity(int entNum);
	extern clientState_s *(*GetClientState)(int entNum);
	DWORD WINAPI XShowKeyboard(LPVOID sProp);
}

