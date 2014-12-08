//
//  RenderComponent.h
//  Project: Isolation
//
//  Created by Nathan Hunt on 9/17/14.
//  Copyright (c) 2014 Multidimensional Programming. All rights reserved.
//

#ifndef __Project__Isolation__RenderComponent__
#define __Project__Isolation__RenderComponent__

class RenderComponent
{
	
public:
	RenderComponent();
	~RenderComponent();
	
	virtual void Render() = 0;
};

#endif /* defined(__Project__Isolation__RenderComponent__) */
