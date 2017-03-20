/*
 * Player.h
 *
 *  Created on: 02 gen 2017
 *      Author: Claudio
 */

#ifndef PLAYER_H_
#define PLAYER_H_

#include "tinyxml2/tinyxml2.h"

#include "tilemap/Tileset.h"
#include "tilemap/Tile.h"
#include "animation/PlayerAnimation.h"
#include "Entity.h"
#include "shaders/PlayerShader.h"
#include "Error.h"

using namespace tinyxml2;

class Player: public Entity{
public:
	Player();
	//Player(std::string tilesetImagePath, std::string tilesetDefinitionPath, PlayerShader* shader);
	~Player(){};

	void render();
	void update();
	void bindBuffers();
	void bindUniform();
	void bindTexture();
	void bindProjectionMatrix(glm::mat4 projectionMatrix);

	void setTile(Tile* tile){this->tile = tile;}
	void setTileset(std::vector<Tileset*> tileset){this->tilesets = tileset;}
	void setTexture(Texture* texture){this->playerTexture = texture;}
	void setAnimation(Animation* animation);
	GLuint getVAO(){return VAO;}
	PlayerShader* getShader(){return shader;}
	void setShader(Shader* shader){this->shader = (PlayerShader*)shader;}

	void setCurrentAnimation(Animation* currentAnimation) {
		this->currentAnimation = currentAnimation;
	}

private:
	GLuint VAO, VBO, EBO;
	Animation* walkLeft;
	Animation* walkRight;
	Animation* walkUp;
	Animation* walkDown;
	Animation* idleLeft;
	Animation* idleRight;
	Animation* idleUp;
	Animation* idleDown;
	Animation* currentAnimation;
	PlayerShader* shader;
	Tile* tile;
	std::vector<Tileset*> tilesets;
	Texture* playerTexture;
	glm::mat4 modelMatrix;
	glm::vec3 position;
	GLuint indexCount;

	void bindAttribute();
	void createModelMatrix();
	void unbindAttribute();


};



#endif /* PLAYER_H_ */
