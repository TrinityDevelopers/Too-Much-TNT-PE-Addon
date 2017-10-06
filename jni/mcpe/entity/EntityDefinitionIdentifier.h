#pragma once

#include <string>
#include "EntityType.h"

class EntityDefinitionIdentifier {
public:
	//std::string a, id, event;
	char data[12];

	EntityDefinitionIdentifier(const EntityDefinitionIdentifier&);
	EntityDefinitionIdentifier(EntityDefinitionIdentifier&&);
	EntityDefinitionIdentifier(EntityType);
	EntityDefinitionIdentifier(const char*);
	EntityDefinitionIdentifier(const std::string&);
	EntityDefinitionIdentifier(const std::string&, const std::string&, const std::string&);
	EntityDefinitionIdentifier();
	std::string getCanonicalName() const;
	std::string getFullName() const;
	EntityDefinitionIdentifier& operator=(const EntityDefinitionIdentifier&);
	bool operator==(const EntityDefinitionIdentifier&);
};