#ifndef BLOCKTNTX5_H_
#define BLOCKTNTX5_H_

#include "mcpe/world/level/tile/Tile.h"
#include "mcpe/world/level/TileSource.h"
#include "mcpe/world/level/Level.h"
#include "mcpe/utils/Random.h"
#include "mcpe/CommonTypes.h"
#include "mcpe/world/entity/player/Player.h"
#include "mcpe/world/material/Material.h"
#include "mcpe/world/item/ItemInstance.h"
#include "mcpe/world/item/Item.h"
#include "mcpe/world/item/TileItem.h"

class BlockTNTx5 : public Tile {
public:
	static Tile* block_tntx5;

	BlockTNTx5(int);

	virtual const TextureUVCoordinateSet& getTexture(signed char);
	virtual void neighborChanged(TileSource*, int, int, int, int, int, int);
	virtual int getResourceCount(Random*);
	virtual bool use(Player*, int, int, int);
	virtual void wasExploded(TileSource*, int, int, int);
	virtual void spawnPrimed(TileSource*, int, int, int, int);

protected:
	Tile* super;
	TextureUVCoordinateSet bottomIcon;
	TextureUVCoordinateSet topIcon;
};

#endif