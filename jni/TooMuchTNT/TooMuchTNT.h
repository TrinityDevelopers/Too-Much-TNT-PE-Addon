#pragma once

//#include <memory>

class Block;
class BlockLegacy;
class TntDef;
class BlockPalette;
/*class EntityRenderer;
class Entity;
class EntityDefinitionGroup;
class EntityDefinitionIdentifier;
class BlockTessellator;
class BaseEntityRenderContext;
class Vec3;
class Vec2;
namespace mce { class TextureGroup; };*/

class TooMuchTNT {
public:
	static Block* TNTx5;
	static BlockLegacy* legacyTNTx5;

	static TntDef tntDef;
	
	static void initBlocks();
	static void postInitBlocks(const BlockPalette&);
	static void initBlockItems();
	static void initBlockGraphics();
	static short getNextBlockId();
	static short getBlockItemId(short);
	
	static void registerCreativeItems();

	/*static EntityRenderer* TNTx5Renderer;

	static std::unique_ptr<Entity> createPrimedTNT(EntityDefinitionGroup&, EntityDefinitionIdentifier const&);
	static void registerTNTRenderers(mce::TextureGroup&, BlockTessellator&);
	static void renderTNT(BaseEntityRenderContext&, Entity&, const Vec3&, const Vec2&);*/
};
