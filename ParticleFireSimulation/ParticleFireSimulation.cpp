// ParticleFireSimulation.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Screen.h"
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
		// Draw partoc;es
		// Check for messeges/events
		if (!screen->ProcessEvents()) { break; }
	}

	delete screen;
    return 0;
}

