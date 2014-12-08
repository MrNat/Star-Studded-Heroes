//
//  InputModule.cpp
//  Project: Isolation
//
//  Created by Nathan Hunt on 9/14/14.
//  Copyright (c) 2014 Multidimensional Programming. All rights reserved.
//

#include "InputModule.h"

#include <iostream>

InputModule::InputModule() : Module()
{
	jumpButton = new JumpCommand();
}

InputModule::~InputModule()
{
	
}

Command * InputModule::HandleInput(SDL_Event event)
{
	if (event.type == SDL_KEYUP)
	{
		if (event.key.keysym.sym == SDLK_SPACE) return jumpButton;
	}

	return NULL;
}