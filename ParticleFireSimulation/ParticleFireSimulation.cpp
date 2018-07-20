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

	bool quit = false;
	SDL_Event Event;

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


	SDL_DestroyWindow(window);
	SDL_Quit();
    return 0;
}

