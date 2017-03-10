/*
 * Texture.cpp
 *
 *  Created on: 04 ott 2016
 *      Author: clasb
 */

#include "Texture.h"

Texture::Texture(){
	dimension = glm::vec2(0,0);
	textureID = 0;
	image 	  = NULL;
}

void Texture::loadTexture(std::string imagePath){
	glGenTextures(1, &textureID);
	glBindTexture(GL_TEXTURE_2D, textureID);

	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);

	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

	int width;
	int height;
	image = SOIL_load_image(imagePath.c_str(), &width, &height, 0, SOIL_LOAD_RGBA);
	this->dimension.x = width;
	this->dimension.y = height;
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, image);
	glGenerateMipmap(GL_TEXTURE_2D);
	SOIL_free_image_data(image);
	glBindTexture(GL_TEXTURE_2D, 0);
}

