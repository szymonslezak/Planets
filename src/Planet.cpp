#include "Planet.h"

const std::vector<double> Planet::Get_positions()
{
	return this->positions;
}

const std::vector<double> Planet::Get_vel()
{
	return this->velocity;
}

const int Planet::Get_r()
{
	return this->radius;
}

const void Planet::draw(const bool& sun)
{

	if (!sun)
	{
		if (this->mass >= 1.0)
			ofSetColor(this->color[0], this->color[1], this->color[2]);
		else
			ofSetColor(255, 255, 255);
	}
	this->sphere.setPosition(this->positions[0],this->positions[1],this->positions[2]);
	this->sphere.draw();
}

void Planet::calc_position(const double dt)
{
	for (int i = 0; i < 3; i++)
	{
		this->positions[i] += this->velocity[i] * dt;
	}

}

void Planet::calc_v(const double dt)
{
	for (int i = 0; i < 3; i++)
	{
		this->velocity[i] = this->velocity[i] - this->a[i] * dt;
		this->a[i] = 0.0;
	}
	
}

const void Planet::print_info()
{
	std::cout << "positons:\n" << this->positions[0] << "\n" << this->positions[1] << "\n" << this->positions[2] << "\nn";
	std::cout<< "velocities:\n"<<this->velocity[0] << "\n" << this->velocity[1] << "\n" << this->velocity[2] << "\nn";
	std::cout<< "przyszp:\n"<<this->a[0] << "\n" << this->a[1] << "\n" << this->a[2] << "\nnnn";
}

void Planet::calc_a(const Planet& sun, const double& G)
{
	const double d = sqrt(pow((this->positions[0] - sun.positions[0]), 2) + pow((this->positions[1] - sun.positions[1]), 2) + pow((this->positions[2] - sun.positions[2]), 2));
	double vers[3];
	vers[0] = (this->positions[0] - sun.positions[0]) / d;
	vers[1] = (this->positions[1] - sun.positions[1]) / d;
	vers[2] = (this->positions[2] - sun.positions[2]) / d; //.normalize() vector
	for (int i = 0; i < 3; i++)
	{
		this->a[i] += G * sun.mass * vers[i] / d/d;
		
	}
}
