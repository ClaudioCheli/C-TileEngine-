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
	this->programID = linkToProgram(this->vertexShaderID, this->fragmentShaderID);

	bindAttributes();
	getAllUniformLocation();
}

TileMapShader::~TileMapShader(){
	glDeleteProgram(programID);
}

void TileMapShader::getAllUniformLocation(){
	location_viewMatrix 			= getUniformLocation("view");
	location_projectionMatrix 		= getUniformLocation("projection");
	location_tilesetNumberOfRows 	= getUniformLocation("tilesetNumberOfRows");
	location_tilesetNumberOfColumns = getUniformLocation("tilesetNumberOfColumns");
	location_levelNumber 			= getUniformLocation("levelNumber");
}

void TileMapShader::printUniformLocation(){
	std::cout << "location_viewMatrix: " << location_viewMatrix << std::endl;
	std::cout << "location_projectionMatrix: " << location_projectionMatrix << std::endl;
	std::cout << "location_tilesetNumberOfRows: " << location_tilesetNumberOfRows << std::endl;
	std::cout << "location_tilesetNumberOfColumns: " << location_tilesetNumberOfColumns << std::endl;
}

void TileMapShader::bindAttributes(){
	bindAttribute(0, "vertexPosition");
	bindAttribute(1, "texCoord");
	bindAttribute(2, "tilePosition");
}

void TileMapShader::loadTilesetNumberOfRows(int tilesetNumberOfRows){
	loadInt(location_tilesetNumberOfRows, tilesetNumberOfRows);
}


void TileMapShader::loadTilesetNumberOfColumns(int tilesetNumberOfColumns){
	loadInt(location_tilesetNumberOfColumns, tilesetNumberOfColumns);
}


void TileMapShader::loadProjectionMatrix(glm::mat4 matrix){
	loadMatrix(location_projectionMatrix, matrix);
}


 void TileMapShader::loadViewMatrix(glm::mat4 matrix){
	loadMatrix(location_viewMatrix, matrix);
}

 void TileMapShader::loadLevelNumber(int level){
	 loadInt(location_levelNumber, level);
 }



