#pragma once
#include <string>
#include <vector>
#include <map>
#include <memory>
#include "mcpe/tile/TileTypeEnum.h"
#include "mcpe/tile/RenderLayerEnum.h"
#include "mcpe/tileentity/TileEntityTypeEnum.h"
#include "mcpe/tile/TileID.h"
class LevelSettings;
class Level;
class TileEntity;
class ChestTileEntity;
class FurnaceTileEntity;
class ItemEntity;
class ChunkSource;
class TileSource;
class TextureAtlasTextureItem;
class MinecraftClient;
class IntRectangle;
class CompoundTag;
class EntityPos;
class Player;
class ChunkPos;
class Mob;
class Item;
class LocalPlayer;
class ServerCommandParser;
class Font;
class Random;
class TilePos;
class ItemInstance;
class LevelChunk;
class Color;
class Entity;
class Vec3;
class EntityDamageSource;
class Brightness;
class PacketSender;
class Vec2;
class MobEffect;
class MobEffectInstance;
class EntityLink;
class RakNet {
public:
	class RakNetGUID;
};

enum TextureFile {
	FILE_TERRAIN,
	FILE_ITEM
};

class TextureAtlas {
public:
	TextureAtlas(const std::string &, TextureFile);
	TextureAtlasTextureItem getTextureItem(const std::string &) const;
	void load(MinecraftClient *);
};

class TextureUVCoordinateSet {
public:
	float minU;		// 0
	float minV;		// 4
	float maxU;			// 8
	float maxV;			// 12
	float width;		// 16
	float height;		// 20
	int i1;				// 24
	TextureFile type;	// 28
public:
	TextureUVCoordinateSet(float, float, float, float, float, float, int, TextureFile);
	TextureUVCoordinateSet();
	void fix();
};

class TextureAtlasTextureItem {
public:
	std::string _name;
	int _uvCount;
	std::vector<TextureUVCoordinateSet> _textureUVs;
public:
	TextureAtlasTextureItem(std::string const&, std::vector<TextureUVCoordinateSet> const&);
	TextureAtlasTextureItem();
	void getName() const;
	int uvCount() const;
	TextureUVCoordinateSet operator[](int) const;
};

class TilePos {
public:
	int x;
	int y;
	int z;
public:
	TilePos(const ChunkPos &, int);
	TilePos(const Vec3 &);
	TilePos(float, float, float);
};

class Vec3 {
public:
    float x;
    float y;
    float z;
public:
    Vec3(const TilePos&);
};

class AABB {
public:
    char filler[27];
	AABB(void);
	AABB(const Vec3 &, float);
	AABB(const Vec3 &, const Vec3 &);
	AABB(float, float, float, float, float, float);
	void clip(const Vec3 &, const Vec3 &) const;
	void clipXCollide(const AABB &, float) const;
	void clipYCollide(const AABB &, float) const;
	void clipZCollide(const AABB &, float) const;
	void cloneMove(const Vec3 &) const;
	bool contains(const Vec3 &) const;
	void copy() const;
	void expand(const Vec3 &);
	void expanded(float, float, float);
	void flooredCeiledCopy() const;
	void flooredCopy(float, float) const;
	void getBounds() const;
	void getSize() const;
	void grow(const Vec3 &) const;
	void intersects(const AABB &) const;
	void intersectsInner(const AABB &) const;
	bool isEmpty() const;
	bool isNan() const;
	void merge(const AABB &) const;
	void move(float, float, float);
	void set(const AABB &);
	void set(const Vec3 &, const Vec3 &);
	void set(float, float, float, float, float, float);
	void shrink(const Vec3 &);
	std::string toString() const;
	void translated(const Vec3 &) const;
};

class Material {
public:
	static Material water;
	static Material air;
	static Material leaves;
	static Material vegetable;
	static Material dirt;
	static Material lava;
	static Material replaceable_plant;
	static Material wood;
	static Material stone;
	static Material sand;
	static Material plant;
	static Material cake;
	static Material decoration;
	static Material topSnow;
	static Material cloth;
	static Material glass;
	static Material web;
	static Material metal;
	static Material ice;
	static Material snow;
	static Material clay;
	static Material fire;
	static Material sponge;
	static Material explosive;
	static Material coral;
	static Material cactus;
	static Material portal;
	static Material bed;
};

