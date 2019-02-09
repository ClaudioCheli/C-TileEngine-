/*
 * Tile.h
 *
 *  Created on: 10 mar 2017
 *      Author: Claudio
 */

#ifndef TILEMAP_TILE_H_
#define TILEMAP_TILE_H_

#ifndef GLEW_STATIC
#define GLEW_STATIC
#include <GL/glew.h>
#endif
#include <vector>
#include <iostream>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

class Tile {
public:
	Tile(glm::vec2 dimension);

	void updateModelMatrix();

	std::vector<float> getVertexArray();
	std::vector<int> getIndexArray();
	GLuint getIndexCount(){return indexCount;}
	glm::vec2 getDimension() {return dimension;}
	glm::mat4 getModelMatrix() {return modelMatrix;}
	glm::vec3 getPosition() {return position;}
	void setPosition(glm::vec3 position);
	void setRotation(glm::vec3 rotationAxis, float rotationAngle);
	void setScale(glm::vec3 scale);


private:
	glm::vec2 dimension;
	glm::vec3 position;
	float rotationAngle;
	glm::vec3 rotationAxis;
	glm::vec3 scale;
	glm::mat4 modelMatrix;
	GLuint vertexCount = 4;
	GLuint textureVertexCount = 4;
	GLuint indexCount = 6;
	static const GLuint VERTEX_ARRAY_SIZE = 12;
	static const GLuint TEXTURE_ARRAY_SIZE = 8;
	static const GLuint INDEX_ARRAY_SIZE = 6;

	float vertex[VERTEX_ARRAY_SIZE] = {
			1.0f, 0.0f, 0.0f, // Top Right
			1.0f, 1.0f, 0.0f, // Bottom Right
			0.0f, 1.0f, 0.0f, // Bottom Left
			0.0f, 0.0f, 0.0f
	};

	float texture[TEXTURE_ARRAY_SIZE] = {
			1.0f, 0.0f,
			1.0f, 1.0f,
			0.0f, 1.0f,
			0.0f, 0.0f
	};

	float index[INDEX_ARRAY_SIZE] = {
			0, 1, 3,
			1, 2, 3
	};
};

#endif /* TILEMAP_TILE_H_ */
