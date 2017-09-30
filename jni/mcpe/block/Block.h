#pragma once

#include <memory>
#include <string>
#include <vector>
#include <map>
#include <unordered_map>
#include "BlockID.h"
#include "FullBlock.h"
#include "BlockState.h"
#include "Material.h"
#include "../item/CreativeItemCategory.h"
#include "../math/AABB.h"
#include "../util/Color.h"
#include "../util/Util.h"

class BlockSource;
class BlockPos;
class Entity;
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

// 1.2.0.81

class Block {
public:
    /* 0x04 */ unsigned char blockId;
    /* 0x08 */ std::string descriptionId;
    /* 0x0c */ std::string nameId;
    /* 0x10 */ bool fancy;
    /* 0x11 */ bool canBuildOver;
    /* 0x14 */ BlockRenderLayer renderLayer;
    /* 0x18 */ int properties;
    /* 0x1c */ int idk_i;
	/* 0x20 */ BlockEntityType blockEntityType;
    /* 0x24 */ bool animates;
	/* 0x28 */ float idk_f;
	/* 0x2c */ float thickness;
	/* 0x30 */ bool slideable;
	/* 0x31 */ bool instatick;
	/* 0x32 */ bool isInteraction;
	/* 0x34 */ float gravity;
	/* 0x38 */ Material* material;
    /* 0x3c */ Color mapColor;
    /* 0x4c */ float friction;
    /* 0x50 */ bool heavy;
    /* 0x54 */ float particleQuantity;
	/* 0x58 */ float destroyTime;
	/* 0x5c */ float blastResistance;
	/* 0x60 */ CreativeItemCategory category;
	/* 0x64 */ bool allowsRunes;
    /* 0x65 */ bool idk_b;
    /* 0x68 */ AABB aabb;
	/* 0x84 */ int bitsUsed;
	/* 0x88 */ BlockState blockStates[42];

