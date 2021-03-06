/*
 * PlayerShader.cpp
 *
 *  Created on: 05 gen 2017
 *      Author: Claudio
 */


#include "PlayerShader.h"

PlayerShader::PlayerShader(){
	std::string vertexShaderSource   = loadShader(this->VERTEX_SHADER_PATH);
	std::string fragmentShaderSource = loadShader(this->FRAGMENT_SHADER_PATH);

	this->vertexShaderID   = compileShader(GL_VERTEX_SHADER, vertexShaderSource);
	this->fragmentShaderID = compileShader(GL_FRAGMENT_SHADER, fragmentShaderSource);
	this->programID = linkToProgram(this->vertexShaderID, this->fragmentShaderID);

	bindAttributes();
	getAllUniformLocation();
}

PlayerShader::~PlayerShader(){
	glDeleteProgram(programID);
}

void PlayerShader::getAllUniformLocation(){
	location_modelMatrix 			= getUniformLocation("model");
	location_viewMatrix 			= getUniformLocation("view");
	location_projectionMatrix 		= getUniformLocation("projection");
	location_textureIndex 			= getUniformLocation("textureIndex");
	location_tilesetNumberOfRows 	= getUniformLocation("tilesetNumberOfRows");
	location_tilesetNumberOfColumns = getUniformLocation("tilesetNumberOfColumns");
}

void PlayerShader::printUniformLocation(){
	std::cout << "location_modelMatrix: " << location_modelMatrix << std::endl;
	std::cout << "location_viewMatrix: " << location_viewMatrix << std::endl;
	std::cout << "location_projectionMatrix: " << location_projectionMatrix << std::endl;
	std::cout << "location_textureIndex: " << location_textureIndex << std::endl;
	std::cout << "location_tilesetNumberOfRows: " << location_tilesetNumberOfRows << std::endl;
	std::cout << "location_tilesetNumberOfColumns: " << location_tilesetNumberOfColumns << std::endl;
}

void PlayerShader::bindAttributes(){
	bindAttribute(0, "vertexPosition");
	bindAttribute(1, "texCoord");
}

