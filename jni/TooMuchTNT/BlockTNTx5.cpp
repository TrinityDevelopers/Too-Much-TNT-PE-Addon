#include "BlockTNTx5.h"

#include "mcpe/leveledit.h"

BlockTNTx5::BlockTNTx5(std::string name, int id) : 
	Block(name, id, "tnt", Material::getMaterial(MaterialType::EXPLOSIVE)) {
		
	creativeCategory = 3;
	setDestroyTime(0.0F);
	setSoundType(SOUND_GRASS);
}

/*const TextureUVCoordinateSet& BlockTNTx5::getTexture(signed char side) {
	return side == 1 ? topIcon : (side == 0 ? bottomIcon : tex);
}

void BlockTNTx5::neighborChanged(TileSource* ts, int i1, int i2, int i3, int i4, int i5, int i6) { }

int BlockTNTx5::getResourceCount(Random *rand) {
	return 1;
}

bool BlockTNTx5::use(Player* player, int x, int y, int z) {
	if(player->getCarriedItem() != NULL && player->getCarriedItem()->item == Item::flintAndSteel) {
		player->getCarriedItem()->hurtAndBreak(1, (Mob*)player);
		//this->spawnPrimed(TileSource::inst, x, y, z, 1);
		TileSource::inst->setTileAndData(x, y, z, {0, 0}, 3);
		return true;
	}
	return super->use(player, x, y, z);
}

void BlockTNTx5::spawnPrimed(TileSource* ts, int x, int y, int z, int i4) {
	if((i4 & 1) == 1) {
		/*std::unique_ptr<PrimedTNTx5> primedTnt ( new PrimedTNTx5(ts, (float)x + 0.5F, (float)y + 0.5F, (float)z + 0.5F));
		ts->getLevel()->addEntity(primedTnt);
		ts->getLevel()->playSound((Entity*) primedTnt.get(), "random.fuse", 1.0F, 1.0F;
	}
}

void BlockTNTx5::wasExploded(TileSource* ts, int x, int y, int z) {
	/*std::unique_ptr<PrimedTNTx5> primedTnt ( new PrimedTNTx5(ts, (float)x + 0.5F, (float)y + 0.5F, (float)z + 0.5F));
	primedTnt->fuse = ((ts->getLevel()->random.genrand_int32() % (primedTnt->fuse / 4)) + primedTnt->fuse / 8;
	ts->getLevel()->addEntity(primedTnt);
}*/