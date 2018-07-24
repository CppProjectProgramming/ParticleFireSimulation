// ParticleFireSimulation.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Screen.h"
#include <math.h>
#include <SDL.h>
#undef main
using namespace std;


int main(int arg, char *argv)
{
	Screen* screen = new Screen();

	if (!screen) { return 1; }
	screen->Init();
	

	// Event Loop
	while (true)
	{
		// Update particles
		// Draw Particles

		int ticks = SDL_GetTicks();

		unsigned char  red = (1 + sin(ticks * 0.001)) * 128;
		unsigned char  green = (1 + sin(ticks * 0.002)) * 128;
		unsigned char  blue = (1 + sin(ticks * 0.003)) * 128;


		for (int y = 0; y < Screen::HEIGHT; y++)
		{
			for (int x = 0; x < Screen::WIDTH; x++)
			{
				screen->SetPixel(x, y, red, green, blue);
			}
		}
		// Update Screen
		screen->Update();
		// Check for messeges/events
		if (!screen->ProcessEvents()) { break; }
	}

	delete screen;
    return 0;
}

