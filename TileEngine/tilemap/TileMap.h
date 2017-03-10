/*
 * TileMap.h
 *
 *  Created on: 04 ott 2016
 *      Author: clasb
 */

#ifndef TILEMAP_H_
#define TILEMAP_H_

#include "../tinyxml2/tinyxml2.h"
#include <cstdio>

#include "TileLevel.h"
#include "../Texture.h"
#include "../Renderable.h"


using namespace tinyxml2;

static const GLfloat tileVertex[] = {
		// Positions
		64.0f,  0.0f, 0.0f, 1.0f, 0.0f, // Top Right
		64.0f, 64.0f, 0.0f, 1.0f, 1.0f, // Bottom Right
		0.0f, 64.0f, 0.0f, 0.0f, 1.0f, // Bottom Left
		0.0f,  0.0f, 0.0f, 0.0f, 0.0f  // Top Left
};
static const GLuint tileIndex[] = {  // Note that we start from 0!
		0, 1, 3, // First Triangle
		1, 2, 3  // Second Triangle
};

class TileMap: public Renderable{
public:
	TileMap(Shader* shader);
	~TileMap(){};

	void render();
	void loadTexture(std::string imagePath);
	void bindUniform(Shader* shader, GLuint level);
	void bindBuffers();
	void bindTileLevelPositions(GLuint level);
	void bindSSBO(GLuint level);
	void bindTexture();
	void loadMapDefinition(std::string mapDefinitionFilePath);
	void createMap();
	void printMapData();
	void printLayerData();
	void printMapVertexData();

	GLuint getVAO(){return VAO;}
	GLuint getTileCount(){return tileCount;}
	GLuint getTextureID(){return mapTexture->getTextureID();}
	GLuint getLevelsNumber(){return tileMap.size();}
	GLuint getVertexCount(){return tileCount * 4;}
	Shader* getShader(){return shader;}

private:
	GLuint VAO, VBO, EBO, positionVBO;
	Shader* shader;
	XMLDocument mapXMLFile;
	Texture* mapTexture;
	glm::vec2 mapDimension;
	GLuint tileCount;
	std::vector< Tileset* > tilesets;
	std::vector< TileLevel* > tileMap;

	std::vector< std::vector<GLint> > getIntData(std::vector<std::string>);
	Tileset* findTileset(std::string name);

};

#endif /* TILEMAP_H_ */
