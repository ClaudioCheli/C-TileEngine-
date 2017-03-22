/*
 * TileMapBuilder.cpp
 *
 *  Created on: 12 mar 2017
 *      Author: Claudio
 */

#include "TileMapBuilder.h"

const std::string TileMapBuilder::TILEMAP_PATH = "res/entities/island.xml";

void TileMapBuilder::createEntity(){
	tileMap = new TileMap();

	XMLDocument tileMapXMLFile;
	GLint errorID = tileMapXMLFile.LoadFile(TILEMAP_PATH.c_str());
	tinyxmlError(errorID);
	XMLElement* tileset = tileMapXMLFile.FirstChildElement("object")->FirstChildElement("tileset");

	tileMapDefPath = tileset->Attribute("definitionPath");
	tileMapImgPath = tileset->Attribute("imagePath");
}

void TileMapBuilder::createTileset(){
	std::vector<Tileset*> tilesets;
	XMLDocument playerDefFile;
	GLint errorID = playerDefFile.LoadFile(tileMapDefPath.c_str());
	tinyxmlError(errorID);
	XMLElement* tilesetNode = playerDefFile.FirstChildElement("tileset");
	int textureWidth, textureHeight, tilesNumber, tileWidth,
	tileHeight, columns, rows;
	tilesetNode->QueryIntAttribute("width", &textureWidth);
	tilesetNode->QueryIntAttribute("height", &textureHeight);
	tilesetNode->QueryIntAttribute("tilesNumber", &tilesNumber);
	tilesetNode->QueryIntAttribute("tileWidth", &tileWidth);
	tilesetNode->QueryIntAttribute("tileHeight", &tileHeight);
	columns = textureWidth/tileWidth;
	rows = textureHeight/tileHeight;
	std::string tilesetName = tilesetNode->Attribute("name");
	Tileset* tileset = new Tileset();
	tileset->setTextureWidth(textureWidth);
	tileset->setTextureHeight(textureHeight);
	tileset->setTileWidth(tileWidth);
	tileset->setTileHeight(tileHeight);
	tileset->setTilesNumber(tilesNumber);
	tileset->setNumberOfRows(rows);
	tileset->setNumberOfColumns(columns);
	tileset->setTilesetName(tilesetName);
	tileset->setTexture(new Texture(tileMapImgPath));

	tilesets.push_back(tileset);
	tileMap->setTileset(tilesets);
}

void TileMapBuilder::createTileLevels(){
	std::vector< TileLevel* > levels;
	XMLDocument tileMapXMLFile;
	GLint errorID = tileMapXMLFile.LoadFile(TILEMAP_PATH.c_str());
	tinyxmlError(errorID);
	XMLElement* layer = tileMapXMLFile.FirstChildElement("object")->FirstChildElement("layer");
	XMLElement* data = layer->FirstChildElement("data");
	XMLElement* property = layer->FirstChildElement("properties")->FirstChildElement("property");
	const GLchar* layerData; // Contiene i dati di un livello
	int width;
	int height;
	int z;
	std::string levelName;
	while(layer != nullptr){
		layer->QueryIntAttribute("width", &width);
		layer->QueryIntAttribute("height", &height);
		layer->QueryIntAttribute("z", &z);
		levelName = layer->Attribute("name");
		std::cout << "level " << levelName << ", level width: " << width << ", level height: " << height << ", z: " << z << std::endl;
		layerData = data->GetText();
		Tileset* tileset = tileMap->getTileset(property->Attribute("value"));
		TileLevel* tilelevel = new TileLevel(layerData, tileset, width, height, levelName);
		levels.push_back( tilelevel );
		layer = layer->NextSiblingElement("layer");
		if(layer != nullptr){
			data = layer->FirstChildElement("data");
			property = layer->FirstChildElement("properties")->FirstChildElement("property");

		}
	}

	std::reverse(levels.begin(), levels.end());

	tileMap->setTileLevels(levels);
}

void TileMapBuilder::createAnimation(){

}

void TileMapBuilder::createShader(){
	TileMapShader* shader = new TileMapShader();
	tileMap->setShader(shader);
}

void TileMapBuilder::bindBuffers(){
	tileMap->bindBuffers();
}


