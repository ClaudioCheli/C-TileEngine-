/*
 * tileLevel.h
 *
 *  Created on: 22 dic 2016
 *      Author: Claudio
 */

#ifndef TILEMAP_TILELEVEL_H_
#define TILEMAP_TILELEVEL_H_

/*
 * Ogni livello ha un unico tileset
 */
#include <stdlib.h>
#include <vector>

#include "Tileset.h"

class TileLevel{
public:
	TileLevel();
	TileLevel(const GLchar* layerData, Tileset* tileset, GLuint width, GLuint height, std::string levelName);
	~TileLevel(){}

	void bindSSBO(GLuint VAO);
	void bindUniform(Shader* shader);

	GLuint getTileCount(){return tileCount;}
	glm::vec2 getLevelDimensions(){return glm::vec2(levelWidth, levelHeight);}
	std::vector< glm::vec3 > getTilePositions(){return tilePositions;}
	GLuint getLevelDepth(){return levelDepth;}
	Tileset* getTileset(){return tileset;}
	std::vector< GLuint > getTileIDs(){return tileIDs;}
	std::string getLevelName(){return levelName;}

private:
	Tileset* tileset;
	GLuint levelWidth, levelHeight, levelDepth, tileCount, ssbo;
	std::vector< GLuint > tileIDs;
	std::vector< glm::vec3 > tilePositions;
	std::string levelName;

	std::vector<GLuint> getIntData(std::string layer);
	std::vector<glm::vec3> calculateTilesPosition();

};



#endif /* TILEMAP_TILELEVEL_H_ */
