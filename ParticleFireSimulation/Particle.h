#pragma once
struct Particle
{
	double xPos;
	double yPos;

	double xSpeed;
	double ySpeed;

public:
	Particle();
	~Particle();

	void UpdatePosition();
};

