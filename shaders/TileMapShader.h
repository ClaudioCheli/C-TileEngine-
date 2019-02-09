/*
 * BaseShader.h
 *
 *  Created on: 04 ott 2016
 *      Author: clasb
 */

#ifndef BASESHADER_H_
#define BASESHADER_H_

#include "Shader.h"

class TileMapShader: public Shader{
public:
	TileMapShader();
	~TileMapShader();

	void loadTilesetNumberOfRows(int tilesetNumberOfRows);
	void loadTilesetNumberOfColumns(int tilesetNumberOfColumns);
	void loadProjectionMatrix(glm::mat4 matrix);
	void loadViewMatrix(glm::mat4 matrix);
	void loadLevelNumber(int level);

private:
	std::string VERTEX_SHADER_PATH = "shader/tileMapVertexShader.vs";
	std::string FRAGMENT_SHADER_PATH = "shader/tileMapFragmentShader.fs";
	int location_viewMatrix;
	int location_projectionMatrix;
	int location_tilesetNumberOfRows;
	int location_tilesetNumberOfColumns;
	int location_levelNumber;

	void printUniformLocation();
	void getAllUniformLocation();
	void bindAttributes();

};

#endif /* BASESHADER_H_ */