class Tile {
public:
	// inner classes
	class SoundType {
		SoundType(const std::string &, float, float);
		~SoundType();
	};
	
public:
	static Tile *netherFence, *stairs_netherBricks, *stairs_sandStone, *quartzBlock, *mycelium, *brownMushroomBlock, *redMushroomBlock, *emeraldBlock, *redStoneDust, *waterlily, *emeraldOre;
	static Tile *woodStairsJungle, *woodStairsBigOak, *woodStairsAcacia, *deadBush, *leaves2, *log2, *stairs_stoneBrickSmooth, *netherBrick, *netherrack, *ironFence, *stairs_quartz, *stainedClay;
	static Tile *pumpkin, *litPumpkin, *info_updateGame1, *carrots, *potatoes, *beetroot, *netherReactor, *glowingObsidian, *woodStairsDark, *woodStairsBirch, *hayBlock, *coalBlock, *woolCarpet;
	static Tile *stoneBrickSmooth, *fenceGateOak, *fenceGateSpruce, *fenceGateBirch, *fenceGateJungle, *fenceGateBigOak, *fenceGateAcacia, *info_updateGame2, *info_reserved6, *cobbleWall;
	static Tile *stairs_stone, *stairs_brick, *door_wood, *door_iron, *cactus, *rail, *goldenRail, *activatorRail, *melon, *pumpkinStem, *melonStem, *bed, *tallgrass, *trapdoor, *monsterStoneEgg;
	static Tile *water, *lava, *fire, *invisible_bedrock, *goldBlock, *ironBlock, *diamondBlock, *workBench, *stonecutterBench, *crops, *furnace, *furnace_lit, *chest, *lightGem, *stairs_wood, *fence;
	static Tile *redStoneOre, *redStoneOre_lit, *goldOre, *ironOre, *coalOre, *lapisOre, *lapisBlock, *reeds, *ladder, *obsidian, *tnt, *bookshelf, *sign, *wallSign, *mossStone, *torch, *mobSpawner;
	static Tile *sandStone, *sand, *stoneSlab, *stoneSlabHalf, *woodSlab, *woodSlabHalf, *cloth, *yellowFlower, *redFlower, *brownMushroom, *redMushroom, *topSnow, *log, *snow, *leaves, *diamondOre;
	static Tile *calmLava, *calmWater, *thinGlass, *web, *glass, *sponge, *sapling, *wood, *redBrick, *farmland, *clay, *ice, *grass, *podzol, *dirt, *unbreakable, *rock, *gravel, *stoneBrick, *endStone;
	static Tile *hardenedClay, *doublePlant;

	static SoundType SOUND_SILENT, SOUND_SAND, SOUND_CLOTH, SOUND_GLASS, SOUND_METAL, SOUND_STONE, SOUND_GRASS, SOUND_GRAVEL, SOUND_WOOD, SOUND_NORMAL;