	// virtual
	virtual ~Block();
	virtual void tick(BlockSource&, const BlockPos&, Random&) const;
	virtual bool getCollisionShape(AABB&, BlockSource&, const BlockPos&, Entity*) const;
	virtual bool isObstructingChests(BlockSource&, const BlockPos&) const;
	virtual Vec3 randomlyModifyPosition(const BlockPos&, int&) const;
	virtual Vec3 randomlyModifyPosition(const BlockPos&) const;
	virtual void addAABBs(BlockSource&, const BlockPos&, const AABB*, std::vector<AABB, std::allocator<AABB> >&) const;
	virtual void getAABB(BlockSource&, const BlockPos&, AABB&, int, bool, int) const;
	virtual void addCollisionShapes(BlockSource&, const BlockPos&, const AABB*, std::vector<AABB, std::allocator<AABB> >&, Entity*) const;
	virtual void getOutline(BlockSource&, const BlockPos&, AABB&) const;
	virtual bool canProvideSupport(BlockSource&, const BlockPos&, signed char, BlockSupportType) const;
	virtual bool isInfiniburnBlock(int) const;
	virtual bool isCropBlock() const;
	virtual bool isStemBlock() const;
	virtual bool isContainerBlock() const;
	virtual bool isCraftingBlock() const;
	virtual bool isInteractiveBlock() const;
	virtual bool isWaterBlocking() const;
	virtual bool isHurtableBlock() const;
	virtual bool isFenceBlock() const;
	virtual bool isStairBlock() const;
	virtual bool isSlabBlock() const;
	virtual bool isRailBlock() const;
	virtual bool canHurtAndBreakItem() const;
	virtual bool isSignalSource() const;
	virtual bool canBeOriginalSurface() const;
	virtual bool isValidAuxValue(int) const;
	virtual bool canFillAtPos(BlockSource&, const BlockPos&, unsigned char) const;
	virtual void sanitizeFillBlock(BlockSource&, const BlockPos&, FullBlock) const;
	virtual void onFillBlock(BlockSource&, const BlockPos&, FullBlock) const;
	virtual int getDirectSignal(BlockSource&, const BlockPos&, int) const;
	virtual bool waterSpreadCausesSpawn() const;
	virtual bool shouldConnectToRedstone(BlockSource&, const BlockPos&, int) const;
	virtual void handleRain(BlockSource&, const BlockPos&, float) const;
	virtual float getThickness() const;
	virtual bool checkIsPathable(Entity&, const BlockPos&, const BlockPos&) const;
	virtual bool shouldDispense(BlockSource&, Container&) const;
	virtual bool dispense(BlockSource&, Container&, int, const Vec3&, signed char) const;
	virtual void onPlace(BlockSource&, const BlockPos&) const;
	virtual void onRemove(BlockSource&, const BlockPos&) const;
	virtual void onExploded(BlockSource&, const BlockPos&, Entity*) const;
	virtual void onStepOn(Entity&, const BlockPos&) const;
	virtual void onFallOn(BlockSource&, const BlockPos&, Entity*, float) const;
	virtual void onRedstoneUpdate(BlockSource&, const BlockPos&, int, bool) const;
	virtual void onMove(BlockSource&, const BlockPos&, const BlockPos&) const;
	virtual bool detachesOnPistonMove(BlockSource&, const BlockPos&) const;
	virtual void onLoaded(BlockSource&, const BlockPos&) const;
	virtual int getRedstoneProperty(BlockSource&, const BlockPos&) const;
	virtual void updateEntityAfterFallOn(Entity&) const;
	virtual void ignoreEntitiesOnPistonMove(unsigned char) const;
	virtual bool onFertilized(BlockSource&, const BlockPos&, Entity*, ItemUseCallback*) const;
	virtual bool mayConsumeFertilizer(BlockSource&) const;
	virtual bool mayPick() const;
	virtual bool mayPick(BlockSource&, int, bool) const;
	virtual bool mayPlace(BlockSource&, const BlockPos&, signed char) const;
	virtual bool mayPlace(BlockSource&, const BlockPos&) const;
	virtual bool mayPlaceOn(const Block&) const;
	virtual bool tryToPlace(BlockSource&, const BlockPos&, unsigned char) const;
	virtual bool breaksFallingBlocks(int) const;
	virtual void destroy(BlockSource&, const BlockPos&, int, Entity*) const;
	virtual bool playerWillDestroy(Player&, const BlockPos&, int) const;
	virtual void getIgnoresDestroyPermissions(Entity&, const BlockPos&) const;
	virtual void neighborChanged(BlockSource&, const BlockPos&, const BlockPos&) const;
	virtual bool getSecondPart(unsigned char, const BlockPos&, BlockPos&) const;
	virtual bool getSecondPart(BlockSource&, const BlockPos&, BlockPos&) const;
	virtual unsigned char getResource(Random&, int, int) const;
	virtual int getResourceCount(Random&, int, int) const;
	virtual ItemInstance asItemInstance(BlockSource&, const BlockPos&, int) const;
	virtual bool spawnResources(BlockSource&, const BlockPos&, int, float, int) const;
	virtual bool spawnBurnResources(BlockSource&, float, float, float);
	virtual float getExplosionResistance(Entity*) const;
	virtual void clip(BlockSource&, const BlockPos&, const Vec3&, const Vec3&, bool, int) const;
	virtual bool use(Player&, const BlockPos&, ItemUseCallback*) const;
	virtual int getPlacementDataValue(Entity&, const BlockPos&, signed char, const Vec3&, int) const;
	virtual int calcVariant(BlockSource&, const BlockPos&, unsigned char) const;
	virtual bool isAttachedTo(BlockSource&, const BlockPos&, BlockPos&) const;
	virtual bool attack(Player*, const BlockPos&) const;
	virtual void handleEntityInside(BlockSource&, const BlockPos&, Entity*, Vec3&) const;
	virtual void entityInside(BlockSource&, const BlockPos&, Entity&) const;
	virtual void playerDestroy(Player&, const BlockPos&, int) const;
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
	virtual int getComparatorSignal(BlockSource&, const BlockPos&, signed char, int) const;
	virtual int getIconYOffset() const;
	virtual std::string buildDescriptionId(unsigned char) const;
	virtual unsigned int getColor(int) const;
	virtual unsigned int getColor(BlockSource&, const BlockPos&) const;
	virtual unsigned int getColor(BlockSource&, const BlockPos&, unsigned char) const;
	virtual unsigned int getColorForParticle(BlockSource&, const BlockPos&, int) const;
	virtual bool isSeasonTinted(BlockSource&, const BlockPos&) const;
	virtual void onGraphicsModeChanged(bool, bool, bool);
	virtual BlockRenderLayer getRenderLayer(BlockSource&, const BlockPos&) const;
	virtual void* getExtraRenderLayers() const;
	virtual AABB const& getVisualShape(BlockSource&, const BlockPos&, AABB&, bool) const;
	virtual AABB const& getVisualShape(unsigned char, AABB&, bool) const;
	virtual int getVariant(int) const;
	virtual signed char getMappedFace(signed char, int) const;
	virtual void animateTick(BlockSource&, const BlockPos&, Random&) const;
	virtual void init();
	virtual bool canBeSilkTouched() const;
	virtual ItemInstance getSilkTouchItemInstance(unsigned char) const;
	virtual void setVisualShape(const AABB&);
	virtual void setVisualShape(const Vec3&, const Vec3&);
	virtual void setLightBlock(Brightness);
	virtual void setLightEmission(float);
	virtual void setExplodeable(float);
	virtual void setDestroyTime(float);
	virtual void setFriction(float);
	virtual void setTicking(bool);
	virtual void setMapColor(const Color&);
	virtual void addProperty(BlockProperty);
	virtual void addBlockState(BlockState::BlockStates, int);
	virtual void resetBitsUsed();
	virtual void setAllowsRunes(bool);
	virtual int getSpawnResourcesAuxValue(unsigned char) const;

