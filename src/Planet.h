#pragma once
#include <vector>
#include "ofMain.h"

class Planet
{
	ofSpherePrimitive sphere;
	std::vector<double> positions{ 0.0,0.0,0.0 };
	std::vector<double> velocity{ 20.0,20.0,0.0 };
	double radius = 0;
	//double G = 20000;
	double wat_g = 8.314 * 0.0009 * 6 * 3.14;
//ROBI SIE KATAPULTA!!!!!!!
	int color[3] = { rand() % 255,rand() % 255,rand() % 255 };
	double mass = 100000.0;
	double a[3] = { 0.0,0.0,0.0 };
public:
	Planet()
	{
		sphere.setRadius(radius);
		sphere.enableColors();
	}

	Planet(const double pos[3], const double r)
	{
		positions[0] = pos[0];
		positions[1] = pos[1];
		positions[2] = pos[2];
		radius = r;
		sphere.setRadius(radius);
		sphere.enableColors();
	}
	Planet(const double pos[3], const double r,const double m)
	{
		positions[0] = pos[0];
		positions[1] = pos[1];
		positions[2] = pos[2];
		radius = r;
		mass = m;
		sphere.setRadius(radius);
		sphere.enableColors();
	}
	Planet(const double pos[3],const double vel[3], const double r, const double m)
	{
		positions[0] = pos[0];
		positions[1] = pos[1];
		positions[2] = pos[2];
		velocity[0] = vel[0];
		velocity[1] = vel[1];
		velocity[2] = vel[2];
		radius = r;
		mass = m;
		sphere.setRadius(radius);
		sphere.enableColors();
	}
	Planet(const std::vector<double> pos, const std::vector<double> vel, const double r, const double m)
	{
		positions[0] = pos[0];
		positions[1] = pos[1];
		positions[2] = pos[2];
		velocity[0] = vel[0];
		velocity[1] = vel[1];
		velocity[2] = vel[2];
		radius = r;
		mass = m;
		sphere.setRadius(radius);
		
	}
	const std::vector<double> Get_positions();
	const std::vector<double> Get_vel();
	const int Get_r();
	const void draw(const bool& sun = false);
	const double Get_Mass() {
		return this->mass;
	}
	void calc_position(const double dt);
	void calc_a(const Planet& sun, const double& G);
	void calc_v(const double dt);
	const void print_info();
	void Set_Mass(const double M)
	{
		mass = M;
	}
	void Set_Radius(const double R)
	{
		radius = R;
		sphere.setRadius(radius);
	}

};

