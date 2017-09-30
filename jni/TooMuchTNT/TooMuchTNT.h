#pragma once
class Block;

class TooMuchTNT {
public:
	static Block* TNTx5;
	
	static void initBlocks();
	static void initBlockItems();
	static void initBlockGraphics();
	static int getNextBlockId();
	
	static void registerCreativeItems();
};
