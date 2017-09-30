#pragma once

class Random;

class Level  {
public:
	virtual ~Level();
	Random* getRandom() const;
	int getSeaLevel();
	void setTime(int);
	bool isClientSide() const;
};

