#include <iostream> //std::cout lives here
#include <cmath>    //std::pow lives here
#include "vec2d.h"  //vec2d lives here (duh)
#include <fstream>  //std::ofstream lives here

// Calculates the gravitational acceleration acted on a planet, by the sun, by applying N2L to the gravitational force.
vec2d gravitational_acceleration(vec2d position)
{
    float const star_mass{2.750553637204563};
    // Gravitational constant in solar system units [AU^3/yr^2/m_sun]
    float const Gravitational_constant{39.47841760435743};
    return -star_mass * Gravitational_constant * position.unit() / std::pow(position.norm(), 2);
}

int main()
{
    // initial position and velocity for planet in solar system, where sun exists within the origin.
    vec2d r{3.61360399, 0.};
    //vec2d v{0., 5.45623455};
    vec2d v{0., 0.45623455};
    int const step_amount{10000000};
    // duration for simulation [yr]
    float const duration{100};
    //  Timestep for simulation [yr]
    float const dt{duration / step_amount};
    int step{0};
    std::ofstream myfile;
    myfile.open("data.txt");
    while (step_amount > step)

    {
        v = v + gravitational_acceleration(r) * dt;
        r = r + v * dt;
        step++;
        myfile << r.x << " " << r.y << " " << v.x << " " << v.y << "\n";
    }
    myfile.close();
    return 0;
}