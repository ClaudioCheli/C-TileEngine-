/*
 * Shader.h
 *
 *  Created on: 03 ott 2016
 *      Author: clasb
 */

#ifndef SHADER_H_
#define SHADER_H_

#ifndef GLEW_STATIC
#define GLEW_STATIC
#include <GL/glew.h>
#endif
#include <string>
#include <fstream>
#include <sstream>
#include <iostream>

class Shader{
public:
	std::string loadShader(std::string shaderPath);
	int compileShader(GLuint shaderTipe, std::string shaderSource);
	void linkToProgram(int vertexShaderID, int fragmentShaderID);
	void start(){glUseProgram(this->programID);}
	void stop(){glUseProgram(0);}
	void loadProjectionMatrix(glm::mat4);
	int getProgramID(){return programID;}
protected:
	int vertexShaderID;
	int fragmentShaderID;
	int programID;
};

#endif /* SHADER_H_ */
