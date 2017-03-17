/*
 * Renderable.h
 *
 *  Created on: 14 mar 2017
 *      Author: Claudio
 */

#ifndef RENDERABLE_H_
#define RENDERABLE_H_

#include <glm/glm.hpp>

class Renderable{
public:
	Renderable(){}
	virtual ~Renderable(){};

	virtual void render()=0;
	virtual void update()=0;
	virtual void bindProjectionMatrix(glm::mat4 projectionMatrix)=0;

};



#endif /* RENDERABLE_H_ */
