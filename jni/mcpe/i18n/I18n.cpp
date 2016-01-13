#include "I18n.h"

std::string I18n::languages[14] = {"en_US", "de_DE", "es_ES", "es_MX", "fr_FR", "fr_CA", "it_IT", "ja_JP", "ko_KR", "pt_BR", "pt_PT", "ru_RU", "zh_CN", "zh_TW"};

std::string I18n::getCurrentLangString() {
        for(int l = 0; l < 14; l++) {
                if(getCurrentLanguage() == getLocaleFor(languages[l]))
                        return languages[l];
        }
}
