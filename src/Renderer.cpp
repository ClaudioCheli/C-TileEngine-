/*
 * Renderer.cpp
 *
 *  Created on: 07 ott 2016
 *      Author: clasb
 */

#include "Renderer.h"

Renderer::Renderer(){
	setProjectionMatrix();
}

void Renderer::render(std::vector<Renderable*> entities){
	clear();
	for(auto &entity : entities){
		entity->update();
		entity->bindProjectionMatrix(projection);
		entity->render();
	}

}

void Renderer::clear(){
	glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}

void Renderer::setProjectionMatrix(){
	projection = glm::ortho(0.0f, (GLfloat)DisplayManager::WIDTH, (GLfloat)DisplayManager::HEIGHT, 0.0f, 0.1f, 100.0f); //left, right, bottom, top, zNear, zFar
}


