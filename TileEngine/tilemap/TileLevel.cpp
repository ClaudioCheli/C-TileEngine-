/*
 * TileLevel.cpp
 *
 *  Created on: 22 dic 2016
 *      Author: Claudio
 */

#include "TileLevel.h"

TileLevel::TileLevel(){

}

TileLevel::TileLevel(const GLchar* layerData, Tileset* tileset, GLuint width, GLuint height){
	this->tileset = tileset;
	this->levelWidth = width;
	this->levelHeight = height;
	this->tileCount = width*height;
	tileIDs = getIntData(layerData);
	tilePositions = calculateTilesPosition();
}

void TileLevel::bindSSBO(GLuint VAO){
	GLuint size = tileIDs.size();
	GLuint layerData[size];
	for(GLuint i=0; i<size; i++){
		layerData[i] = tileIDs.at(i);
	}

	glBindVertexArray(VAO);

	glGenBuffers(1, &ssbo);
	glBindBuffer(GL_SHADER_STORAGE_BUFFER, ssbo);
	glBufferData(GL_SHADER_STORAGE_BUFFER, size*sizeof(GLuint), &layerData, GL_STATIC_DRAW);
	glBindBufferBase(GL_SHADER_STORAGE_BUFFER, 0, ssbo);
	glBindBuffer(GL_SHADER_STORAGE_BUFFER, 0);
}

void TileLevel::bindUniform(Shader* shader){
	tileset->bindNumberOfColumns(shader);
	tileset->bindNumberOfRows(shader);
}

std::vector<GLuint> TileLevel::getIntData(std::string layer){
	std::istringstream f(layer);
	std::string token;
	std::vector<GLuint> layerIntData;
	GLuint intToken;
	while(std::getline(f, token, ',')){
		intToken = atoi(token.c_str());
		layerIntData.push_back(intToken);
	}
	return layerIntData;
}

std::vector<glm::vec3> TileLevel::calculateTilesPosition(){
	std::vector<glm::vec3> tilePositions;
	glm::vec2 dimension = tileset->getTileDimensions();
	for(GLuint i=0; i<levelWidth; i++){
		for(GLuint j=0; j<levelHeight; j++){
			tilePositions.push_back(glm::vec3(j*dimension.x, i*dimension.y, 50));
		}
	}
	return tilePositions;
}


