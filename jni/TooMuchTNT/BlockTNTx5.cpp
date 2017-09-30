#include "BlockTNTx5.h"

#include "mcpe/level/BlockSource.h"
#include "mcpe/level/Level.h"

BlockTNTx5::BlockTNTx5(std::string asset, int id) : 
	TntBlock(asset, id) {
	
	setCategory(CreativeItemCategory::ITEMS);
	setDestroyTime(0.0F);
	addBlockState((BlockState::BlockStates) 14, 1);
}

/*bool BlockTNTx5::use(Player& player, const BlockPos& pos) {
	return Block::use(player, pos);
}

/*bool BlockTNTx5::use(Player* player, int x, int y, int z) {
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
