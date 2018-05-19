#pragma once

#include "Item.h"

class BlockItem : public Item {
public:
	BlockItem(std::string const&, int);

	virtual ~BlockItem();
	virtual bool isDestructive(int) const;
	virtual bool isValidAuxValue(int) const;
	virtual std::string buildDescriptionId(const ItemInstance&) const;
	virtual bool isEmissive(int) const;
	virtual const TextureUVCoordinateSet& getIcon(int, int, bool) const;
	virtual int getIconYOffset() const;
	virtual bool _calculatePlacePos(ItemInstance&, Entity&, signed char&, BlockPos&) const;
	virtual bool _useOn(ItemInstance&, Entity&, BlockPos, signed char, float, float, float, ItemUseCallback*) const;
};

