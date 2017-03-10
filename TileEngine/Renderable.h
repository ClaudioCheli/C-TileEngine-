/*
 * Renderable.h
 *
 *  Created on: 01 feb 2017
 *      Author: Claudio
 */

#ifndef RENDERABLE_H_
#define RENDERABLE_H_

#define GLEW_STATIC
#include <GL/glew.h>

class Renderable{
public:
	Renderable(){};
	virtual ~Renderable(){};

	virtual void render()=0;

protected:
	virtual void bindTexture()=0;

};



#endif /* RENDERABLE_H_ */
