#pragma once

#include <string>
#include <vector>

class TileSource;
class Level;
class PacketSender;
class CompoundTag;
class Entity;
class ItemInstance;
class ChestTileEntity;
class FurnaceTileEntity;
class TileEntity;
class Tile;
class Item;
class TilePos;
class Vec3;
class ItemEntity;
class ChunkSource;
class RakNet {
public:
	class RakNetGUID;
};


class Player {
public:
	// TODO: add my complete Entity struct and make this extend entity... er, Mob.
	char filler[48];
	TileSource& region;
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