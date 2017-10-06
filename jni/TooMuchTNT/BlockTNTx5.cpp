#include "BlockTNTx5.h"

#include "mcpe/level/BlockSource.h"
#include "mcpe/level/Level.h"
#include "mcpe/item/ItemInstance.h"
#include "mcpe/util/GameRules.h"
#include "mcpe/entity/EntityDefinitionIdentifier.h"
#include "mcpe/entity/EntityFactory.h"
#include "mcpe/entity/Entity.h"
#include "mcpe/entity/PrimedTnt.h"
#include "mcpe/level/BlockPos.h"
#include "mcpe/inventory/Container.h"

#include "TooMuchTNT.h"
#include "TntDef.h"

BlockTNTx5::BlockTNTx5(std::string asset, int id) : 
	TntBlock(asset, id) {
	
	setCategory(CreativeItemCategory::ITEMS);
	setDestroyTime(0.0F);
	addBlockState((BlockState::BlockStates) 14, 1);
}

bool BlockTNTx5::dispense(BlockSource& region, Container& container, int slotId, const Vec3& pos, signed char sc) const {
	Vec3 vecPos = Vec3(BlockPos(pos));
	TooMuchTNT::tntDef = {TntType::TNTX5, TntStat::REGULAR};
	std::unique_ptr<Entity> tnt = EntityFactory::createSpawnedEntity(EntityDefinitionIdentifier(EntityType::PRIMED_TNT), NULL, {vecPos.x + 0.5F, vecPos.y + 0.5F, vecPos.z + 0.5F}, Vec2::ZERO);
	TooMuchTNT::tntDef = {TntType::REGULAR, TntStat::REGULAR};
	if(tnt) {
		Level& level = region.getLevel();
		level.addEntity(region, std::move(tnt));
		level.broadcastLevelEvent((LevelEvent) 1000, pos, 1000, NULL);
		level.broadcastDimensionEvent(region, (LevelEvent) 1005, vecPos, 0, NULL);
		container.removeItem(slotId, 1);
		return true;
	}
	return false;
}

void BlockTNTx5::onExploded(BlockSource& region, const BlockPos& pos, Entity* exploder) const {
	TooMuchTNT::tntDef = {TntType::TNTX5, TntStat::FROM_EXPLOSION};
	std::unique_ptr<Entity> tnt = EntityFactory::createSpawnedEntity(EntityDefinitionIdentifier("minecraft", "tnt", "from_explosion"), exploder, {(float)pos.x + 0.5F, (float)pos.y, (float)pos.z + 0.5F}, Vec2::ZERO);
	TooMuchTNT::tntDef = {TntType::REGULAR, TntStat::REGULAR};
	if(tnt) {
		Level& level = region.getLevel();
		level.addEntity(region, std::move(tnt));
	}
}

void BlockTNTx5::destroy(BlockSource& region, const BlockPos& pos, int data, Entity* exploder) const {
	if(!region.getLevel().isClientSide() && getBlockState((BlockState::BlockStates) 14).getBool(data)) {
		GameRules& rules = region.getLevel().getGameRules();
		if(rules.hasRule(GameRules::DO_TNT_EXPLODE) && rules.getBool(GameRules::DO_TNT_EXPLODE)) {
			Vec3 vecPos = Vec3(pos);
			TooMuchTNT::tntDef = {TntType::TNTX5, TntStat::REGULAR};
			std::unique_ptr<Entity> tnt = EntityFactory::createSpawnedEntity(EntityDefinitionIdentifier(EntityType::PRIMED_TNT), exploder, {vecPos.x + 0.5F, vecPos.y, vecPos.z + 0.5F}, Vec2::ZERO);
			TooMuchTNT::tntDef = {TntType::REGULAR, TntStat::REGULAR};
			if(tnt) {
				Level& level = region.getLevel();
				level.broadcastDimensionEvent(region, (LevelEvent) 1005, tnt->getPos(), 0, NULL);
				level.addEntity(region, std::move(tnt));
			}
		}
	}
}