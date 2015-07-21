#include <jni.h>
#include <dlfcn.h>
#include <android/log.h>
#include <stdlib.h>
#include <Substrate.h>
#include <string>
#include <map>
#include <memory>

#include "mcpe/world/level/tile/Tile.h"
#include "mcpe/world/item/Item.h"
#include "mcpe/world/level/Level.h"
#include "mcpe/world/level/TileSource.h"

#include "tnt/BlockTNTx5.h"

static void (*_Tile_initTiles)();
static void Tile_initTiles() {
	_Tile_initTiles();
	BlockTNTx5::block_tntx5 = (Tile*) new BlockTNTx5(195);
}

static void (*_Item_initCreativeItems)();
static void Item_initCreativeItems() {
	_Item_initCreativeItems();
	Item::addCreativeItem(BlockTNTx5::block_tntx5, 0);
}

static std::string (*_I18n_get)(std::string const&, std::vector<std::string,std::allocator<std::string>> const&);
static std::string I18n_get(std::string const& key, std::vector<std::string,std::allocator<std::string>> const& a) {
	if(key == "tile.blockTNTx5.name") return "TNTx5";
	return _I18n_get(key, a);
};

static void(*_Level_onSourceCreated)(Level*, TileSource*);
static void Level_onSourceCreated(Level* level, TileSource* ts) {
	_Level_onSourceCreated(level, ts);
	TileSource::inst = ts;
}

JNIEXPORT jint JNI_OnLoad(JavaVM* vm, void* reserved) {
	void* I18n_get = dlsym(RTLD_DEFAULT, "_ZN4I18n3getERKSsRKSt6vectorISsSaISsEE");
    MSHookFunction((void*) &Tile::initTiles, (void*) &Tile_initTiles, (void**) &_Tile_initTiles);
	MSHookFunction((void*) &Item::initCreativeItems, (void*) &Item_initCreativeItems, (void**) &_Item_initCreativeItems);
	MSHookFunction(I18n_get, (void*) &I18n_get, (void**) &_I18n_get);
	MSHookFunction((void*)&Level::onSourceCreated, (void*)&Level_onSourceCreated, (void**) &_Level_onSourceCreated);
    return JNI_VERSION_1_2;
}