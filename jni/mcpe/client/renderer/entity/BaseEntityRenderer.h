#pragma once

#include "EntityShaderManager.h"

class BaseEntityRenderer : public EntityShaderManager {
public:
	mce::MaterialPtr name_tag;					// 40
	mce::MaterialPtr name_tag_depth_tested;		// 52
	mce::MaterialPtr name_tag_depth_tested2;	// 64

	BaseEntityRenderer();
	virtual ~BaseEntityRenderer();
};