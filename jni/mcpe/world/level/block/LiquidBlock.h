#pragma once
#include "Block.h"
#include "../../../client/renderer/texture/TextureAtlasTextureItem.h"
class BlockSource;
struct BlockPos;
struct Vec3;

class LiquidBlock : public Block {
protected:
	TextureUVCoordinateSet topTexture;
	TextureUVCoordinateSet sideTexture;
	TextureAtlasTextureItem textureItem;

public:
	LiquidBlock(const std::string&, int, const Material&, const std::string&, const std::string&);

	virtual ~LiquidBlock();
	virtual void animateTick(BlockSource&, const BlockPos&, Random&);
	virtual bool shouldRenderFace(BlockSource&, const BlockPos&, signed char, const AABB&) const;
	virtual const TextureUVCoordinateSet& getTexture(signed char);
	virtual AABB* getAABB(BlockSource&, const BlockPos&, AABB&, int, bool, int);
	virtual bool checkIsPathable(Entity&, const BlockPos&, const BlockPos&);
	virtual void onPlace(BlockSource&, const BlockPos&);
	virtual bool mayPick(BlockSource&, int, bool);
	virtual void neighborChanged(BlockSource&, const BlockPos&, const BlockPos&);
	virtual int getResource(Random&, int, int);
	virtual int getResourceCount(Random&, int, int);
	virtual void handleEntityInside(BlockSource&, const BlockPos&, Entity*, Vec3&);
	virtual int getColor(BlockSource&, const BlockPos&);
	virtual TextureUVCoordinateSet getTextureNum(int);
	virtual void getMobToSpawn(BlockSource&, const BlockPos&) const;
	
	int getTickDelay(BlockSource&) const;
	Vec3 _getFlow(BlockSource&, const BlockPos&);
	int getRenderedDepth(BlockSource&, const BlockPos&);
};
