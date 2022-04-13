#include <iostream>
#include <cmath>
#include "vec2d.h"
//ignore stuff above, defines 2d vector behaviour!
vec2d drag(vec2d v){
    float rho =1.2;     //density of air at sea level
    float A  = 0.1*M_PI;//cross section of ball with radius r=10cm
    float Cd = 0.47;    //Drag coefficient for a sphere
    return -0.5*rho*Cd*A*pow(v.norm(),2)*v.unit();
}
vec2d acceleration(vec2d v){
    vec2d g = {-9.81, 0}; //constant acceleration g acting on object [m/s**2]
    float m = 0.1;      //kg, mass of ball
    vec2d drag_acceleration = drag(v)/m;
    vec2d total_acceleration = drag_acceleration + g;
    return total_acceleration;
}
int main(){
//initial conditions
    vec2d r = {5, 0}; //intial posistion r0 of object [m]
    vec2d v = {10, 7}; //initial velocity v0s of object [m/s]
                        //Integration loop parameters:
    int N = 100;       //amount of steps for simulation
    int n = 0;          //index which will increment    
    float T = 2;        //s, duration of simulation
    float dt = T/N;     //timestep for simulation
    while(N>n){         //Euler-Cromer integration loop
        v = v + acceleration(v)*dt;
        r = r + v*dt;
        n++;
    }
    std::cout << "r_final:\t" << r << std::endl << "v_final:\t" << v << std::endl;
    return 0; 
}