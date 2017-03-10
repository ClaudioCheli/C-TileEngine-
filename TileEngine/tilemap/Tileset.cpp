/*
 * Tileset.cpp
 *
 *  Created on: 22 dic 2016
 *      Author: Claudio
 */

#include "Tileset.h"

Tileset::Tileset(GLuint tileWidth, GLuint tileHeight, GLuint firstTileID, GLuint columns, GLuint rows, std::string tilesetName){
	this->tileWidth   = tileWidth;
	this->tileHeight  = tileHeight;
	this->firstTileID = firstTileID;
	this->columns 	  = columns;
	this->rows 		  = rows;
	this->lastTileID  = (tileWidth*tileHeight) + firstTileID + 1;
	this->tilesetName = tilesetName;
}

void Tileset::bindNumberOfColumns(Shader* shader){
	GLuint numberOfColumnsLocation = glGetUniformLocation(shader->getProgramID(), "tilesetNumberOfColumns");
	glUniform1i(numberOfColumnsLocation, columns);
}

void Tileset::bindNumberOfRows(Shader* shader){
	GLuint numberOfRowsLocation = glGetUniformLocation(shader->getProgramID(), "tilesetNumberOfRows");
	glUniform1i(numberOfRowsLocation, rows);
}


