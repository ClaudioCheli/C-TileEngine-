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

#include "../Entity.h"
#include "TileLevel.h"
#include "../Texture.h"
#include "../shaders/TileMapShader.h"


using namespace tinyxml2;

static const GLfloat tileVertex[] = {
		// Positions
		64.0f,  0.0f, 0.0f, 1.0f, 0.0f, // Top Right
		64.0f, 64.0f, 0.0f, 1.0f, 1.0f, // Bottom Right
		0.0f, 64.0f, 0.0f, 0.0f, 1.0f, // Bottom Left
		0.0f,  0.0f, 0.0f, 0.0f, 0.0f  // Top Left
};
static const GLuint tileIndex[] = {
		0, 1, 3, // First Triangle
		1, 2, 3  // Second Triangle
};

class TileMap: public Renderable{
public:
	TileMap();
	//TileMap(TileMapShader* shader);
	~TileMap(){};

	void render();
	void update();
	void bindAttribute();
	void bindTexture(GLuint level);
	void bindUniform(GLuint level);
	void bindLevelSSBO(GLuint level);
	void unbindAttribute();
    void bindProjectionMatrix(glm::mat4 projectionMatrix);
    void bindBuffers();


	GLuint getVAO(){return VAO;}
	GLuint getLevelsNumber(){return levels.size();}
	Shader* getShader(){return shader;}
	Tileset* getTileset(std::string name){return findTileset(name);}
	void setTileset(std::vector<Tileset*> tilesets){this->tilesets = tilesets;}
	void setTileLevels(std::vector<TileLevel*> tileLevels){this->levels = tileLevels;}
	void setShader(TileMapShader* shader){ this->shader = shader;}

private:
	GLuint VAO, VBO, EBO, positionVBO;
	TileMapShader* shader;
	std::vector<GLuint> ssbo;
	GLuint indexCount = 6;
	GLuint vertexCount = 4;
	std::vector< Tileset* > tilesets;
	std::vector< TileLevel* > levels;

	std::vector< std::vector<GLint> > getIntData(std::vector<std::string>);
	Tileset* findTileset(std::string name);
	void bindVertexBuffer();
	void bindIndexBuffer();
	void bindPositionBuffer();
	void bindSSBO();

};

#endif /* TILEMAP_H_ */
