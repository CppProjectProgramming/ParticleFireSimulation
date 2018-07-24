#pragma once
#include"Particle.h"

class Swarm
{
public:
	const static int NPARTICLES = 5000;
private:
	Particle * particle;

public:
	Swarm();
	~Swarm();

	Particle *GetParticles() const;
};

