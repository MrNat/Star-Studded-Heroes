//
//  RenderModule.cpp
//  Project: Isolation
//
//  Created by Nathan Hunt on 9/14/14.
//  Copyright (c) 2014 Multidimensional Programming. All rights reserved.
//

#include "RenderModule.h"

#include <iostream>
#include <sstream>
#include <fstream>
#include <vector>

RenderModule::RenderModule(SDL_Window *window, World *world) : Module()
{
	// Save window pointer //
	windowReference = window;
	
	// World //
	worldReference = world;
	
	// Init GLEW //
	glewExperimental = GL_TRUE;
	glewInit(); // TODO: handle potential init error.
	
	printf("Renderer: %s\n", glGetString(GL_RENDERER));
	printf("OpenGL Version Supported: %s\n", glGetString(GL_VERSION));
	
	// Setup Matrices //
	int width, height;
	width = 800;
	height = 600;
	//glfwGetFramebufferSize(windowReference, &width, &height);
	//float ratio = width / (float) height;
	glViewport(0, 0, width, height);
	
	projectionMatrix = glm::ortho(0.0f, (float)width, (float)height, 0.0f, 1.0f, -1.0f);
	viewMatrix = glm::mat4(1.0f); // Identity
	
	// Render Components //
	renderComponents = new EntityRenderComponent[10];
	//renderComponents[0] = *new EntityRenderComponent();
	componentCount = 0;
	
	// Load Shaders //
	shaders[0] = LoadShader("src/shaders/EntityShader.vert", "src/shaders/EntityShader.frag");
	glUseProgram(shaders[0]);
	SetMatrixUniform(shaders[0], "projectionMatrix", 1, GL_FALSE, glm::value_ptr(projectionMatrix));
	SetMatrixUniform(shaders[0], "viewMatrix", 1, GL_FALSE, glm::value_ptr(viewMatrix));
	SetMatrixUniform(shaders[0], "modelMatrix", 1, GL_FALSE, glm::value_ptr(glm::mat4(1.0f)));
	glUseProgram(0);

	// By default, inactive //
	active = false;
}

/*
void RenderModule::Enable()
{
	active = true;
}

void RenderModule::Disable()
{
	active = false;
}
*/

GLuint RenderModule::LoadShader(const std::string vertexShaderFileName, const std::string fragmentShaderFileName)
{
	// Generate Shader Program ID //
	GLuint shaderProgram = glCreateProgram();
	GLuint vertexShader = glCreateShader(GL_VERTEX_SHADER);
	GLuint fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
	
	std::ifstream file;
	
	// Load vertex shader //
	file.open(vertexShaderFileName);
	if (!file.good())
	{
		std::cout << "Error - could not open vertex shader file: " << vertexShaderFileName << std::endl;
		return -1;
	}
	std::stringstream vertexShaderStream;
	vertexShaderStream << file.rdbuf();
	file.close();
	
	// Load fragment shader //
	file.open(fragmentShaderFileName);
	if (!file.good())
	{
		std::cout << "Error - could not open fragment shader file: " << fragmentShaderFileName << std::endl;
		return -1;
	}
	std::stringstream fragmentShaderStream;
	fragmentShaderStream << file.rdbuf();
	file.close();
	
	// Convert shaders //
	std::string tempVertexString = vertexShaderStream.str();
	std::string tempFragmentString = fragmentShaderStream.str();
	const char *vertexShaderSource = tempVertexString.c_str();
	const char *fragmentShaderSource = tempFragmentString.c_str();
	
	GLint result = GL_FALSE;
    int logLength;
	
	glShaderSource(vertexShader, 1, &vertexShaderSource, NULL);
	glShaderSource(fragmentShader, 1, &fragmentShaderSource, NULL);
	glCompileShader(vertexShader);
	glCompileShader(fragmentShader);
	
	glGetShaderiv(vertexShader, GL_COMPILE_STATUS, &result);
    glGetShaderiv(vertexShader, GL_INFO_LOG_LENGTH, &logLength);
    std::vector<char> vertShaderError((logLength > 1) ? logLength : 1);
    glGetShaderInfoLog(vertexShader, logLength, NULL, &vertShaderError[0]);
    std::cout << &vertShaderError[0] << std::endl;
	
	glGetShaderiv(fragmentShader, GL_COMPILE_STATUS, &result);
    glGetShaderiv(fragmentShader, GL_INFO_LOG_LENGTH, &logLength);
    std::vector<char> fragShaderError((logLength > 1) ? logLength : 1);
    glGetShaderInfoLog(fragmentShader, logLength, NULL, &fragShaderError[0]);
    std::cout << &fragShaderError[0] << std::endl;
	
	glAttachShader(shaderProgram, vertexShader);
	glAttachShader(shaderProgram, fragmentShader);
	glLinkProgram(shaderProgram);
	
	int params = -1;
	glGetProgramiv(shaderProgram, GL_LINK_STATUS, &params);
	if (params != GL_TRUE)
	{
		std::cout << "Could not link program...\n";
		int max_length = 2048;
		int actual_length = 0;
		char log[2048];
		glGetProgramInfoLog(shaderProgram, max_length, &actual_length, log);
		printf("info log: %s", log);
	}
	
	return shaderProgram;
}

void RenderModule::SetMatrixUniform(GLuint program, const char *uniformName, GLsizei count, GLboolean transpose, const GLfloat *value)
{
	GLuint location = glGetUniformLocation(program, uniformName);
	//glUseProgram(program);
	glUniformMatrix4fv(location, count, transpose, value);
	//glUseProgram(0);
}

RenderModule::~RenderModule()
{
	
}

void RenderModule::AddRenderComponent(EntityRenderComponent *component)
{
	renderComponents[componentCount] = *component;
	componentCount++;
}

void RenderModule::Render()
{
	// Only continue if active //
	if (!active)
	{
		SDL_GL_SwapWindow(windowReference);
		return;
	}

	// Clear Screen //
	glClear(GL_COLOR_BUFFER_BIT);
	glClearColor(0.13f, 0.0f, 0.11f, 1.0f);
	
	if (componentCount > 0)
	{
		glUseProgram(shaders[0]);
		
		for (int i = 0; i < componentCount; i++)
		{
			SetMatrixUniform(shaders[0], "modelMatrix", 1, GL_FALSE, glm::value_ptr(glm::translate(glm::mat4(1.0f), glm::vec3(worldReference->GetEntity(0)->GetX(), worldReference->GetEntity(0)->GetY(), 1.0f))));
			//std::cout << worldReference->GetEntity(0)->GetX() << std::endl;
			renderComponents[0].Render();
		}
		
		glUseProgram(0);
	}
	
	SDL_GL_SwapWindow(windowReference);
}