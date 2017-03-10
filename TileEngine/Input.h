/*
 * Input.h
 *
 *  Created on: 12 ott 2016
 *      Author: clasb
 */

#ifndef INPUT_H_
#define INPUT_H_

#include <SDL2/SDL.h>
#include "DisplayManager.h"

enum key{
	W,
	A,
	S,
	D
};



class Input{
public:
	static const int KEY_MAX = 4;

	Input(DisplayManager* display);
	void update();
	int* getKeyPress(){return keyPress;}

private:
	int keyPress[4];
	DisplayManager* display;
	SDL_Event event;
};



#endif /* INPUT_H_ */
