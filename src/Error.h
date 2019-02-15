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
#include <string>
#include <iostream>

#include "../lib/tinyxml2/tinyxml2.h"
#include "logger/Logger.h"

/*void check_(const char *file, int line){
	std::cout << file << " (" << line << ")" << std::endl;
}
#define check() check_(__FILE__, __LINE__)
 */

void glCheckError_(const char *file, int line);
#define glCheckError() glCheckError_(__FILE__, __LINE__)

void tinyxmlError(int errorID);

#endif /* ERROR_H_ */
