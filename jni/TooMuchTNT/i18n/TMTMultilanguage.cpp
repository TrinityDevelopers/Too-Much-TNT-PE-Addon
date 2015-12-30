#include "TMTMultilanguage.h"

std::string TMTMultilanguage::get(const std::string& key) {
	std::string langcode = I18n::get("language.code");
	
	/*
	if (langcode == "es_MX") {
		return "TODO: Spanish"
	}
	else {	// en_US by default
		return "TODO: English";
	}
	*/
	
	return "";
}
