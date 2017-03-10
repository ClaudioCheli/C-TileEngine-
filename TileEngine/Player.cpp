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

Player::Player(std::string tilesetImagePath, std::string tilesetDefinitionPath, Shader* shader){
	this->shader = shader;

	position.x = 0.0f;
	position.y = 0.0f;
	position.z = 0.0f;

	playerTexture = new Texture();
	playerTexture->loadTexture(tilesetImagePath.c_str());

	XMLDocument playerXMLFile;
	GLint errorID = playerXMLFile.LoadFile(tilesetDefinitionPath.c_str());
	if(errorID == XML_ERROR_FILE_NOT_FOUND)
		std::cout << "TinyXML error id: " << errorID << std::endl;
	XMLElement* texture = playerXMLFile.FirstChildElement("Object")->FirstChildElement("Texture");
	int textureWidth, textureHeight, tilesNumber, tilesWidth, tilesHeight;
	texture->QueryIntAttribute("width", &textureWidth);
	texture->QueryIntAttribute("height", &textureHeight);
	texture->QueryIntAttribute("tilesNumber", &tilesNumber);
	texture->QueryIntAttribute("tileWidth", &tilesWidth);
	texture->QueryIntAttribute("tileHeight", &tilesHeight);
	GLuint columns = textureWidth / tilesWidth;
	GLuint rows    = textureHeight / tilesHeight;
	#ifdef DEBUG
    std::cout << "Player info:" << std::endl
    		  << "	textureWidth: " << textureWidth << std::endl
			  << "	textureHeight: " << textureHeight << std::endl
			  << "	tilesNumber: " << tilesNumber << std::endl
			  << "	tileWidth: " << tilesWidth << std::endl
			  << "	tileHeight: " << tilesHeight << std::endl
			  << "	colums: " << columns << std::endl
			  << "	rows: " << rows << std::endl;
	#endif
	this->tileset   = new Tileset(tilesWidth, tilesHeight, 0, columns, rows, "Player");

	XMLElement* animations = playerXMLFile.FirstChildElement("Object")->FirstChildElement("Animations");
	XMLElement* animation  = animations->FirstChildElement("Animation");
	std::vector<GLuint> frameTextureId;
	int animationLength = 0;
	animation->QueryIntAttribute("length", &animationLength);
	frameTextureId = readAnimation(animation, animationLength);
	this->walkRight = new PlayerAnimation(animationLength, frameTextureId);

	animation = animation->NextSiblingElement("Animation");
	animation->QueryIntAttribute("length", &animationLength);
	frameTextureId = readAnimation(animation, animationLength);
	this->walkLeft = new PlayerAnimation(animationLength, frameTextureId);

	createModelMatrix();

	bindBuffers();
}

std::vector<GLuint> Player::readAnimation(XMLElement* animation, int animationLength){
	std::vector<GLuint> frameTextureId(animationLength);
	XMLElement* frame = animation->FirstChildElement("Frame");
	while(frame != NULL){
		frameTextureId.push_back(frame->IntAttribute("subTextureId"));
		frame = frame->NextSiblingElement("Frame");
	}
	return frameTextureId;
}

/*
 * Implements from Renderable
 */
void Player::render(){
	shader->start();

	bindTexture();
	glBindVertexArray(VAO);
	bindUniform();
	glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
	glBindVertexArray(0);

	shader->stop();
}

void Player::bindProjectionMatrix(glm::mat4 projectionMatrix){
	shader->start();
	shader->loadProjectionMatrix(projectionMatrix);
	shader->stop();
}

void Player::update(){

}

void Player::bindUniform(){
	tileset->bindNumberOfColumns(shader);
	tileset->bindNumberOfRows(shader);

	GLuint textureIndex = glGetUniformLocation(shader->getProgramID(), "textureIndex");
	glUniform1i(textureIndex, 1);

	GLuint modelMatrixLocation = glGetUniformLocation(shader->getProgramID(), "model");
	glUniformMatrix4fv(modelMatrixLocation, 1, GL_FALSE, glm::value_ptr(modelMatrix));
}

void Player::bindTexture(){
	glActiveTexture(GL_TEXTURE0);
	glBindTexture(GL_TEXTURE_2D, playerTexture->getTextureID());
}

void Player::bindBuffers(){
	glGenVertexArrays(1, &VAO);
	glGenBuffers(1, &VBO);
	glGenBuffers(1, &EBO);

	glBindVertexArray(VAO);

	//Bind vertexBuffer
	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glBufferData(GL_ARRAY_BUFFER, sizeof(playerVertex), playerVertex, GL_STATIC_DRAW);

	//Bind indexBuffer
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(playerIndex), playerIndex, GL_STATIC_DRAW);

	//vertexPosition
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 5*sizeof(GLfloat), (GLvoid*)0);
	glEnableVertexAttribArray(0);

	//texture
	glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 5*sizeof(GLfloat), (GLvoid*)(3*sizeof(GLfloat)));
	glEnableVertexAttribArray(1);

	glBindVertexArray(0);
}

void Player::createModelMatrix(){
	modelMatrix = glm::translate(position)
				* glm::rotate(0.0f, glm::vec3(0.0f, 1.0f, 0.0f))
				* glm::scale(glm::vec3(1.0f, 1.0f, 1.0f));
}


