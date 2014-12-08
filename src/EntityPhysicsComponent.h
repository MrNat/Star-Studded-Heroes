//
//  EntityPhysicsComponent.h
//  Project: Isolation
//
//  Created by Nathan Hunt on 9/17/14.
//  Copyright (c) 2014 Multidimensional Programming. All rights reserved.
//

#ifndef __Project__Isolation__EntityPhysicsComponent__
#define __Project__Isolation__EntityPhysicsComponent__

#include "World.h"

class EntityPhysicsComponent
{
private:
	Entity entityReference;
	
public:
	EntityPhysicsComponent();
	~EntityPhysicsComponent();
	
	void Update(Entity &entity);
};

#endif /* defined(__Project__Isolation__EntityPhysicsComponent__) */
