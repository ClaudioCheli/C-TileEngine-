/*
 * EntityCreationDirector.cpp
 *
 *  Created on: 10 mar 2017
 *      Author: Claudio
 */

#include "EntityCreationDirector.h"
#include "../Error.h"

void EntityCreationDirector::createEntity(){
	std::cout << "------------Start entity creation------------" << std::endl;
	builder->createEntity();
	glCheckError();
	std::cout << "------------entity created------------" << std::endl;
	builder->createTile();
	glCheckError();
	std::cout << "------------tile created------------" << std::endl;
	builder->createTileset();
	glCheckError();
	std::cout << "------------tileset created------------" << std::endl;
	builder->createAnimation();
	glCheckError();
	std::cout << "------------animation created------------" << std::endl;
	builder->createShader();
	glCheckError();
	std::cout << "------------shader created------------" << std::endl;
	builder->bindBuffers();
	glCheckError();
	std::cout << "------------buffer binded------------" << std::endl;
}

