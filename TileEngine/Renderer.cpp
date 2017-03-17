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
	for(GLuint i=0; i<entities.size(); i++){
		entities[i]->update();
		entities[i]->bindProjectionMatrix(projection);
		entities[i]->render();
	}
}


void Renderer::clear(){
	glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}

void Renderer::setProjectionMatrix(){
	projection = glm::ortho(0.0f, (GLfloat)DisplayManager::WIDTH, (GLfloat)DisplayManager::HEIGHT, 0.0f, 0.1f, 100.0f); //left, right, bottom, top, zNear, zFar
	//projection = glm::perspective(45.0f, (GLfloat)640 / (GLfloat)480, 0.1f, 100.0f);
}


