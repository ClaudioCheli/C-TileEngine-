/*
 * SDLTexture.cpp
 *
 *  Created on: 11 ott 2016
 *      Author: clasb
 */

#include "SDLTexture.h"

SDLTexture::SDLTexture(){
	texture = NULL;
	width 	= 0;
	height 	= 0;
}

SDLTexture::~SDLTexture(){
	free();
}

bool SDLTexture::loadFromFile(std::string path, SDL_Renderer* renderer){
	free();

	SDL_Texture* newTexture = NULL;
	SDL_Surface* loadedSurface = IMG_Load(path.c_str());
	if(loadedSurface == NULL){
		std::cout << "Unable to load image " << path << "! SDL_image Error: " << IMG_GetError() << std::endl;
	} else {
		SDL_SetColorKey(loadedSurface, SDL_TRUE, SDL_MapRGB(loadedSurface->format, 0, 0xFF, 0xFF));

		newTexture = SDL_CreateTextureFromSurface(renderer, loadedSurface);
		if(newTexture == NULL){
			std::cout << "Unable to create texture from " << path << "! SDL Error: " << SDL_GetError() << std::endl;
		} else {
			width  = loadedSurface->w;
			height = loadedSurface->h;
		}
		SDL_FreeSurface(loadedSurface);
	}
	texture = newTexture;
	return texture != NULL;
}

bool SDLTexture::loadFromRenderedText(std::string textureText, TTF_Font* font, SDL_Color textColor, SDL_Renderer* renderer){
	free();

	SDL_Surface* textureSurface = TTF_RenderText_Solid(font, textureText.c_str(), textColor);
	if(textureSurface == NULL){
		std::cout << "Unable to render text surface! SDL_ttf Error: " << TTF_GetError() << std::endl;
	} else {
		texture = SDL_CreateTextureFromSurface(renderer, textureSurface);
		if(texture == NULL){
			std::cout << "Unable to create texture from rendered text! SDL Error: " << SDL_GetError() << std::endl;
		} else {
			width  = textureSurface->w;
			height = textureSurface->h;
		}
		SDL_FreeSurface(textureSurface);
	}

	return texture != NULL;
}
void SDLTexture::free(){
	if(texture != NULL){
		SDL_DestroyTexture(texture);
		texture = NULL;
		width 	= 0;
		height 	= 0;
	}
}

void SDLTexture::setColor( Uint8 red, Uint8 green, Uint8 blue )
{
	SDL_SetTextureColorMod( texture, red, green, blue );
}

void SDLTexture::setBlendMode( SDL_BlendMode blending )
{
	SDL_SetTextureBlendMode( texture, blending );
}

void SDLTexture::setAlpha( Uint8 alpha )
{
	SDL_SetTextureAlphaMod( texture, alpha );
}

void SDLTexture::render(int x, int y, SDL_Rect* clip, double angle, SDL_Point* center, SDL_RendererFlip flip, SDL_Renderer* renderer){
	SDL_Rect renderQuad = {x, y, width, height};

	if(clip != NULL){
		renderQuad.w = clip->w;
		renderQuad.h = clip->h;
	}

	SDL_RenderCopyEx(renderer, texture, clip, &renderQuad, angle, center, flip);
}


