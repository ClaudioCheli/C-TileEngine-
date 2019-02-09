/*
 * Shader.cpp
 *
 *  Created on: 03 ott 2016
 *      Author: clasb
 */

#include "Shader.h"

std::string Shader::loadShader(std::string shaderPath){
	std::string shaderSource;
	std::ifstream shaderFile;

	shaderFile.exceptions(std::ifstream::badbit);
	try{
		shaderFile.open(shaderPath.c_str());
		std::stringstream shaderStream;
		shaderStream << shaderFile.rdbuf();
		shaderFile.close();
		shaderSource = shaderStream.str();
	}catch(std::ifstream::failure &e){
		std::cout << "ERROR::SHADER::FILE_NOT_SUCCESFULLY_READ" << std::endl;
	}

	return shaderSource;
}

GLuint Shader::compileShader(GLuint shaderTipe, std::string shaderSource){
	GLuint shaderID = glCreateShader(shaderTipe);
	GLint success;
	GLchar infoLog[512];
	const GLchar* shaderCode = shaderSource.c_str();
	glShaderSource(shaderID, 1, &shaderCode, NULL);
	glCompileShader(shaderID);
	glGetShaderiv(shaderID, GL_COMPILE_STATUS, &success);
 	#ifdef DEBUG
	glGetShaderInfoLog(shaderID, 512, NULL, infoLog);
	switch (shaderTipe){
	case GL_VERTEX_SHADER:
		std::cout <<"Vertex Shader info: " << infoLog << std::endl;
		break;
	case GL_FRAGMENT_SHADER:
		std::cout << "Fragment Shader info: " << infoLog << std::endl;
		break;
	}

	#endif
	if(!success)
	{
	    glGetShaderInfoLog(shaderID, 512, NULL, infoLog);
	    switch (shaderTipe){
	    case GL_VERTEX_SHADER:
	    	std::cout << "ERROR::SHADER::VERTEX::COMPILATION_FAILED\n" << infoLog << std::endl;
			break;
	    case GL_FRAGMENT_SHADER:
	    	std::cout << "ERROR::SHADER::FRAGMENT::COMPILATION_FAILED\n" << infoLog << std::endl;
			break;
	    }
	    exit(1);
	};
	return shaderID;
}

GLuint Shader::linkToProgram(int vertexShaderID, int fragmentShaderID){
	GLint success;
	GLchar infoLog[512];
	GLuint programID = glCreateProgram();
	glAttachShader(programID, vertexShaderID);
	glAttachShader(programID, fragmentShaderID);
	glLinkProgram(programID);
	glGetProgramiv(programID, GL_LINK_STATUS, &success);
	if(!success)
	{
	    glGetProgramInfoLog(programID, 512, NULL, infoLog);
	    std::cout << "ERROR::SHADER::PROGRAM::LINKING_FAILED\n" << infoLog << std::endl;
	    exit(2);
	}
	return programID;
}



