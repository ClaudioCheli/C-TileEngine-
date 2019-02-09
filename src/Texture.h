/*
 * Texture.h
 *
 *  Created on: 04 ott 2016
 *      Author: clasb
 */

#ifndef TEXTURE_H_
#define TEXTURE_H_

#include <iostream>
#define GLEW_STATIC
#include <GL/glew.h>
#include <SOIL/SOIL.h>
#include <glm/glm.hpp>

class Texture{
public:
	Texture(std::string imagePath);

	//unsigned char* getImage(){return image;}
	glm::vec2 getDimension(){return dimension;}
	GLuint getTextureID(){return textureID;}
private:
	glm::vec2 dimension;
	unsigned char* image;
	GLuint textureID;

	void loadTexture(std::string imagePath);

};

#endif /* TEXTURE_H_ */
