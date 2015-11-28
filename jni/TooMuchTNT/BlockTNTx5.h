#pragma once

#include "mcpe/world/level/block/Block.h"

class BlockTNTx5 : public Block {
public:
	BlockTNTx5(std::string, int);

	virtual const TextureUVCoordinateSet& getTexture(signed char);
	virtual int getResourceCount(Random&, int, int);
	virtual bool use(Player&, const BlockPos&);
	//virtual void wasExploded(TileSource*, int, int, int);

protected:
	TextureUVCoordinateSet bottomIcon;
	TextureUVCoordinateSet topIcon;
};