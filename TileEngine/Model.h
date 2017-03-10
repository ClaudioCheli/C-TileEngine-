/*
 * Model.h
 *
 *  Created on: 07 ott 2016
 *      Author: clasb
 */

#ifndef MODEL_H_
#define MODEL_H_

#include <vector>
#include <iostream>
#include "Texture.h"
#include "shaders/Shader.h"
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

class Model{
public:
	Model(std::vector<glm::vec3> vertices, glm::vec3 position);
	Model(std::vector<glm::vec3> vertices, std::vector<GLuint> indices, glm::vec3 position);
	void setTexture(std::string imagePath);
	void bindTexture(Shader* shader);
	void bindModelMatrix(Shader* shader);
	GLuint getVertexCount(){return vertexCount;}
	GLuint getVAO(){return VAO;}
	GLuint getIndexCount(){return indexCount;}
	void rotate();

private:
	GLuint VAO, VBO, EBO;
	GLuint vertexCount;
	GLuint indexCount;
	Texture texture;
	glm::vec3 position;
	glm::mat4 modelMatrix;
};



#endif /* MODEL_H_ */
