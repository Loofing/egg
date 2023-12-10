#pragma once
namespace game
{
	struct vec2_t
	{
		float y;
		float z;
	};
	struct vec3_t
	{
		float x;
		float y;
		float z;
	};
	struct vec4_t
	{
		float x;
		float y;
		float z;
		float m;
	};
	struct VariableStackBuffer
	{
		const char* pos;
		unsigned __int16 size;
		unsigned __int16 bufLen;
		unsigned __int16 localId;
		unsigned __int8 time;
		char buf[1];
	};

	/* 9453 */
	union VariableUnion
	{
		int intValue;
		float floatValue;
		unsigned int stringValue;
		const float* vectorValue;
		const char* codePosValue;
		unsigned int pointerValue;
		VariableStackBuffer* stackValue;
		unsigned int entityOffset;
	};

	/* 9454 */
	struct VariableValue
	{
		VariableUnion u;
		int type;
	};
	enum sessionState_s
	{
		playing,
		dead,
		spectator,
		intermission
	};
	enum buttons_t
	{
		RT = 0x100,
		RS = 0x400,
		X = 0x2000,
		PRONE = 0x10000,
		CROUCH = 0x20000,
		A = 0x40000,
		LS = 0x200200,
		RB = 0x400000,
		LB = 0x800000,
		LT = 0x8080000
	};
	struct usercmd_s
	{
		int servertime; //00
		buttons_t buttons; //04
		int angle[2]; //0C
		char padding[4]; //10
		short weapon; //12
		char _padding[2];//14
		short offHandIndex;//16
		char forwardMove; //17
		char rightMove; //18
		char __padding[0xC]; //24
	};
	struct viewClamp
	{
		vec2_t start;
		vec2_t current;
		vec2_t goal;
	};
	struct viewClampState
	{
		viewClamp min;
		viewClamp max;
		float accelTime;
		float decelTime;
		float totalTime;
		float startTime;
	};
	typedef enum
	{
		TEAM_NONE,
		TEAM_AXIS,
		TEAM_ALLIES,
		TEAM_SPECTATOR
	} sessionTeam_t;
	struct clientState_s
	{
		int clientIndex;
		sessionTeam_t team;
		int modelindex;
		int dualwielding;
		int riotShieldNext;
		int attachModelIndex[6];
		int attachTagIndex[6];
		char name[0x20];
		float maxSprintTimeMultiplier;
		int rank;
		int prestige;
		int perks[2];
		int diveState;
		int voiceConnectivityBits;
		char clanAbbrev[8];
		int playerCardIcon;
		int playerCardTitle;
		int playerCardNameplate;
	};
	static_assert(sizeof(clientState_s) == 0x94, "size of clientState_s different than 0x94");
	enum clientConnected_t
	{
		CON_DISCONNECTED,
		CON_CONNECTING,
		CON_CONNECTED
	};
	struct clientSession_t
	{

