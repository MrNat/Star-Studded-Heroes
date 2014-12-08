//
//  PhysicsModule.h
//  Project: Isolation
//
//  Created by Nathan Hunt on 9/14/14.
//  Copyright (c) 2014 Multidimensional Programming. All rights reserved.
//

#ifndef __Project__Isolation__PhysicsModule__
#define __Project__Isolation__PhysicsModule__

#include "Module.h"
#include "World.h"
#include "EntityPhysicsComponent.h"

class PhysicsModule : public Module
{
private:
	// World Reference //
	World *worldReference;
	
	// Entity Physics Components //
	EntityPhysicsComponent *physicsComponents;
	int componentCount;
	
public:
	PhysicsModule(World *world);
	~PhysicsModule();
	
	// Component Control //
	void AddPhysicsComponent(EntityPhysicsComponent *component);
	
	void Update();
};


#endif /* defined(__Project__Isolation__PhysicsModule__) */
