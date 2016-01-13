#pragma once

#include <map>

#include "mcpe/i18n/I18n.h"

class TMTMultilanguage {
public:
	static std::map<std::string, std::string> en_US;
	
	static std::string get(const std::string&);
};
