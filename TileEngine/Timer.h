/*
 * Timer.h
 *
 *  Created on: 10 ott 2016
 *      Author: clasb
 */

#ifndef TIMER_H_
#define TIMER_H_

#include <SDL2/SDL.h>
#define GLEW_STATIC
#include <GL/glew.h>

class Timer{
public:
	Timer();
	void start();
	void stop();
	void pause();
	void unpause();
	GLuint getTicks();
	GLuint getTime();

	bool isStarted();
	bool isPaused();

private:
	GLuint startTicks;
	GLuint pausedTicks;

	bool paused;
	bool started;
};



#endif /* TIMER_H_ */
