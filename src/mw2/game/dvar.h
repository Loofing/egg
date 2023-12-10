#pragma once

namespace dvar
{
	using namespace game;

	typedef void (__cdecl * Dvar_Reregister_t)(dvar_s *dvar, const char *dvarName, char type, unsigned __int16 flags, DvarValue resetValue, DvarLimits domain, const char *description);
	extern Dvar_Reregister_t Dvar_Reregister;

	typedef dvar_s * (__cdecl * Dvar_RegisterNew_t)(const char *dvarName, char type, unsigned __int16 flags, DvarValue value, DvarLimits domain, const char *description);
	extern Dvar_RegisterNew_t Dvar_RegisterNew;
 
	typedef dvar_s * (__cdecl * Dvar_RegisterVariant_t)(const char *dvarName, char type, unsigned __int16 flags, DvarValue value, DvarLimits domain, const char *description);
	extern Dvar_RegisterVariant_t Dvar_RegisterVariant;
 
	typedef dvar_s * (__cdecl * Dvar_RegisterBool_t)(const char* dvarName, bool value, unsigned __int16 flags, const char* description);
	extern Dvar_RegisterBool_t Dvar_RegisterBool;
 
	typedef dvar_s * (__cdecl * Dvar_RegisterInt_t)(const char* dvarName, int value, int min, int max, unsigned __int16 flags, const char* description);
	extern Dvar_RegisterInt_t Dvar_RegisterInt;
 
	typedef dvar_s * (__cdecl * Dvar_RegisterFloat_t)(const char* dvarName, float value, float min, float max, unsigned __int16 flags, const char* description);
	extern Dvar_RegisterFloat_t Dvar_RegisterFloat;
 
	typedef dvar_s * (__cdecl * Dvar_RegisterVec2_t)(const char* dvarName, float x, float y, float min, float max, unsigned __int16 flags, const char* description);
	extern Dvar_RegisterVec2_t Dvar_RegisterVec2;
 
	typedef dvar_s * (__cdecl * Dvar_RegisterVec3_t)(const char* dvarName, float x, float y, float z, float min, float max, unsigned __int16 flags, const char* description);
	extern Dvar_RegisterVec3_t Dvar_RegisterVec3;
 
	typedef dvar_s * (__cdecl * Dvar_RegisterVec4_t)(const char* dvarName, float x, float y, float z, float w, float min, float max, unsigned __int16 flags, const char* description);
	extern Dvar_RegisterVec4_t Dvar_RegisterVec4;
 
	typedef dvar_s * (__cdecl * Dvar_RegisterString_t)(const char* dvarName, const char* value, unsigned __int16 flags, const char *description);
	extern Dvar_RegisterString_t Dvar_RegisterString;
 
	typedef dvar_s * (__cdecl * Dvar_RegisterEnum_t)(const char* dvarName, const char* * valueList, int defaultIndex, unsigned __int16 flags, const char* description);
	extern Dvar_RegisterEnum_t Dvar_RegisterEnum;
 
	typedef dvar_s * (__cdecl * Dvar_RegisterColor_t)(const char* dvarName, float r, float g, float b, float a, unsigned __int16 flags, const char* description);
	extern Dvar_RegisterColor_t Dvar_RegisterColor;

	typedef dvar_s * (__cdecl * Dvar_RegisterDevTweak_t)(const char* dvarName, float x, float y, float min, float max, unsigned __int16 flags, const char* description);
	extern Dvar_RegisterDevTweak_t Dvar_RegisterDevTweak;

	typedef bool (__cdecl * Dvar_GetBool_t)(const char* dvarName);
	extern Dvar_GetBool_t Dvar_GetBool;

	typedef int (__cdecl * Dvar_GetInt_t)(const char* dvarName);
	extern Dvar_GetInt_t Dvar_GetInt;

	typedef float (__cdecl * Dvar_GetFloat_t)(const char* dvarName);
	extern Dvar_GetFloat_t Dvar_GetFloat;

	typedef void (__cdecl * Dvar_GetVec3_t)(const char* dvarName, float *out);
	extern Dvar_GetVec3_t Dvar_GetVec3;

	typedef const char * (__cdecl * Dvar_GetString_t)(const char* dvarName);
	extern Dvar_GetString_t Dvar_GetString;
 
	typedef const char * (__cdecl * Dvar_GetVariantString_t)(const char* dvarName);
	extern Dvar_GetVariantString_t Dvar_GetVariantString;

	typedef void (__cdecl * Dvar_SetBoolFromSource_t)(dvar_s *dvar, bool value, DvarSetSource source);
	extern Dvar_SetBoolFromSource_t Dvar_SetBoolFromSource;

	typedef void (__cdecl * Dvar_SetIntFromSource_t)(dvar_s *dvar, int value, DvarSetSource source);
	extern Dvar_SetIntFromSource_t Dvar_SetIntFromSource;
 
	typedef void (__cdecl * Dvar_SetFloatFromSource_t)(dvar_s *dvar, float value, DvarSetSource source);
	extern Dvar_SetFloatFromSource_t Dvar_SetFloatFromSource;
 
	typedef void (__cdecl * Dvar_SetVec2FromSource_t)(dvar_s *dvar, float x, float y, DvarSetSource source);
	extern Dvar_SetVec2FromSource_t Dvar_SetVec2FromSource;
 
