#pragma once

#include <string>
#include "BaseEntityRenderer.h"
#include "EntityRenderDispatcher.h"
#include "../TexturePtr.h"

class BaseEntityRenderContext;
class Vec3;
class Vec2;
class Entity;

class EntityRenderData {
public:
	EntityRenderData(Entity&, const Vec3&, const Vec2&);	
};

class EntityRenderer : public BaseEntityRenderer {
public:
	bool idk;									// 76
	int unknown;								// 80
	mce::MaterialPtr entity_alphatest2;			// 84
	mce::MaterialPtr entity_alphatest_glint;	// 96
	mce::TexturePtr glint_texture;				// 108
	mce::TextureGroup* texture_group;			// 132

	EntityRenderer(mce::TextureGroup&, bool);
	virtual ~EntityRenderer();
	virtual void render(BaseEntityRenderContext&, EntityRenderData&) = 0;
	virtual void renderDebug(BaseEntityRenderContext&, EntityRenderData&);
	virtual void renderEffects(BaseEntityRenderContext&, EntityRenderData&);
	virtual void renderTrading(BaseEntityRenderContext&, EntityRenderData&, float);
	virtual void renderFlame(BaseEntityRenderContext&, EntityRenderData&);
	virtual void renderLeash(BaseEntityRenderContext&, EntityRenderData&);
	virtual void renderWaterHole(BaseEntityRenderContext&, EntityRenderData&);
};