	static bool shouldTick[256];
	static float translucency[256];
	static bool solid[256];
	static float lightEmission[256];
	static int lightBlock[256];
	static Tile *tiles[256];
	static TextureAtlas *_terrainTextureAtlas;
	static const char *TILE_DESCRIPTION_PREFIX;

public:
	// Size : 140
	//void **vtable;		// 0
	/*char filler1[56];					//4
	bool _replaceable;					//56
	AABB shape;			//64
	char filler0[24];
	TextureUVCoordinateSet tex;*/ //28
	char filler1[64];
	const TileID id;			//68
	const SoundType* soundType;			//72
	RenderLayer renderLayer;			//76
	bool canBuildOver;					//80
	int renderShape;					//84
	/*TileType tileType;					//88
	TileEntityType tileEntityType;		//92
	float thickness;					//96
	bool canSlide;						//100
	bool canInstatick;					//104
	float gravity;						//108
	const Material* material;			//112
	float friction;						//116
	float destroyTime;					//120
	float explosionResistance;			
	int creativeCategory;				//124
	bool fancy;							//128
	char filler2[4];		//std::shared_ptr<TextureAtlas> _terrainTextureAtlas;  //132
	unsigned int faceTextureIsotropic;	//136
	std::string descriptionId;*/			//140
	char filler4[56];
public:
	Tile(int, Material const*);
	Tile(int, TextureUVCoordinateSet, Material const*);
	Tile(int, std::string const&, Material const*);
	virtual ~Tile(); // 2
	virtual void onFertilized(TileSource*, int, int, int); // 3
	virtual void getShape(TileSource*, int, int, int, AABB&, bool); // 4
	virtual void getShape(unsigned char, AABB&, bool); // 5
	virtual bool isObstructingChests(TileSource*, int, int, int); // 6
	virtual void shouldRenderFace(TileSource*, int, int, int, signed char, AABB const&) const; // 7
	virtual TextureUVCoordinateSet& getTexture(signed char) const; // 9
	virtual TextureUVCoordinateSet& getTexture(signed char, int) const; // 10
	virtual void getTexture(TileSource*, int, int, int, signed char); // 11
	virtual void getTessellatedUVs(); // 12
	virtual void getCarriedTexture(signed char, int); // 13
	virtual AABB *getAABB(TileSource*, int, int, int, AABB&, int, bool, int); // 14
	virtual void addAABBs(TileSource*, int, int, int, AABB const*, std::vector<AABB, std::allocator<AABB> >&); // 15
	virtual void getTileAABB(TileSource*, int, int, int, AABB&); // 16
	virtual bool isPathfindable(TileSource*, int, int, int); // 17
	virtual bool mayPick(); // 18
	virtual bool mayPick(int, bool); // 19
	virtual bool mayPlace(TileSource*, int, int, int, signed char); // 20
	virtual bool mayPlace(TileSource*, int, int, int); // 21
	virtual void getTickDelay(); // 22
	virtual void tick(TileSource*, int, int, int, Random*); // 23
	virtual void animateTick(TileSource*, int, int, int, Random*); // 24
	virtual void destroy(TileSource*, int, int, int, int); // 25
	virtual void playerWillDestroy(Player*, int, int, int, int); // 26
	virtual void neighborChanged(TileSource*, int, int, int, int, int, int); // 27
	virtual void onPlace(TileSource*, int, int, int); // 28
	virtual void onRemove(TileSource*, int, int, int); // 29
	virtual void getSecondPart(TileSource&, TilePos const&, TilePos&); // 30
	virtual void onGraphicsModeChanged(bool, bool); // 31
	virtual void getResource(int, Random*); // 32
	virtual int getResourceCount(Random*); // 33
	virtual void getDestroyProgress(Player*); // 34
	virtual void spawnResources(TileSource*, int, int, int, int, float); // 35
	virtual void spawnBurnResources(TileSource*, float, float, float); // 36
	virtual float getExplosionResistance(Entity*); // 37
	virtual void clip(TileSource*, int, int, int, Vec3 const&, Vec3 const&, bool, int); // 38
	virtual void wasExploded(TileSource*, int, int, int); // 39
	virtual bool use(Player*, int, int, int); // 40
	virtual void stepOn(Entity*, int, int, int); // 41
	virtual void fallOn(TileSource*, int, int, int, Entity*, float); // 42
	virtual void getPlacementDataValue(Mob*, int, int, int, signed char, float, float, float, int); // 43
	virtual void prepareRender(TileSource*, int, int, int); // 44
	virtual void attack(Player*, int, int, int); // 45
	virtual void handleEntityInside(TileSource*, int, int, int, Entity*, Vec3&); // 46
	virtual int getColor(int); // 47
	virtual int getColor(TileSource*, int, int, int); // 48
	virtual bool isSignalSource(); // 49
	virtual int getSignal(TileSource*, int, int, int); // 50
	virtual int getSignal(TileSource*, int, int, int, int); // 51
	virtual int getDirectSignal(TileSource*, int, int, int, int); // 52
	virtual bool entityInside(TileSource*, int, int, int, Entity*); // 53
	virtual void playerDestroy(Player*, int, int, int, int); // 54
	virtual bool canSurvive(TileSource*, int, int, int); // 55
	virtual void setNameId(std::string const&);
	virtual std::string getName(ItemInstance const*) const; // 56
	virtual void triggerEvent(TileSource*, int, int, int, int, int); // 61
	virtual TextureUVCoordinateSet getTextureNum(int); // 62
	virtual void getMobToSpawn(TileSource&, TilePos const&) const; // 63
	virtual int getIconYOffset() const; // 64
	virtual void setShape(float, float, float, float, float, float); // 65
	virtual void setSoundType(Tile::SoundType const&); // 66
	virtual void setLightBlock(Brightness); // 67
	virtual void setLightEmission(float); // 68
	virtual void setExplodeable(float); // 69
	virtual void setDestroyTime(float); // 70
	virtual void setTicking(bool); // 71
	virtual void getSpawnResourcesAuxValue(int); // 72
	virtual void init(); // 73
	static void initTiles();
	static Material *getTileMaterial(int);
	static float getLightEmission(TileID);
	static int getIDByName(const std::string &, bool);
	void _getTypeToSpawn(TileSource &, int, const TilePos &) const;
	void addAABB(const AABB &, const AABB *, std::vector<AABB> &);
	void setCategory(int);
	TextureAtlasTextureItem getTextureItem(const std::string &);
	float getShadeBrightness() const;
	TextureUVCoordinateSet getTextureUVCoordinateSet(const std::string &, int);
};

