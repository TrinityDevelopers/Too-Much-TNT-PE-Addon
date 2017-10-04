#pragma once
#include <string>
#include <memory>

class EntityDefinitionIdentifier;
class Entity;
class Vec3;
class Vec2;

class EntityFactory {
public:
	static std::unique_ptr<Entity> createEntity(const std::string&, const EntityDefinitionIdentifier&, Entity*, const Vec3&, const Vec2&);
	static std::unique_ptr<Entity> createSpawnedEntity(const EntityDefinitionIdentifier&, Entity*, const Vec3&, const Vec2&);
};

