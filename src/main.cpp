/*
 * main.cpp
 *
 *  Created on: 03 ott 2016
 *      Author: Claudio cheli
 */

#include <iterator>
#include <string>
#include <memory>

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
#include "logger/Logger.h"
//#include "../lib/spdlog/sinks/basic_file_sink.h"
//#include "../lib/spdlog/sinks/stdout_color_sinks.h"

int main(int argc, char *argv[]) {
	Logger::Init();
	LOG_INFO("START");

//	std::shared_ptr<spdlog::logger> logger;
//	try {
//		std::vector<spdlog::sink_ptr> sinks;
//		sinks.push_back(std::make_shared<spdlog::sinks::stdout_color_sink_mt>());
//		sinks.push_back(std::make_shared<spdlog::sinks::basic_file_sink_mt> ("logs/TELogger.log", false));
//		auto logger = std::make_shared<spdlog::logger>("TELogger", begin(sinks), end(sinks));
//
//		logger->info("Hello spdlog {} {} {}", 1, 2, "three");
//
////		logger = spdlog::stdout_color_mt("TELogger");
////		logger->sinks().push_back(spdlog::basic_logger_mt("TELogger", "logs/TELogger.log")->);
////		logger = spdlog::basic_logger_mt("TELogger", "logs/TELogger.log");
////		logger->sinks().push_back(
////				std::make_shared<spdlog::sinks::stdout_color_sink_mt>());
//	} catch (const spdlog::spdlog_ex &ex) {
//		std::cout << "Log init failed: " << ex.what() << std::endl;
//	}
//
//	logger->info("Test logger");


	Logger::getLogger()->info("Test logger");

	DisplayManager* display = new DisplayManager();
	display->Init();
	display->CreateDisplay("Test OpenGL | fps: ");

	Input* input = new Input(display);

	LOG_INFO("Input created");

	std::vector<Renderable*> renderables;

	LOG_INFO("Start player creation");

	EntityCreationDirector director;
	PlayerBuilder* playerBuilder = new PlayerBuilder;
	director.setEntityBuilder(playerBuilder);
	director.createEntity();
	renderables.push_back(director.getEntity());
	Player* player = (Player*) director.getEntity();
	input->attach(player);

	LOG_INFO("Player created");

	LOG_INFO("Start tileMap creation");

	TileMapBuilder TileMapBuilder;
	TileMapBuilder.createEntity();
	TileMapBuilder.createTileset();
	TileMapBuilder.createTileLevels();
	TileMapBuilder.createShader();
	TileMapBuilder.bindBuffers();
	renderables.push_back(TileMapBuilder.getTileMap());

	LOG_INFO("TileMap created");

	Renderer* GLRenderer = new Renderer();

	LOG_INFO("Renderer created");

	SDL_StartTextInput();

	SDL_GL_SetSwapInterval(1);

	Timer timer;
	int countedFrames = 0;
	timer.start();
	int fps;
	//int firstTime = timer.getTime();
	//int secondTime = 0;
	//int deltaT = 0;

	//Camera camera(glm::vec3(0.0f, 0.0f, 0.0f), glm::vec3(0.0f, 1.0f, 0.0f), glm::vec3(0.0f, 0.0f, -1.0f));// position, up, front

	LOG_INFO("Start game loop");

	while (!display->isCloseRequest()) {
		input->checkInput();

		fps = countedFrames / (timer.getTicks() / 1000.0f);
		if (fps > 2000000)
			fps = 0;

		//std::cout << "fps: " << fps << std::endl;
		display->setWindowTitle("Test OpenGL | fps: " + std::to_string(fps));
		//secondTime = timer.getTime();
		//deltaT = secondTime - firstTime;
		//firstTime = secondTime;

		//camera.update(deltaT, input);
		//std::cout << "deltaT: " << deltaT << std::endl;
		//std::cout << "cameraPosition: " << camera.position.x << ", " << camera.position.y << ", " << camera.position.z << std::endl;

		//camera.bindViewMatrix(shaders);

		GLRenderer->render(renderables);

		SDL_GL_SwapWindow(display->getWindow());
		++countedFrames;
	}


	LOG_INFO("END");

	return 0;
}

