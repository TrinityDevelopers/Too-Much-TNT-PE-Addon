#pragma once

#include "mcpe/client/renderer/entity/TntRenderer.h"

class RenderTNTx5Primed : public TntRenderer {
public:
	RenderTNTx5Primed(mce::TextureGroup&, BlockTessellator&);
	
	virtual void render(BaseEntityRenderContext&, EntityRenderData&);
};