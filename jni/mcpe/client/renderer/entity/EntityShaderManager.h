#pragma once

#include "../MaterialPtr.h"

class Entity;

class EntityShaderManager {
public:
	//void **vtable;					// 0
	mce::MaterialPtr entity;			// 4
	mce::MaterialPtr entity_alphatest;	// 16
	mce::MaterialPtr entity_static;		// 28

	EntityShaderManager();
	virtual ~EntityShaderManager();
	virtual void* _getOverlayColor(Entity &, float) const;
};