#include "stdafx.h"
#include "Swarm.h"


Swarm::Swarm()
{
	particle = new Particle[NPARTICLES];
}


Swarm::~Swarm()
{
	delete[] particle;
}

Particle * Swarm::GetParticles() const
{
	return particle;
}
