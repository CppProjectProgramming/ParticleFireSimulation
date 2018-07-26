#pragma once
#include"Particle.h"

class Swarm
{
public:
	const static int NPARTICLES = 1000;
private:
	Particle * particles;
	int lastTime;
public:
	Swarm();
	~Swarm();
	void Update(int ticks);
	Particle *GetParticles() const;
};