class ItemInstance {
public:
    int count;
	int auxValue;
	Item* item;
	Tile* tile;
	bool valid;
public:
	ItemInstance();
	ItemInstance(int, int, int);
	ItemInstance(bool);
	ItemInstance(const ItemInstance &);
	ItemInstance(const Tile *);
	ItemInstance(const Tile *, int);
	ItemInstance(const Tile *, int, int);
	ItemInstance(const Item *);
	ItemInstance(const Item *, int);
	ItemInstance(const Item *, int, int);
	void _setItem(int);
	void add(int);
	void canDestroySpecial(Tile *);
	ItemInstance *clone(const ItemInstance *);
	ItemInstance *cloneSafe(const ItemInstance *);
	void fromTag(CompoundTag *);
	int getAttackDamage(Entity *);
	int getAuxValue() const;
	int getDamageValue() const;
	int getDestroySpeed(Tile *);
	void getIcon(int, bool) const;
	int getId() const;
	int getIdAux() const;
	int getMaxDamage() const;
	int getMaxStackSize() const;
	int getMaxUseDuration() const;
	std::string getName() const;
	int getUseAnimation() const;
	void hurtAndBreak(int, Mob *);
	void hurtEnemy(Mob *, Mob *);
	void init(int, int, int);
	void interactEnemy(Mob *, Player *);
	bool isArmorItem(const ItemInstance *);
	bool isDamageableItem() const;
	bool isDamaged() const;
	bool isItem(const ItemInstance *);
	bool isLiquidClipItem();
	bool isNull() const;
	bool isStackable(const ItemInstance *, const ItemInstance *);
	bool isStackable() const;
	bool isStackedByData() const;
	void load(CompoundTag *);
	bool matches(const ItemInstance *) const;
	bool matches(const ItemInstance *, const ItemInstance *);
	bool matchesNulls(ItemInstance const *, const ItemInstance *);
	void mineBlock(int, int, int, int, Mob *);
	bool operator==(const ItemInstance &) const;
	void releaseUsing(Player *, int);
	void remove(int);
	void sameItemAndAux(ItemInstance *) const;
	void save();
	void setAuxValue(int);
	void setDescriptionId(const std::string &);
	void setNull();
	void snap(Player *);
	std::string toString() const;
	void use(Player &);
	void useAsFuel();
	void useOn(Player *, int, int, int, signed char, float, float, float);
	void useTimeDepleted(Level *, Player *);
};

class Gui {
public:
    char filler[2848];
	Gui(MinecraftClient &);
	void addMessage(const std::string &, const std::string &, int);
	void clearMessages();
	void cubeSmoothStep(float, float, float);
	void displayClientMessage(const std::string &);
	void floorAlignToScreenPixel(float);
	void flashSlot(int slot);
	void setNowPlaying(const std::string &);
	void showPopupNotice(const std::string &);
	void showTipMessage(const std::string &);
	void handleKeyPressed(int);
	void handleClick(int, int, int);
	int getNumSlots();
	void getRectangleArea(int);
	int getSlotIdAt(int, int);
	int getSlotPos(int, int &, int &);
	int itemCountItoa(char *, int);
	void inventoryUpdated();
	void onLevelGenerated();
	bool isInside(int, int);
	void postError(int);
	void processLeftShoulder(int);
	void processRightShoulder(int);
	void render(float, bool, int, int);
	void renderToolBar(float, float);
	void renderProgressIndicator(bool, int, int, float);
	void renderSleepAnimation(int, int);
	void renderSlot(int, int, int, float);
	void renderSlotText(const ItemInstance *, float, float, bool, bool, bool);
	void renderHearts();
	void renderBubbles();
	void renderVignette(float, int, int);
	void renderChatMessages(int, int, unsigned int, bool, Font *);
	void renderOnSelectItemNameText(int, Font *, int);
	void tick();
	void tickItemDrop();
};

