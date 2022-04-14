#include <iostream>  //std::cout lives here
#include <cmath>     //std::pow lives here
#include <vector>    //std::vector lives here
#include "vec2d.h"    //vec2d lives here

//this is witchcraft from stackoverflow, it makes it so i can use std::cout for vectors.
template < class T >
std::ostream& operator << (std::ostream& os, const std::vector<T>& v) 
{
    os << "[";
    for (typename std::vector<T>::const_iterator ii = v.begin(); ii != v.end(); ++ii)
    {
        os << " " << *ii;
    }
    os << "]";
    return os;
}

vec2d drag(vec2d v) //calculates the drag force acting on the physical object.
{
    // Density of air at sea level [kg/m^3]
    float density {1.2};
    // Cross-section of ball with radius r=0.1m [m^2]
    float area {0.1 * 0.1 * M_PI}; 
    // Drag coefficient for a sphere
    float drag_coefficient {0.47};
    // Formula for drag-force [N]
    return -0.5 * density * drag_coefficient * area * std::pow(v.norm(),2) * v.unit();  
}

vec2d acceleration(vec2d v) //calculates the total acceleration acting on the object
{
    // Gravitational field, [m/s^2]
    vec2d gravity {0, -9.81};
    // Mass of ball [kg]
    float mass {0.1};
    // Applying N2L to find the acceleration acting on the ball caused by the drag force.
    vec2d drag_acceleration = drag(v)/mass;
    // Finding the total acceleration acting on the ball by adding the accelerations.
    vec2d total_acceleration = drag_acceleration + gravity;
    return total_acceleration;
}

int main()
{
    // Initial position of the ball
    vec2d r {5, 10}; 
    // Initial velociy of the ball
    vec2d v {10, 7};
    // Amount of steps in simulating the toss
    int step_amount {100};
    // Index which will increment within simulation
    int step {0};
    // Duration of simulation [s]
    float duration {2};
    // Timestep for simulation [s]
    float dt {duration/step_amount};
    // Stores position vectors sequentially
    std::vector<vec2d> r_vector {r};
    // Stores velocity vectors sequentially
    std::vector<vec2d> v_vector {v};  
    while(step_amount>step)
    {         
        //Euler-Cromer integration loop
        v = v + acceleration(v)*dt;
        r = r + v*dt;
        //keeping information for displaying plots
        r_vector.push_back(r);
        v_vector.push_back(v);
        step++;
    }
    std::cout << "r_final:\t" << r << std::endl << "v_final:\t" << v << std::endl;
    //std::cout << "r_vector: " << r_vector << std::endl;
    return 0; 
}