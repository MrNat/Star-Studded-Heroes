//
//  RenderModule.h
//  Project: Isolation
//
//  Created by Nathan Hunt on 9/14/14.
//  Copyright (c) 2014 Multidimensional Programming. All rights reserved.
//

#ifndef __Project__Isolation__RenderModule__
#define __Project__Isolation__RenderModule__

#include <string>

//#define GLEW_STATIC
#include <GL\glew.h>
#include <SDL.h>
#include <SDL_opengl.h>

#define GLM_FORCE_RADIANS
#include "glm/glm.hpp"
#include "glm/gtc/type_ptr.hpp"
#include "glm/gtc/matrix_transform.hpp"

#include "Module.h"
#include "EntityRenderComponent.h"
#include "World.h"

class RenderModule : public Module
{
private:
	// SDL Window Reference //
	SDL_Window *windowReference;

	// Matrices //
	glm::mat4 projectionMatrix;
	glm::mat4 viewMatrix; // Camera?
	
	// Shader Data //
	GLuint shaders[10]; // 10 is temp max
	GLuint LoadShader(const std::string vertexShaderFileName, const std::string fragmentShaderFileName);
	void SetMatrixUniform(GLuint program, const char *uniformName, GLsizei count, GLboolean transpose, const GLfloat *value);
	
	// Entity Render Components //
	EntityRenderComponent *renderComponents;
	int componentCount;
	
	World *worldReference;
	
public:
	RenderModule(SDL_Window *window, World *world);
	~RenderModule();

	void AddRenderComponent(EntityRenderComponent *component);
	
	void Render();
};

#endif /* defined(__Project__Isolation__RenderModule__) */
