#pragma once

#include "mcpe/CommonTypes.h"
class Level;
class ChunkSource;
class TilePos;
class Tile;
class TileEntity;
class LightLayer;
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
	TileSource(Player &);
	virtual ~TileSource();
	Level *getLevel() const;
	TileID getTile(int, int, int);
	TileID getTile(const TilePos &);
	DataID getData(int, int, int);
	DataID getData(const TilePos &);
	FullTile getTileAndData(int, int, int);
	FullTile getTileAndData(const TilePos &);
	Tile *getTilePtr(int, int, int);
	TileEntity *getTileEntity(int, int, int);
	TileEntity *getTileEntity(const TilePos &);
	bool setTile(int, int, int, TileID, int);
	bool setTileAndData(int, int, int, FullTile, int);
	int getBrightness(const LightLayer &, const TilePos &);
	int getBrightness(const LightLayer &, int, int, int);
	int getBrightness(const TilePos &);
	int getBrightness(int, int, int);
	bool canSeeSky(int, int, int);
	bool canSeeSky(const TilePos &);
	bool isSolidBlockingTile(int, int, int);
	bool isSolidBlockingTile(const TilePos &);
	
	static TileSource* inst;
};