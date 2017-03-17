/*
 * TileMapBuilder.h
 *
 *  Created on: 12 mar 2017
 *      Author: Claudio
 */

#ifndef BUILDER_TILEMAPBUILDER_H_
#define BUILDER_TILEMAPBUILDER_H_

#include <string>

#include "../Error.h"
#include "../tilemap/TileMap.h"
#include "../tilemap/Tileset.h"

class TileMapBuilder{
public:
	void createEntity();
	void createTile();
	void createTileset();
	void createTileLevels();
	void createAnimation();
	void createShader();
	void bindBuffers();

	TileMap* getTileMap(){return tileMap;}

private:
	static const std::string TILEMAP_PATH;
	std::string tileMapDefPath;
	std::string tileMapImgPath;

	TileMap* tileMap;
};



#endif /* BUILDER_TILEMAPBUILDER_H_ */
