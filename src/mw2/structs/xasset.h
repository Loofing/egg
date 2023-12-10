#pragma once
struct ClipMaterial
{
	const char* name;
	int surfaceFlags;
	int contents;
};
struct cplane_s
{
	float normal[3];
	float dist;
	unsigned char type;
	unsigned char pad[3];
};

struct cbrushside_t
{
	cplane_s* plane;
	unsigned __int16 materialNum;
	char firstAdjacentSideOffset;
	char edgeCount;
};

struct cbrush_t
{
	unsigned short numsides;
	unsigned short glassPieceIndex;
	cbrushside_t* sides;
	unsigned char* baseAdjacentSide;
	unsigned short axialMaterialNum[2][3];
	unsigned char firstAdjacentSideOffsets[2][3];
	unsigned char edgeCount[2][3];
};
struct clipMap_t
{
		const char *name;
		int isInUse;
		int planeCount;
		/*cplane_s **/ unsigned int planes;
		unsigned int numStaticModels;
		/*cStaticModel_s **/ unsigned int staticModelList;
		unsigned int numMaterials;
		/*ClipMaterial **/ ClipMaterial* materials;
		unsigned int numBrushSides;
		/*cbrushside_t */ unsigned int brushsides;
		unsigned int numBrushEdges;
		char *brushEdges;
		unsigned int numNodes;
		/*cNode_t **/ unsigned int nodes;
		unsigned int numLeafs;
		/*cLeaf_t **/ unsigned int leafs;
		unsigned int leafbrushNodesCount;
		/*cLeafBrushNode_s **/ unsigned int leafbrushNodes;
		unsigned int numLeafBrushes;
		unsigned __int16 *leafbrushes;
		unsigned int numLeafSurfaces;
		unsigned int *leafsurfaces;
		unsigned int vertCount;
		float(*verts)[3];
		int triCount;
		unsigned __int16 *triIndices;
		char *triEdgeIsWalkable;
		int borderCount;
		/*CollisionBorder **/ unsigned int borders;
		int partitionCount;
		/*CollisionPartition **/ unsigned int partitions;
		int aabbTreeCount;
		/*CollisionAabbTree **/ unsigned int aabbTrees;
		unsigned int numSubModels;
		/*cmodel_t **/ unsigned int cmodels;
		unsigned __int16 numBrushes;
		/*cbrush_t **/ cbrush_t* brushes;
		/*Bounds **/unsigned int brushBounds;
		int *brushContents;
		/*MapEnts **/  unsigned int mapEnts;
		unsigned __int16 smodelNodeCount;
		/*SModelAabbNode **/ unsigned int smodelNodes;
		unsigned __int16 dynEntCount[2];
		/*DynEntityDef **/ unsigned short dynEntDefList[2];
		/*DynEntityPose **/ unsigned int dynEntPoseList[2];
		/*DynEntityClient **/unsigned int dynEntClientList[2];
		/*DynEntityColl **/ unsigned int dynEntCollList[2];
		unsigned int checksum;
};
enum XAssetType
{
	ASSET_TYPE_PHYSPRESET,
	ASSET_TYPE_PHYSCOLLMAP,
	ASSET_TYPE_XANIMPARTS,
	ASSET_TYPE_XMODEL_SURFS,
	ASSET_TYPE_XMODEL,
	ASSET_TYPE_MATERIAL,
	ASSET_TYPE_PIXELSHADER,
	ASSET_TYPE_TECHNIQUE_SET,
	ASSET_TYPE_IMAGE,
	ASSET_TYPE_SOUND,
	ASSET_TYPE_SOUND_CURVE,
	ASSET_TYPE_LOADED_SOUND,
	ASSET_TYPE_CLIPMAP_SP,
	ASSET_TYPE_CLIPMAP_MP,
	ASSET_TYPE_COMWORLD,
	ASSET_TYPE_GAMEWORLD_SP,
	ASSET_TYPE_GAMEWORLD_MP,
	ASSET_TYPE_MAP_ENTS,
	ASSET_TYPE_FXWORLD,
	ASSET_TYPE_GFXWORLD,
	ASSET_TYPE_LIGHT_DEF,
	ASSET_TYPE_UI_MAP,
	ASSET_TYPE_FONT,
	ASSET_TYPE_MENULIST,
	ASSET_TYPE_MENU,
	ASSET_TYPE_LOCALIZE_ENTRY,
	ASSET_TYPE_WEAPON,
	ASSET_TYPE_SNDDRIVER_GLOBALS,
	ASSET_TYPE_FX,
	ASSET_TYPE_IMPACT_FX,
	ASSET_TYPE_AITYPE,
	ASSET_TYPE_MPTYPE,
	ASSET_TYPE_CHARACTER,
	ASSET_TYPE_XMODELALIAS,
	ASSET_TYPE_RAWFILE,
	ASSET_TYPE_STRINGTABLE,
	ASSET_TYPE_LEADERBOARD,
	ASSET_TYPE_STRUCTURED_DATA_DEF,
	ASSET_TYPE_TRACER,
	ASSET_TYPE_VEHICLE,
	ASSET_TYPE_ADDON_MAP_ENTS,
	ASSET_TYPE_COUNT
};
union XAssetHeader
{
	void* physPreset;
	void* physCollmap;   
	void* parts;        
	void* modelSurfs;   
	/*void*/ unsigned int model;
	void* material;      
	void* pixelShader;   
	void* vertexShader;  
	void* techniqueSet;  
	void* image;        
	void* sound;         
	void* sndCurve;      
	void* loadSnd;        
	clipMap_t* clipMap;
	void* comWorld ;      
	void* gameWorldSp;   
	void* gameWorldMp;    
	void* mapEnts;        
	void* fxWorld;       
	void* gfxWorld;      
	void* lightDef;       
	void* font;          
	void* menuList;       
	void* menu;          
	void* localize;      
	void* weapon;         
	void* sndDriverGlobals;
	void* fx;             
	void* impactFx;      
	void* rawfile;       
	void* stringTable;
	void* leaderboardDef;
	void* structuredDataDefSet;
	void* tracerDef;    
	void* vehDef;     
	void* addonMapEnts;
};
struct XAsset
{
	XAssetType type;
	XAssetHeader header;
};