#include "stdafx.h"
#include "Swarm.h"


Swarm::Swarm()
{
	particles = new Particle[NPARTICLES];
}


Particle * Swarm::GetParticles() const
{
	return particles;
}

void Swarm::Update()
{
	for (int i = 0; i < NPARTICLES; i++)
	{
		particles[i].UpdatePosition();
	}
	
}

Swarm::~Swarm()
{
	delete[] particles;
}




