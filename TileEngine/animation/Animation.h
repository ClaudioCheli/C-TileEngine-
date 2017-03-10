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

class Animation{
public:
	Animation(GLuint animationLength, std::vector<GLuint> frameTextureId);
	virtual ~Animation(){};

	virtual void update()=0;

	GLuint getTextureId(GLuint frameNumber){return frameTextureId[frameNumber];}
protected:
	GLuint animationLength;
	GLuint* frameTextureId; //TextureId for every animation's frame

};



#endif /* ANIMATION_H_ */
