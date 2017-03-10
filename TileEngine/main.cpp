/*
 * main.cpp
 *
 *  Created on: 03 ott 2016
 *      Author: clasb
 */

#include "DisplayManager.h"
#include "tilemap/TileMap.h"
//#include "Model.h"
#include "Renderer.h"
#include "Timer.h"
#include "SDLTexture.h"
#include "Camera.h"
#include <iterator>
#include "shaders/TileMapShader.h"
#include "shaders/PlayerShader.h"
#include "Renderable.h"

int main(int argc, char *argv[]){
    #ifdef DEBUG
	std::cout << "START" << std::endl;
	#endif

	DisplayManager* display = new DisplayManager();
	display->Init();
	display->CreateDisplay("Test OpenGL");

	Input* input = new Input(display);

	Shader* tileMapShader = new TileMapShader();
	Shader* playerShader  = new PlayerShader();
	std::vector<Shader*> shaders({tileMapShader, playerShader});

	TileMap* map   = new TileMap(tileMapShader);

	Player* player = new Player("Debug/Entities/Player.png", "Debug/Entities/Player.xml", playerShader);

	std::vector<Renderable*> entities;
	entities.push_back(map);
	//entities.push_back(player);

	Renderer* GLRenderer = new Renderer();

	SDL_StartTextInput();

	SDL_GL_SetSwapInterval( 1 );

	Timer timer;
	int countedFrames = 0;
	timer.start();
	int fps;
	int firstTime = timer.getTime();
	int secondTime = 0;
	int deltaT = 0;

	Camera camera(glm::vec3(0.0f, 0.0f, 0.0f), glm::vec3(0.0f, 1.0f, 0.0f), glm::vec3(0.0f, 0.0f, -1.0f));// position, up, front

	GLRenderer->bindProjectionMatrix(tileMapShader);
	GLRenderer->bindProjectionMatrix(playerShader);

	while(!display->isCloseRequest()){
		input->update();

		fps = countedFrames/(timer.getTicks()/1000.0f);
		if(fps > 2000000)
			fps = 0;
		//std::cout << "fps: " << fps << std::endl;

		secondTime = timer.getTime();
		deltaT = secondTime - firstTime;
		firstTime = secondTime;

		camera.update(deltaT, input);
		//std::cout << "deltaT: " << deltaT << std::endl;
		//std::cout << "cameraPosition: " << camera.position.x << ", " << camera.position.y << ", " << camera.position.z << std::endl;

		camera.bindViewMatrix(shaders);

		GLRenderer->render(entities);

		SDL_GL_SwapWindow(display->getWindow());
		++countedFrames;
	}

	#ifdef DEBUG
	std::cout << "END" << std::endl;
	#endif
	return 0;
}



