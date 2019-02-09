
#ifndef ENTITYBUILDER_H_
#define ENTITYBUILDER_H_

#include "../../lib/tinyxml2/tinyxml2.h"

#include "../Entity.h"

class EntityBuilder{
public:
	virtual ~EntityBuilder(){};

	virtual void createEntity()=0;
	virtual void createTile()=0;
	virtual void createTileset()=0;
	virtual void createAnimation()=0;
	virtual void createShader()=0;
	virtual void bindBuffers()=0;

	Entity* getEntity(){return entity;}

protected:
	Entity* entity;

};

#endif /* ENTITYBUILDER_H_ */
