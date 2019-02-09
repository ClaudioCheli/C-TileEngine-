/*
 * PlayerBuilder.h
 *
 *  Created on: 10 mar 2017
 *      Author: Claudio
 */

#ifndef BUILDER_PLAYERBUILDER_H_
#define BUILDER_PLAYERBUILDER_H_

#include <string>

#include "../Error.h"
#include "EntityBuilder.h"
#include "../Player.h"
#include "../tilemap/Tileset.h"

class PlayerBuilder: public EntityBuilder {
public:
	PlayerBuilder(){}
	~PlayerBuilder(){}

	void createEntity();
	void createTile();
	void createTileset();
	void createAnimation();
	void createShader();
	void bindBuffers();

private:
	static const std::string PLAYER_PATH;
	std::string playerDefPath;
	std::string playerImgPath;

	std::vector<GLuint> loadAnimationFrames(std::vector<XMLElement*> frameNodes, int length);

};

#endif /* BUILDER_PLAYERBUILDER_H_ */
