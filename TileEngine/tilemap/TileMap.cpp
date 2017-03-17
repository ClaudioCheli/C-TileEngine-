/*
 * TileMap.cpp
 *
 *  Created on: 04 ott 2016
 *      Author: clasb
 */

#include <fstream>
#include <iostream>

#include "TileMap.h"

#include "../Error.h"

TileMap::TileMap(){

}


void TileMap::render(){
	shader->start();

	bindAttribute();
	for(int level=0; level<levels.size(); level++){
		bindTexture(level);
		bindUniform(level);
		bindLevelSSBO(level);
		glDrawElementsInstanced(GL_TRIANGLES, indexCount, GL_UNSIGNED_INT, tileIndex,levels.at(level)->getLevelDimensions().x*levels.at(level)->getLevelDimensions().y*4);
	}
	unbindAttribute();

	shader->stop();
}

void TileMap::bindProjectionMatrix(glm::mat4 projectionMatrix){
	shader->start();
	shader->loadProjectionMatrix(projectionMatrix);
	shader->stop();
}

void TileMap::update(){

}


Tileset* TileMap::findTileset(std::string name){
	Tileset* tileset;
	GLuint i = 0;
	while( i < tilesets.size() ){
		if(tilesets.at(i)->getName() == name)
			tileset = tilesets.at(i);
		i++;
	}
	return tileset;
}

void TileMap::bindLevelSSBO(GLuint level){
	glBindVertexArray(VAO);
	glBindBufferBase(GL_SHADER_STORAGE_BUFFER, 3, ssbo[level]);
}

void TileMap::bindAttribute(){
	glBindVertexArray(VAO);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
}

void TileMap::bindTexture(GLuint level){
	glActiveTexture(GL_TEXTURE0);
	glBindTexture(GL_TEXTURE_2D, levels.at(level)->getTileset()->getTextureID());
}

void TileMap::bindUniform(GLuint level){
	shader->loadTilesetNumberOfColumns(levels.at(level)->getTileset()->getNumberOfRows());
	shader->loadTilesetNumberOfRows(levels.at(level)->getTileset()->getNumberOfRows());
}

void TileMap::unbindAttribute(){
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
	glBindVertexArray(0);
}


void TileMap::bindBuffers(){
	glGenVertexArrays(1, &VAO);
	glGenBuffers(1, &VBO);
	glGenBuffers(1, &EBO);
	glGenBuffers(1, &positionVBO);
	GLuint buffer;
	for(GLuint i=0; i<levels.size(); i++){
		glGenBuffers(1, &buffer);
		ssbo.push_back(buffer);
	}

	glBindVertexArray(VAO);

	//Bind vertexBuffer
	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glBufferData(GL_ARRAY_BUFFER, sizeof(tileVertex), tileVertex, GL_STATIC_DRAW);

	//vertexPosition
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 5*sizeof(GLfloat), (GLvoid*)0);
	glEnableVertexAttribArray(0);

	//texture
	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 5*sizeof(GLfloat), (GLvoid*)(3*sizeof(GLfloat)));
	glEnableVertexAttribArray(1);

	//Bind positionBuffer
	std::vector<glm::vec3> tilePosition = levels.at(0)->getTilePositions();
	float positions[tilePosition.size()*3];
	GLuint j=0;
	for(GLuint i=0; i<tilePosition.size(); i++){
		positions[j] = tilePosition.at(i).x; j++;
		positions[j] = tilePosition.at(i).y; j++;
		positions[j] = tilePosition.at(i).z; j++;
	}

	glBindBuffer(GL_ARRAY_BUFFER, positionVBO);
	glBufferData(GL_ARRAY_BUFFER, levels.at(0)->getTileCount()*3, positions, GL_STATIC_DRAW);
	glVertexAttribPointer(2, 3, GL_FLOAT, false, 3*sizeof(GLfloat), 0);
	glVertexAttribDivisor(2, 1);
	glEnableVertexAttribArray(2);

	//Bind ssbo
	for(GLuint i=0; i<ssbo.size(); i++){
		std::vector<GLuint> tileID = levels.at(i)->getTileIDs();
		GLuint tileIDs[tileID.size()];
		for(GLuint i=0; i<tileID.size(); i++)
			tileIDs[i] = tileID.at(i);
		glBindBuffer(GL_SHADER_STORAGE_BUFFER, ssbo[i]);
		glBufferData(GL_SHADER_STORAGE_BUFFER, tileID.size(), tileIDs, GL_STATIC_DRAW);
	}
	glBindBuffer(GL_SHADER_STORAGE_BUFFER, 0);

	glBindVertexArray(0);

	//Bind indexBuffer
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(tileIndex), tileIndex, GL_STATIC_DRAW);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);

}