class Entity {
public:
    char filler1[80];
    float motionX;
    float motionY;
    float motionZ;
    float yaw;
    float pitch;
    char filler2[171];
    bool fireImmune;
    char filler3[6];
public:
	Entity(Level &);
	Entity(TileSource &);
	virtual ~Entity();
	virtual void reset();
	virtual void remove();
	virtual void setPos(float, float, float);
	virtual void setPos(const Vec3 &);
	virtual void getPos();
	virtual void getPosOld();
	virtual void getPosExtrapolated(float);
	virtual void getVelocity();
	virtual void setRot(float, float);
	virtual void move(float, float, float);
	virtual void moveTo(float, float, float, float, float);
	virtual void moveRelative(float, float, float);
	virtual void lerpTo(float, float, float, float, float, int);
	virtual void lerpMotion(float, float, float);
	virtual void turn(float, float);
	virtual void interpolateTurn(float, float);
	virtual void normalTick();
	virtual void baseTick();
	virtual void rideTick();
	virtual void positionRider(bool);
	virtual float getRidingHeight();
	virtual float getRideHeight();
	virtual void getRideUseAnimation();
	virtual void startRiding(Entity *);
	virtual void addRider(Entity *);
	virtual void removeRider(Entity *);
	virtual void intersects(float, float, float, float, float, float, float);
	virtual bool isFree(float, float, float, float);
	virtual bool isFree(float, float, float);
	virtual bool isInWall();
	virtual bool isInWater();
	virtual bool isInWaterOrRain();
	virtual bool isInLava();
	virtual bool isUnderLiquid(const Material *) const;
	virtual float getShadowRadius();
	virtual void makeStuckInWeb();
	virtual float getHeadHeight();
	virtual float getShadowHeightOffs();
	virtual bool isSkyLit(float);
	virtual int getBrightness(float);
	virtual void interactPreventDefault();
	virtual void interactWithPlayer(Player *);
	virtual bool canInteractWith(Player *);
	virtual std::string getInteractText(Player *);
	virtual void playerTouch(Player *);
	virtual void push(Entity *);
	virtual void push(float, float, float);
	virtual bool isPickable();
	virtual bool isPushable();
	virtual bool isShootable();
	virtual bool isSneaking();
	virtual bool isAlive();
	virtual bool isOnFire() const;
	virtual bool isCreativeModeAllowed();
	virtual bool isSurfaceMob();
	virtual void shouldRenderAtSqrDistance(float);
	virtual void hurt(Entity *, int);
	virtual void animateHurt();
	virtual void doFireHurt();
	virtual void handleEntityEvent(char);
	virtual void getPickRadius();
	virtual void spawnAtLocation(int, int);
	virtual void spawnAtLocation(int, int, float);
	virtual void spawnAtLocation(const ItemInstance &, float);
	virtual void awardKillScore(Entity *, int);
	virtual void setEquippedSlot(int, int, int);
	virtual void save(CompoundTag &);
	virtual void saveWithoutId(CompoundTag &);
	virtual void load(CompoundTag &);
	virtual void loadLinks(CompoundTag const&, std::vector<EntityLink, std::allocator<EntityLink>> &);
	virtual int getEntityTypeId() const;
	virtual void queryEntityRenderer();
	virtual bool isItemEntity();
	virtual bool isHangingEntity();
	virtual int getOwnerID();
	virtual void getHandleWaterAABB();
	virtual void getControllingPlayer();
	virtual void setSize(float, float);
	virtual void setPos(EntityPos *);
	virtual void outOfWorld();
	virtual void checkFallDamage(float, bool);
	virtual void causeFallDamage(float);
	virtual void markHurt();
	virtual void burn(int);
	virtual void lavaHurt();
	virtual void readAdditionalSaveData(CompoundTag *) = 0;
	virtual void addAdditionalSaveData(CompoundTag *) = 0;
	virtual void playStepSound(int, int, int, int);
	virtual void checkInsideTiles();
	virtual void onTileCollision(int);
	virtual void playSound(const std::string, float);
	virtual void onSynchedDataUpdate(int);
	virtual void canAddRider(Entity *);
	virtual void stopRiding(bool);
	void _findRider(Entity &);
	void _init();
	void _manageRider(Entity &);
	void _sendLinkPacket(EntityLink const&);
	void _tryPlaceAt(Vec3 const&);
	void _updateOwnerChunk();
	float getInterpolatedPosition(float);
	float getInterpolatedPosition2(float);
	float getInterpolatedRotation(float);
	void getRandomPointInAABB(Random &);
	float getRotation();
	void getUniqueID();
	void saveAsMount(CompoundTag &);
	bool isControlledByLocalInstance() const;
	bool isInClouds() const;
	bool isInstanceOf(int);
	bool isMob() const;
	bool isRide() const;
	bool isRider(Entity &) const;
	bool isRiding() const;
	bool operator==(Entity &);
};

