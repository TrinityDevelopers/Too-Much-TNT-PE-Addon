#include "TooMuchTNT.h"

#include "mcpe/block/Block.h"
#include "mcpe/block/BlockLegacy.h"
#include "mcpe/block/BlockPalette.h"
#include "mcpe/block/BlockGraphics.h"
#include "mcpe/item/BlockItem.h"
//#include "mcpe/entity/EntityDefinitionIdentifier.h"
//#include "mcpe/entity/PrimedTnt.h"

#include "BlockTNTx5.h"

#include "TntDef.h"

//#include "RenderTNTx5Primed.h"

Block* TooMuchTNT::TNTx5;
BlockLegacy* TooMuchTNT::legacyTNTx5;

TntDef TooMuchTNT::tntDef = {TntType::REGULAR, TntStat::REGULAR};


void TooMuchTNT::initBlocks() {
	legacyTNTx5 = registerBlock<BlockTNTx5>("TNTx5", 253/*getNextBlockId()*/);
}

void TooMuchTNT::postInitBlocks(const BlockPalette& palette) {
	TNTx5 = palette.tryGetLegacyBlockState(16 * legacyTNTx5->blockId);
	Block::mBlockLookupMap[Util::toLowerCase(legacyTNTx5->nameId)] = TNTx5;
	Block::mBlocks[legacyTNTx5->blockId] = TNTx5;
	
	initBlockItems();
}

void TooMuchTNT::initBlockItems() {
	registerItem<BlockItem>(legacyTNTx5->getDescriptionId(), getBlockItemId(legacyTNTx5->blockId));
}

void TooMuchTNT::initBlockGraphics() {
	BlockGraphics::mBlocks[legacyTNTx5->blockId] = new BlockGraphics("tnt");
	BlockGraphics::mBlocks[legacyTNTx5->blockId]->setTextureItem("TNTx5_top", "TNTx5_bottom", "TNTx5_side");
	BlockGraphics::mBlocks[legacyTNTx5->blockId]->setSoundType(BlockSoundType::GRASS);
}

short TooMuchTNT::getNextBlockId() {
	for(short counter = 0; counter < 511; counter++) {
		std::stringstream ss;
		ss << counter;
		std::string blockName = ss.str();
		if(BlockLegacy::mBlocks[counter]->nameId == blockName)
			return counter;
	}
	return 512;
}

short TooMuchTNT::getBlockItemId(short blockId) {
	if(blockId > 255)
		return 255 - blockId;
	return blockId;
}

void TooMuchTNT::registerCreativeItems() {
	Item::addCreativeItem(*TNTx5, 0);
}

/*std::unique_ptr<Entity> TooMuchTNT::createPrimedTNT(EntityDefinitionGroup& definitions, const EntityDefinitionIdentifier& identifier) {
	if(tntDef.stat == TntStat::REGULAR) {
		switch(tntDef.type) {
			case TntType::TNTX5:
			{
				std::unique_ptr<Entity> tnt = std::unique_ptr<Entity>(new PrimedTnt(definitions, EntityDefinitionIdentifier("minecraft:tntx5")));
				//tnt->rendererId = EntityRendererId::TNTX5;
				return tnt;
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
				std::unique_ptr<Entity> tnt = std::unique_ptr<Entity>(new PrimedTnt(definitions, EntityDefinitionIdentifier("minecraft", "tntx5", "from_explosion")));
				//tnt->rendererId = EntityRendererId::TNTX5;
				return tnt;
			}
			default:
			{
				return std::unique_ptr<Entity>(new PrimedTnt(definitions, identifier));
			}
		}
	}
}

EntityRenderer* TooMuchTNT::TNTx5Renderer;

void TooMuchTNT::registerTNTRenderers(mce::TextureGroup& textures, BlockTessellator& tessellator) {
	//TNTx5Renderer = new RenderTNTx5Primed(textures, tessellator);
}

void TooMuchTNT::renderTNT(BaseEntityRenderContext& context, Entity& tnt, const Vec3& pos, const Vec2& rot) {
	/*EntityRenderData data = EntityRenderData(tnt, pos, rot);
	switch(tnt.rendererId) {
		case EntityRendererId::TNTX5:
		{
			TNTx5Renderer->render(context, data);
			TNTx5Renderer->renderFlame(context, data);
			break;
		}
	}*/
//}