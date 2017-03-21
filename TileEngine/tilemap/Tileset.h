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
#include "../Texture.h"


class Tileset{
public:
	Tileset(){};
	Tileset(GLuint tileWidth, GLuint tileHeight, GLuint firstTileID, GLuint columns, GLuint rows, std::string tilesetName);
	~Tileset(){}

	void bindNumberOfRows(Shader* shader);
	void bindNumberOfColumns(Shader* shader);

	glm::vec2 getTileDimensions(){return glm::vec2(tileWidth, tileHeight);}
	std::string getName(){return tilesetName;}
	GLuint 	getNumberOfRows(){return rows;}
	void 	setNumberOfRows(int rows){this->rows = rows;}
	GLuint 	getNumberOfColumns(){return columns;}
	void 	setNumberOfColumns(int columns){this->columns = columns;}
	int 	getFirstTileId() const {return firstTileID;}
	void 	setFirstTileId(int firstTileId) {firstTileID = firstTileId;}
	int 	getLastTileId() const {return lastTileID;}
	void 	setLastTileId(int lastTileId) {lastTileID = lastTileId;}
	Texture* getTexture() const {return texture;}
	void 	setTexture(Texture* texture) {this->texture = texture;}
	GLuint 	getTextureID(){return texture->getTextureID();}
	void 	setTextureHeight(int textureHeight) {	this->textureHeight = textureHeight;}
	void 	setTextureWidth(int textureWidth) {this->textureWidth = textureWidth;}
	int	 	getTileHeight() const {return tileHeight;}
	void 	setTileHeight(int tileHeight) {this->tileHeight = tileHeight;}
	const 	std::string& getTilesetName() const {return tilesetName;}
	void 	setTilesetName(const std::string& tilesetName) {this->tilesetName = tilesetName;}
	int 	getTilesNumber() const {return tilesNumber;}
	void 	setTilesNumber(int tilesNumber) {this->tilesNumber = tilesNumber;}
	int 	getTileWidth() const {return tileWidth;}
	void 	setTileWidth(int tileWidth) {this->tileWidth = tileWidth;}

private:
	//GLuint tileWidth, tileHeight, firstTileID, lastTileID, columns, rows;
	int textureWidth, textureHeight, tilesNumber, tileWidth,
				tileHeight, firstTileID, lastTileID, columns, rows;
	std::string tilesetName;
	Texture* texture;

};



#endif /* TILEMAP_TILESET_H_ */
