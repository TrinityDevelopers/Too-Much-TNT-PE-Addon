#pragma once

#include "BlockLegacy.h"
#include "../nbt/CompoundTag.h"

class BlockPalette;

// 1.2.13.60

class Block {
public:
	unsigned char data;
    const BlockLegacy* block;
    CompoundTag nbt;
    unsigned int runtimeId;

    Block(unsigned char, const BlockLegacy*);
	virtual ~Block();
	virtual BlockRenderLayer getRenderLayer() const;

    static Block* lookupByName(std::string const&, bool);
	static void initBlocks(BlockPalette&);
	static void teardownBlocks();

    static std::unordered_map<std::string,Block const*> mBlockLookupMap;
	static Block* mBlocks[512];

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

/*template <typename BlockType,typename...Args>
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
}*/