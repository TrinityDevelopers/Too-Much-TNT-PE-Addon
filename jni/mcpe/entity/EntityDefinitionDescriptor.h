#pragma once

#include <string>

class Entity;
class VariantParameterList;

class EntityDefinitionDescriptor {
public:
	void executeEvent(Entity&, const std::string&, const VariantParameterList&);
};