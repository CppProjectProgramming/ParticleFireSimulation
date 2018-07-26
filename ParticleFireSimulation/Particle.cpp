#include "stdafx.h"
#include "Particle.h"
#include <time.h>

# define M_PI           3.14159265358979323846  /* pi */

Particle::Particle() : xPos(0), yPos(0)
{
	// Setting X and Y as a random number from 
	direction = (2 * M_PI * rand()) / RAND_MAX;
	speed = (0.000001 * rand()) / RAND_MAX;
}


Particle::~Particle()
{
}

void Particle::UpdatePosition(int interval)
{
	double xSpeed = speed * cos(direction);
	double ySpeed = speed * sin(direction);
	
	xPos += xSpeed * interval;
	yPos += ySpeed * interval;
}
