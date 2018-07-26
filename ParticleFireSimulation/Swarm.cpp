#include "stdafx.h"
#include "Swarm.h"


Swarm::Swarm() : lastTime(0)
{
	particles = new Particle[NPARTICLES];
}


Particle * Swarm::GetParticles() const
{
	return particles;
}

void Swarm::Update(int ticks)
{
	int interval = ticks - lastTime;
	for (int i = 0; i < NPARTICLES; i++)
	{
		particles[i].UpdatePosition(interval);
	}
}

Swarm::~Swarm()
{
	delete[] particles;
}




