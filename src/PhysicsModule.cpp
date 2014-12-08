//
//  PhysicsModule.cpp
//  Project: Isolation
//
//  Created by Nathan Hunt on 9/14/14.
//  Copyright (c) 2014 Multidimensional Programming. All rights reserved.
//

#include "PhysicsModule.h"

PhysicsModule::PhysicsModule(World *world) : Module()
{
	worldReference = world;
	
	physicsComponents = new EntityPhysicsComponent[10];
	componentCount = 0;
}

PhysicsModule::~PhysicsModule()
{
	
}

void PhysicsModule::AddPhysicsComponent(EntityPhysicsComponent *component)
{
	physicsComponents[componentCount] = *component;
	componentCount++;
}

void PhysicsModule::Update()
{
	if (!active) return;

	if (componentCount > 0)
	{
		for (int i = 0; i < componentCount; i++)
		{
			Entity *entity = worldReference->GetEntity(0);
			physicsComponents[i].Update(*entity);
		}
	}
}