//
//  EntityPhysicsComponent.cpp
//  Project: Isolation
//
//  Created by Nathan Hunt on 9/17/14.
//  Copyright (c) 2014 Multidimensional Programming. All rights reserved.
//

#include "EntityPhysicsComponent.h"

EntityPhysicsComponent::EntityPhysicsComponent()
{
	
}

EntityPhysicsComponent::~EntityPhysicsComponent()
{
	
}

void EntityPhysicsComponent::Update(Entity &entity)
{
	entity.OffsetX(entity.GetVX());
	entity.OffsetY(entity.GetVY());
}