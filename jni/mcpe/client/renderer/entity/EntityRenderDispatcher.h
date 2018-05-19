#pragma once

#include "EntityRendererId.h"

class EntityRenderer;
class Entity;
class GeometryGroup;
namespace mce { class TextureGroup; };
class BlockTessellator;
class BaseEntityRenderContext;
class Vec3;
class Vec2;

class EntityRenderDispatcher {
public:
	EntityRenderer* getRenderer(Entity&);
	EntityRenderer* getRenderer(EntityRendererId);
	void initializeEntityRenderers(GeometryGroup&, mce::TextureGroup&, BlockTessellator&);
	void render(BaseEntityRenderContext&, Entity&, const Vec3&, const Vec2&);
};