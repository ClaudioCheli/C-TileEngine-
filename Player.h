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
#include "observer/Observer.h"
#include "input.h"

using namespace tinyxml2;

class Player: public Entity, public Observer{
public:
	Player();
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

	void updateObserver(Subject* sub, std::list<int> list);

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
	glm::vec2 direction;
	const float SPEED = 10;

	void bindAttribute();
	void unbindAttribute();


};



#endif /* PLAYER_H_ */
