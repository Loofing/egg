#pragma once
namespace game
{
    typedef unsigned int scr_entref_t;
	enum DvarSetSource
    {
        DVAR_SOURCE_INTERNAL = 0,
        DVAR_SOURCE_EXTERNAL = 1,
        DVAR_SOURCE_SCRIPT = 2
    };
    union DvarLimits {
        struct
        {
            int stringCount;
            char * * strings;
        } enumeration;
        struct
        {
            int min;
            int max;
        } integer;
        struct
        {
            float min;
            float max;
        } decimal;
    };
    union DvarValue {
        bool enabled;
        int integer;
        unsigned int unsignedInt;
        float value;
        float vector[4];
        char * string;
        byte color[4];
    };
    enum DvarType
    {
        Dvar_Bool = 0x00,
        Dvar_Float = 0x01,
        Dvar_Vec2 = 0x02,
        Dvar_Vec3 = 0x03,
        Dvar_Vec4 = 0x04,
        Dvar_Int = 0x05,
        Dvar_Enum = 0x06,
        Dvar_String = 0x07,
        Dvar_Color = 0x08,
        Dvar_DevTweak = 0x09
    };
    struct dvar_s
    {
        char * dvarName;
        short flags;
        DvarType type;
        bool modified;
 
        DvarValue current;
        DvarValue latched;
        DvarValue reset;
        DvarLimits domain;
        dvar_s * next;
    };
    struct XKeyboardProperties
    {
        const char* noti;
        const char* desc;
        int lenght;
        unsigned int entity;

    };
    enum VariableType
	{
		VAR_UNDEFINED = 0x0,
		VAR_BEGIN_REF = 0x1,
		VAR_POINTER = 0x1,
		VAR_STRING = 0x2,
		VAR_ISTRING = 0x3,
		VAR_VECTOR = 0x4,
		VAR_END_REF = 0x5,
		VAR_FLOAT = 0x5,
		VAR_INTEGER = 0x6,
		VAR_CODEPOS = 0x7,
		VAR_PRECODEPOS = 0x8,
		VAR_FUNCTION = 0x9,
		VAR_BUILTIN_FUNCTION = 0xA,
		VAR_BUILTIN_METHOD = 0xB,
		VAR_STACK = 0xC,
		VAR_ANIMATION = 0xD,
		VAR_PRE_ANIMATION = 0xE,
		VAR_THREAD = 0xF,
		VAR_NOTIFY_THREAD = 0x10,
		VAR_TIME_THREAD = 0x11,
		VAR_CHILD_THREAD = 0x12,
		VAR_OBJECT = 0x13,
		VAR_DEAD_ENTITY = 0x14,
		VAR_ENTITY = 0x15,
		VAR_ARRAY = 0x16,
		VAR_DEAD_THREAD = 0x17,
		VAR_COUNT = 0x18,
		VAR_FREE = 0x18,
		VAR_THREAD_LIST = 0x19,
		VAR_ENDON_LIST = 0x1A,
		VAR_TOTAL_COUNT = 0x1B,
	};
    struct BuiltinMethodDef
    {
        const char* actionString;
        void(__cdecl* actionFunc)(scr_entref_t);
        int type;
    };
    struct BuiltinFunctionDef
    {
        const char* actionString;
        void(__cdecl* actionFunc)();
        int type;
    };
    struct Bounds
    {
        float midPoint[3];
        float halfSize[3];
    };
    enum TraceHitType
    {
        TRACE_HITTYPE_NONE = 0,
        TRACE_HITTYPE_ENTITY = 1,
        TRACE_HITTYPE_DYNENT_MODEL = 2,
        TRACE_HITTYPE_DYNENT_BRUSH = 3
    };
    struct trace_t
    {
        FLOAT Fraction;
        FLOAT Normal[3];
        DWORD SurfaceFlags;
        DWORD Contents;
        PCHAR Material;
        TraceHitType HitType;
        UINT16 HitId;
        UINT16 ModelIndex;
        UINT16 PartName;
        UINT16 PartGroup;
        bool AllSolid;
        bool StartSolid;
        bool Walkable;
    };
    struct pml_t
    {
        float forward[3];
        float right[3];
        float up[3];
        float frametime;
        int msec;
        int walking;
        int groundPlane;
        int almostGroundPlane;
        trace_t groundTrace;
        float impactSpeed;
        float previous_origin[3];
        float previous_velocity[3];
        unsigned int holdrand;
    };
    struct pmove_t
    {
        playerState_s* ps;
        usercmd_s cmd;
        usercmd_s oldcmd;
        int tracemask;
        int numtouch;
        int touchents[32];
        Bounds bounds;
        float xyspeed;
        int proneChange;
        float maxSprintTimeMultiplier;
        bool mantleStarted;
        float mantleEndPos[3];
        int mantleDuration;
        int viewChangeTime;
        float viewChange;
        float fTorsoPitch;
        float fWaistPitch;
        unsigned __int8 handler;
    };
}
