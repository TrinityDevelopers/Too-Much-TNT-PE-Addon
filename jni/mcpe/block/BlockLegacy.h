#pragma once

#include <memory>
#include <string>
#include <vector>
#include <unordered_map>
#include "BlockID.h"
#include "BlockState.h"
#include "../item/CreativeItemCategory.h"
#include "../math/AABB.h"
#include "../util/Color.h"
#include "../util/Util.h"

class BlockPalette;
class BlockSource;
class BlockPos;
class Block;
class Entity;
class Material;
class Mob;
class Player;
class Random;
class ItemInstance;
class Container;
class Brightness;
class ItemUseCallback;
enum class BlockProperty;
enum class BlockSupportType;
enum class BlockRenderLayer;
enum class BlockEntityType;
enum class EntityType;

// 1.2.13.60

class BlockLegacy {
public:
	std::string descriptionId;
	std::string nameId;
	bool fancy;
	bool canBuildOver;
	BlockRenderLayer renderLayer;
	int i1;
	int properties;
	int i2;
	BlockEntityType blockEntityType;
	bool animates;
	float f1;
	float thickness;
	bool slideable;
	bool instatick;
	bool isInteraction;
	float gravity;
	Material* material;
	Color mapColor;
	float friction;
	bool heavy;
	float particleQuantity;
	float destroyTime;
	float blastResistance;
	CreativeItemCategory category;
	bool allowsRunes;
	bool canBreakFromFalling;
	bool solid;
	bool pushesItems;
	bool ignoreBlock;
	float translucency;
	uint8_t lightBlock;
	uint8_t lightEmission;
	bool ticking;
	void* flameOdds;
	void* burnOdds;
	short blockId;
	bool experimental;
	AABB aabb;
	int bitsUsed;
	BlockState blockStates[46];
	int i3;
	int i4;
	int i5;
	BlockState& defaultBlockState;

