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
#include "Texture.h"
#include "animation/PlayerAnimation.h"
#include "Renderable.h"

using namespace tinyxml2;

static const GLfloat playerVertex[] = {
		// Positions
		128.0f,  0.0f, 0.0f, 1.0f, 0.0f, // Top Right
		128.0f, 64.0f, 0.0f, 1.0f, 1.0f, // Bottom Right
		0.0f, 64.0f, 0.0f, 0.0f, 1.0f, // Bottom Left
		0.0f,  0.0f, 0.0f, 0.0f, 0.0f  // Top Left
};
static const GLuint playerIndex[] = {  // Note that we start from 0!
		0, 1, 3, // First Triangle
		1, 2, 3  // Second Triangle
};

class Player: public Renderable{
public:
	Player(std::string tilesetImagePath, std::string tilesetDefinitionPath, Shader* shader);
	~Player(){};

	void render();
	void update();
	void bindBuffers();
	void bindUniform();
	void bindTexture();
	void bindProjectionMatrix(glm::mat4 projectionMatrix);
	GLuint getVAO(){return VAO;}
	Shader* getShader(){return shader;}

private:
	GLuint VAO, VBO, EBO;
	Animation* walkLeft;
	Animation* walkRight;
	Shader* shader;
	Tileset* tileset;
	Texture* playerTexture;
	glm::mat4 modelMatrix;
	glm::vec3 position;

	void createModelMatrix();
	std::vector<GLuint> readAnimation(XMLElement* animation, int animationLength);

};



#endif /* PLAYER_H_ */
