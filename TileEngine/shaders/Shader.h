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
#include <glm/glm.hpp>
#include <glm/gtc/type_ptr.hpp>

#include <string>
#include <fstream>
#include <sstream>
#include <iostream>

#include "../Error.h"

class Shader{
public:
	std::string loadShader(std::string shaderPath);
	GLuint compileShader(GLuint shaderTipe, std::string shaderSource);
	GLuint linkToProgram(int vertexShaderID, int fragmentShaderID);
	void start(){glUseProgram(this->programID);}
	void stop(){glUseProgram(0);}
	int getProgramID(){return programID;}

protected:
	GLuint vertexShaderID;
	GLuint fragmentShaderID;
	GLuint programID;

	int getUniformLocation(std::string uniformName){return glGetUniformLocation(programID, uniformName.c_str());}
	void bindAttribute(int attrib, std::string variableName){glBindAttribLocation(programID, attrib, variableName.c_str());}
	void loadInt(int location, int value){glUniform1i(location, value);}
	void loadFloat(int location, float value){glUniform1f(location, value);}
	void loadVector2f(int location, glm::vec2 vec){glUniform2f(location, vec.x, vec.y);}
	void loadVector3f(int location, glm::vec3 vec){glUniform3f(location, vec.x, vec.y, vec.z);}
	void loadMatrix(int location, glm::mat4 mat){glUniformMatrix4fv(location, 1, GL_FALSE, glm::value_ptr(mat));}


};

#endif /* SHADER_H_ */
