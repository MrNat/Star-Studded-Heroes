//
//  CoreEngine.h
//  Project: Isolation
//
//  Created by Nathan Hunt on 9/8/14.
//  Copyright (c) 2014 Multidimensional Programming. All rights reserved.
//

#ifndef __Project__Isolation__CoreEngine__
#define __Project__Isolation__CoreEngine__

#include "InputModule.h"
#include "PhysicsModule.h"
#include "RenderModule.h"

#include "World.h"

#include "EntityRenderComponent.h"
#include "EntityPhysicsComponent.h"



class CoreEngine
{
private:
	// SDL Window Information //
	SDL_Window *mainWindow;
	
	// FPS //
	void UpdateFPSCounter();
	
	// World Data //
	World *world;
	
	// Modules //
	InputModule *inputModule;
	PhysicsModule *physicsModule;
	RenderModule *renderModule;
	
public:
	// Init and Dealloc //
	CoreEngine();
	~CoreEngine();
	
	// One call to start, might split up later //
	void Start();

	// Activate/Deactivate Modules //
	void EnableInputModule(void);
	void DisableInputModule(void);

	void EnablePhysicsModule(void);
	void DisablePhysicsModule(void);

	void EnableRenderModule(void);
	void DisableRenderModule(void);
 
};

#endif /* defined(__Project__Isolation__CoreEngine__) */
