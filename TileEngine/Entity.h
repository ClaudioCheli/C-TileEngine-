/*
 * Renderable.h
 *
 *  Created on: 01 feb 2017
 *      Author: Claudio
 */

#ifndef ENTITY_H_
#define ENTITY_H_

#define GLEW_STATIC
#include <GL/glew.h>
#include <glm/glm.hpp>
#include <vector>

#include "tileMap/Tile.h"
#include "tileMap/Tileset.h"
#include "Texture.h"
#include "animation/Animation.h"
#include "Renderable.h"
#include "shaders/Shader.h"

class Entity: public Renderable{
public:
	Entity(){};
	virtual ~Entity(){};

	virtual void setTile(Tile* tile)=0;
	virtual void setTileset(std::vector<Tileset*> tileset)=0;
	virtual void setTexture(Texture* texture)=0;
	virtual void setAnimation(Animation* animation)=0;
	virtual void setShader(Shader* shader)=0;
	virtual void bindBuffers()=0;

};



#endif /* ENTITY_H_ */
