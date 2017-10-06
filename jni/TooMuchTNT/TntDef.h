#pragma once

enum class TntType : int {
	REGULAR,
	TNTX5,
	TNTX20,
	TNTX100,
	TNTX500
};

enum class TntStat : int {
	REGULAR,
	FROM_EXPLOSION
};

class TntDef {
public:
	TntType type;
	TntStat stat;
	TntDef(TntType _type, TntStat _stat) : type(_type), stat(_stat) { }
};