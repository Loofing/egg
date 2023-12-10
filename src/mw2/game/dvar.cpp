#include "pch.h"
#include "dvar.h"

namespace dvar
{
	Dvar_Reregister_t Dvar_Reregister = Dvar_Reregister_t(0x8230E988);
	Dvar_RegisterNew_t Dvar_RegisterNew = Dvar_RegisterNew_t(0x8230EAA0);
	Dvar_RegisterVariant_t Dvar_RegisterVariant = Dvar_RegisterVariant_t(0x8230ED58);
	Dvar_RegisterBool_t Dvar_RegisterBool = Dvar_RegisterBool_t(0x8230EE00);
	Dvar_RegisterInt_t Dvar_RegisterInt = Dvar_RegisterInt_t(0x8230EE48);
	Dvar_RegisterFloat_t Dvar_RegisterFloat = Dvar_RegisterFloat_t(0x8230EE90);
	Dvar_RegisterVec2_t Dvar_RegisterVec2 = Dvar_RegisterVec2_t(0x8230EED8);
	Dvar_RegisterVec3_t Dvar_RegisterVec3 = Dvar_RegisterVec3_t(0x8230EF20);
	Dvar_RegisterVec4_t Dvar_RegisterVec4 = Dvar_RegisterVec4_t(0x8230EFC0);
	Dvar_RegisterString_t Dvar_RegisterString = Dvar_RegisterString_t(0x8230F010);
	Dvar_RegisterEnum_t Dvar_RegisterEnum = Dvar_RegisterEnum_t(0x8230F058);
	Dvar_RegisterColor_t Dvar_RegisterColor = Dvar_RegisterColor_t(0x8230F0C0);
	Dvar_RegisterDevTweak_t Dvar_RegisterDevTweak = (Dvar_RegisterDevTweak_t)0x822A0228;
	
	Dvar_GetBool_t Dvar_GetBool = Dvar_GetBool_t(0x8230DBD8);
	Dvar_GetInt_t Dvar_GetInt = Dvar_GetInt_t(0x8230DC40);
	Dvar_GetFloat_t Dvar_GetFloat = Dvar_GetFloat_t(0x8230DCA8);
	Dvar_GetVec3_t Dvar_GetVec3 = Dvar_GetVec3_t(0x8230DD18);
	Dvar_GetString_t Dvar_GetString = Dvar_GetString_t(0x8230DD98);
	Dvar_GetVariantString_t Dvar_GetVariantString = Dvar_GetVariantString_t(0x8230DE18);

	Dvar_SetBoolFromSource_t Dvar_SetBoolFromSource = (Dvar_SetBoolFromSource_t)0x8230F1F8;
	Dvar_SetIntFromSource_t Dvar_SetIntFromSource = (Dvar_SetIntFromSource_t)0x8230F260;
	Dvar_SetFloatFromSource_t Dvar_SetFloatFromSource = (Dvar_SetFloatFromSource_t)0x8230F2E8;
	Dvar_SetVec2FromSource_t Dvar_SetVec2FromSource = (Dvar_SetVec2FromSource_t)0x8230F368;
	Dvar_SetVec3FromSource_t Dvar_SetVec3FromSource = (Dvar_SetVec3FromSource_t)0x8230F3F8;
	Dvar_SetVec4FromSource_t Dvar_SetVec4FromSource = (Dvar_SetVec4FromSource_t)0x8230F498;
	Dvar_SetStringFromSource_t Dvar_SetStringFromSource = (Dvar_SetStringFromSource_t)0x8230F540;
	Dvar_SetColorFromSource_t Dvar_SetColorFromSource = (Dvar_SetColorFromSource_t)0x8230F5B8;

