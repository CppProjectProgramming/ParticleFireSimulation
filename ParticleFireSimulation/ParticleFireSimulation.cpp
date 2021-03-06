// ParticleFireSimulation.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Screen.h"
#include <math.h>
#include <SDL.h>
#include <time.h>
#include "Swarm.h"
#undef main
using namespace std;


int main(int arg, char *argv)
{

	srand(time(nullptr));

	Screen* screen = new Screen();

	if (!screen) { return 1; }
	screen->Init();
	screen->SetBackgroundColor(0, 0, 0);
	
	Swarm* swarm = new Swarm();

	// Event Loop
	while (true)
	{
		int ticks = SDL_GetTicks();

		//screen->Clear();
		swarm->Update(ticks);

		unsigned char  red = (1 + sin(ticks * 0.001)) * 128;
		unsigned char  green = (1 + sin(ticks * 0.002)) * 128;
		unsigned char  blue = (1 + sin(ticks * 0.003)) * 128;

		// Update particles
		// Draw Particles
		Particle* particles = swarm->GetParticles();
		for (int i = 0; i < Swarm::NPARTICLES; i++)
		{
			Particle particle = particles[i];
			int xPos = (particle.xPos + 1) * Screen::WIDTH / 2;
			int yPos = (particle.yPos + 0.75) * Screen::WIDTH / 2;
			screen->SetPixel(xPos, yPos, red, green, blue);
		}

		screen->BoxBlur();
		// Update Screen
		screen->Update();
		// Check for messeges/events
		if (!screen->ProcessEvents()) { break; }
	}

	delete swarm;
	delete screen;
    return 0;
}