class Mob : public Entity {
public:
    Mob(Level &);
	Mob(TileSource &);
	virtual ~Mob();
	virtual void lerpTo(Vec3 const&, Vec2 const&, int);
	virtual void normalTick();
	virtual void baseTick();
	virtual void rideTick();
	virtual float getHeadHeight();
	virtual bool isPickable();
	virtual bool isPushable();
	virtual bool isShootable();
	virtual bool isSneaking();
	virtual bool isAlive();
	virtual bool isOnFire() const;
	virtual void hurt(Entity *, int);
	virtual void animateHurt();
	virtual void doFireHurt(int);
	virtual void handleEntityEvent(char);
	virtual void setSize(float, float);
	virtual void outOfWorld();
	virtual void causeFallDamage(float);
	virtual void readAdditionalSaveData(CompoundTag *);
	virtual void addAdditionalSaveData(CompoundTag *);
	virtual void postInit(void);
	virtual void knockback(Entity *, int, float, float);
	virtual void die(EntityDamageSource *);
	virtual bool canSee(Entity *);
	virtual void onLadder();
	virtual void spawnAnim();
	virtual void *getTexture(); 
	virtual bool isSleeping();
	virtual bool isWaterMob();
	virtual void setSneaking(bool);
	virtual float getVoicePitch();
	virtual int getMobType();
	virtual void playAmbientSound();
	virtual int getAmbientSoundInterval();
	virtual void *getItemInHandIcon(const ItemInstance *, int); 
	virtual float getBaseSpeed() = 0;
	virtual float getJumpPower();
	virtual void superTick();
	virtual void heal(int);
	virtual int getMaxHealth();
	virtual void actuallyHurt(int, EntityDamageSource*);
	virtual float getArmorValue();
	virtual bool isInvertedHealAndHarm();
	virtual void pick(float, float, bool);
	virtual void travel(float, float);
	virtual void updateWalkAnim();
	virtual void aiStep();
	virtual void pushEntities();
	virtual void lookAt(Entity *, float, float);
	virtual bool isLookingAtAnEntity();
	virtual void beforeRemove();
	virtual bool canSpawn();
	virtual void finalizeMobSpawn();
	virtual bool shouldDespawn();
	virtual float getAttackAnim(float);
	virtual bool isBaby();
	virtual bool isTamable();
	virtual ItemInstance *getCarriedItem();
	virtual int getUseItemDuration();
	virtual void swing();
	virtual void ate();
	virtual float getMaxHeadXRot();
	virtual Mob *getLastHurtByMob();
	virtual void setLastHurtByMob(Mob *);
	virtual Entity *getLastHurtMob();
	virtual void setLastHurtMob(Entity *);
	virtual Mob *getTarget();
	virtual void setTarget(Mob *);
	virtual bool isAlliedTo(Mob *);
	virtual void doHurtTarget(Entity *);
	virtual bool canBeControlledByRider();
	virtual void teleportTo(float, float, float);
	virtual bool removeWhenFarAway();
	virtual Item *getDeathLoot();
	virtual void dropDeathLoot();
	virtual bool isImmobile();
	virtual void jumpFromGround();
	virtual void updateAi();
	virtual void newServerAiStep();
	virtual void serverAiMobStep();
	virtual float getSoundVolume();
	virtual const char *getAmbientSound();
	virtual std::string getHurtSound();
	virtual std::string getDeathSound();
	virtual float getWalkingSpeedModifier();
	virtual int getDamageAfterArmorAbsorb(int);
	virtual int getDamageAfterMagicAbsorb(int);
	virtual void hurtArmor(int);
	virtual bool useNewAi();
	virtual bool canBeAffected(const MobEffectInstance*);
	virtual void onEffectAdded(const MobEffectInstance*);
	virtual void onEffectUpdated(const MobEffectInstance*);
	virtual void onEffectRemoved(const MobEffectInstance*);
	void _init();
	void _ctor();
	void addEffect(const MobEffectInstance&);
	bool canShowNameTag();
	bool checkDespawn();
	bool checkDespawn(Mob *);
	void *getAllEffects(); 
	void *getEffect(MobEffect*);
	void *getMoveControl(); 
	void *getNavigation(); 
	void *getWalkingSpeedEffect();
	bool getSensing();
	bool getSharedFlag(int) const;
	float getSpeed();
	float getYHeadRot();
	bool hasAnyEffects();
	bool hasEffect(MobEffect*);
	bool interpolateOnly();
	void removeAllEffects();
	void removeEffect(int);
	void removeEffectNoUpdate(int);
	void removeEffectParticles();
	void setJumping(bool);
	void setSharedFlag(int, bool);
	void setSpeed(float);
	void setYHeadRot(float);
	void setYya(float);
	void tickEffects();
	void updateMobId(int *);
};

