#pragma once

#include <memory>

class Block;
class TntDef;
class Entity;
class EntityDefinitionGroup;
class EntityDefinitionIdentifier;

class TooMuchTNT {
public:
	static Block* TNTx5;

	static TntDef tntDef;
	
	static void initBlocks();
	static void initBlockItems();
	static void initBlockGraphics();
	static int getNextBlockId();
	
	static void registerCreativeItems();

	static std::unique_ptr<Entity> createPrimedTNT(EntityDefinitionGroup&, EntityDefinitionIdentifier const&);
};
