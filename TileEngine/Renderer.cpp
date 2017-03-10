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
	for(GLuint i=0; i<entities.size(); i++)
		entities.at(i)->render();
}

/*void Renderer::render(TileMap* tileMap, Player* player){
	clear();

	//---------------------Map render--------------------------------------------
	tileMap->getShader()->use();

	glActiveTexture(GL_TEXTURE0);
	glBindTexture(GL_TEXTURE_2D, tileMap->getTextureID());

	glBindVertexArray(tileMap->getVAO());
	for(GLuint levelNumber=0; levelNumber<tileMap->getLevelsNumber(); levelNumber++){
		tileMap->bindUniform(tileMap->getShader(), levelNumber);
		tileMap->bindTileLevelPositions(levelNumber);
		tileMap->bindSSBO(levelNumber);
		glDrawElementsInstanced(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0, tileMap->getVertexCount());
	}

	glBindVertexArray(0);

	//---------------------player render-----------------------------------------
	player->getShader()->use();
	player->bindUniform();
	player->bindTexture();
	glBindVertexArray(player->getVAO());
	glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
	glBindVertexArray(0);
}*/

void Renderer::clear(){
	glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}

void Renderer::setProjectionMatrix(){
	projection = glm::ortho(0.0f, (GLfloat)DisplayManager::WIDTH, (GLfloat)DisplayManager::HEIGHT, 0.0f, 0.1f, 100.0f); //left, right, bottom, top, zNear, zFar
	//projection = glm::perspective(45.0f, (GLfloat)640 / (GLfloat)480, 0.1f, 100.0f);
}

void Renderer::bindProjectionMatrix(Shader* shader){
	GLint projectionLocation = glGetUniformLocation(shader->getProgramID(), "projection");
	glUniformMatrix4fv(projectionLocation, 1, GL_FALSE, glm::value_ptr(projection));
}


