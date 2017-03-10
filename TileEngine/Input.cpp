/*
 * Input.cpp
 *
 *  Created on: 12 ott 2016
 *      Author: clasb
 */

#include "Input.h"

Input::Input(DisplayManager* display){
	this->display = display;
}

void Input::update(){
	while(SDL_PollEvent(&event) != 0){
		switch (this->event.type){
		case SDL_QUIT:
			this->display->setCloseRequest(true);
			break;
		case SDL_KEYDOWN:
			switch (this->event.key.keysym.sym){
			case SDLK_w:
				keyPress[W] = 1;
				break;
			case SDLK_a:
				keyPress[A] = 1;
				break;
			case SDLK_s:
				keyPress[S] = 1;
				break;
			case SDLK_d:
				keyPress[D] = 1;
				break;
			}
			break;
			case SDL_KEYUP:
				switch (this->event.key.keysym.sym){
				case SDLK_w:
					keyPress[W] = 0;
					break;
				case SDLK_a:
					keyPress[A] = 0;
					break;
				case SDLK_s:
					keyPress[S] = 0;
					break;
				case SDLK_d:
					keyPress[D] = 0;
					break;
				}
				break;
		}
	}
}


