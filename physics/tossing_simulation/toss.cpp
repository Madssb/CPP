/*
 *This program simulates the trajectory of an object (currently a ball, but parameters within drag can be edited to specify somethingelse).
 *The drag force is simulated, along with the gravitational force,
 *an approximation for near sea-level gravitational force has been made, with a constant acceleration of -9.81 in y-direction.
 */

#include <iostream> //std::cout lives here
#include <cmath>    //std::pow lives here
#include "vec2d.h"  //vec2d lives here
#include <fstream>  //std::ofstream lives here

vec2d drag(vec2d v) // calculates the drag force acting on the physical object.
{
    // Density of air at sea level [kg/m^3]
    float density{1.2};
    // Cross-section of ball with radius r=0.1m [m^2]
    float area{0.1 * 0.1 * M_PI};
    // Drag coefficient for a sphere
    float drag_coefficient{0.47};
    // Formula for drag-force [N]
    return -0.5 * density * drag_coefficient * area * std::pow(v.norm(), 2) * v.unit();
}

vec2d acceleration(vec2d v) // calculates the total acceleration acting on the object
{
    // Gravitational field, [m/s^2]
    vec2d gravity{0, -9.81};
    // Mass of ball [kg]
    float mass{0.1};
    // Applying N2L to find the acceleration acting on the ball caused by the drag force.
    vec2d drag_acceleration = drag(v) / mass;
    // Finding the total acceleration acting on the ball by adding the accelerations.
    vec2d total_acceleration = drag_acceleration + gravity;
    return total_acceleration;
}

int main()
{
    // Initial position of the ball
    vec2d r{0,10};
    // Initial velociy of the ball
    vec2d v{5,300};
    //std::cout << "insert r0: ";
    //std::cin >> r;
    //std::cout << "insert v0: ";
    //std::cin >> v;

    // Amount of steps in simulating the toss
    int step_amount{};
    std::cout << "insert step amount";
    std::cin >> step_amount;

    // Duration of simulation [s]
    float duration{2};
    //std::cout << "insert simulation length:";
    //std::cin >> duration;
    // Timestep for simulation [s]
    float dt{duration / step_amount};
    // Index which will increment within simulation
    int step{0};
    std::ofstream myfile;
    myfile.open("data.txt");
    while (step_amount > step and r.y > 0)
    {
        // Euler-Cromer integration loop
        v = v + acceleration(v) * dt;
        r = r + v * dt;
        // information about position and velocity is stored in data.txt for usage in display.py, visualizing the data of the simulation
        myfile << r.x << " " << r.y << " " << v.x << " " << v.y << std::endl;
        step++;
    }
    myfile.close();
    return 0;
}