#include "Physics.h"

void Physic::create_planets(const int N)
{
	
#pragma openmp parallel for private(i)
	for (int i = 0; i < N; i++)
	{
		std::vector<double> arr{ 0.0,0.0,0.0 };
		std::vector<double> vel{ 0.0,0.0,0.0 };
		while ((arr[0] < 500 && arr[0] > -500))
			arr[0] = ofRandom(-10000, 10000);
		while ((arr[1] < 500 && arr[1] > -500))
			arr[1] = ofRandom(-10000, 10000);

		arr[2] = ofRandom(-5000, 5000);
		vel = this->calc_speed(arr, sun);

		
		double mass;
		if(this->Mass_bounds[0] <= this->Mass_bounds[1])
			mass = ofRandom(Mass_bounds[0], Mass_bounds[1]);
		else
			mass = ofRandom(Mass_bounds[1], Mass_bounds[0]);
		double r = ofRandom(20, 300);
		planets.push_back(Planet(arr,vel,r,mass));


	}
	if (use_moons)
	{
	#pragma openmp parallel for private(i)
		for (int i = 0; i < N; i++)
		{
			if (ofRandom(0, 100) <= moon_chance)
			{
				std::vector<double> arr{ 0.0,0.0,0.0 };
				std::vector<double> vel{ 0.0,0.0,0.0 };
				const std::vector<double> p = this->planets[i].Get_positions();
				const std::vector<double> v = this->planets[i].Get_vel();
				arr[0] = p[0] + 5 + this->planets[i].Get_r();
				arr[1] = p[1] + 5 + this->planets[i].Get_r();
				arr[2] = p[2] + 5 + this->planets[i].Get_r();
				vel = calc_speed(arr, this->planets[i], 2);
				vel[0] = v[0];
				vel[1] = v[1];
				vel[2] = v[2];
				//arr[2] = ofRandom(1000, 4000);
			//}
				double mass = 0.1;
				double r = this->planets[i].Get_r() / 3.0;
				planets.push_back(Planet(arr, vel, r, mass));
			}

		}
	}
	
}

const void Physic::update_positions()
{

#pragma openmp parallel for private(i)
	for (int i = 0; i < int(this->planets.size()); i++)
	{
		for (int b = 0; b < int(this->planets.size()); b++)
		{
			if (b != i && (this->planets[i].Get_Mass() > 1.0) )
				this->planets[i].calc_a(this->planets[b],this->G);
		}
		this->planets[i].calc_a(sun,this->G);
		
		//if (i == this->planets.size() - 3)
			//this->planets[i].print_info();

		this->planets[i].calc_v(this->dt);
	}
#pragma openmp parallel for private(i)
	for (int i = 0; i < int(this->planets.size()); i++)
	{
		this->planets[i].calc_position(this->dt);
	}

}

const void Physic::draw_planets()
{
	ofSetColor(255, 211, 0);
	this->sun.draw(true);
#pragma openmp parallel for private(i)
	for (int i = 0; i < int(this->planets.size()); i++)
	{

		this->planets[i].draw();
	}
}

std::vector<double> Physic::calc_speed(const std::vector<double>& pos,Planet& sun, const int N)
{
	std::vector<double> v{ 0.0,0.0,0.0 };
	std::vector<double> sunpos = sun.Get_positions();
	const double d = sqrt(pow((pos[0] - sunpos[0]), 2) + pow((pos[1] - sunpos[1]), 2) + pow((pos[2] - sunpos[2]), 2));
	std::cout << d << std::endl;
	//double vers[3];
	//vers[0] = -(pos[0] - sunpos[0]) / d;
	//vers[1] = -(pos[1] - sunpos[1]) / d;
	//vers[2] = -(pos[2] - sunpos[2]) / d;
	v[N] = sqrt(this->G * sun.Get_Mass() / d); //* vers[i];
	//std::cout << "v[i]" << v[1] << std::endl;
	return v;
}
