#pragma once

#include <memory>
#include <unordered_set>

#include "mcpe/AppPlatformListener.h"
#include "LevelListener.h"
#include "mcpe/CommonTypes.h"

class Minecraft;
class LevelStorage;
class LevelSettings;
class LightLayer;
class EntityDamageSource;
class SoundPlayer;
class ChunkSource;
class EntityUniqueID;
class Random;

class Level : public AppPlatformListener, public LevelListener {
public:
	//void **vtable;						// 8
	char filler[8];
	bool isMultiLevel;						// 12
	char filler1[47];						// 13
	std::unordered_set<Player *> _players;	// 60
	char filler2[32];
	Random* random;

public:
	Level(SoundPlayer &, std::unique_ptr<LevelStorage, std::default_delete<LevelStorage>>, const std::string &, const LevelSettings &, bool);
	virtual ~Level();
	virtual void onSourceCreated(TileSource *);
	virtual void onSourceDestroyed(TileSource *);
	virtual void onTileChanged(TileSource *, const TilePos &, FullTile, FullTile, int);
	virtual bool isNaturalDimension();
	virtual void addEntity(Entity *);
	virtual void addPlayer(Player *);
	virtual void onPlayerDeath(Player *, EntityDamageSource *);
	virtual void tick();
	virtual void directTickEntities();
	virtual void updateSleepingPlayerList();
	virtual void setDifficulty(int);
	virtual void runLightUpdates(TileSource &, const LightLayer &, const TilePos &, const TilePos &);
	virtual void onNewChunkFor(Player &, LevelChunk &);
	virtual void onChunkLoaded(LevelChunk &);
	virtual void removeEntity(std::unique_ptr<Entity, std::default_delete<Entity>> &&);
	virtual void removeEntity(Entity &);
	virtual void onAppSuspended();
	virtual void onAppResumed();
	bool addParticle(ParticleType, const Vec3 &, float, float, float, int);
	void addListener(LevelListener *);
	void removeListener(LevelListener *);
	char getDifficulty() const;
	long getSeed();
	Entity *getEntity(EntityUniqueID, bool);
	Mob *getMob(EntityUniqueID);
	Player *getLocalPlayer();
	Player *getPlayer(int);
	Player *getPlayer(const std::string &);
	Player *getPlayerByClientId(int);
	Player *getRandomPlayer();
	Player *getNearestPlayer(Entity *, float);
	Player *getNearestPlayer(float, float, float, float);
	long getTime() const;
	float getSunAngle(float);
	ChunkSource* getChunkSource();
	void setTime(long);
	void setNightMode(bool);
	void setDayCycleActive(bool);
	void setDefaultSpawn(const TilePos &);
	bool isDay();
	bool isNightMode();
	void explode(Entity *, float, float, float, float);
	void explode(Entity *, float, float, float, float, bool);
	void forceRemoveEntity(Entity &);
	void playSound(Entity *, std::string const&, float, float);
	void playSound(float, float, float, std::string const&, float, float);
};
