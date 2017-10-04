#pragma once

#include <string>

class GameRules {
public:
	static const std::string DO_TNT_EXPLODE;

	bool hasRule(const std::string&) const;
	bool getBool(const std::string&) const;
};