#pragma once
#include"Particle.h"

class Swarm
{
public:
	const static int NPARTICLES = 1000;
private:
	Particle * particles;

public:
	Swarm();
	~Swarm();
	void Update();
	Particle *GetParticles() const;
};

