#pragma once
#include <vector>
#include "Planet.h"
class Physic
{
	int bounds[3] = { 0,0,0 };
	double dt = 0.1;
	double G = 20000;
	std::vector<Planet> planets;
	Planet sun;
	const void draw_bounds();
	//toogle
	bool use_moons = true;
	bool use_multi_moons = false;
	int moon_chance = 10;

	double Mass_bounds[2] = { 0.0,0.0 };

public:
	void create_planets(const int N);
	const void update_positions();
	const void draw_planets();
	std::vector<double> calc_speed(const std::vector<double>& pos,Planet& sun,const int N = 1);
	Physic()
	{
		double arr2[3] = { 0.0,0.0,0.0 };
		sun = Planet(arr2, 300);
	}
	Physic(int bound_x,int bound_y,int bound_z)
	{
		bounds[0] = bound_x;
		bounds[1] = bound_y;
		bounds[2] = bound_z;
		double arr2[3] = { 0.0,0.0,0.0 };
		sun = Planet(arr2, 300);
	}
	//Togglers
	void Toggle_Moons(bool use)
	{
		use_moons = use;
	}
	void Toggle_Multiple_Moons(bool use)
	{
		use_multi_moons = use;
	}
	Planet* get_sun()
	{
		return &sun;
	}
	void Set_G(const double g)
	{
		G = g;
	}
	const double Get_G()
	{
		return G;
	}
	void Set_Mass(const double M[2])
	{
		Mass_bounds[0] = M[0];
		Mass_bounds[1] = M[1];
	}
	void Set_moon_chance(const int N)
	{
		moon_chance = N;
	}
};

