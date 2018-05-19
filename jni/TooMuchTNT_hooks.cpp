#include <jni.h>
#include <dlfcn.h>
#include <android/log.h>
#include <stdlib.h>
#include <string>
#include <memory>
#include "Substrate.h"

#include "mcpe/block/BlockLegacy.h"
#include "mcpe/block/BlockGraphics.h"
#include "mcpe/item/Item.h"
#include "mcpe/locale/Localization.h"
/*#include "mcpe/entity/EntityDefinitionIdentifier.h"
#include "mcpe/entity/Entity.h"
#include "mcpe/client/renderer/entity/EntityRenderDispatcher.h"*/

#include "TooMuchTNT/TooMuchTNT.h"
#include "TooMuchTNT/TntDef.h"

void (*_BlockLegacy$initBlocks)();
void BlockLegacy$initBlocks() {
	_BlockLegacy$initBlocks();
	
	TooMuchTNT::initBlocks();
}

void (*_BlockLegacy$postInitBlocks)(const BlockPalette&);
void BlockLegacy$postInitBlocks(const BlockPalette& palette) {
	TooMuchTNT::postInitBlocks(palette);
	
	_BlockLegacy$postInitBlocks(palette);
}

void (*_initBlockGraphics)(ResourcePackManager&);
void initBlockGraphics(ResourcePackManager& rpm) {
	_initBlockGraphics(rpm);

	TooMuchTNT::initBlockGraphics();
}

void (*_Item$initCreativeItems)(bool);
void Item$initCreativeItems(bool experimental) {
	_Item$initCreativeItems(experimental);

	TooMuchTNT::registerCreativeItems();
}

/*void (*_EntityRenderDispatcher$initializeEntityRenderers)(GeometryGroup&, mce::TextureGroup&, BlockTessellator&);
void EntityRenderDispatcher$initializeEntityRenderers(GeometryGroup& geometry, mce::TextureGroup& textures, BlockTessellator& tessellator) {
	_EntityRenderDispatcher$initializeEntityRenderers(geometry, textures, tessellator);

	//TooMuchTNT::registerTNTRenderers(textures, tessellator);
}*/

/*void (*_EntityRenderDispatcher$render)(BaseEntityRenderContext&, Entity&, const Vec3&, const Vec2&);
void EntityRenderDispatcher$render(BaseEntityRenderContext& context, Entity& entity, const Vec3& pos, const Vec2& rot) {
	/*if(entity.rendererId >= EntityRendererId::TNTX5)
		TooMuchTNT::renderTNT(context, entity, pos, rot);
	else
		_EntityRenderDispatcher$render(context, entity, pos, rot);
}*/

/*std::unique_ptr<Entity> (*_CreateTNT)(EntityDefinitionGroup&, EntityDefinitionIdentifier const&);
std::unique_ptr<Entity> CreateTNT(EntityDefinitionGroup& definitions, EntityDefinitionIdentifier const& identifier) {
	if(TooMuchTNT::tntDef.type != TntType::REGULAR)
		return TooMuchTNT::createPrimedTNT(definitions, identifier);

	return _CreateTNT(definitions, identifier);
}*/

void (*_Localization$loadFromPack)(Localization*, std::string const&, const PackAccessStrategy&, std::vector<std::string> const&);
void Localization$loadFromPack(Localization *self, std::string const& s1, const PackAccessStrategy& pas, std::vector<std::string> const& stringVec) {
	_Localization$loadFromPack(self, s1, pas, stringVec);
	
	if(self->langCode == "en_US" )
	{
		std::string backupString = self->langCode;
		self->langCode = "toomuchtnt/" + self->langCode;
		_Localization$loadFromPack(self, s1, pas, stringVec);
		self->langCode = backupString;
	}

}

void (*_Localization$loadFromResourcePackManager)(Localization*, ResourcePackManager&, std::vector<std::string> const&);
void Localization$loadFromResourcePackManager(Localization *self, ResourcePackManager& rpm, std::vector<std::string> const& stringVec) {
	_Localization$loadFromResourcePackManager(self, rpm, stringVec);
	
	if(self->langCode == "en_US" )
	{
		std::string backupString = self->langCode;
		self->langCode = "toomuchtnt/" + self->langCode;
		_Localization$loadFromResourcePackManager(self, rpm, stringVec);
		self->langCode = backupString;
	}
}

JNIEXPORT jint JNI_OnLoad(JavaVM* vm, void* reserved) {
	MSHookFunction((void*) &BlockLegacy::initBlocks, (void*) &BlockLegacy$initBlocks, (void**) &_BlockLegacy$initBlocks);
	MSHookFunction((void*) &BlockLegacy::postInitBlocks, (void*) &BlockLegacy$postInitBlocks, (void**) &_BlockLegacy$postInitBlocks);
	MSHookFunction((void*) &BlockGraphics::initBlocks, (void*) &initBlockGraphics, (void**) &_initBlockGraphics);
	MSHookFunction((void*) &Item::initCreativeItems, (void*) &Item$initCreativeItems, (void**) &_Item$initCreativeItems);
	//MSHookFunction((void*) &EntityRenderDispatcher::initializeEntityRenderers, (void*) &EntityRenderDispatcher$initializeEntityRenderers, (void**) &_EntityRenderDispatcher$initializeEntityRenderers);
	/*MSHookFunction((void*) &EntityRenderDispatcher::render, (void*) &EntityRenderDispatcher$render, (void**) &_EntityRenderDispatcher$render);*/

	//void* SpawnTNT = dlsym(RTLD_DEFAULT, "_Z16_entityFromClassI9PrimedTntESt10unique_ptrI6EntitySt14default_deleteIS2_EER21EntityDefinitionGroupRK26EntityDefinitionIdentifier");
	//MSHookFunction(SpawnTNT, (void*) &CreateTNT, (void**) &_CreateTNT);

	MSHookFunction((void*) &Localization::loadFromPack, (void*) &Localization$loadFromPack, (void**) &_Localization$loadFromPack);
	MSHookFunction((void*) &Localization::loadFromResourcePackManager, (void*) &Localization$loadFromResourcePackManager, (void**) &_Localization$loadFromResourcePackManager);

	return JNI_VERSION_1_2;
}
