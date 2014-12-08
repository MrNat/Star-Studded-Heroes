//
//  World.h
//  Project: Isolation
//
//  Created by Nathan Hunt on 9/17/14.
//  Copyright (c) 2014 Multidimensional Programming. All rights reserved.
//

#ifndef __Project__Isolation__World__
#define __Project__Isolation__World__

#include "Entity.h"

typedef struct
{
	float x, y, vx, vy;
} EntityData;

class World
{
private:
	// Entities //
	Entity *entities;
	int numEntities;
	
public:
	World();
	~World();
	
	int AddEntity(Entity *entity); // Returns index
	Entity *GetEntity(int index); // Returns entity
	
};

#endif /* defined(__Project__Isolation__World__) */
