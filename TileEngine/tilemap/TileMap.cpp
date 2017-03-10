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

TileMap::TileMap(Shader* shader){
	this->shader = shader;

	loadMapDefinition("Debug//tileMap//baseMap.tmx");

	loadTexture("Debug//tileMap//mapPackTilesheet.png");

	shader->start();
	bindBuffers();
}

void TileMap::render(){
	shader->start();
	bindTexture();
	glBindVertexArray(VAO);
	for(GLuint levelNumber=0; levelNumber<tileMap.size(); levelNumber++){
		bindUniform(shader, levelNumber);
		bindTileLevelPositions(levelNumber);
		bindSSBO(levelNumber);
		glDrawElementsInstanced(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0, tileCount*4);
	}
	glBindVertexArray(0);
}

void TileMap::loadTexture(std::string imagePath){
	mapTexture = new Texture();
	mapTexture->loadTexture(imagePath);
}

void TileMap::loadMapDefinition(std::string mapDefinitionFilePath){

	GLint errorID = mapXMLFile.LoadFile(mapDefinitionFilePath.c_str());
	if(errorID == XML_ERROR_FILE_NOT_FOUND)
		std::cout << "TinyXML error id: " << errorID << std::endl;
	XMLElement* mapElement = mapXMLFile.FirstChildElement("map");
	// Legge le dimensioni della mappa
	int dimension;
	mapElement->QueryIntAttribute("width", &dimension);
	mapDimension.x = dimension;
	mapElement->QueryIntAttribute("height", &dimension);
	mapDimension.y = dimension;

	// Calcola il numero di tile di ogni livello
	tileCount = mapDimension.x * mapDimension.y;
	std::cout << "tileCount: " << tileCount << std::endl;

	// Legge le dimensioni delle tile e il numero di colonne del tileset
	XMLElement* tileset = mapXMLFile.FirstChildElement("map")->FirstChildElement("tileset");
	int tileWidth, tileHeight, firstTileID, columns;
	std::string tilesetName;
	while(tileset != NULL){
		tileset->QueryIntAttribute("tilewidth", &tileWidth);
		tileset->QueryIntAttribute("tileheight", &tileHeight);
		tileset->QueryIntAttribute("columns", &columns);
		tileset->QueryIntAttribute("firstgid", &firstTileID);
		tilesetName = tileset->Attribute("name");
		tilesets.push_back(new Tileset(tileWidth, tileHeight, firstTileID, columns, columns, tilesetName));

		tileset = tileset->NextSiblingElement("tileset");
	}

	// Legge i dati di ogni livello
	XMLElement* layer = mapXMLFile.FirstChildElement("map")->FirstChildElement("layer");
	XMLElement* data = layer->FirstChildElement("data");
	XMLElement* property = layer->FirstChildElement("properties")->FirstChildElement("property");
	const GLchar* layerData; // Contiene i dati di un livello
	int width;
	int height;
	layer->QueryIntAttribute("width", &width);
	layer->QueryIntAttribute("height", &height);
	std::vector<std::string> layers; // Contiene i dati di tutti i livelli, uno per posizione
	while(layer != NULL){
		// Legge i dati del livello corrente
		layerData = data->GetText();
		layers.push_back(layerData);
		// Crea un nuovo livello
		Tileset* tileset = findTileset(property->Attribute("value"));
		//std::cout << "tileDimension: " << tileset->getTileDimensions().x << ", " << tileset->getTileDimensions().x << std::endl;
		TileLevel* tilelevel = new TileLevel(layerData, tileset, width, height);
		tileMap.push_back( tilelevel );
		// Incrementa il ivello
		layer = layer->NextSiblingElement("layer");
		if(layer != NULL){
			data = layer->FirstChildElement("data");
			property = layer->FirstChildElement("properties")->FirstChildElement("property");
		}
	}
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

void TileMap::bindTexture(){
	glActiveTexture(GL_TEXTURE0);
	glBindTexture(GL_TEXTURE_2D, mapTexture->getTextureID());
}

void TileMap::bindUniform(Shader* shader, GLuint level){
	tileMap.at(level)->bindUniform(shader);
}

void TileMap::bindBuffers(){
	glGenVertexArrays(1, &VAO);
	glGenBuffers(1, &VBO);
	glGenBuffers(1, &EBO);
	glGenBuffers(1, &positionVBO);

	glBindVertexArray(VAO);

	//Bind vertexBuffer
	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glBufferData(GL_ARRAY_BUFFER, sizeof(tileVertex), tileVertex, GL_STATIC_DRAW);

	//Bind indexBuffer
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(tileIndex), tileIndex, GL_STATIC_DRAW);

	//vertexPosition
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 5*sizeof(GLfloat), (GLvoid*)0);
	glEnableVertexAttribArray(0);

	//texture
	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 5*sizeof(GLfloat), (GLvoid*)(3*sizeof(GLfloat)));
	glEnableVertexAttribArray(1);

	glBindVertexArray(0);
}

void  TileMap::bindTileLevelPositions(GLuint level){
	glBindVertexArray(VAO);
	glBindBuffer(GL_ARRAY_BUFFER, positionVBO);

	//std::cout << "before getTilecount" << std::endl;
	GLuint numberOfTilePositions = tileMap.at(level)->getTileCount()*3;
	std::vector< glm::vec3 > tilePositions = tileMap.at(level)->getTilePositions();
	//std::cout << "after getTilecount" << std::endl;
	GLfloat tilePositionsArray[numberOfTilePositions];
	GLuint j=0;
	//std::cout << "before loop" << std::endl;
	for(GLuint i=0; i<tileMap.at(level)->getTileCount(); i++){
		tilePositionsArray[j++] = tilePositions.at(i).x;
		tilePositionsArray[j++] = tilePositions.at(i).y;
		tilePositionsArray[j++] = tilePositions.at(i).z;
		//std::cout << tilePositions.at(i).x << ", " << tilePositions.at(i).y << ", " << tilePositions.at(i).z << std::endl;
	}
	//std::cout << "before bufferdata" << std::endl;
	glBufferData(GL_ARRAY_BUFFER, numberOfTilePositions*sizeof(GLfloat), tilePositionsArray, GL_STATIC_DRAW);
	//std::cout << "after bufferdata" << std::endl;
	GLuint location = 2;
	GLint components = 3;
	GLenum type = GL_FLOAT;
	GLboolean normalized = GL_FALSE;
	GLsizei datasize = sizeof(GLfloat)*3;
	GLvoid* pointer = 0;
	GLuint divisor = 1;
	glEnableVertexAttribArray(location);
	glVertexAttribPointer(location, components, type, normalized, datasize, pointer);
	glVertexAttribDivisor(location, divisor);

	glBindVertexArray(0);
}

void TileMap::bindSSBO(GLuint level){
	tileMap.at(level)->bindSSBO(VAO);
}

