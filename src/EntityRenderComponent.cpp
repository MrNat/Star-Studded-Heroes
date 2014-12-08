//
//  EntityRenderComponent.cpp
//  Project: Isolation
//
//  Created by Nathan Hunt on 9/17/14.
//  Copyright (c) 2014 Multidimensional Programming. All rights reserved.
//

#include "EntityRenderComponent.h"

#include <GL/glew.h>

#define GLM_FORCE_RADIANS
#include "glm/glm.hpp"
#include "glm/gtc/type_ptr.hpp"
#include "glm/gtc/matrix_transform.hpp"

EntityRenderComponent::EntityRenderComponent() : RenderComponent()
{
	float w = 5;
	float h = 5;
	
	// Gen VBOS //
	float points[] = {
		-w, -h,
		 w, -h,
		-w,  h,
		-w,  h,
		 w, -h,
		 w,  h,
	};
	
	GLuint vbo = 0;
	glGenBuffers(1, &vbo);
	glBindBuffer(GL_ARRAY_BUFFER, vbo);
	glBufferData(GL_ARRAY_BUFFER, sizeof(points), points, GL_STATIC_DRAW);
	
	vao = 0;
	glGenVertexArrays(1, &vao);
	glBindVertexArray(vao);
	glEnableVertexAttribArray(0);
	glBindBuffer(GL_ARRAY_BUFFER, vbo);
	glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 0, NULL);
}

EntityRenderComponent::~EntityRenderComponent()
{
	
}

void EntityRenderComponent::AttachEntity(Entity *entity)
{
	entityReference = entity;
}

void EntityRenderComponent::Render()
{
	//glUseProgram(shaderProgram);
	glBindVertexArray(vao);
	glDrawArrays(GL_TRIANGLES, 0, 6);
}