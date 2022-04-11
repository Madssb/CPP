#include <iostream>
#include <vector>
#include <cmath>
using namespace std;



struct point{
    double x, y;
}

point planet_initial_position;

struct point accelerate(struct point=planet_position){
    double mass_sun = 2.750553637204563;  //solar masses
    double G = 4.300e-3;                  //Gravitational constant, AU units.
    double planet_acceleration_x = mass_sun*G/std::pow(planet_position.x,2);
    double planet_acceleration_y = mass_sun*G/std::pow(planet_position.y,2);
    point planet_acceleration;
    point.x=planet_acceleration_x;
    point.y=planet_acceleration_y;
    return planet_acceleration