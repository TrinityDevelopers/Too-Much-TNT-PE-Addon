#pragma once
#include <string>
#include <vector>

#include "EntityType.h"
#include "VariantParameterList.h"
#include "../math/Vec3.h"
#include "../client/renderer/entity/EntityRendererId.h"

class Vec3;
class Vec2;
class AABB;
class UIProfanityContext;
enum class MaterialType;
class Player;
class EntityUniqueID;
class Mob;
class EntityDamageSource;
class BlockPos;
class FullBlock;
class Block;
class EntityEvent;
class ItemInstance;
class CompoundTag;
class ArmorSlot;
class EntityLink;
enum class DimensionId;
class SetEntityDataPacket;
class ChangeDimensionPacket;
class LevelSoundEvent;
class EntityInteraction;
class EntityPos;
class EntityDefinitionGroup;
class EntityDefinitionIdentifier;
class EntityDefinitionDescriptor;
class Level;
class BlockSource;

class Entity {
public: 
	class InitializationMethod;

	bool unknown; // 4
	VariantParameterList varList; // 8
	char e_vars[12]; // 36
	EntityDefinitionDescriptor& descriptor; // 48
	char e_vars0[20]; // 52
	Vec3 chunkPos; // 72
	char e_vars1[68]; // 84
	Vec3 pos; // 152;
	char e_vars2[84]; // 164
	EntityRendererId rendererId; // 248

	char e_data[3160];

	Entity(BlockSource&, const std::string&);
	Entity(EntityDefinitionGroup&, const EntityDefinitionIdentifier&);
	Entity(Level&);

