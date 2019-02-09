/*
 * PlayerShader.h
 *
 *  Created on: 05 gen 2017
 *      Author: Claudio
 */

#ifndef SHADERS_PLAYERSHADER_H_
#define SHADERS_PLAYERSHADER_H_

#include "Shader.h"

class PlayerShader: public Shader{
public:
	PlayerShader();
	~PlayerShader();

	void loadTextureIndex(int textureIndex){loadInt(location_textureIndex, textureIndex);}
	void loadTilesetNumberOfRows(int tilesetNumberOfRows){loadInt(location_tilesetNumberOfRows, tilesetNumberOfRows);}
	void loadTilesetNumberOfColumns(int tilesetNumberOfColumns){loadInt(location_tilesetNumberOfColumns, tilesetNumberOfColumns);}
	void loadModelMatrix(glm::mat4 matrix){loadMatrix(location_modelMatrix, matrix);}
	void loadProjectionMatrix(glm::mat4 matrix){loadMatrix(location_projectionMatrix, matrix);}
	void loadViewMatrix(glm::mat4 matrix){loadMatrix(location_viewMatrix, matrix);}

private:
	std::string VERTEX_SHADER_PATH = "shader/playerVertexShader.vs";
	std::string FRAGMENT_SHADER_PATH = "shader/playerFragmentShader.fs";
	int location_modelMatrix;
	int location_viewMatrix;
	int location_projectionMatrix;
	int location_textureIndex;
	int location_tilesetNumberOfRows;
	int location_tilesetNumberOfColumns;

	void printUniformLocation();
	void getAllUniformLocation();
	void bindAttributes();

};



#endif /* SHADERS_PLAYERSHADER_H_ */
