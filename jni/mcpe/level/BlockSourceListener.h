#pragma once

#include <memory>

class BlockSource;
class BlockPos;
class FullBlock;
class Entity;
class BlockEntity;

class BlockSourceListener {
public: 
	virtual ~BlockSourceListener();
	virtual void onSourceCreated(BlockSource&);
	virtual void onSourceDestroyed(BlockSource&);
	virtual void onAreaChanged(BlockSource&, const BlockPos&, const BlockPos&);
	virtual void onBlockChanged(BlockSource&, const BlockPos&, FullBlock, FullBlock, int, Entity*);
	virtual void onBrightnessChanged(BlockSource&, const BlockPos&);
	virtual void onBlockEntityChanged(BlockSource&, BlockEntity&);
	virtual void onEntityChanged(BlockSource&, Entity&);
	virtual void onBlockEntityRemoved(BlockSource&, std::unique_ptr<BlockEntity>);
	virtual void onBlockEvent(BlockSource&, int, int, int, int, int);
};