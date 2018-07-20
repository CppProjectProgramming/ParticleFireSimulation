// ParticleFireSimulation.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include <SDL.h>
#undef main
using namespace std;

int main(int arg, char *argv)
{
	if (SDL_Init(SDL_INIT_VIDEO) < 0)
	{
		cout << "SDL Init failed" << endl;
		return 1;
	}
	cout << "SDL Init Succeeded" << endl;

	SDL_Quit();
    return 0;
}

