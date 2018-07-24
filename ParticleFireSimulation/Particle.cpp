#include "stdafx.h"
#include "Particle.h"


Particle::Particle()
{
	// Setting X and Y as a random number from 
	xPos = ((2.0 * rand()) / RAND_MAX) - 1;
	yPos = ((2.0 * rand()) / RAND_MAX) - 1;

}


Particle::~Particle()
{
}
