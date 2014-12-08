//
//  World.cpp
//  Project: Isolation
//
//  Created by Nathan Hunt on 9/17/14.
//  Copyright (c) 2014 Multidimensional Programming. All rights reserved.
//

#include "World.h"

World::World()
{
	entities = new Entity[10];
	numEntities = 0;
}

World::~World()
{
	
}

int World::AddEntity(Entity *entity)
{
	entities[numEntities] = *entity;
	numEntities++;
	
	return numEntities-1;
}

Entity * World::GetEntity(int index)
{
	return &entities[index];
}