	// virtual
	virtual ~BlockLegacy();
	virtual void tick(BlockSource&, const BlockPos&, Random&) const;
	virtual void* getCollisionShape(AABB&, BlockSource&, const BlockPos&, Entity*) const;
	virtual bool isObstructingChests(BlockSource&, const BlockPos&) const;
	virtual Vec3 randomlyModifyPosition(const BlockPos&, int&) const;
	virtual Vec3 randomlyModifyPosition(const BlockPos&) const;
	virtual void addAABBs(BlockSource&, const BlockPos&, const AABB*, std::vector<AABB, std::allocator<AABB> >&) const;
	virtual void* getAABB(BlockSource&, const BlockPos&, const Block&, AABB&, bool) const;
	virtual void addCollisionShapes(BlockSource&, const BlockPos&, const AABB*, std::vector<AABB, std::allocator<AABB> >&, Entity*) const;
	virtual void* getOutline(BlockSource&, const BlockPos&, AABB&) const;
	virtual bool isStrippable() const;
	virtual void* getStrippedBlock(const Block&) const;
	virtual bool canProvideSupport(BlockSource&, const BlockPos&, signed char, BlockSupportType) const;
	virtual bool canConnect(const Block&, signed char, const Block&) const;
	virtual void* getConnectedDirections(const BlockPos&, BlockSource&, bool&, bool&, bool&, bool&) const;
	virtual bool isCropBlock() const;
	virtual bool isStemBlock() const;
	virtual bool isContainerBlock() const;
	virtual bool isCraftingBlock() const;
	virtual bool isInteractiveBlock() const;
	virtual bool isWaterBlocking() const;
	virtual bool isHurtableBlock() const;
	virtual bool isFenceBlock() const;
	virtual bool isThinFenceBlock() const;
	virtual bool isStairBlock() const;
	virtual bool isSlabBlock() const;
	virtual bool isRailBlock() const;
	virtual bool canHurtAndBreakItem() const;
	virtual bool isSignalSource() const;
	virtual bool canBeOriginalSurface() const;
	virtual bool isValidAuxValue(int) const;
	virtual bool canFillAtPos(BlockSource&, const BlockPos&, const Block&) const;
	virtual void sanitizeFillBlock(BlockSource&, const BlockPos&, const Block&) const;
	virtual void onFillBlock(BlockSource&, const BlockPos&, const Block&) const;
	virtual int getDirectSignal(BlockSource&, const BlockPos&, int) const;
	virtual bool waterSpreadCausesSpawn() const;
	virtual bool shouldConnectToRedstone(BlockSource&, const BlockPos&, int) const;
	virtual void handleRain(BlockSource&, const BlockPos&, float) const;
	virtual float getThickness() const;
	virtual void* getFlexibility(BlockSource&, const BlockPos&) const;
	virtual bool checkIsPathable(Entity&, const BlockPos&, const BlockPos&) const;
	virtual bool shouldDispense(BlockSource&, Container&) const;
	virtual bool dispense(BlockSource&, Container&, int, const Vec3&, signed char) const;
	virtual void onPlace(BlockSource&, const BlockPos&) const;
	virtual void onRemove(BlockSource&, const BlockPos&) const;
	virtual void onExploded(BlockSource&, const BlockPos&, Entity*) const;
	virtual void onStepOn(Entity&, const BlockPos&) const;
	virtual void onFallOn(BlockSource&, const BlockPos&, Entity*, float) const;
	virtual void transformOnFall(BlockSource&, const BlockPos&, Entity*, float) const;
	virtual void onRedstoneUpdate(BlockSource&, const BlockPos&, int, bool) const;
	virtual void onMove(BlockSource&, const BlockPos&, const BlockPos&) const;
	virtual bool detachesOnPistonMove(BlockSource&, const BlockPos&) const;
	virtual void setupRedstoneComponent(BlockSource&, const BlockPos&) const;
	virtual int getRedstoneProperty(BlockSource&, const BlockPos&) const;
	virtual void updateEntityAfterFallOn(Entity&) const;
	virtual bool isBounceBlock() const;
	virtual void ignoreEntitiesOnPistonMove(const Block&) const;
	virtual bool onFertilized(BlockSource&, const BlockPos&, Entity*, ItemUseCallback*) const;
	virtual bool mayConsumeFertilizer(BlockSource&) const;
	virtual bool mayPick() const;
	virtual bool mayPick(BlockSource&, const Block&, bool) const;
	virtual bool mayPlace(BlockSource&, const BlockPos&, signed char) const;
	virtual bool mayPlace(BlockSource&, const BlockPos&) const;
	virtual bool mayPlaceOn(const Block&) const;
	virtual bool tryToPlace(BlockSource&, const BlockPos&, const Block&) const;
	virtual bool breaksFallingBlocks(const Block&) const;
	virtual void destroy(BlockSource&, const BlockPos&, const Block&, Entity*) const;
	virtual bool playerWillDestroy(Player&, const BlockPos&, const Block&) const;
	virtual void* getIgnoresDestroyPermissions(Entity&, const BlockPos&) const;
	virtual void neighborChanged(BlockSource&, const BlockPos&, const BlockPos&) const;
	virtual void* getSecondPart(BlockSource&, const BlockPos&, BlockPos&) const;
	virtual int getResourceCount(Random&, const Block&, int) const;
	virtual ItemInstance getResourceItem(Random&, const Block&, int) const;
	virtual ItemInstance asItemInstance(BlockSource&, const BlockPos&, const Block&) const;
	virtual bool spawnResources(BlockSource&, const BlockPos&, const Block&, float, int) const;
	virtual bool spawnBurnResources(BlockSource&, float, float, float) const;
	virtual float getExplosionResistance(Entity*) const;
	virtual void clip(BlockSource&, const BlockPos&, const Vec3&, const Vec3&, bool) const;
	virtual bool use(Player&, const BlockPos&, ItemUseCallback*) const;
	virtual void* getPlacementBlock(Entity&, const BlockPos&, signed char, const Vec3&, int) const;
	virtual int calcVariant(BlockSource&, const BlockPos&) const;
	virtual bool isAttachedTo(BlockSource&, const BlockPos&, BlockPos&) const;
	virtual bool attack(Player*, const BlockPos&) const;
	virtual void handleEntityInside(BlockSource&, const BlockPos&, Entity*, Vec3&) const;
	virtual void entityInside(BlockSource&, const BlockPos&, Entity&) const;
	virtual void playerDestroy(Player&, const BlockPos&, const Block&) const;
	virtual bool canSurvive(BlockSource&, const BlockPos&) const;
	virtual int getExperienceDrop(Random&) const;
	virtual bool canBeBuiltOver(BlockSource&, const BlockPos&) const;
	virtual void triggerEvent(BlockSource&, const BlockPos&, int, int) const;
	virtual void* getMobToSpawn(BlockSource&, const BlockPos&) const;
	virtual Color getMapColor(BlockSource&, const BlockPos&) const;
	virtual Color getMapColor() const;
	virtual bool shouldStopFalling(Entity&) const;
	virtual bool pushesUpFallingBlocks() const;
	virtual float calcGroundFriction(Mob&, const BlockPos&) const;
	virtual bool canHaveExtraData() const;
	virtual bool hasComparatorSignal() const;
	virtual int getComparatorSignal(BlockSource&, const BlockPos&, const Block&, signed char) const;
	virtual int getIconYOffset() const;
	virtual BlockRenderLayer getRenderLayer() const;
	virtual std::string buildDescriptionId(const Block&) const;
	virtual bool isAuxValueRelevantForPicking() const;
	virtual unsigned int getColor(const Block&) const;
	virtual unsigned int getColorAtPos(BlockSource&, const BlockPos&) const;
	virtual unsigned int getColor(BlockSource&, const BlockPos&, const Block&) const;
	virtual unsigned int getColorForParticle(BlockSource&, const BlockPos&, const Block&) const;
	virtual bool isSeasonTinted(BlockSource&, const BlockPos&) const;
	virtual void onGraphicsModeChanged(bool, bool, bool);
	virtual BlockRenderLayer getRenderLayer(BlockSource&, const BlockPos&) const;
	virtual void* getExtraRenderLayers() const;
	virtual AABB const& getVisualShape(BlockSource&, const BlockPos&, AABB&, bool) const;
	virtual AABB const& getVisualShape(const Block&, AABB&, bool) const;
	virtual void telemetryVariant(BlockSource&, const BlockPos&) const;
	virtual int getVariant(const Block&) const;
	virtual signed char getMappedFace(signed char, const Block&) const;
	virtual void animateTick(BlockSource&, const BlockPos&, Random&) const;
	virtual void init();
	virtual void postInit();
	virtual bool canBeSilkTouched() const;
	virtual ItemInstance getSilkTouchItemInstance(const Block&) const;
	virtual void setVisualShape(const AABB&);
	virtual void setVisualShape(const Vec3&, const Vec3&);
	virtual void setLightBlock(Brightness);
	virtual void setLightEmission(float);
	virtual void setExplodeable(float);
	virtual void setDestroyTime(float);
	virtual void setFriction(float);
	virtual void setMapColor(const Color&);
	virtual void addProperty(BlockProperty);
	virtual void addBlockState(BlockState::BlockStates, int);
	virtual void resetBitsUsed();
	virtual void setAllowsRunes(bool);

