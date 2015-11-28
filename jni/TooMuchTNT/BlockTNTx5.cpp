#include "BlockTNTx5.h"

#include "mcpe/leveledit.h"
#include "mcpe/world/entity/player/Player.h"
#include "mcpe/world/item/Item.h"
#include "mcpe/world/item/ItemInstance.h"

BlockTNTx5::BlockTNTx5(std::string asset, int id) : 
	Block(asset, id, asset, Material::getMaterial(MaterialType::EXPLOSIVE)) {
		
	creativeCategory = 3;
	setDestroyTime(0.0F);
	setSoundType(SOUND_GRASS);
	
	bottomIcon = getTextureUVCoordinateSet(asset, 1);
	topIcon = getTextureUVCoordinateSet(asset, 2);
}

const TextureUVCoordinateSet& BlockTNTx5::getTexture(signed char side) {
	return side == 1 ? topIcon : (side == 0 ? bottomIcon : texture);
}

int BlockTNTx5::getResourceCount(Random& rand, int i1, int i2) {
	return 1;
}

bool BlockTNTx5::use(Player& player, const BlockPos& pos) {
	ItemInstance* selected = player.getSelectedItem();
	if(selected && Item::mFlintAndSteel && selected->item == Item::mFlintAndSteel) {
		BlockSource& region = player.getRegion();
		region.setBlock(pos, BlockID::AIR, 11);
		return true;
	}
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
