/*
 * Test.h
 *
 *  Created on: 30 dic 2016
 *      Author: Claudio
 */

#ifndef ERROR_H_
#define ERROR_H_

#define GLEW_STATIC
#include <GL/glew.h>

void check_(const char *file, int line){
	std::cout << file << " (" << line << ")" << std::endl;
}
#define check() check_(__FILE__, __LINE__)

void glCheckError_(const char *file, int line){
	GLuint error = glGetError();

	if(error != GL_NO_ERROR){
		switch(error){
		case 1280:
			std::cout << "glError: GL_INVALID_ENUM" << " | " << file << " (" << line << ")" << std::endl;
			break;
		case 1281:
			std::cout << "glError: GL_INVALID_VALUE" << " | " << file << " (" << line << ")" << std::endl;
			break;
		case 1282:
			std::cout << "glError: GL_INVALID_OPERATION" << " | " << file << " (" << line << ")" << std::endl;
			break;
		case 1286:
			std::cout << "glError: GL_INVALID_FRAMEBUFFER_OPERATION" << " | " << file << " (" << line << ")" << std::endl;
			break;
		default:
			std::cout << "glError: " << error << " | " << file << " (" << line << ")" << std::endl;
		}

		exit(1);
	}
}
#define glCheckError() glCheckError_(__FILE__, __LINE__)


#endif /* ERROR_H_ */
