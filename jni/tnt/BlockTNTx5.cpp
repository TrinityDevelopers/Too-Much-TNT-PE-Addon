#include "BlockTNTx5.h"

int BlockTNTx5::_TNTx5Id = 198;

BlockTNTx5::BlockTNTx5(int id, std::string const& texture, std::string const& desc) : Tile(id, texture, &Material::explosive) {
	init();
	setNameId(desc);
	setCategory(3);
	sideIcon = getTextureUVCoordinateSet(texture, 0);
	topIcon = getTextureUVCoordinateSet(texture, 1);
	bottomIcon = getTextureUVCoordinateSet(texture, 2);
	Tile::solid[id] = false;
	Tile::lightBlock[id] = 0;
}

const TextureUVCoordinateSet& BlockTNTx5::getTexture(signed char side) {
	switch(side) {
	case 0:
		return bottomIcon;
		break;
	case 1:
		return topIcon;
		break;
	default:
		return sideIcon;
	}
}

void BlockTNTx5::neighborChanged(TileSource* ts, int i1, int i2, int i3, int i4, int i5, int i6) { }

int BlockTNTx5::getResourceCount(Random *rand) {
	return 1;
}

bool BlockTNTx5::use(Player* player, int x, int y, int z) {
	if(player->getCarriedItem() != NULL && player->getCarriedItem()->item == Item::flintAndSteel) {
		player->getCarriedItem()->hurtAndBreak(1, (Mob*)player);
		//this->spawnPrimed(TileSource::inst, x, y, z, 1);
		player->region.setTileAndData(x, y, z, {0, 0}, 3);
		return true;
	}
	Tile* ref = (Tile*)this;
	return ref->use(player, x, y, z);
}

void BlockTNTx5::spawnPrimed(TileSource* ts, int x, int y, int z, int i4) {
	if(!(ts->getLevel()->isMultiLevel) && ((i4 & 1) == 1)) {
		/*PrimedTNTx5* primedTnt = new PrimedTNTx5(ts, (float)x + 0.5F, (float)y + 0.5F, (float)z + 0.5F);
		ts->getLevel()->addEntity(primedTnt);
		ts->getLevel()->playSound(primedTnt, "random.fuse", 1.0F, 1.0F);*/
	}
}

void BlockTNTx5::wasExploded(TileSource* ts, int x, int y, int z) {
	if(!(ts->getLevel()->isMultiLevel)) {
		/*PrimedTNTx5* primedTnt = new PrimedTNTx5(ts, (float)x + 0.5F, (float)y + 0.5F, (float)z + 0.5F);
		primedTnt->fuse = ((ts->getLevel()->random->genrand_int32() % (primedTnt->fuse / 4)) + primedTnt->fuse / 8;
		ts->getLevel()->addEntity(primedTnt);*/
	}
}

void BlockTNTx5::destroy(TileSource* ts, int x, int y, int z, int i4) {
	this->spawnPrimed(ts, x, y, z, i4);
}