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
private:
	std::string VERTEX_SHADER_PATH = "D://Development//Workspace//Windows C++//TileEngine//Debug//shader//tileMapVertexShader.vs";
	std::string FRAGMENT_SHADER_PATH = "D://Development//Workspace//Windows C++//TileEngine//Debug//shader//tileMapFragmentShader.fs";
};

#endif /* BASESHADER_H_ */
