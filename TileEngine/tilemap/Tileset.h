/*
 * Tile.h
 *
 *  Created on: 22 dic 2016
 *      Author: Claudio
 */

#ifndef TILEMAP_TILESET_H_
#define TILEMAP_TILESET_H_

#include <glm/glm.hpp>

#include "../shaders/Shader.h"


class Tileset{
public:
	Tileset(GLuint tileWidth, GLuint tileHeight, GLuint firstTileID, GLuint columns, GLuint rows, std::string tilesetName);
	~Tileset(){}

	void bindNumberOfRows(Shader* shader);
	void bindNumberOfColumns(Shader* shader);

	glm::vec2 getTileDimensions(){return glm::vec2(tileWidth, tileHeight);}
	std::string getName(){return tilesetName;}

private:
	GLuint tileWidth, tileHeight, firstTileID, lastTileID, columns, rows;
	std::string tilesetName;

};



#endif /* TILEMAP_TILESET_H_ */
