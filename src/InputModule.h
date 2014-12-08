//
//  InputModule.h
//  Project: Isolation
//
//  Created by Nathan Hunt on 9/14/14.
//  Copyright (c) 2014 Multidimensional Programming. All rights reserved.
//

#ifndef __Project__Isolation__InputModule__
#define __Project__Isolation__InputModule__

#include "Module.h"
//#include "Command.h"

#include "JumpCommand.h"

#include <SDL.h>

class InputModule : public Module
{
private:
	Command * jumpButton;

public:
	InputModule();
	~InputModule();
	
	Command *HandleInput(SDL_Event event);
};

#endif /* defined(__Project__Isolation__InputModule__) */