class Player : public Mob {
public:
	char filler[8];
	TileSource* _tileSource;
    char filler1[3384];
public:
	Player(Level &, PacketSender &, bool, RakNet::RakNetGUID const&);
	virtual ~Player();
	virtual void remove();
	virtual void normalTick();
	virtual void rideTick();
	virtual float getRidingHeight();
	virtual void ride(Entity *);
	virtual bool isInWall();
	virtual float getHeadHeight();
	virtual bool isPushable();
	virtual bool isShootable();
	virtual bool isCreativeModeAllowed();
	virtual void hurt(Entity *, int);
	virtual void handleEntityEvent(char);
	virtual void awardKillScore(Entity *, int);
	virtual int getEntityTypeId() const;
	virtual void readAdditionalSaveData(CompoundTag *);
	virtual void addAdditionalSaveData(CompoundTag *);
	virtual void die(Entity *);
	virtual bool isSleeping();
	virtual float getBaseSpeed();
	virtual int getMaxHealth();
	virtual float getArmorValue();
	virtual void travel(float, float);
	virtual void aiStep();
	virtual ItemInstance *getCarriedItem();
	virtual int getItemUseDuration();
	virtual bool isImmobile();
	virtual void updateAi();
	virtual float getWalkingSpeedModifier();
	virtual void hurtArmor(int);
	virtual bool useNewAi();
	virtual void tickWorld(void *); 
	virtual void moveView();
	virtual void respawn();
	virtual bool hasResource(int);
	virtual void completeUsingItem();
	virtual void drop(const ItemInstance *);
	virtual void drop(const ItemInstance *, bool);
	virtual void startCrafting(int, int, int, int);
	virtual void startStonecutting(int, int, int);
	virtual void startDestroying();
	virtual void stopDestroying();
	virtual void openContainer(ChestTileEntity *);
	virtual void openFurnace(FurnaceTileEntity *);
	virtual void displayChatMessage(const std::string &, const std::string &);
	virtual void displayClientMessage(const std::string &);
	virtual void displayLocalizableMessage(std::string const&, std::vector<std::string, std::allocator<std::string>> const&);
	virtual void animateRespawn();
	virtual void startSleepInBed(int, int, int);
	virtual void stopSleepInBed(bool, bool);
	virtual void *getSleepTimer(); 
	virtual void openTextEdit(TileEntity *);
	virtual bool isLocalPlayer();
	virtual void closeContainer();
	void _init();
	void _findNearSpawnPosition(const Vec3 &);
	void _fixSpawnPosition(const Vec3 &);
	void animateRespawn(Player *, Level *);
	int getScore();
	bool checkBed();
	bool canUseCarriedItemWhileMoving();
	bool canDestroy(Tile *);
	void updateTeleportDestPos();
	void touch(Entity *);
	void interact(Entity *);
	void tileEntityDestroyed(int);
	float getDestroySpeed(Tile *);
	ItemInstance *getSelectedItem();
	Item *getTicksUsingItem();
	Item *getItemInUse();
	void startUsingItem(ItemInstance, int);
	void stopUsingItem();
	void releaseUsingItem();
	bool isUsingItem();
	bool isHurt();
	bool isSleepingLongEnough();
	std::string getArmorTypeHash();
	void spawnEatParticles(const ItemInstance *, int);
	void setRespawnPosition(const TilePos &);
	void settTeleportDestPos(const Vec3 &);
	void setDefaultHeadHeight();
	void setBedOffset(int);
	void setArmor(int, const ItemInstance *);
	void setAllPlayersSleeping();
	float getSleepRotation();
	void resetPos(bool);
	void reallyDrop(ItemEntity *);
	void prepareRegion(ChunkSource &);
	float getViewRadius() const;
	void *hasRespawnPosition() const; 
	void *getStandingPositionOnBlock(const TilePos &); 
	void *getSpawnPosition(); 
};

class Minecraft {
public:
	Minecraft(int, char **);
	virtual ~Minecraft();
	virtual void update();
	virtual void init();
	virtual void teardown();
	virtual void selectLevel(const std::string &, const std::string &, const LevelSettings &);
	virtual void setLevel(std::unique_ptr<Level> &, const std::string &, Player *);
	virtual void startFrame();
	virtual void updateGraphics();
	virtual void endFrame();
	virtual void tick(int, int);
	virtual void leaveGame(bool, bool);
	virtual void play(const std::string &, float, float, float, float, float);
	virtual void playUI(const std::string &, float, float);
	virtual void updateSoundLocation(Mob *, float);
	virtual void isServerVisible();
	virtual void sendLocalMessage();
	virtual LocalPlayer *getPlayer();
	virtual void onInternetUpdate();
	virtual void onPlayerLoaded(Player &);
	virtual void vibrate(int);
	void init(const std::string &);
	void hostMultiplayer(int);
	void cancelLocateMultiplayer();
	void *getLevelSource();
	ServerCommandParser *getCommandParser();
	const char *getCreator();
	std::string getServerName();
	bool isCreativeMode();
	void setIsCreativeMode(bool);
	void setLeaveGame();
	void removeAllPlayers();
	bool isOnline();
	bool isOnlineClient();
	void updateStats();
};

