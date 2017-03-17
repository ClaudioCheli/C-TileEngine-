/*
 * Error.cpp
 *
 *  Created on: 16 mar 2017
 *      Author: Claudio
 */

#include "Error.h"

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

void tinyxmlError(int errorID){
	if(errorID != 0){
		std::string error;
		switch (errorID) {
		case 1:  error = "XML_NO_ATTRIBUTE"; 					break;
		case 2:  error = "XML_WRONG_ATTRIBUTE_TYPE"; 			break;
		case 3:  error = "XML_ERROR_FILE_NOT_FOUND";			break;
		case 4:  error = "XML_ERROR_FILE_COULD_NOT_BE_OPENED"; 	break;
		case 5:  error = "XML_ERROR_FILE_READ_ERROR";			break;
		case 6:  error = "XML_ERROR_ELEMENT_MISMATCH";			break;
		case 7:  error = "XML_ERROR_PARSING_ELEMENT";			break;
		case 8:  error = "XML_ERROR_PARSING_ATTRIBUTE";			break;
		case 9:  error = "XML_ERROR_IDENTIFYING_TAG";			break;
		case 10: error = "XML_ERROR_PARSING_TEXT";				break;
		case 11: error = "XML_ERROR_PARSING_CDATA";				break;
		case 12: error = "XML_ERROR_PARSING_COMMENT";			break;
		case 13: error = "XML_ERROR_PARSING_DECLARATION";		break;
		case 14: error = "XML_ERROR_PARSING_UNKNOWN";			break;
		case 15: error = "XML_ERROR_EMPTY_DOCUMENT";			break;
		case 16: error = "XML_ERROR_MISMATCHED_ELEMENT";		break;
		case 17: error = "XML_ERROR_PARSING";					break;
		case 18: error = "XML_CAN_NOT_CONVERT_TEXT";			break;
		case 19: error = "XML_NO_TEXT_NODE"; 					break;
		case 20: error = "XML_ERROR_COUNT"; 					break;
		}
		std::cout << "tinyxml Error: " << error << std::endl;
	}
}

