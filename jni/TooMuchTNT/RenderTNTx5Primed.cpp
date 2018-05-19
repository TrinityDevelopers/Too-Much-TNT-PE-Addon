/*#include "RenderTNTx5Primed.h"

#include "mcpe/block/Block.h"
#include "TooMuchTNT.h"

RenderTNTx5Primed::RenderTNTx5Primed(mce::TextureGroup& group, BlockTessellator& tessellator) :
	TntRenderer(group, tessellator) {

}

void RenderTNTx5Primed::render(BaseEntityRenderContext& context, EntityRenderData& data) {
	Block::mTNT = TooMuchTNT::TNTx5;
	TntRenderer::render(context, data);
	Block::mTNT = Block::mBlocks[46];
}*/