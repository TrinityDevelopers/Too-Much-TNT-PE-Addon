#pragma once

#include "mcpe/world/level/block/Block.h"

class BlockTNTx5 : public Block {
public:
	BlockTNTx5(std::string, int);

	/*virtual const TextureUVCoordinateSet& getTexture(signed char);
	virtual void neighborChanged(TileSource*, int, int, int, int, int, int);
	virtual int getResourceCount(Random*);
	virtual bool use(Player*, int, int, int);
	virtual void wasExploded(TileSource*, int, int, int);
	virtual void spawnPrimed(TileSource*, int, int, int, int);*/

protected:
	TextureUVCoordinateSet bottomIcon;
	TextureUVCoordinateSet topIcon;
};