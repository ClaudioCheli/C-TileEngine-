/*
 * PlayerAnimation.h
 *
 *  Created on: 06 gen 2017
 *      Author: Claudio
 */

#ifndef ANIMATION_PLAYERANIMATION_H_
#define ANIMATION_PLAYERANIMATION_H_

#include "Animation.h"

class PlayerAnimation{
public:
	PlayerAnimation(GLuint animationLength, std::vector<GLuint> frameTextureId, std::string name);
	~PlayerAnimation(){};

	void update();

private:
	GLuint animationLength;
	std::vector<GLuint> frameTextureId;
	std::string name;

};



#endif /* ANIMATION_PLAYERANIMATION_H_ */