    // non virtual
    Block(std::string const&, int, Material const&);
    void setCategory(CreativeItemCategory);
    void setNameId(std::string const&);
    void setSolid(bool);
    bool canSlide() const;
    bool canInstatick() const;
    CreativeItemCategory getCreativeCategory() const;
    float getGravity() const;
    Material* getMaterial() const;
    float getFriction() const;
    float getDestroySpeed() const;
    bool isType(Block const*) const;
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
    BlockRenderLayer getRenderLayer() const;
    int getProperties() const;
    float getShadeBrightness() const;
    void getDebugText(std::vector<std::string>&) const;
    bool canGrowChorus() const;
    void* getTypeToSpawn(BlockSource&, EntityType, BlockPos const&) const;
    void* getMobToSpawn(BlockSource&, BlockPos const&, std::map<EntityType, int>, bool&) const;

    static Block* lookupByName(std::string const&, bool);
	static void initBlocks();
	static void teardownBlocks();
	static float getLightEmission(BlockID);
	static signed char getPlacementFacingAll(Entity&, const BlockPos&, float);
	static BlockID transformToValidBlockId(BlockID);
	static BlockID transformToValidBlockId(BlockID, const BlockPos&);
	static signed char getPlacementFacingAllExceptAxisY(Entity&, const BlockPos&, float);

    static std::unordered_map<std::string,Block const*> mBlockLookupMap;
	static std::vector<std::unique_ptr<Block>> mOwnedBlocks;
	static Block* mBlocks[256];
	static bool mSolid[256];
	static float mTranslucency[256];
	static uint8_t mLightBlock[256];
	static int mLightEmission[256];
	static bool mShouldTick[256];

