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

private:
	std::string VERTEX_SHADER_PATH = "D://Development//Workspace//Windows C++//TileEngine//Debug//shader//playerVertexShader.vs";
	std::string FRAGMENT_SHADER_PATH = "D://Development//Workspace//Windows C++//TileEngine//Debug//shader//playerFragmentShader.fs";
};



#endif /* SHADERS_PLAYERSHADER_H_ */
