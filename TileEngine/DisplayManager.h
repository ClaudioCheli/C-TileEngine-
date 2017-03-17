/*
 * DisplayManager.h
 *
 *  Created on: 03 ott 2016
 *      Author: clasb
 */

#ifndef DISPLAYMANAGER_H_
#define DISPLAYMANAGER_H_

#include <SDL2/SDL.h>
#define GLEW_STATIC
#include <GL/glew.h>
#include <iostream>

class DisplayManager{
public:
	static const GLuint WIDTH = 1280;
	static const GLuint HEIGHT = 720;

	DisplayManager();
	~DisplayManager();
	void Init();
	void CreateDisplay(std::string title);
	void pause(){SDL_Delay(500);}
	void setCloseRequest(bool req){this->closeRequest = req;}
	bool isCloseRequest(){return closeRequest;}
	void setWindowTitle(std::string title);
	SDL_Window* getWindow(){return window;}

private:
	SDL_Window* window = NULL;
	SDL_GLContext context = NULL;
	bool closeRequest;
};



#endif /* DISPLAYMANAGER_H_ */
