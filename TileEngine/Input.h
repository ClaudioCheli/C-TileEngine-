/*
 * Input.h
 *
 *  Created on: 12 ott 2016
 *      Author: clasb
 */

#ifndef INPUT_H_
#define INPUT_H_

#include <SDL2/SDL.h>
#include <list>

#include "DisplayManager.h"
#include "observer/Observer.h"

enum key{
	W,
	A,
	S,
	D,
	ESC
};

class Input: public Subject{
public:
	static const int KEY_MAX = 5;

	Input(DisplayManager* display);
	void checkInput();
	void update();
	bool getKeyState(int key){return keyState[key];}
	std::list<int> getKeyEvents(){return keyEvents;}
	int* getKeyPress(){ return keyPress;}

private:
	bool pressed;
	std::list<int> keyEvents;
	int keyState[5];
	DisplayManager* display;
	SDL_Event event;
	int keyPress[5];

	void setKeyState(int key, bool state);
};



#endif /* INPUT_H_ */
