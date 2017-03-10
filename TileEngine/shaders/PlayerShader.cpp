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

	linkToProgram(this->vertexShaderID, this->fragmentShaderID);
}

PlayerShader::~PlayerShader(){
	glDeleteProgram(programID);
}

