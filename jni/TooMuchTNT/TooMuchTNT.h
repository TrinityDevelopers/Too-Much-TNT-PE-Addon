#pragma once
class Block;

class TooMuchTNT {
public:
	static Block* TNTx5;
	
	static void initBlocks();
	static void registerBlocks();
	static void registerBlock(Block*);
	static int getNewRandomID();
	
	static void registerCreativeItems();
};