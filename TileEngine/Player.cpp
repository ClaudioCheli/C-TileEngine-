/*
 * Player.cpp
 *
 *  Created on: 02 gen 2017
 *      Author: Claudio
 */

#include "Player.h"

#include <glm/glm.hpp>
#include <glm/gtx/transform.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

Player::Player(){

}


void Player::render(){
	shader->start();

	bindAttribute();
	bindTexture();
	bindUniform();
	glDrawElements(GL_TRIANGLES, tile->getIndexCount(), GL_UNSIGNED_INT, 0);
	unbindAttribute();

	shader->stop();
}

void Player::bindAttribute(){
	glBindVertexArray(VAO);
	glEnableVertexAttribArray(0);
	glEnableVertexAttribArray(1);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
}

void Player::bindProjectionMatrix(glm::mat4 projectionMatrix){
	shader->start();
	shader->loadProjectionMatrix(projectionMatrix);
	shader->stop();
}

void Player::unbindAttribute(){
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
	glDisableVertexAttribArray(0);
	glDisableVertexAttribArray(1);
	glBindVertexArray(0);
}

void Player::update(){

}

void Player::bindUniform(){
	shader->loadModelMatrix(tile->getModelMatrix());
	shader->loadTilesetNumberOfRows(tilesets[0]->getNumberOfRows());
	shader->loadTilesetNumberOfColumns(tilesets[0]->getNumberOfColumns());
	shader->loadTextureIndex(currentAnimation->getCurrentId());
}

void Player::bindTexture(){
	glActiveTexture(GL_TEXTURE0);
	glBindTexture(GL_TEXTURE_2D, tilesets[0]->getTextureID());
}

void Player::bindBuffers(){
	glGenVertexArrays(1, &VAO);
	glCheckError();
	glGenBuffers(1, &VBO);
	glGenBuffers(1, &EBO);

	glBindVertexArray(VAO);
	glCheckError();

	//Bind vertexBuffer
	std::vector<float> vertexArray = tile->getVertexArray();
	float playerVertex[vertexArray.size()];
	for(GLuint i=0; i<vertexArray.size(); i++)
		playerVertex[i] = vertexArray[i];
	std::cout << "Player Vertex: " << std::endl;
	for(int i=0; i<vertexArray.size(); i++){
		std::cout << playerVertex[i] << ", ";
	}

	std::cout << std::endl;
	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glBufferData(GL_ARRAY_BUFFER, sizeof(playerVertex), playerVertex, GL_STATIC_DRAW);
	glCheckError();

	//Bind indexBuffer
	std::vector<int> indexArray = tile->getIndexArray();
	int playerIndex[indexArray.size()];
	for(GLuint i=0; i<indexArray.size(); i++)
		playerIndex[i] = indexArray[i];
	std::cout << "Player index: " << std::endl;
	for(int i=0; i<indexArray.size(); i++){
		std::cout << playerIndex[i] << ", ";
	}

	std::cout << std::endl;
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(playerIndex), playerIndex, GL_STATIC_DRAW);
	glCheckError();

	//vertexPosition
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 5*sizeof(GLfloat), (GLvoid*)0);
	glEnableVertexAttribArray(0);
	glCheckError();

	//texture
	glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 5*sizeof(GLfloat), (GLvoid*)(3*sizeof(GLfloat)));
	glEnableVertexAttribArray(1);
	glCheckError();

	glBindVertexArray(0);
}

void Player::setAnimation(Animation* animation){
	if(animation->getName().compare("walk_up"))
		walkUp = animation;
	if(animation->getName().compare("walk_down"))
			walkDown = animation;
	if(animation->getName().compare("walk_left"))
			walkLeft = animation;
	if(animation->getName().compare("walk_right"))
			walkRight = animation;
	if(animation->getName().compare("idle_down"))
			idleDown = animation;
}


