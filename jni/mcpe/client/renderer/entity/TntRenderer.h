#pragma once

#include "EntityRenderer.h"

class BlockTessellator;

class TntRenderer : public EntityRenderer {
public:
	BlockTessellator* tessellator; 			// 136

	TntRenderer(mce::TextureGroup&, BlockTessellator&);
	virtual ~TntRenderer() { };
	virtual void render(BaseEntityRenderContext&, EntityRenderData&);
};
