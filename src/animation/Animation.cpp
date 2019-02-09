/*
 * Animation.cpp
 *
 *  Created on: 06 gen 2017
 *      Author: Claudio
 */


#include "Animation.h"

/*Animation::Animation(GLuint animationLength, std::vector<GLuint> frameTextureId){
	this->animationLength = animationLength;
	this->frameTextureId = new GLuint[animationLength];
	for(GLuint i=0; i<frameTextureId.size(); i++){
		this->frameTextureId[i] = frameTextureId[i];
	}
}*/

Animation::Animation(GLuint animationLenght, std::vector<GLuint> frames, std::string name){
	this->animationLength = animationLenght;
	this->ids = frames;
	this->name = name;
}