	typedef void (__cdecl * Dvar_SetVec3FromSource_t)(dvar_s *dvar, float x, float y, float z, DvarSetSource source);
	extern Dvar_SetVec3FromSource_t Dvar_SetVec3FromSource;
 
	typedef void (__cdecl * Dvar_SetVec4FromSource_t)(dvar_s *dvar, float x, float y, float z, float w, DvarSetSource source);
	extern Dvar_SetVec4FromSource_t Dvar_SetVec4FromSource;
 
	typedef void (__cdecl * Dvar_SetStringFromSource_t)(dvar_s *dvar, const char *string, DvarSetSource source);
	extern Dvar_SetStringFromSource_t Dvar_SetStringFromSource;
 
	typedef void (__cdecl * Dvar_SetColorFromSource_t)(dvar_s *dvar, float r, float g, float b, float a, DvarSetSource source);
	extern Dvar_SetColorFromSource_t Dvar_SetColorFromSource;

	typedef void (__cdecl * Dvar_SetBool_t)(dvar_s * dvar, bool value);
	extern Dvar_SetBool_t Dvar_SetBool;
 
	typedef void (__cdecl * Dvar_SetInt_t)(dvar_s * dvar, int value);
	extern Dvar_SetInt_t Dvar_SetInt;
 
	typedef void (__cdecl * Dvar_SetFloat_t)(dvar_s * dvar, float value);
	extern Dvar_SetFloat_t Dvar_SetFloat;
 
	typedef void (__cdecl * Dvar_SetVec2_t)(dvar_s *dvar, float x, float y);
	extern Dvar_SetVec2_t Dvar_SetVec2;
 
	typedef void (__cdecl * Dvar_SetVec3_t)(dvar_s *dvar, float x, float y, float z);
	extern Dvar_SetVec3_t Dvar_SetVec3;
 
	typedef void (__cdecl * Dvar_SetVec4_t)(dvar_s *dvar, float x, float y, float z, float w);
	extern Dvar_SetVec4_t Dvar_SetVec4;
 
	typedef void (__cdecl * Dvar_SetString_t)(dvar_s *dvar, const char *string);
	extern Dvar_SetString_t Dvar_SetString;
 
	typedef void (__cdecl * Dvar_SetColor_t)(dvar_s *dvar, float r, float g, float b, float a);
	extern Dvar_SetColor_t Dvar_SetColor;
 
	typedef void (__cdecl * Dvar_SetFromStringFromSource_t)(dvar_s *dvar, const char *string, DvarSetSource source);
	extern Dvar_SetFromStringFromSource_t Dvar_SetFromStringFromSource;
 
	typedef void (__cdecl * Dvar_SetFromString_t)(dvar_s *dvar, const char *string);
	extern Dvar_SetFromString_t Dvar_SetFromString;

	typedef void (__cdecl * Dvar_SetBoolByName_t)(const char *dvarName, bool value);
	extern Dvar_SetBoolByName_t Dvar_SetBoolByName;
 
	typedef void (__cdecl * Dvar_SetIntByName_t)(const char *dvarName, int value);
	extern Dvar_SetIntByName_t Dvar_SetIntByName;
 
	typedef void (__cdecl * Dvar_SetFloatByName_t)(const char *dvarName, float value);
	extern Dvar_SetFloatByName_t Dvar_SetFloatByName;
 
	typedef void (__cdecl * Dvar_SetVec2ByName_t)(const char *dvarName, float x, float y);
	extern Dvar_SetVec2ByName_t Dvar_SetVec2ByName;
 
	typedef void (__cdecl * Dvar_SetVec3ByName_t)(const char *dvarName, float x, float y, float z);
	extern Dvar_SetVec3ByName_t Dvar_SetVec3ByName;
 
	typedef void (__cdecl * Dvar_SetVec4ByName_t)(const char *dvarName, float x, float y, float z, float w);
	extern Dvar_SetVec4ByName_t Dvar_SetVec4ByName;
 
	typedef void (__cdecl * Dvar_SetStringByName_t)(const char *dvarName, const char *string);
	extern Dvar_SetStringByName_t Dvar_SetStringByName;
 
	typedef void (__cdecl * Dvar_SetColorByName_t)(const char *dvarName, float r, float g, float b, float a);
	extern Dvar_SetColorByName_t Dvar_SetColorByName;
 
	typedef void (__cdecl * Dvar_SetFromStringByNameFromSource_t)(const char *dvarName, const char *string, DvarSetSource source);
	extern Dvar_SetFromStringByNameFromSource_t Dvar_SetFromStringByNameFromSource;
 
	typedef void (__cdecl * Dvar_SetFromStringByName_t)(const char *dvarName, const char *string);
	extern Dvar_SetFromStringByName_t Dvar_SetFromStringByName;

	typedef void (__cdecl * Dvar_AddFlags_t)(dvar_s *dvar, int flags);
	extern Dvar_AddFlags_t Dvar_AddFlags;
 
	typedef void (__cdecl * Dvar_Reset_t)(dvar_s *dvar, DvarSetSource setSource);
	extern Dvar_Reset_t Dvar_Reset;
}