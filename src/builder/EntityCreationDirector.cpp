/*
 * EntityCreationDirector.cpp
 *
 *  Created on: 10 mar 2017
 *      Author: Claudio
 */

#include "EntityCreationDirector.h"
#include "../Error.h"
#include "../logger/Logger.h"

void EntityCreationDirector::createEntity(){
	LOG_INFO("------------Start entity creation------------");
	builder->createEntity();
	glCheckError();
	LOG_INFO("------------entity created------------");
	builder->createTile();
	glCheckError();
	LOG_INFO("------------tile created------------");
	builder->createTileset();
	glCheckError();
	LOG_INFO("------------tileset created------------");
	builder->createAnimation();
	glCheckError();
	LOG_INFO("------------animation created------------");
	builder->createShader();
	glCheckError();
	LOG_INFO("------------shader created------------");
	builder->bindBuffers();
	glCheckError();
	LOG_INFO("------------buffer binded------------");
}

