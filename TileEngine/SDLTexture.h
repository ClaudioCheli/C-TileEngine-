/*
 * SDLTexture.h
 *
 *  Created on: 11 ott 2016
 *      Author: clasb
 */

#ifndef SDLTEXTURE_H_
#define SDLTEXTURE_H_

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>
#include <iostream>

class SDLTexture{
public:
	SDLTexture();
	~SDLTexture();
	bool loadFromFile(std::string path, SDL_Renderer* renderer);
	bool loadFromRenderedText(std::string textureText, TTF_Font* font, SDL_Color textColor, SDL_Renderer* renderer);
	void free();
	void setColor(Uint8 red, Uint8 green, Uint8 blue);
	void setBlendMode(SDL_BlendMode blending);
	void setAlpha(Uint8 alpha);
	void render(int x, int y, SDL_Rect* clip = NULL, double angle = 0.0, SDL_Point* center = NULL, SDL_RendererFlip flip = SDL_FLIP_NONE, SDL_Renderer* renderer = NULL);
	int getWidth(){return width;}
	int getHeight(){return height;}

private:
	SDL_Texture* texture;
	int width;
	int height;

};



#endif /* SDLTEXTURE_H_ */
