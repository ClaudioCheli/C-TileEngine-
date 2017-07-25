/*
 * Renderer.h
 *
 *  Created on: 07 ott 2016
 *      Author: clasb
 */

#ifndef RENDERER_H_
#define RENDERER_H_

#include "tilemap/TileMap.h"
#include "shaders/Shader.h"
#include "DisplayManager.h"
#include "Player.h"

#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <vector>
#include <algorithm>
#include <iostream>

class Renderer{
public:
	Renderer();
	void render(std::vector<Renderable*> entities);
	//void render(TileMap* tileMap, Player* player);
	void clear();
private:
	glm::mat4 projection;
	//static void draw(Entity entity);
	void setProjectionMatrix();
};



#endif /* RENDERER_H_ */