	static Block* mAir; // 0
	static Block* mStone; // 1
	static Block* mGrass; // 2
	static Block* mDirt; // 3
	static Block* mCobblestone; // 4
	static Block* mWoodPlanks; // 5
	static Block* mSapling; // 6
	static Block* mBedrock; // 7
	static Block* mFlowingWater; // 8
	static Block* mStillWater; // 9
	static Block* mFlowingLava; // 10
	static Block* mStillLava; // 11
	static Block* mSand; // 12
	static Block* mGravel; // 13
	static Block* mGoldOre; // 14
	static Block* mIronOre; // 15
	static Block* mCoalOre; // 16
	static Block* mLog; // 17
	static Block* mLeaves; // 18
	static Block* mSponge; // 19
	static Block* mGlass; // 20
	static Block* mLapisOre; // 21
	static Block* mLapisBlock; // 22
	static Block* mDispenser; // 23
	static Block* mSandStone; // 24
	static Block* mNote; // 25
	static Block* mBed; // 26
	static Block* mGoldenRail; // 27
	static Block* mDetectorRail; // 28
	static Block* mStickyPiston; // 29
	static Block* mWeb; // 30
	static Block* mTallgrass; // 31
	static Block* mDeadBush; // 32
	static Block* mPiston; // 33
	static Block* mPistonArm; // 34
	static Block* mWool; // 35
	static Block* mYellowFlower; // 37
	static Block* mRedFlower; // 38
	static Block* mBrownMushroom; // 39
	static Block* mRedMushroom; // 40
	static Block* mGoldBlock; // 41
	static Block* mIronBlock; // 42
	static Block* mDoubleStoneSlab; // 43
	static Block* mStoneSlab; // 44
	static Block* mBrick; // 45
	static Block* mTNT; // 46
	static Block* mBookshelf; // 47
	static Block* mMossyCobblestone; // 48
	static Block* mObsidian; // 49
	static Block* mTorch; // 50
	static Block* mFire; // 51
	static Block* mMobSpawner; // 52
	static Block* mOakStairs; // 53
	static Block* mChest; // 54
	static Block* mRedStoneDust; // 55
	static Block* mDiamondOre; // 56
	static Block* mDiamondBlock; // 57
	static Block* mWorkBench; // 58
	static Block* mWheatCrop; // 59
	static Block* mFarmland; // 60
	static Block* mFurnace; // 61
	static Block* mLitFurnace; // 62
	static Block* mSign; // 63
	static Block* mWoodenDoor; // 64
	static Block* mLadder; // 65
	static Block* mRail; // 66
	static Block* mStoneStairs; // 67
	static Block* mWallSign; // 68
	static Block* mLever; // 69
	static Block* mStonePressurePlate; // 70
	static Block* mIronDoor; // 71
	static Block* mWoodPressurePlate; // 72
	static Block* mRedStoneOre; // 73
	static Block* mLitRedStoneOre; // 74
	static Block* mUnlitRedStoneTorch; // 75
	static Block* mLitRedStoneTorch; // 76
	static Block* mStoneButton; // 77
	static Block* mTopSnow; // 78
	static Block* mIce; // 79
	static Block* mSnow; // 80
	static Block* mCactus; // 81
	static Block* mClay; // 82
	static Block* mReeds; // 83
	static Block* mFence; // 85
	static Block* mPumpkin; // 86
	static Block* mNetherrack; // 87
	static Block* mSoulSand; // 88
	static Block* mGlowStone; // 89
	static Block* mPortal; // 90
	static Block* mLitPumpkin; // 91
	static Block* mCake; // 92
	static Block* mUnpoweredRepeater; // 93
	static Block* mPoweredRepeater; // 94
	static Block* mInvisibleBedrock; // 95
	static Block* mTrapdoor; // 96
	static Block* mMonsterStoneEgg; // 97
	static Block* mStoneBrick; // 98
	static Block* mBrownMushroomBlock; // 99
	static Block* mRedMushroomBlock; // 100
	static Block* mIronFence; // 101
	static Block* mGlassPane; // 102
	static Block* mMelon; // 103
	static Block* mPumpkinStem; // 104
	static Block* mMelonStem; // 105
	static Block* mVine; // 106
	static Block* mFenceGateOak; // 107
	static Block* mBrickStairs; // 108
	static Block* mStoneBrickStairs; // 109
	static Block* mMycelium; // 110
	static Block* mWaterlily; // 111
	static Block* mNetherBrick; // 112
	static Block* mNetherFence; // 113
	static Block* mNetherBrickStairs; // 114
	static Block* mNetherWart; // 115
	static Block* mEnchantingTable; // 116
	static Block* mBrewingStand; // 117
	static Block* mCauldron; // 118
	static Block* mEndPortalFrame; // 120
	static Block* mEndStone; // 121
	static Block* mUnlitRedStoneLamp; // 123
	static Block* mLitRedStoneLamp; // 124
	static Block* mActivatorRail; // 126
	static Block* mCocoa; // 127
	static Block* mSandStoneStairs; // 128
	static Block* mEmeraldOre; // 129
	static Block* mTripwireHook; // 131
	static Block* mTripwire; // 132
	static Block* mEmeraldBlock; // 133
	static Block* mSpruceStairs; // 134
	static Block* mBirchStairs; // 135
	static Block* mJungleStairs; // 136
	static Block* mCobblestoneWall; // 139
	static Block* mFlowerPot; // 140
	static Block* mCarrotCrop; // 141
	static Block* mPotatoCrop; // 142
	static Block* mWoodButton; // 143
	static Block* mSkull; // 144
	static Block* mAnvil; // 145
	static Block* mTrappedChest; // 146
	static Block* mLightWeightedPressurePlate; // 147
	static Block* mHeavyWeightedPressurePlate; // 148
	static Block* mUnpoweredComparator; // 149
	static Block* mPoweredComparator; // 150
	static Block* mDaylightDetector; // 151
	static Block* mRedstoneBlock; // 152
	static Block* mQuartzOre; // 153
	static Block* mHopper; // 154
	static Block* mQuartzBlock; // 155
	static Block* mQuartzStairs; // 156
	static Block* mDoubleWoodenSlab; // 157
	static Block* mWoodenSlab; // 158
	static Block* mStainedClay; // 159
	static Block* mLeaves2; // 161
	static Block* mLog2; // 162
	static Block* mAcaciaStairs; // 163
	static Block* mDarkOakStairs; // 164
	static Block* mSlimeBlock; // 165
	static Block* mIronTrapdoor; // 167
	static Block* mHayBlock; // 170
	static Block* mWoolCarpet; // 171
	static Block* mHardenedClay; // 172
	static Block* mCoalBlock; // 173
	static Block* mPackedIce; // 174
	static Block* mDoublePlant; // 175
	static Block* mDaylightDetectorInverted; // 178
	static Block* mRedSandstone; // 179
	static Block* mRedSandstoneStairs; // 180
	static Block* mDoubleStoneSlab2; // 181
	static Block* mStoneSlab2; // 182
	static Block* mSpuceFenceGate; // 183
	static Block* mBirchFenceGate; // 184
	static Block* mJungleFenceGate; // 185
	static Block* mDarkOakFenceGate; // 186
	static Block* mAcaciaFenceGate; // 187
	static Block* mWoodenDoorSpruce; // 193
	static Block* mWoodenDoorBirch; // 194
	static Block* mWoodenDoorJungle; // 195
	static Block* mWoodenDoorAcacia; // 196
	static Block* mWoodenDoorDarkOak; // 197
	static Block* mGrassPathBlock; // 198
	static Block* mItemFrame; // 199
	static Block* mPodzol; // 243
	static Block* mBeetrootCrop; // 244
	static Block* mStonecutterBench; // 245
	static Block* mGlowingObsidian; // 246
	static Block* mNetherReactor; // 247
	static Block* mInfoUpdateGame1; // 248
	static Block* mInfoUpdateGame2; // 249
	static Block* mObserver; // 251
	static Block* mInfoReserved6; // 255
};

template <typename BlockType,typename...Args>
BlockType* registerBlock(std::string const&name,int id,const Args&...rest)
{
	//std::string const block_name = Util::toLowerCase(name);
	//if(Block::mBlockLookupMap.count(block_name)!=0)
		//return (BlockType*)Block::mBlocks[id];
	
	BlockType* new_instance = new BlockType(name,id,rest...);
	Block::mBlocks[id] = new_instance;
	Block::mOwnedBlocks.emplace_back(std::unique_ptr<BlockType>(new_instance));
	//Block::mBlockLookupMap.emplace(block_name,(Block const*)new_instance);
	return new_instance;
}