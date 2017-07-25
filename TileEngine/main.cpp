/*
 * main.cpp
 *
 *  Created on: 03 ott 2016
 *      Author: clasb
 */

#include <iterator>
#include <string>

#include "DisplayManager.h"
#include "tilemap/TileMap.h"
#include "Renderer.h"
#include "Timer.h"
#include "SDLTexture.h"
#include "Camera.h"
#include "Entity.h"
#include "shaders/TileMapShader.h"
#include "shaders/PlayerShader.h"
#include "builder/EntityCreationDirector.h"
#include "builder/PlayerBuilder.h"
#include "builder/TileMapBuilder.h"

int main(int argc, char *argv[]){
    #ifdef DEBUG
	std::cout << "START" << std::endl;
	#endif

	DisplayManager* display = new DisplayManager();
	display->Init();
	display->CreateDisplay("Test OpenGL | fps: ");

	Input* input = new Input(display);

	std::cout << "----------------------------Input created-----------------------------" << std::endl;

	std::vector<Renderable*> renderables;

	std::cout << "------------------------Start player creation-------------------------" << std::endl;

	EntityCreationDirector director;
	PlayerBuilder* playerBuilder = new PlayerBuilder;
	director.setEntityBuilder(playerBuilder);
	director.createEntity();
	renderables.push_back(director.getEntity());
	Player* player = (Player*) director.getEntity();
	input->attach(player);

	std::cout << "-----------------------------Player created---------------------------" << std::endl;

	std::cout << "------------------------Start tileMap creation------------------------" << std::endl;

	TileMapBuilder TileMapBuilder;
	TileMapBuilder.createEntity();
	TileMapBuilder.createTileset();
	TileMapBuilder.createTileLevels();
	TileMapBuilder.createShader();
	TileMapBuilder.bindBuffers();
	renderables.push_back(TileMapBuilder.getTileMap());

	std::cout << "-----------------------------TileMap created--------------------------" << std::endl;

	Renderer* GLRenderer = new Renderer();

	std::cout << "--------------------------Renderer created---------------------------" << std::endl;

	SDL_StartTextInput();

	SDL_GL_SetSwapInterval( 1 );

	Timer timer;
	int countedFrames = 0;
	timer.start();
	int fps;
	int firstTime = timer.getTime();
	int secondTime = 0;
	int deltaT = 0;

	//Camera camera(glm::vec3(0.0f, 0.0f, 0.0f), glm::vec3(0.0f, 1.0f, 0.0f), glm::vec3(0.0f, 0.0f, -1.0f));// position, up, front

	std::cout << "----------------------------Start game loop-------------------------" << std::endl;

	while(!display->isCloseRequest()){
		input->checkInput();

		fps = countedFrames/(timer.getTicks()/1000.0f);
		if(fps > 2000000)
			fps = 0;

		//std::cout << "fps: " << fps << std::endl;
		display->setWindowTitle("Test OpenGL | fps: " + std::to_string(fps));
		secondTime = timer.getTime();
		deltaT = secondTime - firstTime;
		firstTime = secondTime;

		//camera.update(deltaT, input);
		//std::cout << "deltaT: " << deltaT << std::endl;
		//std::cout << "cameraPosition: " << camera.position.x << ", " << camera.position.y << ", " << camera.position.z << std::endl;

		//camera.bindViewMatrix(shaders);

		GLRenderer->render(renderables);

		SDL_GL_SwapWindow(display->getWindow());
		++countedFrames;
	}

	#ifdef DEBUG
	std::cout << "END" << std::endl;
	#endif
	return 0;
}



