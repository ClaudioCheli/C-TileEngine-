/*
 * TileLevel.cpp
 *
 *  Created on: 22 dic 2016
 *      Author: Claudio
 */

#include "TileLevel.h"

TileLevel::TileLevel(){

}

TileLevel::TileLevel(const GLchar* layerData, Tileset* tileset, GLuint width, GLuint height, std::string levelName){
	this->tileset = tileset;
	this->levelWidth = width;
	this->levelHeight = height;
	this->tileCount = width*height;
	this->levelName = levelName;
	tileIDs = getIntData(layerData);
	tilePositions = calculateTilesPosition();
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
	for(GLuint i=0; i<levelHeight; i++){
		for(GLuint j=0; j<levelWidth; j++){
			tilePositions.push_back(glm::vec3(j*dimension.x, i*dimension.y, 0));
		}
	}
	return tilePositions;
}