class Item {
public:
	static Item* flintAndSteel;
public:
    int _maxStackSize;
	std::string _textureAtlasFile;
	int _frameCount;
	bool _animatesInToolbar;
	const int id;
	int maxDamage;
	int creativeCategory;
	bool _handEquipped;
	bool _isStackedByData;
	Item* craftingRemainingItem;
	std::string descriptionId;

	char filler_item[76];
public:
    static Item* items[256];
    static TextureAtlas *_itemTextureAtlas;
	Item(int);
	virtual ~Item();
	virtual int getMaxStackSize(const ItemInstance *);
	virtual void setMaxStackSize(unsigned char);
	virtual bool canBeDepleted();
	virtual TextureUVCoordinateSet getIcon(int, int, bool) const;
	virtual float getIconYOffset() const;
	virtual void setIcon(const std::string &, int);
	virtual void setIcon(TextureUVCoordinateSet);
	virtual bool isMirroredArt() const;
	virtual ItemInstance &use(ItemInstance &, Player &);
	virtual bool useOn(ItemInstance *, Player *, int, int, int, signed char, float, float, float);
	virtual int getMaxUseDuration() const;
	virtual void useTimeDepleted(ItemInstance *, Level *, Player *);
	virtual int getUseAnimation() const;
	virtual void releaseUsing(ItemInstance *, Player *, int);
	virtual float getDestroySpeed(ItemInstance *, Tile *);
	virtual bool canDestroySpecial(const Tile *) const;
	virtual int getLevelDataForAuxValue(int) const;
	virtual bool isStackedByData() const;
	virtual int getMaxDamage();
	virtual int getAttackDamage(Entity *);
	virtual void hurtEnemy(ItemInstance *, Mob *, Mob *);
	virtual void interactEnemy(ItemInstance *, Mob *, Player *);
	virtual bool mineBlock(ItemInstance *, int, int, int, int, Mob *);
	virtual void handEquipped();
	virtual bool isHandEquipped() const;
	virtual bool isFood() const;
	virtual bool isSeed() const;
	virtual bool isArmor() const;
	virtual bool isDye() const;
	virtual bool isLiquidClipItem(int) const;
	virtual bool requiresInteract() const;
	virtual std::string getInteractText() const;
	virtual std::string getName(const ItemInstance *) const;
	virtual void setNameID(const std::string &);
	virtual bool isEmissive(int) const;
	virtual void *getAnimationFrameFor(Mob &) const; 
	static void addCreativeItem(short,short);
	static void addCreativeItem(Tile *,short);
	static void addCreativeItem(Item *,short);
	static void initCreativeItems();
	static void initItems();
	static TextureAtlasTextureItem getTextureItem(const std::string &);
	static TextureUVCoordinateSet getTextureUVCoordinateSet(const std::string &, int);
	static ItemInstance getIDByName(const std::string &, bool);
	void setCategory(int);
	void setStackedByData(bool);
	void setMaxDamage(int);
};


class TileItem : public Item {
public:
	char filler[84 - 76];
	TileItem(int);
	virtual TextureUVCoordinateSet getIcon(int, int, bool) const;
	virtual float getIconYOffset() const;
	virtual bool useOn(ItemInstance *, Player *, int, int, int, signed char, float, float, float);
	virtual std::string getDescriptionId() const;
	virtual std::string getDescriptionId(const ItemInstance *) const;
	virtual bool isEmissive(int) const;
};

class BowItem : public Item {
public:
    char filler[172- 76];
    BowItem(int);
    virtual ~BowItem();
    virtual TextureUVCoordinateSet getIcon(int, int, bool) const;
    virtual int getMaxUseDuration() const;
    virtual int getUseAnimation() const;
    virtual ItemInstance &use(ItemInstance&, Player&);
    virtual float _getLaunchPower(int) const;
    virtual void *getAnimationFrameFor(Mob &) const;
    virtual void releaseUsing(ItemInstance *, Player *, int);
};

class ArmorItem : public Item {
public:
    class ArmorMaterial {
	public:
	    ArmorMaterial(int, int, int, int, int);
		int getHealthForSlot(int) const;
		int getDefenseForSlot(int) const;
    };
    ArmorItem(int, const ArmorMaterial&, int, int);
	virtual ~ArmorItem();
    virtual bool isArmor() const;
};

class ItemPack
{
public:
	std::map<int, int> items;
};

class Recipe
{
public:
	ItemPack myItems;
};

class Recipes
{
public:

	std::vector<Recipe*> recipes;
	class Type
	{
	public:
		Item* item;
		Tile* tile;
		ItemInstance itemInstance;
		char c;
	};

	static Recipes* getInstance();
	void addShapedRecipe(ItemInstance const&, std::vector<std::string> const&, std::vector<Recipes::Type> const&);
};