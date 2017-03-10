/*
 * Vector2f.h
 *
 *  Created on: 04 ott 2016
 *      Author: clasb
 */

#ifndef VECTOR2F_H_
#define VECTOR2F_H_

class Vector2f{
public:
	Vector2f(){this->x=0; this->y=0;}
	Vector2f(float x, float y){this->x = x; this->y = y;}
	Vector2f(int x, int y){this->x = (float)x; this->y = (float)y;}
	~Vector2f(){x = 0; y = 0;}

	float x;
	float y;
};



#endif /* VECTOR2F_H_ */
