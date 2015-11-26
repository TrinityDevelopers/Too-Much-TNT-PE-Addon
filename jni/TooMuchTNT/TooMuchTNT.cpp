#include "TooMuchTNT.h"

#include "mcpe/world/level/block/Block.h"
#include "mcpe/world/item/BlockItem.h"
#include "mcpe/world/item/Item.h"

#include "BlockTNTx5.h"

Block* TooMuchTNT::TNTx5;

void TooMuchTNT::initBlocks() {
	TNTx5 = new BlockTNTx5("TNTx5", getNewRandomID());
	
	registerBlocks();
}

void TooMuchTNT::registerBlocks() {
	registerBlock(TNTx5);
}

void TooMuchTNT::registerBlock(Block* block) {
	block->init();
	Block::mBlocks[block->blockId] = block;
	Block::mOwnedBlocks.emplace_back(std::unique_ptr<Block>(block));
	Item::mItems[block->blockId] = new BlockItem(block->getDescriptionId(), block->blockId - 0x100);
}

int TooMuchTNT::getNewRandomID() {
	int id = 0;
	while(Block::mBlocksHook[id] != NULL) {
		if(id < 256)
			id++;
		else 
			return NULL;
	}	
	return id;
}

void TooMuchTNT::registerCreativeItems() {
	Item::addCreativeItem(TooMuchTNT::TNTx5, 0);
}