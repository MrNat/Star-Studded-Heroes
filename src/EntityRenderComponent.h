//
//  EntityRenderComponent.h
//  Project: Isolation
//
//  Created by Nathan Hunt on 9/17/14.
//  Copyright (c) 2014 Multidimensional Programming. All rights reserved.
//

#ifndef __Project__Isolation__EntityRenderComponent__
#define __Project__Isolation__EntityRenderComponent__

#include "Entity.h"
#include "RenderComponent.h"

class EntityRenderComponent : public RenderComponent
{
private:
	unsigned int vao;
	
	Entity *entityReference;
	
public:
	EntityRenderComponent();
	~EntityRenderComponent();
	
	void AttachEntity(Entity *entity);
	void Render();
};

#endif /* defined(__Project__Isolation__EntityRenderComponent__) */