    // non virtual
    BlockLegacy(std::string const&, int, Material const&);
    void setCategory(CreativeItemCategory);
    void setNameId(std::string const&);
    void setSolid(bool);
    bool canSlide() const;
    bool canInstatick() const;
    CreativeItemCategory getCreativeCategory() const;
    float getGravity() const;
    Material* getMaterial() const;
	BlockState& getBlockState(BlockState::BlockStates) const;
    float getFriction() const;
    float getDestroySpeed() const;
    bool isType(BlockLegacy const*) const;
    void clip(BlockSource&, BlockPos const&, Vec3 const&, Vec3 const&, bool, int, AABB const&) const;
    void popResource(BlockSource&, BlockPos const&, ItemInstance const&) const;
    bool hasProperty(BlockProperty) const;
    bool isSolid() const;
    bool addAABB(AABB const&, AABB const*, std::vector<AABB>&) const;
    bool pushesOutItems() const;
    void setPushesOutItems(bool);
    bool isUnbreakable() const;
    bool isHeavy() const;
    std::string const& getDescriptionId() const;
    bool isAlphaTested() const;
    bool isSolidBlockingBlock() const;
    BlockEntityType getBlockEntityType() const;
    bool hasBlockEntity() const;
    int getProperties() const;
    float getShadeBrightness() const;
    void getDebugText(std::vector<std::string>&) const;
    bool canGrowChorus() const;
    void* getTypeToSpawn(BlockSource&, EntityType, BlockPos const&) const;

