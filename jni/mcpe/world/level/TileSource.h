#pragma once

#include "mcpe/CommonTypes.h"
#include "mcpe/world/phys/Vec3.h"
#include <memory>

class Tile;
class Entity;
class Mob;
class Level;
class ChunkSource;
class TilePos;
class LevelChunk;
class HitResult;
class AABB;
class Material;
class TileEntity;
class LightLayer;
class ChunkPos;
class Bounds;
class TileTickingQueue;
class Player;

class TileSource {
public:
	const Player* player;
	const bool allowUnpopulatedChunks;
	const bool publicSource;
	Level* level;
	ChunkSource* source;
public:
	TileSource(Level &, ChunkSource *, bool, bool);
	virtual ~TileSource();
	void _neighborChanged(const TilePos &, const TilePos &, TileID);
	void _shouldFireEvent(LevelChunk &) const;
	void _tileChanged(const TilePos &, FullTile, FullTile, int);
	bool canSeeSky(const TilePos &);
	bool canSeeSky(int, int, int);
	void clip(HitResult &, const Vec3 &, const Vec3 &, bool, bool);
	bool containsAny(const TilePos &, const TilePos &);
	bool containsAnyLiquid(const AABB &);
	bool containsFireTile(const AABB &);
	bool containsLiquid(const AABB &, const Material *);
	bool containsMaterial(const AABB &, const Material *);
	void findNextTopSolidTileUnder(TilePos &);
	void fireAreaChanged(const TilePos &, const TilePos &);
	void fireBrightnessChanged(const TilePos &);
	void fireTileChanged(const TilePos &, FullTile, FullTile, int);
	void fireTileEntityChanged(TileEntity &);
	void fireTileEntityRemoved(std::unique_ptr<TileEntity> &);
	void fireTileEvent(int, int, int, int, int);
	void fireTilesDirty(int, int, int, int, int, int);
	void getBiome(const TilePos &);
	int getBrightness(const LightLayer &, const TilePos &);
	int getBrightness(const LightLayer &, int, int, int);
	int getBrightness(const TilePos &);
	int getBrightness(int, int, int);
	void getBrightnessPropagate(const LightLayer &, const TilePos &);
	void getChunk(const ChunkPos &);
	void getChunk(int, int);
	void getChunkAt(const TilePos &);
	void getChunkAt(int, int, int);
	void getCubes(const AABB &, float *, bool);
	void getData(const TilePos &);
	void getData(int, int, int);
	void getEntities(Entity *, const AABB &);
	void getEntities(int, const AABB &, Entity *);
	void getGrassColor(const TilePos &);
	void getHeightmap(const TilePos &);
	void getHeightmap(int, int);
	void getHeightmapPos(const TilePos &);
	Level *getLevel() const;
	Level *getLevelConst() const;
	void getLightColor(const TilePos &, int);
	Material *getMaterial(const TilePos &);
	Material *getMaterial(int, int, int);
	void getNearestEntityOfType(Entity *, float, float, float, float, int, int);
	void getRawBrightness(const TilePos &, bool);
	void getRawBrightness(int, int, int, bool);
	void getSeenPercent(const Vec3 &, const AABB &);
	void getSkyDarken();
	void getTickQueue(const TilePos &);
	void getTile(const TilePos &);
	FullTile getTile(int, int, int);
	void getTileAndData(const TilePos &);
	void getTileAndData(int, int, int);
	void getTileEntity(const TilePos &);
	void getTileEntity(int, int, int);
	Tile *getTilePtr(const TilePos &);
	Tile *getTilePtr(int, int, int);
	void getTopRainTilePos(const TilePos &);
	void getTopSolidBlock(const TilePos &, bool);
	void getTopSolidBlock(int, int, bool);
	void getWritableChunk(const ChunkPos &);
	bool hasChunksAt(const AABB &);
	bool hasChunksAt(const Bounds &);
	bool hasChunksAt(const TilePos &, const TilePos &);
	bool hasChunksAt(const TilePos &, int);
	bool hasChunksAt(int, int, int, int);
	bool hasNeighborSignal(int, int, int);
	bool hasTile(const TilePos &);
	bool hasTile(int, int, int);
	bool isEmptyTile(const TilePos &);
	bool isEmptyTile(int, int, int);
	bool isHumidAt(const TilePos &);
	bool isOwnerThread() const;
	bool isSolidBlockingTile(const TilePos &);
	bool isSolidBlockingTile(int, int, int);
	bool isSolidRenderTile(const TilePos &);
	bool isSolidRenderTile(int, int, int);
	bool isTopSolidBlocking(Tile *, unsigned char);
	bool isTopSolidBlocking(const TilePos &);
	bool isTopSolidBlocking(int, int, int);
	bool isUnobstructedByEntities(const AABB &, Entity *);
	bool isWaterAt(const TilePos &);
	bool mayPlace(TileID, const TilePos &, signed char, Mob *, bool, Entity *);
	void onChunkDiscarded(LevelChunk &);
	void removeTile(int, int, int);
	void runLightUpdates(const LightLayer &, const TilePos &, const TilePos &);
	void setBrightness(const LightLayer &, const TilePos &, Brightness);
	void setBrightness(const LightLayer &, int, int, int, Brightness);
	void setGrassColor(int, const TilePos &, int);
	void setTickingQueue(TileTickingQueue &);
	bool setTile(int, int, int, TileID, int);
	bool setTileAndData(const TilePos &, FullTile, int);
	bool setTileAndData(int, int, int, FullTile, int);
	bool setTileAndDataNoUpdate(int, int, int, FullTile);
	bool setTileNoUpdate(int, int, int, TileID);
	void shouldFreeze(const TilePos &, bool);
	void shouldFreezeIgnoreNeighbors(const TilePos &);
	void shouldSnow(const TilePos &, bool);
	void tileEvent(const TilePos &, int, int);
	void tileEvent(int, int, int, int, int);
	void updateLightIfOtherThan(const LightLayer &, const TilePos &, Brightness);
	void updateNeighborsAt(const TilePos &, TileID);
	
	static TileSource* inst;
};