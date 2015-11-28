#pragma once
#include "../Mob.h"

namespace RakNet {
	class RakNetGUID;
};
class Tick;
class PacketSender;
class ChestTileEntity;
class FurnaceTileEntity;
class BlockEntity;
class Packet;

class Player : public Mob {
public:
	char filler2[2971];
	bool creativeMode;

public:
	Player(Level &, PacketSender &, bool, const RakNet::RakNetGUID &);
	virtual ~Player();
	virtual void remove();
	virtual void normalTick();
	virtual void rideTick();
	virtual float getRidingHeight();
	virtual bool isInWall();
	virtual float getHeadHeight() const;
	virtual bool isImmobile();
	virtual bool isPushable();
	virtual bool isShootable();
	virtual bool isCreativeModeAllowed();
	virtual void hurt(EntityDamageSource &, int);
	virtual void handleEntityEvent(char);
	virtual void awardKillScore(Entity *, int);
	virtual EntityType getEntityTypeId() const;
	virtual void readAdditionalSaveData(const CompoundTag *);
	virtual void addAdditionalSaveData(CompoundTag *);
	virtual void die(EntityDamageSource &);
	virtual bool isSleeping();
	virtual float getBaseSpeed();
	virtual int getMaxHealth();
	virtual void getArmorValue();
	virtual void travel(float, float);
	virtual void aiStep();
	virtual ItemInstance *getCarriedItem();
	virtual void getItemUseDuration();
	virtual void updateAi();
	virtual float getWalkingSpeedModifier();
	virtual void hurtArmor(int);
	virtual bool useNewAi();
	virtual void tickWorld(const Tick &);
	virtual void moveView();
	virtual void setName(const std::string &);
	virtual void respawn();
	virtual bool hasResource(int);
	virtual void completeUsingItem();
	virtual void drop(const ItemInstance *);
	virtual void drop(const ItemInstance *, bool);
	virtual void startCrafting(int);
	virtual void startStonecutting(int, int, int);
	virtual void startDestroying();
	virtual void stopDestroying();
	virtual void openContainer(ChestTileEntity *);
	virtual void openFurnace(FurnaceTileEntity *);
	virtual void displayChatMessage(const std::string &, const std::string &);
	virtual void displayClientMessage(const std::string &);
	virtual void displayLocalizableMessage(const std::string &, const std::vector<std::string> &);
	virtual void animateRespawn();
	virtual void startSleepInBed(int, int, int);
	virtual void stopSleepInBed(bool, bool);
	virtual void getSleepTimer();
	virtual void openTextEdit(BlockEntity *);
	virtual bool isLocalPlayer();
	virtual void stopLoading();
	virtual void closeContainer();

	ItemInstance *getSelectedItem();
};