	virtual void reloadHardcodedClient(Entity::InitializationMethod, const VariantParameterList&);
	virtual void initializeComponents(Entity::InitializationMethod, const VariantParameterList&);
	virtual void reloadComponents(Entity::InitializationMethod, const VariantParameterList&);
	virtual bool hasComponent(const std::string&) const;
	virtual bool hasInventory() const;
	virtual void getInventory();
	virtual ~Entity();
	virtual void placeholder();
	virtual void reset();
	virtual void getOwnerEntityType();
	virtual void remove();
	virtual void setPos(const Vec3&);
	virtual Vec3 getPos() const;
	virtual void getPosOld() const;
	virtual void getPosExtrapolated(float) const;
	virtual void getVelocity() const;
	virtual void getFiringPos() const;
	virtual void setRot(const Vec2&);
	virtual void move(const Vec3&);
	virtual void getInterpolatedRidingPosition(float) const;
	virtual void getInterpolatedBodyRot(float) const;
	virtual void checkBlockCollisions(const AABB&);
	virtual void checkBlockCollisions();
	virtual void breaksFallingBlocks() const;
	virtual void moveRelative(float, float, float);
	virtual void teleportTo(const Vec3&, int, int);
	virtual void tryTeleportTo(const Vec3&, bool, bool, int, int);
	virtual void lerpTo(const Vec3&, const Vec2&, int);
	virtual void lerpMotion(const Vec3&);
	virtual void getAddPacket();
	virtual void normalTick();
	virtual void baseTick();
	virtual void rideTick();
	virtual void positionRider(Entity&, float) const;
	virtual void getRidingHeight();
	virtual void startRiding(Entity&);
	virtual void addRider(Entity&);
	virtual void flagRiderToRemove(Entity&);
	virtual void intersects(const Vec3&, const Vec3&);
	virtual bool isFree(const Vec3&, float);
	virtual bool isFree(const Vec3&);
	virtual bool isInWall() const;
	virtual bool isInvisible() const;
	virtual bool canShowNameTag();
	virtual bool canExistInPeaceful() const;
	virtual void setNameTagVisible(bool);
	virtual void getNameTag() const;
	virtual void getFormattedNameTag() const;
	virtual void filterFormattedNameTag(const UIProfanityContext&);
	virtual void setNameTag(const std::string&);
	virtual void getAlwaysShowNameTag() const;
	virtual bool isInWater() const;
	virtual bool isInWaterOrRain() const;
	virtual bool isInLava() const;
	virtual bool isUnderLiquid(MaterialType) const;
	virtual bool isOverWater() const;
	virtual void makeStuckInWeb();
	virtual void getCameraOffset() const;
	virtual void getShadowHeightOffs();
	virtual void getShadowRadius() const;
	virtual void getHeadLookVector(float);
	virtual bool canSeeInvisible();
	virtual bool canSee(const Entity&) const;
	virtual bool isSkyLit(float);
	virtual void getBrightness(float) const;
	virtual void interactPreventDefault();
	virtual void playerTouch(Player&);
	virtual void push(Entity&, bool);
	virtual void push(const Vec3&);
	virtual void partialPush(const Vec3&);
	virtual bool isImmobile() const;
	virtual bool isSilent();
	virtual bool isPickable();
	virtual bool isFishable() const;
	virtual bool isPushable() const;
	virtual bool isPushableByPiston() const;
	virtual bool isShootable();
	virtual bool isSneaking() const;
	virtual bool isAlive() const;
	virtual bool isOnFire() const;
	virtual bool isOnMagma() const;
	virtual bool isCreativeModeAllowed();
	virtual bool isSurfaceMob() const;
	virtual bool isTargetable() const;
	virtual void setTarget(Entity*);
	virtual void findAttackTarget();
	virtual void setOwner(EntityUniqueID);
	virtual void setSitting(bool);
	virtual void onTame();
	virtual void onFailedTame();
	virtual void onMate(Mob&);
	virtual void getInventorySize() const;
	virtual void getEquipSlots() const;
	virtual void getChestSlots() const;
	virtual void setStanding(bool);
	virtual bool canPowerJump() const;
	virtual void setCanPowerJump(bool);
	virtual void rideJumped();
	virtual void rideLanded(const Vec3&, const Vec3&);
	virtual bool shouldRender() const;
	virtual bool isInvulnerableTo(const EntityDamageSource&) const;
	virtual void animateHurt();
	virtual void doFireHurt(int);
	virtual void onLightningHit();
	virtual void onBounceStarted(const BlockPos&, const FullBlock&);
	virtual void feed(int);
	virtual void handleEntityEvent(EntityEvent, int);
	virtual void getPickRadius();
	virtual void spawnAtLocation(int, int);
	virtual void spawnAtLocation(int, int, float);
	virtual void spawnAtLocation(FullBlock, int);
	virtual void spawnAtLocation(FullBlock, int, float);
	virtual void spawnAtLocation(const ItemInstance&, float);
	virtual void killed(Entity*);
	virtual void awardKillScore(Entity&, int);
	virtual void setEquippedSlot(ArmorSlot, int, int);
	virtual void setEquippedSlot(ArmorSlot, const ItemInstance&);
	virtual void save(CompoundTag&);
	virtual void saveWithoutId(CompoundTag&);
	virtual void load(const CompoundTag&);
	virtual void loadLinks(const CompoundTag&, std::vector<EntityLink>&);
	virtual EntityType getEntityTypeId() const = 0;
	virtual void acceptClientsideEntityData(Player&, const SetEntityDataPacket&);
	virtual void queryEntityRenderer();
	virtual void getSourceUniqueID() const;
	virtual void setOnFire(int);
	virtual void getHandleWaterAABB() const;
	virtual void handleInsidePortal(const BlockPos&);
	virtual void getPortalCooldown() const;
	virtual void getPortalWaitTime() const;
	virtual void getDimensionId() const;
	virtual bool canChangeDimensions() const;
	virtual void changeDimension(DimensionId, bool);
	virtual void changeDimension(const ChangeDimensionPacket&);
	virtual void getControllingPlayer() const;
	virtual void checkFallDamage(float, bool);
	virtual void causeFallDamage(float);
	virtual void handleFallDistanceOnServer(float, bool);
	virtual void playSynchronizedSound(LevelSoundEvent, const Vec3&, int, bool);
	virtual void onSynchedDataUpdate(int);
	virtual bool canAddRider(Entity&) const;
	virtual bool canBePulledIntoVehicle() const;
	virtual void inCaravan() const;
	virtual bool canBeLeashed();
	virtual bool isLeashableType();
	virtual void tickLeash();
	virtual void sendMotionPacketIfNeeded();
	virtual bool canSynchronizeNewEntity() const;
	virtual void stopRiding(bool, bool);
	virtual void buildDebugInfo(std::string&) const;
	virtual void getCommandPermissionLevel() const;
	virtual void openContainerComponent(Player&);
	virtual void useItem(ItemInstance&) const;
	virtual bool hasOutputSignal(signed char) const;
	virtual void getOutputSignal() const;
	virtual void getDebugText(std::vector<std::string>&);
	virtual void startSeenByPlayer(Player&);
	virtual void stopSeenByPlayer(Player&);
	virtual void getMapDecorationRotation();
	virtual void getRiderDecorationRotation(Player&);
	virtual void getYHeadRot() const;
	virtual bool isWorldBuilder();
	virtual bool isCreative() const;
	virtual bool isAdventure() const;
	virtual void add(ItemInstance&);
	virtual void drop(const ItemInstance&, bool);
	virtual void getInteraction(Player&, EntityInteraction&, const Vec3&);
	virtual bool canDestroyBlock(const Block&) const;
	virtual void setAuxValue(int);
	virtual void setSize(float, float);
	virtual void wobble();
	virtual void setPos(const EntityPos&);
	virtual void outOfWorld();
	virtual void _hurt(const EntityDamageSource&, int, bool, bool);
	virtual void markHurt();
	virtual void lavaHurt();
	virtual void readAdditionalSaveData(const CompoundTag&);
	virtual void addAdditionalSaveData(CompoundTag&);
	virtual void _playStepSound(const BlockPos&, int);
	virtual void _playFlySound(const BlockPos&, int);
	virtual void _makeFlySound() const;
	virtual void checkInsideBlocks(float);
	virtual void pushOutOfBlocks(const Vec3&);
	virtual void updateWaterState();
	virtual void doWaterSplashEffect();
	virtual void spawnTrailBubbles();
	virtual void updateInsideBlock();
	virtual void getLootTable();
	virtual void getDefaultLootTable();
	virtual void _removeRider(Entity&, bool);
	virtual void onSizeUpdated();

	void setPreviousPosRot(const Vec3&, const Vec2&);
	void moveTo(const Vec3&, const Vec2&);
	void updateDescription();
};