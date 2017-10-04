#pragma once

#include <string>
#include <functional>

class ContainerContentChangeListener;
class ItemInstance;
class BlockSource;
class Vec3;
class Player;
class CompoundTag;

class Container {
public: 
	virtual ~Container();
	virtual void addContentChangeListener(ContainerContentChangeListener*);
	virtual void removeContentChangeListener(ContainerContentChangeListener*);
	virtual ItemInstance* getItem(int) const = 0;
	virtual bool hasRoomForItem(ItemInstance&);
	virtual void addItem(ItemInstance&);
	virtual void addItemToFirstEmptySlot(ItemInstance&);
	virtual void setItem(int, ItemInstance*) = 0;
	virtual void removeItem(int, int);
	virtual void dropContents(BlockSource&, const Vec3&, bool);
	virtual void getContainerSize() const = 0;
	virtual void getMaxStackSize() const = 0;
	virtual void startOpen(Player&) = 0;
	virtual void stopOpen(Player&) = 0;
	virtual void getSlotCopies() const;
	virtual void getSlots() const;
	virtual void getItemCount(int, int);
	virtual void getItemCount(const ItemInstance&);
	virtual bool canPushInItem(BlockSource&, int, int, const ItemInstance&) const;
	virtual bool canPullOutItem(BlockSource&, int, int, const ItemInstance&) const;
	virtual void setContainerChanged(int);
	virtual void setContainerMoved();
	virtual void setCustomName(const std::string&);
	virtual bool hasCustomName() const;
	virtual void readAdditionalSaveData(const CompoundTag&);
	virtual void addAdditionalSaveData(CompoundTag&);
	virtual void createTransactionContext(std::function<void (Container&, int, const ItemInstance&, const ItemInstance&)>, std::function<void ()>);
	virtual void triggerTransactionChange(int, const ItemInstance&, const ItemInstance&);
};