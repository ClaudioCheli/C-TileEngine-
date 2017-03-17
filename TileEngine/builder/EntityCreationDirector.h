/*
 * EntityCreationDirector.h
 *
 *  Created on: 10 mar 2017
 *      Author: Claudio
 */

#ifndef BUILDER_ENTITYCREATIONDIRECTOR_H_
#define BUILDER_ENTITYCREATIONDIRECTOR_H_

#include "EntityBuilder.h"

class EntityCreationDirector {
public:
	void createEntity();

	void setEntityBuilder(EntityBuilder* builder){this->builder = builder;}
	Entity* getEntity(){return builder->getEntity();}

private:
	EntityBuilder* builder;
};

#endif /* BUILDER_ENTITYCREATIONDIRECTOR_H_ */
