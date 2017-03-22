/*
 * DisplayManager.cpp
 *
 *  Created on: 03 ott 2016
 *      Author: clasb
 */

#include "DisplayManager.h"

DisplayManager::DisplayManager(){
	closeRequest = false;
}

void DisplayManager::Init(){
	SDL_Init(SDL_INIT_VIDEO);
	SDL_GL_SetAttribute( SDL_GL_CONTEXT_MAJOR_VERSION, 3 );
	SDL_GL_SetAttribute( SDL_GL_CONTEXT_MINOR_VERSION, 3 );
	SDL_GL_SetAttribute( SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_CORE );
}

void DisplayManager::CreateDisplay(std::string title){
	window = SDL_CreateWindow( title.c_str(), SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, WIDTH, HEIGHT, SDL_WINDOW_OPENGL | SDL_WINDOW_SHOWN );
	context = SDL_GL_CreateContext(window);

	glewExperimental = GL_TRUE;
	glewInit();

	glEnable(GL_DEPTH_TEST);
}

void DisplayManager::setWindowTitle(std::string title){
	SDL_SetWindowTitle(window, title.c_str());
}

DisplayManager::~DisplayManager(){
	SDL_DestroyWindow(window);
	window = NULL;
	SDL_Quit();
}


