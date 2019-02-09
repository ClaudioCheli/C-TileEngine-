/*
 * Tile.cpp
 *
 *  Created on: 10 mar 2017
 *      Author: Claudio
 */

#include "Tile.h"

Tile::Tile(glm::vec2 dimension) {
	this->dimension = dimension;
	for(GLuint i=0; i<vertexCount*3; i+=3){
		vertex[i]   *= dimension.x;
		vertex[i+1] *= dimension.y;
	}

}

std::vector<float> Tile::getVertexArray(){
	std::vector<float> vertexArray(VERTEX_ARRAY_SIZE + TEXTURE_ARRAY_SIZE);
	GLuint ver=0;
	GLuint tex=0;
	GLuint count=0;
	for(GLuint i=0; i<vertexCount; i++){
		vertexArray[count] = vertex[ver];  ver++; count++;
		vertexArray[count] = vertex[ver];  ver++; count++;
		vertexArray[count] = vertex[ver];  ver++; count++;
		vertexArray[count] = texture[tex]; tex++; count++;
		vertexArray[count] = texture[tex]; tex++; count++;
	}
	/*std::cout << "vertexArray" << std::endl;
	GLuint j=0;
	for(GLuint i=0; i<vertexArray.size(); i++){
		std::cout << vertexArray[i] << ", ";
		j++;
		if(j==5){
			std::cout << std::endl;
			j=0;
		}
	}*/

	return vertexArray;
}

std::vector<int> Tile::getIndexArray(){
	std::vector<int> indexArray(indexCount);
	for(int i=0; i<indexArray.size(); i++)
		indexArray[i] = index[i];
	return indexArray;
}

void Tile::setRotation(glm::vec3 rotationAxis, float rotationAngle){
	modelMatrix = glm::rotate(modelMatrix, rotationAngle, rotationAxis);
}

void Tile::setPosition(glm::vec3 position){
	modelMatrix = glm::translate(modelMatrix, position);
}

void Tile::setScale(glm::vec3 scale){
	modelMatrix = glm::scale(modelMatrix, scale);
}