    static BlockLegacy* lookupByName(std::string const&, bool);
	static void initBlocks();
	static void postInitBlocks(const BlockPalette&);
	static void teardownBlocks();
	static signed char getPlacementFacingAll(Entity&, const BlockPos&, float);
	static BlockID transformToValidBlockId(const Block&, const BlockPos&);
	static signed char getPlacementFacingAllExceptAxisY(Entity&, const BlockPos&, float);

    static std::unordered_map<std::string,BlockLegacy const*> mBlockLookupMap;
	static std::vector<std::unique_ptr<BlockLegacy>> mOwnedBlocks;
	static BlockLegacy* mBlocks[256];

	static BlockLegacy* mAir; // 0
	static BlockLegacy* mStone; // 1
	static BlockLegacy* mGrass; // 2
	static BlockLegacy* mDirt; // 3
	static BlockLegacy* mCobblestone; // 4
	static BlockLegacy* mWoodPlanks; // 5
	static BlockLegacy* mSapling; // 6
	static BlockLegacy* mBedrock; // 7
	static BlockLegacy* mFlowingWater; // 8
	static BlockLegacy* mStillWater; // 9
	static BlockLegacy* mFlowingLava; // 10
	static BlockLegacy* mStillLava; // 11
	static BlockLegacy* mSand; // 12
	static BlockLegacy* mGravel; // 13
	static BlockLegacy* mGoldOre; // 14
	static BlockLegacy* mIronOre; // 15
	static BlockLegacy* mCoalOre; // 16
	static BlockLegacy* mLog; // 17
	static BlockLegacy* mLeaves; // 18
	static BlockLegacy* mSponge; // 19
	static BlockLegacy* mGlass; // 20
	static BlockLegacy* mLapisOre; // 21
	static BlockLegacy* mLapisBlock; // 22
	static BlockLegacy* mDispenser; // 23
	static BlockLegacy* mSandStone; // 24
	static BlockLegacy* mNote; // 25
	static BlockLegacy* mBed; // 26
	static BlockLegacy* mGoldenRail; // 27
	static BlockLegacy* mDetectorRail; // 28
	static BlockLegacy* mStickyPiston; // 29
	static BlockLegacy* mWeb; // 30
	static BlockLegacy* mTallgrass; // 31
	static BlockLegacy* mDeadBush; // 32
	static BlockLegacy* mPiston; // 33
	static BlockLegacy* mPistonArm; // 34
	static BlockLegacy* mWool; // 35
	static BlockLegacy* mYellowFlower; // 37
	static BlockLegacy* mRedFlower; // 38
	static BlockLegacy* mBrownMushroom; // 39
	static BlockLegacy* mRedMushroom; // 40
	static BlockLegacy* mGoldBlock; // 41
	static BlockLegacy* mIronBlock; // 42
	static BlockLegacy* mDoubleStoneSlab; // 43
	static BlockLegacy* mStoneSlab; // 44
	static BlockLegacy* mBrick; // 45
	static BlockLegacy* mTNT; // 46
	static BlockLegacy* mBookshelf; // 47
	static BlockLegacy* mMossyCobblestone; // 48
	static BlockLegacy* mObsidian; // 49
	static BlockLegacy* mTorch; // 50
	static BlockLegacy* mFire; // 51
	static BlockLegacy* mMobSpawner; // 52
	static BlockLegacy* mOakStairs; // 53
	static BlockLegacy* mChest; // 54
	static BlockLegacy* mRedStoneDust; // 55
	static BlockLegacy* mDiamondOre; // 56
	static BlockLegacy* mDiamondBlock; // 57
	static BlockLegacy* mWorkBench; // 58
	static BlockLegacy* mWheatCrop; // 59
	static BlockLegacy* mFarmland; // 60
	static BlockLegacy* mFurnace; // 61
	static BlockLegacy* mLitFurnace; // 62
	static BlockLegacy* mSign; // 63
	static BlockLegacy* mWoodenDoor; // 64
	static BlockLegacy* mLadder; // 65
	static BlockLegacy* mRail; // 66
	static BlockLegacy* mStoneStairs; // 67
	static BlockLegacy* mWallSign; // 68
	static BlockLegacy* mLever; // 69
	static BlockLegacy* mStonePressurePlate; // 70
	static BlockLegacy* mIronDoor; // 71
	static BlockLegacy* mWoodPressurePlate; // 72
	static BlockLegacy* mRedStoneOre; // 73
	static BlockLegacy* mLitRedStoneOre; // 74
	static BlockLegacy* mUnlitRedStoneTorch; // 75
	static BlockLegacy* mLitRedStoneTorch; // 76
	static BlockLegacy* mStoneButton; // 77
	static BlockLegacy* mTopSnow; // 78
	static BlockLegacy* mIce; // 79
	static BlockLegacy* mSnow; // 80
	static BlockLegacy* mCactus; // 81
	static BlockLegacy* mClay; // 82
	static BlockLegacy* mReeds; // 83
	static BlockLegacy* mFence; // 85
	static BlockLegacy* mPumpkin; // 86
	static BlockLegacy* mNetherrack; // 87
	static BlockLegacy* mSoulSand; // 88
	static BlockLegacy* mGlowStone; // 89
	static BlockLegacy* mPortal; // 90
	static BlockLegacy* mLitPumpkin; // 91
	static BlockLegacy* mCake; // 92
	static BlockLegacy* mUnpoweredRepeater; // 93
	static BlockLegacy* mPoweredRepeater; // 94
	static BlockLegacy* mInvisibleBedrock; // 95
	static BlockLegacy* mTrapdoor; // 96
	static BlockLegacy* mMonsterStoneEgg; // 97
	static BlockLegacy* mStoneBrick; // 98
	static BlockLegacy* mBrownMushroomBlock; // 99
	static BlockLegacy* mRedMushroomBlock; // 100
	static BlockLegacy* mIronFence; // 101
	static BlockLegacy* mGlassPane; // 102
	static BlockLegacy* mMelon; // 103
	static BlockLegacy* mPumpkinStem; // 104
	static BlockLegacy* mMelonStem; // 105
	static BlockLegacy* mVine; // 106
	static BlockLegacy* mFenceGateOak; // 107
	static BlockLegacy* mBrickStairs; // 108
	static BlockLegacy* mStoneBrickStairs; // 109
	static BlockLegacy* mMycelium; // 110
	static BlockLegacy* mWaterlily; // 111
	static BlockLegacy* mNetherBrick; // 112
	static BlockLegacy* mNetherFence; // 113
	static BlockLegacy* mNetherBrickStairs; // 114
	static BlockLegacy* mNetherWart; // 115
	static BlockLegacy* mEnchantingTable; // 116
	static BlockLegacy* mBrewingStand; // 117
	static BlockLegacy* mCauldron; // 118
	static BlockLegacy* mEndPortalFrame; // 120
	static BlockLegacy* mEndStone; // 121
	static BlockLegacy* mUnlitRedStoneLamp; // 123
	static BlockLegacy* mLitRedStoneLamp; // 124
	static BlockLegacy* mActivatorRail; // 126
	static BlockLegacy* mCocoa; // 127
	static BlockLegacy* mSandStoneStairs; // 128
	static BlockLegacy* mEmeraldOre; // 129
	static BlockLegacy* mTripwireHook; // 131
	static BlockLegacy* mTripwire; // 132
	static BlockLegacy* mEmeraldBlock; // 133
	static BlockLegacy* mSpruceStairs; // 134
	static BlockLegacy* mBirchStairs; // 135
	static BlockLegacy* mJungleStairs; // 136
	static BlockLegacy* mCobblestoneWall; // 139
	static BlockLegacy* mFlowerPot; // 140
	static BlockLegacy* mCarrotCrop; // 141
	static BlockLegacy* mPotatoCrop; // 142
	static BlockLegacy* mWoodButton; // 143
	static BlockLegacy* mSkull; // 144
	static BlockLegacy* mAnvil; // 145
	static BlockLegacy* mTrappedChest; // 146
	static BlockLegacy* mLightWeightedPressurePlate; // 147
	static BlockLegacy* mHeavyWeightedPressurePlate; // 148
	static BlockLegacy* mUnpoweredComparator; // 149
	static BlockLegacy* mPoweredComparator; // 150
	static BlockLegacy* mDaylightDetector; // 151
	static BlockLegacy* mRedstoneBlock; // 152
	static BlockLegacy* mQuartzOre; // 153
	static BlockLegacy* mHopper; // 154
	static BlockLegacy* mQuartzBlock; // 155
	static BlockLegacy* mQuartzStairs; // 156
	static BlockLegacy* mDoubleWoodenSlab; // 157
	static BlockLegacy* mWoodenSlab; // 158
	static BlockLegacy* mStainedClay; // 159
	static BlockLegacy* mLeaves2; // 161
	static BlockLegacy* mLog2; // 162
	static BlockLegacy* mAcaciaStairs; // 163
	static BlockLegacy* mDarkOakStairs; // 164
	static BlockLegacy* mSlimeBlock; // 165
	static BlockLegacy* mIronTrapdoor; // 167
	static BlockLegacy* mHayBlock; // 170
	static BlockLegacy* mWoolCarpet; // 171
	static BlockLegacy* mHardenedClay; // 172
	static BlockLegacy* mCoalBlock; // 173
	static BlockLegacy* mPackedIce; // 174
	static BlockLegacy* mDoublePlant; // 175
	static BlockLegacy* mDaylightDetectorInverted; // 178
	static BlockLegacy* mRedSandstone; // 179
	static BlockLegacy* mRedSandstoneStairs; // 180
	static BlockLegacy* mDoubleStoneSlab2; // 181
	static BlockLegacy* mStoneSlab2; // 182
	static BlockLegacy* mSpuceFenceGate; // 183
	static BlockLegacy* mBirchFenceGate; // 184
	static BlockLegacy* mJungleFenceGate; // 185
	static BlockLegacy* mDarkOakFenceGate; // 186
	static BlockLegacy* mAcaciaFenceGate; // 187
	static BlockLegacy* mWoodenDoorSpruce; // 193
	static BlockLegacy* mWoodenDoorBirch; // 194
	static BlockLegacy* mWoodenDoorJungle; // 195
	static BlockLegacy* mWoodenDoorAcacia; // 196
	static BlockLegacy* mWoodenDoorDarkOak; // 197
	static BlockLegacy* mGrassPathBlock; // 198
	static BlockLegacy* mItemFrame; // 199
	static BlockLegacy* mPodzol; // 243
	static BlockLegacy* mBeetrootCrop; // 244
	static BlockLegacy* mStonecutterBench; // 245
	static BlockLegacy* mGlowingObsidian; // 246
	static BlockLegacy* mNetherReactor; // 247
	static BlockLegacy* mInfoUpdateGame1; // 248
	static BlockLegacy* mInfoUpdateGame2; // 249
	static BlockLegacy* mObserver; // 251
	static BlockLegacy* mInfoReserved6; // 255
};

template <typename BlockType,typename...Args>
BlockType* registerBlock(std::string const&name,int id,const Args&...rest)
{
	//std::string const block_name = Util::toLowerCase(name);
	//if(BlockLegacy::mBlockLookupMap.count(block_name)!=0)
		//return (BlockType*)BlockLegacy::mBlocks[id];
	
	BlockType* new_instance = new BlockType(name,id,rest...);
	BlockLegacy::mBlocks[id] = new_instance;
	BlockLegacy::mOwnedBlocks.emplace_back(std::unique_ptr<BlockType>(new_instance));
	//BlockLegacy::mBlockLookupMap.emplace(block_name,(BlockLegacy const*)new_instance);
	return new_instance;
}