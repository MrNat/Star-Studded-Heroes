//
//  CoreEngine.cpp
//  Project: Isolation
//
//  Created by Nathan Hunt on 9/8/14.
//  Copyright (c) 2014 Multidimensional Programming. All rights reserved.
//

#include "CoreEngine.h"
#include "Settings.h"

#include <SDL.h>
#include <SDL_opengl.h>

#include <iostream>

// MAIN ENGINE INIT //
CoreEngine::CoreEngine(void)
{
	
}

void CoreEngine::Start(void)
{
	// Initialize SDL //
	SDL_Init(SDL_INIT_VIDEO);
	
	// Create SDL Window //
	SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_CORE);
	SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 3);
	SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 2);
	
	mainWindow = SDL_CreateWindow("Star-Studded Heroes", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, SCREEN_W, SCREEN_H, SDL_WINDOW_OPENGL);
	if (!mainWindow)
	{
		SDL_Quit();
		exit(2);
	}
	SDL_GLContext context = SDL_GL_CreateContext(mainWindow);

	// Load World Data //
	Entity *butt = new Entity(10, 10, 2, 0);
	
	world = new World();
	world->AddEntity(butt);
	
	// Init Modules //
	inputModule = new InputModule();
	physicsModule = new PhysicsModule(world);
	EntityPhysicsComponent *epc = new EntityPhysicsComponent();
	//epc->AttachEntity(butt);
	physicsModule->AddPhysicsComponent(epc);
	
	renderModule = new RenderModule(mainWindow, world);
	EntityRenderComponent *erc = new EntityRenderComponent();
	erc->AttachEntity(butt);
	renderModule->AddRenderComponent(erc);
	

	// Enable everything //
	EnableInputModule();
	//EnablePhysicsModule();
	EnableRenderModule();


	bool quit = false;
	SDL_Event windowEvent;
	while (!quit)
	{
		UpdateFPSCounter();
		
		//SDL_PollEvent(&windowEvent);
		while (SDL_PollEvent(&windowEvent))
		{
			if (windowEvent.type == SDL_QUIT) quit = true;
			if (windowEvent.type == SDL_KEYUP && windowEvent.key.keysym.sym == SDLK_ESCAPE) quit = true;

			Command *buttonPress = inputModule->HandleInput(windowEvent);
			if (buttonPress) buttonPress->execute();

			// Temp //
			/*
			if (windowEvent.type == SDL_KEYUP)
			{
				if (windowEvent.key.keysym.sym == SDLK_0)
					std::cout << "--- Module Check ---\n - Input Module:\t" << (inputModule->IsEnabled() ? "enabled" : "disabled") << "\n - Physics Module:\t" << (physicsModule->IsEnabled() ? "enabled" : "disabled") << "\n - Render Module:\t" << (renderModule->IsEnabled() ? "enabled" : "disabled") << "\n";

				if (windowEvent.key.keysym.sym == SDLK_1)
				{
					inputModule->Toggle();
					std::cout << "Input Module:\t" << (inputModule->IsEnabled() ? "enabled" : "disabled") << "\n";
				}
				if (windowEvent.key.keysym.sym == SDLK_2)
				{
					physicsModule->Toggle();
					std::cout << "Physics Module:\t" << (physicsModule->IsEnabled() ? "enabled" : "disabled") << "\n";
				}
				if (windowEvent.key.keysym.sym == SDLK_3)
				{
					renderModule->Toggle();
					std::cout << "Render Module:\t" << (renderModule->IsEnabled() ? "enabled" : "disabled") << "\n";
				}
				
			}
			*/
		}

		//inputModule->Update(windowEvent);
		physicsModule->Update();
		renderModule->Render();
	}
}

void CoreEngine::EnableInputModule()
{
	inputModule->Enable();
}
void CoreEngine::DisableInputModule()
{
	inputModule->Disable();
}

void CoreEngine::EnablePhysicsModule()
{
	physicsModule->Enable();
}
void CoreEngine::DisablePhysicsModule()
{
	physicsModule->Disable();
}

void CoreEngine::EnableRenderModule()
{
	renderModule->Enable();
}
void CoreEngine::DisableRenderModule()
{
	renderModule->Disable();
}

void CoreEngine::UpdateFPSCounter()
{
	static double previousSeconds = SDL_GetTicks() / 1000;
	static int frameCount;
	
	double currentSeconds = SDL_GetTicks() / 1000;
	double elapsedSeconds = currentSeconds - previousSeconds;
	if (elapsedSeconds > 0.25)
	{
		previousSeconds = currentSeconds;
		double fps = (double)frameCount / elapsedSeconds;
		char temp[128];
		sprintf_s(temp, "Project: Isolation - FPS: %.2f", fps);
		SDL_SetWindowTitle(mainWindow, temp);

		frameCount = 0;
	}
	frameCount++;
}

// SHUTDOWN AND DEALLOC //
CoreEngine::~CoreEngine(void)
{
	SDL_DestroyWindow(mainWindow);
	SDL_Quit();
}

