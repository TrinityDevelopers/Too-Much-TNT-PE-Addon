#pragma once

#include "Item.h"

class TileItem : public Item{
public:
	char filler_tileitem[84];
	// constructor
	TileItem(int);
};