#pragma once

class Block;

class BlockPalette {
public:
    Block* tryGetLegacyBlockState(unsigned int) const;
};