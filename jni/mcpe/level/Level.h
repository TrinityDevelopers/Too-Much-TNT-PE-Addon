#pragma once
#include <memory>

#include "../client/AppPlatformListener.h"
#include "BlockSourceListener.h"

class Random;
class GameRules;
class Vec3;
class Player;
class EntityUniqueID;
class LevelChunk;
class EntityDamageSource;
class Difficulty;
class EntityDefinitionGroup;

enum class LevelEvent : int;

class Level : public BlockSourceListener, public AppPlatformListener {
public:
	virtual ~Level();
	virtual void onSourceCreated(BlockSource&);
	virtual void onSourceDestroyed(BlockSource&);
	virtual void addEntity(BlockSource&, std::unique_ptr<Entity>);
	virtual void addGlobalEntity(BlockSource&, std::unique_ptr<Entity>);
	virtual void addAutonomousEntity(BlockSource&, std::unique_ptr<Entity>);
	virtual void addPlayer(std::unique_ptr<Player, std::default_delete<Player> >);
	virtual void takeEntity(EntityUniqueID);
	virtual void borrowEntity(EntityUniqueID, LevelChunk*);
	virtual void onPlayerDeath(Player&, const EntityDamageSource&);
	virtual void tick();
	virtual void directTickEntities(BlockSource&);
	virtual void updateSleepingPlayerList();
	virtual void setDifficulty(Difficulty);
	virtual void setCommandsEnabled(bool);
	virtual void onNewChunk(BlockSource&, LevelChunk&);
	virtual void onNewChunkFor(Player&, LevelChunk&);
	virtual void onChunkLoaded(LevelChunk&);
	virtual void queueEntityRemoval(std::unique_ptr<Entity>&&, bool);
	virtual void removeEntityReferences(Entity&, bool);
	virtual void onAppSuspended();
	virtual void getClientResourcePackManager() const;
	virtual void getServerResourcePackManager() const;
	virtual void getTradeTables();

	GameRules& getGameRules();
	EntityDefinitionGroup& getEntityDefinitions() const;
	Random* getRandom() const;
	int getSeaLevel();
	void setTime(int);
	bool isClientSide() const;
	void broadcastDimensionEvent(BlockSource&, LevelEvent, const Vec3&, int, Player*);
	void broadcastLevelEvent(LevelEvent, const Vec3&, int, Player*);
};

