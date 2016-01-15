#include "TMTMultilanguage.h"

std::map<std::string, std::string> TMTMultilanguage::en_US = {{"tile.TNTx5.name", "TNTx5"}};
std::map<std::string, std::string> TMTMultilanguage::es_MX = {{"tile.TNTx5.name", "TranslateThisPlz"}};

std::string TMTMultilanguage::get(const std::string& key) {
	std::string langcode = I18n::get("language.code");
	
	/*if(langcode == "es_MX")
		return es_MX[key];
	else {*/
		return en_US[key];
	//}
}
