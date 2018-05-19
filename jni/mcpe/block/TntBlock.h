#pragma once

#include "BlockLegacy.h"

class TntBlock : public BlockLegacy {
public: 
	TntBlock(const std::string&, int);
	virtual bool shouldDispense(BlockSource&, Container&) const;
	virtual bool dispense(BlockSource&, Container&, int, const Vec3&, signed char) const;
	virtual void onPlace(BlockSource&, const BlockPos&) const;
	virtual void onExploded(BlockSource&, const BlockPos&, Entity*) const;
	virtual void onRedstoneUpdate(BlockSource&, const BlockPos&, int, bool) const;
	virtual void setupRedstoneComponent(BlockSource&, const BlockPos&) const;
	virtual void destroy(BlockSource&, const BlockPos&, const Block&, Entity*) const;
	virtual int getResourceCount(Random&, const Block&, int) const;
	virtual bool use(Player&, const BlockPos&, ItemUseCallback*) const;
};