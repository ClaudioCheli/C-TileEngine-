/*
 * PlayerBuilder.cpp
 *
 *  Created on: 10 mar 2017
 *      Author: Claudio
 */

#include "PlayerBuilder.h"

const std::string PlayerBuilder::PLAYER_PATH = "res/entities/knight.xml";

void PlayerBuilder::createEntity(){
	entity = new Player();

	XMLDocument playerXMLFile;
	GLint errorID = playerXMLFile.LoadFile(PLAYER_PATH.c_str());
	tinyxmlError(errorID);

	XMLElement* tileset = playerXMLFile.FirstChildElement("object")->FirstChildElement("tileset");

	playerDefPath = tileset->Attribute("definitionPath");
	playerImgPath = tileset->Attribute("imagePath");
}

void PlayerBuilder::createTile(){
	XMLDocument playerDefFile;
	GLint errorID = playerDefFile.LoadFile(playerDefPath.c_str());
	tinyxmlError(errorID);
	XMLElement* tileset = playerDefFile.FirstChildElement("tileset");
	int tileWidth;
	int tileHeight;
	tileset->QueryIntAttribute("tileWidth", &tileWidth);
	tileset->QueryIntAttribute("tileHeight", &tileHeight);

	Tile* tile = new Tile(glm::vec2(tileWidth, tileHeight));
	tile->setPosition(glm::vec3(0,0,-10));
	tile->setRotation(glm::vec3(0,0,1), 0);
	tile->setScale(glm::vec3(1,1,1));
	entity->setTile(tile);
}

void PlayerBuilder::createTileset(){
	std::vector<Tileset*> tilesets;
	XMLDocument playerDefFile;
	GLint errorID = playerDefFile.LoadFile(playerDefPath.c_str());
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
	tileset->setTexture(new Texture(playerImgPath));

	tilesets.push_back(tileset);
	entity->setTileset(tilesets);
}

void PlayerBuilder::createAnimation(){
	XMLDocument playerXMLFile;
	GLint errorID = playerXMLFile.LoadFile(PLAYER_PATH.c_str());
	tinyxmlError(errorID);
	XMLElement* animationNode = playerXMLFile.FirstChildElement("object")->FirstChildElement("animation");
	std::string animationName;
	int animationLength;
	std::vector<GLuint> frames;
	while(animationNode != nullptr){
		animationNode->QueryIntAttribute("length", &animationLength);
		animationName = animationNode->Attribute("name");
		std::vector<XMLElement*> frameNodes;
		XMLElement* frameNode = animationNode->FirstChildElement("frame");
		while(frameNode != nullptr){
			frameNodes.push_back(frameNode);
			frameNode = frameNode->NextSiblingElement("frame");
		}
		frames = loadAnimationFrames(frameNodes, animationLength);

		entity->setAnimation(new Animation(animationLength, frames, animationName));

		animationNode = animationNode->NextSiblingElement("animation");
	}
}

void PlayerBuilder::createShader(){
	PlayerShader* shader = new PlayerShader();
	entity->setShader(shader);
}

void PlayerBuilder::bindBuffers(){
	entity->bindBuffers();
	glCheckError();
}

std::vector<GLuint> PlayerBuilder::loadAnimationFrames(std::vector<XMLElement*> frameNodes, int length){
	std::vector<GLuint> frames(length);
	int id;
	int subTextureId;
	for(GLuint i=0; i<frameNodes.size(); i++){
		frameNodes[i]->QueryIntAttribute("id", &id);
		frameNodes[i]->QueryIntAttribute("subTextureId", &subTextureId);
		frames[id] = subTextureId;
	}
	return frames;
}

