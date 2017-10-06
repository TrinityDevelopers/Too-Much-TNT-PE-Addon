#include "TooMuchTNT.h"

#include "mcpe/block/Block.h"
#include "mcpe/block/BlockGraphics.h"
#include "mcpe/item/BlockItem.h"
#include "mcpe/entity/EntityDefinitionIdentifier.h"
#include "mcpe/entity/PrimedTnt.h"

#include "BlockTNTx5.h"

#include "TntDef.h"

Block* TooMuchTNT::TNTx5;

TntDef TooMuchTNT::tntDef = {TntType::REGULAR, TntStat::REGULAR};


void TooMuchTNT::initBlocks() {
	TNTx5 = registerBlock<BlockTNTx5>("TNTx5", getNextBlockId());
	
	initBlockItems();
}

void TooMuchTNT::initBlockItems() {
	registerItem<BlockItem>(TNTx5->getDescriptionId(), TNTx5->blockId - 256);
}

void TooMuchTNT::initBlockGraphics() {
	BlockGraphics::mBlocks[TNTx5->blockId] = new BlockGraphics("tnt");
	BlockGraphics::mBlocks[TNTx5->blockId]->setTextureItem("TNTx5_top", "TNTx5_bottom", "TNTx5_side");
	BlockGraphics::mBlocks[TNTx5->blockId]->setSoundType(BlockSoundType::GRASS);
}

int TooMuchTNT::getNextBlockId() {
	for(int counter = 0; counter < 254; counter++) {
		std::stringstream ss;
		ss << counter;
		std::string blockName = ss.str();
		if(Block::mBlocks[counter]->nameId == blockName)
			return counter;
	}
	return 255;
}

void TooMuchTNT::registerCreativeItems() {
	Item::addCreativeItem(TNTx5, 0);
}

std::unique_ptr<Entity> TooMuchTNT::createPrimedTNT(EntityDefinitionGroup& definitions, const EntityDefinitionIdentifier& identifier) {
	if(tntDef.stat == TntStat::REGULAR) {
		switch(tntDef.type) {
			case TntType::TNTX5:
			{
				return std::unique_ptr<Entity>(new PrimedTnt(definitions, EntityDefinitionIdentifier("minecraft:tntx5")));
			}
			default:
			{
				return std::unique_ptr<Entity>(new PrimedTnt(definitions, identifier));
			}
		}
	}
	else {
		switch(tntDef.type) {
			case TntType::TNTX5:
			{
				return std::unique_ptr<Entity>(new PrimedTnt(definitions, EntityDefinitionIdentifier("minecraft", "tntx5", "from_explosion")));
			}
			default:
			{
				return std::unique_ptr<Entity>(new PrimedTnt(definitions, identifier));
			}
		}
	}
}