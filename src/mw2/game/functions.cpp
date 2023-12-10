#include "pch.h"
#include "functions.h"

namespace game
{
	Game_VA_t Game_VA = (Game_VA_t)0x823160A8;
	RemoveRefToObject_t RemoveRefToObject = RemoveRefToObject_t(0x822AA208);
	FindEntityId_t FindEntityId = FindEntityId_t(0x822A50C0);
	Cbuf_AddText_t Cbuf_AddText = Cbuf_AddText_t(0x82275C60);
	SV_GameSendServerCommand_t SV_GameSendServerCommand = (SV_GameSendServerCommand_t)0x822BDF00;

	Scr_GetSelf_t Scr_GetSelf = (Scr_GetSelf_t)0x822A43C8;
	Scr_AddInt_t Scr_AddInt = (Scr_AddInt_t)0x822ADD18;
	Scr_AddFloat_t Scr_AddFloat = (Scr_AddFloat_t)0x822ADD98;
	Scr_AddString_t Scr_AddString = Scr_AddString_t(0x822ADFF0);
	Scr_AddVector_t Scr_AddVector = Scr_AddVector_t(0x822AE198);
	Scr_ExecThread_t Scr_ExecThread = (Scr_ExecThread_t)0x822B29A0;
	Scr_FreeThread_t Scr_FreeThread = Scr_FreeThread_t(0x822AD850);
	Scr_ClearOutParams_t Scr_ClearOutParams = Scr_ClearOutParams_t(0x822ABD08);
	Scr_NotifyNum_t Scr_NotifyNum = Scr_NotifyNum_t(0x822AD550);
	Scr_GetInt_t Scr_GetInt = Scr_GetInt_t(0x822B2D70);
	Scr_NotifyLevel_t Scr_NotifyLevel = Scr_NotifyLevel_t(0x822AD598);
	Scr_Notify_t Scr_Notify = Scr_Notify_t(0x82259CC0);
	Scr_AddArray_t Scr_AddArray = Scr_AddArray_t(0x822AE328);
	Scr_MakeArray_t Scr_MakeArray = Scr_MakeArray_t(0x822AE2B0);
	Scr_AddEntity_t Scr_AddEntity = Scr_AddEntity_t(0x82259A60);
	Scr_AddArrayStringIndexed_t Scr_AddArrayStringIndexed = Scr_AddArrayStringIndexed_t(0x822AE3A0);
	Scr_GetEntity_t Scr_GetEntity = Scr_GetEntity_t(0x82259AF8);
	Scr_GetFloat_t Scr_GetFloat = Scr_GetFloat_t(0x822B30D0);
	Scr_GetString_t Scr_GetString = Scr_GetString_t(0x822B33A8);
	Scr_GetVector_t Scr_GetVector = Scr_GetVector_t(0x822B35B8);
	Scr_RegisterFunction_t Scr_RegisterFunction = (Scr_RegisterFunction_t)0x822963C0;
	Scr_GetNumParam_t Scr_GetNumParam = Scr_GetNumParam_t(0x822ADC88);
	Scr_GetType_t Scr_GetType = Scr_GetType_t(0x822B39F0);

	BG_GetEquippedWeaponIndex_t BG_GetEquippedWeaponIndex = BG_GetEquippedWeaponIndex_t(0x820FE530);

	SL_GetString_t SL_GetString = SL_GetString_t(0x822A2E18);
	SL_ConvertToString_t SL_ConvertToString = (SL_ConvertToString_t)0x822A2418;

	ChangeViewmodelDobj_t ChangeViewmodelDobj = (ChangeViewmodelDobj_t)0x82164EC8;
	DB_FindXAssetHeader_t DB_FindXAssetHeader = (DB_FindXAssetHeader_t)0x821E25B0;
	DB_EnumXAssets_Internal_t DB_EnumXAssets_Internal = (DB_EnumXAssets_Internal_t)0x821DD910;
	Com_SurfaceTypeToName_t Com_SurfaceTypeToName = (Com_SurfaceTypeToName_t)0x82319CD0;
	
	clientState_s *(*GetClientState)(int entNum) = reinterpret_cast<clientState_s *(*)(int)>(0x82231F40);

	void iPrintLn(int index, const std::string &text)
	{
        SV_GameSendServerCommand(index, 0, Formatter::Format("f \"%s\"", text.c_str()).c_str());
    }
	gentity_s *GetEntity(int entNum) 
	{ 
		return reinterpret_cast<gentity_s *>(0x82E2A580 + (sizeof(gentity_s) * entNum)); 
	}
	DWORD WINAPI XShowKeyboard(LPVOID sProp)
	{
		XKeyboardProperties *props = (XKeyboardProperties*)sProp;
		delete sProp;

		wchar_t wResultText[512];
		char buffer[512];

		wchar_t wDesc [20];
		mbstowcs(wDesc, props->desc, strlen(props->desc)+1);

		XOVERLAPPED Overlapped;
		ZeroMemory(&Overlapped, sizeof(Overlapped));
		XShowKeyboardUI(0, VKBD_DEFAULT, L"", L"Keyboard", wDesc, wResultText, props->lenght, &Overlapped);

		while (!XHasOverlappedIoCompleted(&Overlapped))
			Sleep(100);

		uint32_t overlappedResult = XGetOverlappedResult(&Overlapped, nullptr, TRUE);

		if (overlappedResult == ERROR_SUCCESS) 
		{ 
			wcstombs(buffer, wResultText, props->lenght);
			Scr_AddString(buffer);
			Scr_AddString(props->noti);
			script::notify::send(props->entity, "keyboard_result", 2);
		}
		return 0;
	}
	void setGamertag(int index,const char* input)
    {
		auto ent = GetClientState(index);
		strcpy(ent->name, input);
    }
	void setClantag(int index,const char* input)
    {
		auto ent = GetClientState(index);
		strcpy(ent->clanAbbrev, input);

		if(!strlen(input))
		{
			Cbuf_AddText(index,"reset clanname");
			return;
		}
		std::string dvarString = Formatter::Format("clanname %s", input);
		Cbuf_AddText(index,dvarString.c_str());
    }
}

