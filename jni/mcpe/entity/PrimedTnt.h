#pragma once

#include "Entity.h"

class PrimedTnt : public Entity {
public:
	PrimedTnt(EntityDefinitionGroup&, const EntityDefinitionIdentifier&); 
	
	virtual void reloadHardcoded(Entity::InitializationMethod, const VariantParameterList&);
	virtual void reloadHardcodedClient(Entity::InitializationMethod, const VariantParameterList&);
	virtual ~PrimedTnt();
	virtual void getOwnerEntityType();
	virtual void normalTick();
	virtual void getShadowHeightOffs();
	virtual void getShadowRadius() const;
	virtual bool isPickable();
	virtual bool isPushableByPiston() const;
	virtual EntityType getEntityTypeId() const;
	virtual void getSourceUniqueID() const;
	virtual void _hurt(const EntityDamageSource&, int, bool, bool);
	virtual void readAdditionalSaveData(const CompoundTag&);
	virtual void addAdditionalSaveData(CompoundTag&);
};