		sessionState_s sessionState;
		int forceSpectatorClient;
		int killCamEntity;
		int  killCamLookAtEntity;
		int status_icon;
		int archiveTime;
		int score;
		int deaths;
		int kills;
		int assists;
		unsigned __int16 scriptPersId;
		unsigned __int16 pad0;
		clientConnected_t connect;
		usercmd_s cmd;
		usercmd_s oldCmd;
		int localClient;
		int predictItemPickup;
		char newnetname[32];
		int maxHealth;
		int enterTime;
		int teamState;
		int voteCount;
		int teamVoteCount;
		float  moveSpeedScaleMultiplier;
		int viewmodelIndex;
		int noSpectate;
		int teamInfo;
		clientState_s _cs;
		int psOffsetTime;
		int hasRadar;
		int isRadarBlocked;
		int radarMode;
		int weaponHudIconOverrides[6];
		int unusableEntFlags[64];
		float spectateDefaultPos[3];
		float spectateDefaultAngles[3];
	};
	static_assert(sizeof(clientSession_t) == 0x2A0, "size of clientSession_t different than 0x2A0");
	enum ActionSlotType
	{
		ACTIONSLOTTYPE_DONOTHING = 0x0,
		ACTIONSLOTTYPE_SPECIFYWEAPON = 0x1,
		ACTIONSLOTTYPE_ALTWEAPONTOGGLE = 0x2,
		ACTIONSLOTTYPE_NIGHTVISION = 0x3,
		ACTIONSLOTTYPECOUNT = 0x4,
	};
	struct ActionSlotParam_SpecifyWeapon
	{
		unsigned int index;
	};
	struct ActionSlotParam
	{
		ActionSlotParam_SpecifyWeapon specifyWeapon;
	};
	enum OffhandClass
	{
		PLAYER_OFFHAND_NONE = 0x0,
		PLAYER_OFFHAND_FRAG = 0x1,
		PLAYER_OFFHAND_SMOKE = 0x2,
		PLAYER_OFFHAND_FLASH = 0x3,
		PLAYER_OFFHAND_THROWINGKNIFE = 0x4,
		PLAYER_OFFHAND_OTHER = 0x5
	};
	struct ClipAmmo
	{
		int clipIndex;
		int ammoCount[2];
	};
	struct GlobalAmmo
	{
		int ammoType;
		int ammoCount;
	};
	enum PlayerHandIndex
	{
		WEAPON_HAND_RIGHT = 0x0,
		WEAPON_HAND_LEFT = 0x1,
		NUM_WEAPON_HANDS = 0x2,
		WEAPON_HAND_DEFAULT = 0x0,
	};
	struct PlayerWeaponCommonState
	{
		int offHandIndex;
		OffhandClass offhandPrimary;
		OffhandClass offhandSecondary;
		unsigned int weapon;
		unsigned int primaryWeaponForAltMode;
		int weapFlags;
		float fWeaponPosFrac;
		float aimSpreadScale;
		int adsDelayTime;
		int spreadOverride;
		int spreadOverrideState;
		PlayerHandIndex lastWeaponHand;
		GlobalAmmo ammoNotInClip[15];
		ClipAmmo ammoInClip[15];
		int weapLockFlags;
		int weapLockedEntnum;
		float weapLockedPos[3];
		int weaponIdleTime;
	};
	struct SprintState_s
	{
		int sprintButtonUpRequired;
		int sprintDelay;
		int lastSprintStart;
		int lastSprintEnd;
		int sprintStartMaxLength;
	};
	struct MantleState_s
	{
		float yaw;
		int timer;
		int transIndex;
		int flags;
	};
	struct PlayerActiveWeaponState_s
	{
		int weapAnim;
		int weaponTime;
		int weaponDelay;
		int weaponRestrictKickTime;
		int weaponState;
		int weapHandFlags;
		int weaponShotCount;
	};
	struct PlayerEquippedWeaponState
	{
		bool usedBefore;
		bool dualWielding;
		unsigned __int8 weaponModel;
		bool needsRechamber[2];
	};
	static_assert(sizeof(PlayerEquippedWeaponState) == 0x5, "size of PlayerEquippedWeaponState different than 0x5");
	struct playerState_s
	{
		int commandTime;
		int pm_type;
		int pm_time;
		int pm_flags;
		int otherFlags;
		int linkFlags;
		int bobCycle;
		float origin[3];
		float velocity[3];
		int grenadeTimeLeft;
		int throwBackGrenadeOwner;
		int throwBackGrenadeTimeLeft;
		int throwbackWeaponIndex;
		int remoteEyesEnt;
		int remoteEyesTagname;
		int remoteControlEnt;
		int foliageSoundTime;
		int gravity;
		float leanf;
		int speed;
		float delta_angles[3];
		int groundEntityNum;
		float vLadderVe[3];
		int jumpTime;
		int jumpOriginZ;
		int legsTimer;
		int legsAnim;
		int torsoTimer;
		int torsoAnim;
		char Unknown_Data[8];
		int damageTimer;
		int damageDuration;
		int flinchYawAnim;
		int corpseIndex;
		int movementDir;
		int eFlags;
		int eventSequence;
		int events[4];
		int eventParms[4];
		int oldEventSequence;
		int unpredictableEventSequence;
		int unpredictableEventSequenceOld;
		int unpredictableEvents[4];
		int unpredictableEventParms[4];
		int clientNum;
		int viewmodelIndex;
		float viewAngles[3];
		int viewHeightTarget;
		float viewHeightCurrent;
		int viewHeightLerpTime;
		int viewHeightLerpTarget;
		int viewHeightLerpDown;
		int viewAngleClampBase[2];
		int viewAngleClampRange[2];
		int damageEvent;
		int damageYaw;
		int damagePitch;
		int damageCount;
		int damageFlags;
		int stats[4];
		float proneDirection;
		float proneDirectionPitch;
		float proneTorsoPitch;
		int viewlocked;
		int Unknown;
		vec3_t linkAngles;
		vec3_t linkWeaponAngles;
		int linkWeaponEnt;
		int loopSound;
		int cursorHint;
		char unknown[8];
		int cursorHintDualWield;
		int iCompassPlayerInfo;
		int radarEnabled;
		int radarBlocked;
		int radarMode;
		int locationSelectionInfo;
		SprintState_s sprintState;
		int holdBreathScale;
		int holdBreathTimer;
		float moveSpeedScaleMultiplier;
		MantleState_s mantleState;
		PlayerActiveWeaponState_s weaponstate[2];
		unsigned int weaponsEquipped[15];
		PlayerEquippedWeaponState weapEquippedData[15];
		PlayerWeaponCommonState weapCommon;
		float meleeChargeYaw;
		float meleeChargeDist;
		int meleeChargeTime;
		int perks[2];
		int perkSlots[8];
		ActionSlotType actionSlotType[4];
		ActionSlotParam actionSlotParam[4];
		int weaponHudIconOverrides[6];
		int animScriptedType;
		int shellshockIndex;
		int shellshockTime;
		int shellshockDuration;
		float dofNearStart;
		float dofNearEnd;
		float dofFarStart;
		float dofFarEnd;
		float dofNearBlur;
		float dofFarBlur;
		float dofViewmodelStart;
		float dofViewmodelEnd;
		char Unknown_data[0x380];
		int deltaTime;
		int killCamEntity;
		int killCamLookAtEntity;
		int killCamClientNum;
		char _Unknown[0x28B0];
		int partbits[6];
		int recoilScale;
		int diveDirection;
		int stunTime;
		char still_unknown[0x64];

	};
	static_assert(sizeof(playerState_s) == 0x3180, "size of playerState_s different than 0x3180");
	struct gclient_s
	{
		playerState_s ps;
		clientSession_t sess;
		int flags;
		int spectatorClient;
		int lastCmdTime;
		int mpviewer;
		int buttons;
		int oldbutton;
		int latched_buttons;
		int buttonsSinceLastFrame;
		vec3_t oldOrigin;
		float fGunPitch;
		float fGunYaw;
		int damage_blood;
		int damage_stun;
		vec3_t damage_from;
		int damage_fromWorld;
		int accurateCount;
		int accuracy_shots;
		int accuracy_hits;
		int inactivityTime;
		int inactivityWarning;
		int lastVoiceTime;
		int switchTeamTime;
		float currentAimSpreadScale;
		vec4_t prevLinkedInvQuat;
		char prevLinkAnglesSet;
		char link_rotationMovesEyePos;
		char link_doCollision;
		char link_useTagAnglesForViewAngles;
		float linkAnglesFrac;
		viewClampState link_viewClamp;
		int persistantPowerup;//#offset
		int portalID;
		int dropWeaponTime;
		int sniperRifleFiredTime;
		float sniperRifleMuzzleYaw;
		int PCSpecialPickedUpCount;
		int useHoldEntitychar;
		int useHoldTime;
		int usebuttonDone;
		int iLastCompassPlayerInfoEnt;
		int compassPingTime;
		int damageTime;
		float v_dmg_roll;
		float v_dmg_pitch;
		vec3_t baseAngles;
		vec3_t baseOrigin;
		vec3_t swayViewAngles;
		vec3_t swayOffset;
		vec3_t swayAngles;
		vec3_t recoilAngles;
		vec3_t recoilSpeed;
		float fLastIdleFactor;
		int weapIdleTime;
		int lastServerTime;
		int lastWeapon;
		char previouslyFiring;
		char previouslyFiringLeftHand;
		char previouslyUsingNightVision;
		char previouslySprinting;
		int visionDuration[5];
		char visionName[0x140];
		int lastStand;
		int lastStandTime;
		int hudElemLastAssignedSoundID;
		vec3_t lockedTargetOffset;
		int attachShieldTagName;
		int hintForcedType;
		int hintForcedString;
		char undefined[0x4];
	};
	static_assert(sizeof(gclient_s) == 0x3700, "size of gclient_s different than 0x3700");
	struct entityShared_t
	{
		bool isLinked;
		char modelType;
		char svFlags;
		bool isInUse;
		float mins[3];
		float maxs[3];
		int contents;
		float absmin[3];
		float absmax[3];
		float currentOrigin[3];
		float currentAngles[3];
		int ownerNum;
		int eventTime;
	};
	static_assert(sizeof(entityShared_t) == 0x58, "size of entityShared_t different than 0x58");
	struct entityState_s
	{
		int number;
		int eType;
		char padding0[0x70]; /*LerpEntityState*/
		int time2;
		int otherEntityNum;
		int attackerEntityNum;
		int groundEntityNum;
		int loopSound;
		int surfType;
		int index;
		int clientNum;
		int iHeadIcon;
		int iHeadIconTeam;
		int solid;
		int eventParam;
		int eventSequence;
		int events[4];
		int eventParams[4];
		int wes;
		int legsAnim;
		int torsoAnim;
		int unknown0;
		int unknown1;
		int clientLinkInfo;/*clientLinkInfo_t*/
		int partBits[5];
		int clientMask;
		int unknown2;
	};
	static_assert(sizeof(entityState_s) == 0x100, "size of entityState_s different than 0x100");
	struct gentity_s
	{
		entityState_s state;
		entityShared_t r;
		gclient_s* client;
		int pTurretInfo;
		int scr_vehicle;
		int physicsBody;
		unsigned __int16 model;
		char physicsObject;
		char takeDamage;
		char active;
		char handler;
		char team;
		char freeAfterEvent;
		unsigned __int16 pad;
		unsigned __int16 code_classname;
		unsigned __int16 classname;
		unsigned __int16 script_linkname;
		unsigned __int16 target;
		unsigned __int16 targetname;
		int attachIgnoreCollision;
		int spawnFlags;
		int flags;
		int eventTime;
		int clipMask;
		int processedFrame;
		int parent;
		int nextthink;
		int health;
		int maxhealth;
		int dmg;
		int count;
		char still_unknown[0x18];
		float slidevelocity[3];
		char still_Unknown_[0x3C];
		int projEntity;
		int linkedEntity;
		int tagInfo;
		gentity_s* tagChildren;
		char unknown[0x4C];
		int useCount;
		int nextFree;
		int birthtime;
		char still_Unknown[0xC];
	};
	static_assert(sizeof(gentity_s) == 0x280, "size of gentity_s different than 0x280");
}