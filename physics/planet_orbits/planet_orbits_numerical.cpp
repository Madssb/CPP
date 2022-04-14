#include <iostream>
#include <vector>
#include <cmath>
#include <array>
using namespace std;


array<float,8> planet_initial_positions_x{3.61360399,  -1.39467103, -20.01756337,  28.33682944,   0.52782907, 7.11068085,  14.30313512,  -0.97153932};

array<float,8> planet_initial_positions_y{ 0.,           4.44044087,   6.40207052,  16.33104498,  -0.49957176, 3.83605895,  -0.95801576,  10.89478772};


float planet_positions [2] [8] [100000] = {};


struct point{
    double x, y;
}

struct point accelerate(struct point=planet_position){
    double mass_sun = 2.750553637204563;  //solar masses
    double G = 4.300e-3;                  //Gravitational constant, AU units.
    double planet_acceleration_x = mass_sun*G/std::pow(planet_position.x,2);
    double planet_acceleration_y = mass_sun*G/std::pow(planet_position.y,2);
    point planet_acceleration;
    point.x=planet_acceleration_x;
    point.y=planet_acceleration_y;
    return planet_acceleration
}


int main(){

}