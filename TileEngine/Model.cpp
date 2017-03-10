/*
 * Model.cpp
 *
 *  Created on: 07 ott 2016
 *      Author: clasb
 */

#include "Model.h"

Model::Model(std::vector<glm::vec3> vertices, glm::vec3 position){
	this->position = position;
	this->modelMatrix = glm::translate(modelMatrix, position);

	this->vertexCount = vertices.size()/3;

	GLfloat vertex[vertices.size()*3];
	GLuint j = 0;
	for(GLuint i=0; i<vertices.size(); i++){
		vertex[j++] = vertices[i].x;
		vertex[j++] = vertices[i].y;
		vertex[j++] = vertices[i].z;
	}
	glGenVertexArrays(1, &VAO);
	glGenBuffers(1, &VBO);

	glBindVertexArray(VAO);

	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertex), vertex, GL_STATIC_DRAW);

	//position
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3*sizeof(GLfloat), (GLvoid*)0);
	glEnableVertexAttribArray(0);

	glBindBuffer(GL_ARRAY_BUFFER, 0);

	glBindVertexArray(0);
}

Model::Model(std::vector<glm::vec3> vertices, std::vector<GLuint> indices, glm::vec3 position){
	this->position = position;
	this->modelMatrix = glm::translate(modelMatrix, position);

	indexCount = indices.size();
	//std::cout << "indici: " << indexCount << std::endl;
	GLfloat vertex[vertices.size()];
	GLuint index[indices.size()];
	GLuint j = 0;
	for(GLuint i=0; i<vertices.size(); i++){
		vertex[j++] = vertices[i].x;
		vertex[j++] = vertices[i].y;
		vertex[j++] = vertices[i].z;
	}
	for(GLuint i=0; i<indices.size(); i++)
		index[i] = indices[i];

	glGenVertexArrays(1, &VAO);
	glGenBuffers(1, &VBO);
	glGenBuffers(1, &EBO);

	glBindVertexArray(VAO);

	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertex), vertex, GL_STATIC_DRAW);

	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(index), index, GL_STATIC_DRAW);

	//position
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 5*sizeof(GLfloat), (GLvoid*)0);
	glEnableVertexAttribArray(0);
	//texture
	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 5*sizeof(GLfloat), (GLvoid*)(3*sizeof(GLfloat)));
	glEnableVertexAttribArray(1);

	glBindBuffer(GL_ARRAY_BUFFER, 0);

	glBindVertexArray(0);
}

void Model::setTexture(std::string imagePath){
	texture.loadTexture(imagePath);
}

void Model::bindTexture(Shader* shader){
	glActiveTexture(GL_TEXTURE0);
	glBindTexture(GL_TEXTURE_2D, texture.getTextureID());
	glUniform1f(glGetUniformLocation(shader->getProgramID(), "myTexture"), 0);
}

void Model::rotate(){
	this->modelMatrix = glm::rotate(this->modelMatrix, (GLfloat)0.02, glm::vec3(0.0f, 1.0f, 0.0f));
}

void Model::bindModelMatrix(Shader* shader){
	GLint modelLocation = glGetUniformLocation(shader->getProgramID(), "model");
	glUniformMatrix4fv(modelLocation, 1, GL_FALSE, glm::value_ptr(this->modelMatrix));
}