	Dvar_SetBool_t Dvar_SetBool = (Dvar_SetBool_t)0x8230F748;
	Dvar_SetInt_t Dvar_SetInt = (Dvar_SetInt_t)0x8230F7B0;
	Dvar_SetFloat_t Dvar_SetFloat = (Dvar_SetFloat_t)0x8230F7B8;
	Dvar_SetVec2_t Dvar_SetVec2 = (Dvar_SetVec2_t)0x8230F7C0;
	Dvar_SetVec3_t Dvar_SetVec3 = (Dvar_SetVec3_t)0x8230F7C8;
	Dvar_SetVec4_t Dvar_SetVec4 = (Dvar_SetVec4_t)0x8230F7D0;
	Dvar_SetString_t Dvar_SetString = (Dvar_SetString_t)0x8230F7D8;
	Dvar_SetColor_t Dvar_SetColor = (Dvar_SetColor_t)0x8230F7E0;
	Dvar_SetFromStringFromSource_t Dvar_SetFromStringFromSource = (Dvar_SetFromStringFromSource_t)0x8230F7E8;
	Dvar_SetFromString_t Dvar_SetFromString = (Dvar_SetFromString_t)0x8230F8F8;

	Dvar_SetBoolByName_t Dvar_SetBoolByName = (Dvar_SetBoolByName_t)0x8230F900;
	Dvar_SetIntByName_t Dvar_SetIntByName = (Dvar_SetIntByName_t)0x8230F9A0;
	Dvar_SetFloatByName_t Dvar_SetFloatByName = (Dvar_SetFloatByName_t)0x8230FA40;
	Dvar_SetVec2ByName_t Dvar_SetVec2ByName = (Dvar_SetVec2ByName_t)0x8230FAE0;
	Dvar_SetVec3ByName_t Dvar_SetVec3ByName = (Dvar_SetVec3ByName_t)0x8230FB98;
	Dvar_SetVec4ByName_t Dvar_SetVec4ByName = (Dvar_SetVec4ByName_t)0x8230FC70;
	Dvar_SetStringByName_t Dvar_SetStringByName = (Dvar_SetStringByName_t)0x8230FD50;
	Dvar_SetColorByName_t Dvar_SetColorByName = (Dvar_SetColorByName_t)0x8230FDD8;
	Dvar_SetFromStringByNameFromSource_t Dvar_SetFromStringByNameFromSource = (Dvar_SetFromStringByNameFromSource_t)0x8230FEB8;
	Dvar_SetFromStringByName_t Dvar_SetFromStringByName = (Dvar_SetFromStringByName_t)0x8230FF38;

	Dvar_AddFlags_t Dvar_AddFlags = (Dvar_AddFlags_t)0x8230FF40;
	Dvar_Reset_t Dvar_Reset = (Dvar_Reset_t)0x8230FF68;

