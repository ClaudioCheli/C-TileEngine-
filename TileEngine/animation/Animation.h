/*
 * Animation.h
 *
 *  Created on: 06 gen 2017
 *      Author: Claudio
 */

#ifndef ANIMATION_H_
#define ANIMATION_H_

#define GLEW_STATIC
#include <GL/glew.h>
#include <vector>
#include <string>

class Animation{
public:
	Animation(GLuint animationLenght, std::vector<GLuint> frames, std::string name);
	Animation(GLuint animationLength, std::vector<GLuint> frameTextureId);
	 ~Animation(){};

	void update();

	GLuint getCurrentId(){return 0;}
	std::string getName(){return name;}
protected:
	GLuint animationLength;
	std::vector<GLuint> ids;
	std::string name;

};



#endif /* ANIMATION_H_ */
