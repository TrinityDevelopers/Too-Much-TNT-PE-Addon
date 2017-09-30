#include <jni.h>
#include <dlfcn.h>
#include <android/log.h>
#include <stdlib.h>
#include <string>
#include <memory>
#include "Substrate.h"

#include "mcpe/block/Block.h"
#include "mcpe/block/BlockGraphics.h"
#include "mcpe/item/Item.h"
#include "mcpe/locale/Localization.h"

#include "TooMuchTNT/TooMuchTNT.h"

void (*_Block$initBlocks)();
void Block$initBlocks() {
	_Block$initBlocks();
	
	TooMuchTNT::initBlocks();
}

void (*_initBlockGraphics)(ResourcePackManager&);
void initBlockGraphics(ResourcePackManager& rpm) {
	_initBlockGraphics(rpm);

	TooMuchTNT::initBlockGraphics();
}

void (*_Item$initCreativeItems)();
void Item$initCreativeItems() {
	_Item$initCreativeItems();

	TooMuchTNT::registerCreativeItems();
}

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
	MSHookFunction((void*) &Block::initBlocks, (void*) &Block$initBlocks, (void**) &_Block$initBlocks);
	MSHookFunction((void*) &BlockGraphics::initBlocks, (void*) &initBlockGraphics, (void**) &_initBlockGraphics);
	MSHookFunction((void*) &Item::initCreativeItems, (void*) &Item$initCreativeItems, (void**) &_Item$initCreativeItems);
	MSHookFunction((void*) &Localization::loadFromPack, (void*) &Localization$loadFromPack, (void**) &_Localization$loadFromPack);
	MSHookFunction((void*) &Localization::loadFromResourcePackManager, (void*) &Localization$loadFromResourcePackManager, (void**) &_Localization$loadFromResourcePackManager);

	return JNI_VERSION_1_2;
}
