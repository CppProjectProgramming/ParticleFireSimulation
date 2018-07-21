// ParticleFireSimulation.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include <SDL.h>
#undef main
using namespace std;

const char TITLE[200] = "Particle Fire Simulation";

int main(int arg, char *argv)
{
	const char TITLE[200] = "Particle Fire Simulation";
	const int WIDTH = 800;
	const int HEIGHT = 600;

	if (SDL_Init(SDL_INIT_VIDEO) < 0)
	{
		cout << "SDL Init failed" << endl;
		return 1;
	}

	SDL_Window *window = SDL_CreateWindow(TITLE,
		SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 
		WIDTH, HEIGHT, SDL_WINDOW_SHOWN);
	if (!window) 
	{ 
		SDL_Quit();
		return 2; 
	}

	SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_PRESENTVSYNC);
	SDL_Texture* texture = SDL_CreateTexture(renderer, SDL_PIXELFORMAT_RGBA8888, SDL_TEXTUREACCESS_STATIC,
		WIDTH, HEIGHT);

	Uint32* buffer = new Uint32[WIDTH * HEIGHT];

	//http://www.cplusplus.com/reference/cstring/memset/
	memset(buffer, 0xFF, WIDTH*HEIGHT*sizeof(Uint32));
	
	SDL_UpdateTexture(texture, nullptr, buffer, WIDTH * sizeof(Uint32));
	SDL_RenderClear(renderer);
	SDL_RenderCopy(renderer, texture, nullptr, nullptr);
	SDL_RenderPresent(renderer);
	bool quit = false;
	SDL_Event Event;

	if (!renderer)
	{
		SDL_DestroyWindow(window);
		SDL_Quit();
		return 3;
	}

	if (!texture)
	{
		SDL_DestroyRenderer(renderer);
		SDL_DestroyWindow(window);
		SDL_Quit();
		return 4;
	}

	// Event Loop
	while (!quit)
	{
		// Update particles
		// Draw partoc;es
		// Check for messeges/events

		while (SDL_PollEvent(&Event))
		{
			if (Event.type == SDL_QUIT)
			{
				quit = true;
			}
		}
	}

	delete[] buffer;
	SDL_DestroyRenderer(renderer);
	SDL_DestroyTexture(texture);
	SDL_DestroyWindow(window);
	SDL_Quit();
    return 0;
}

