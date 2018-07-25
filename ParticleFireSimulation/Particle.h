#pragma once
struct Particle
{
	double xPos;
	double yPos;

	double speed;
	double direction;
public:
	Particle();
	~Particle();

	void UpdatePosition();
};

