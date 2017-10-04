#pragma once

#include "mcpe/block/TntBlock.h"

class BlockTNTx5 : public TntBlock {
public:
	BlockTNTx5(std::string, int);
	virtual bool dispense(BlockSource&, Container&, int, const Vec3&, signed char) const;
	virtual void onExploded(BlockSource&, const BlockPos&, Entity*) const;
	virtual void destroy(BlockSource&, const BlockPos&, int, Entity*) const;
};