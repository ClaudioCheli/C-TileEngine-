/*
 * BaseShader.cpp
 *
 *  Created on: 04 ott 2016
 *      Author: clasb
 */

#include "TileMapShader.h"

TileMapShader::TileMapShader(){
	std::string vertexShaderSource   = loadShader(this->VERTEX_SHADER_PATH);
	std::string fragmentShaderSource = loadShader(this->FRAGMENT_SHADER_PATH);

	this->vertexShaderID   = compileShader(GL_VERTEX_SHADER, vertexShaderSource);
	this->fragmentShaderID = compileShader(GL_FRAGMENT_SHADER, fragmentShaderSource);

	linkToProgram(this->vertexShaderID, this->fragmentShaderID);
}

TileMapShader::~TileMapShader(){
	glDeleteProgram(programID);
}


