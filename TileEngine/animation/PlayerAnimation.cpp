/*
 * PlayerAnimation.cpp
 *
 *  Created on: 06 gen 2017
 *      Author: Claudio
 */

#include "PlayerAnimation.h"

PlayerAnimation::PlayerAnimation(GLuint animationLength, std::vector<GLuint> frameTextureId, std::string name){
	this->animationLength = animationLength;
	this->frameTextureId = frameTextureId;
	this->name = name;
}

void PlayerAnimation::update(){

}