	/*Dvar_IsSystemActive_t Dvar_IsSystemActive = (Dvar_IsSystemActive_t)0x;
	Dvar_IsValidName_t Dvar_IsValidName = (Dvar_IsValidName_t)0x;
	Dvar_AssignCurrentString_t Dvar_AssignCurrentString = (Dvar_AssignCurrentString_t)0x;
	Dvar_AssignLatchedString_t Dvar_AssignLatchedString = (Dvar_AssignLatchedString_t)0x;
	Dvar_AssignResetString_t Dvar_AssignResetString = (Dvar_AssignResetString_t)0x;
	Dvar_EnumToString_t Dvar_EnumToString = (Dvar_EnumToString_t)0x;
	Dvar_IndexStringToEnumString_t Dvar_IndexStringToEnumString = (Dvar_IndexStringToEnumString_t)0x;
	Dvar_ValueToString_t Dvar_ValueToString = (Dvar_ValueToString_t)0x;
	Dvar_StringToBool_t Dvar_StringToBool = (Dvar_StringToBool_t)0x;
	Dvar_StringToInt_t Dvar_StringToInt = (Dvar_StringToInt_t)0x;
	Dvar_StringToFloat_t Dvar_StringToFloat = (Dvar_StringToFloat_t)0x;
	Dvar_StringToVec2_t Dvar_StringToVec2 = (Dvar_StringToVec2_t)0x;
	Dvar_StringToVec3_t Dvar_StringToVec3 = (Dvar_StringToVec3_t)0x;
	Dvar_StringToVec4_t Dvar_StringToVec4 = (Dvar_StringToVec4_t)0x;
	Dvar_StringToEnum_t Dvar_StringToEnum = (Dvar_StringToEnum_t)0x;
	Dvar_StringToColor_t Dvar_StringToColor = (Dvar_StringToColor_t)0x;
	Dvar_StringToValue_t Dvar_StringToValue = (Dvar_StringToValue_t)0x;
	Dvar_DisplayableValue_t Dvar_DisplayableValue = (Dvar_DisplayableValue_t)0x;
	Dvar_DisplayableResetValue_t Dvar_DisplayableResetValue = (Dvar_DisplayableResetValue_t)0x;
	Dvar_DisplayableLatchedValue_t Dvar_DisplayableLatchedValue = (Dvar_DisplayableLatchedValue_t)0x;
	Dvar_ClampVectorToDomain_t Dvar_ClampVectorToDomain = (Dvar_ClampVectorToDomain_t)0x;
	Dvar_VectorInDomain_t Dvar_VectorInDomain = (Dvar_VectorInDomain_t)0x;
	Dvar_ClampValueToDomain_t Dvar_ClampValueToDomain = (Dvar_ClampValueToDomain_t)0x;
	Dvar_ValueInDomain_t Dvar_ValueInDomain = (Dvar_ValueInDomain_t)0x;
	Dvar_VectorDomainToString_t Dvar_VectorDomainToString = (Dvar_VectorDomainToString_t)0x;
	Dvar_DomainToString_Internal_t Dvar_DomainToString_Internal = (Dvar_DomainToString_Internal_t)0x;
	Dvar_DomainToString_t Dvar_DomainToString = (Dvar_DomainToString_t)0x;
	Dvar_DomainToString_GetLines_t Dvar_DomainToString_GetLines = (Dvar_DomainToString_GetLines_t)0x;
	Dvar_ValuesEqual_t Dvar_ValuesEqual = (Dvar_ValuesEqual_t)0x;
	Dvar_SetLatchedValue_t Dvar_SetLatchedValue = (Dvar_SetLatchedValue_t)0x;
	Dvar_HasLatchedValue_t Dvar_HasLatchedValue = (Dvar_HasLatchedValue_t)0x;
	Dvar_FindMalleableVar_t Dvar_FindMalleableVar = (Dvar_FindMalleableVar_t)0x;
	Dvar_FindVar_t Dvar_FindVar = (Dvar_FindVar_t)0x;
	Dvar_ClearModified_t Dvar_ClearModified = (Dvar_ClearModified_t)0x;
	Dvar_SetModified_t Dvar_SetModified = (Dvar_SetModified_t)0x;
	Dvar_UpdateEnumDomain_t Dvar_UpdateEnumDomain = (Dvar_UpdateEnumDomain_t)0x;
	Dvar_Shutdown_t Dvar_Shutdown = (Dvar_Shutdown_t)0x;
	Dvar_PerformUnregistration_t Dvar_PerformUnregistration = (Dvar_PerformUnregistration_t)0x;
	Dvar_UpdateResetValue_t Dvar_UpdateResetValue = (Dvar_UpdateResetValue_t)0x;
	Dvar_ChangeResetValue_t Dvar_ChangeResetValue = (Dvar_ChangeResetValue_t)0x;
	Dvar_UpdateValue_t Dvar_UpdateValue = (Dvar_UpdateValue_t)0x;
	Dvar_MakeExplicitType_t Dvar_MakeExplicitType = (Dvar_MakeExplicitType_t)0x0;
	Dvar_GetReinterpretedResetValue_t Dvar_GetReinterpretedResetValue = (Dvar_GetReinterpretedResetValue_t)0x0;
	Dvar_ReinterpretDvar_t Dvar_ReinterpretDvar = (Dvar_ReinterpretDvar_t)0x0;
	Dvar_MakeLatchedValueCurrent_t Dvar_MakeLatchedValueCurrent = (Dvar_MakeLatchedValueCurrent_t)0x0;
	Dvar_ClearLatchedValue_t Dvar_ClearLatchedValue = (Dvar_ClearLatchedValue_t)0x0;
	*/
}