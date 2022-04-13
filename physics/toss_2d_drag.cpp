#include <iostream>
#include <cmath>
#include <vector> //will be used for vector stuff lol
#include "vec2d.h" //defines the vec2d datatype, which is 2d mathematical vectors. 


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


vec2d drag(vec2d v){
    float rho =1.2;     //density of air at sea level
    float A  = 0.1*0.1*M_PI;//cross section of ball with radius r=0.1m
    float Cd = 0.47;    //Drag coefficient for a sphere
    return -0.5*rho*Cd*A*pow(v.norm(),2)*v.unit();  //drag force acting on object [N]
}
vec2d acceleration(vec2d v){
    vec2d g = {-9.81, 0};   //constant acceleration g acting on object, [m/s**2]
    float m = 0.1;          //kg, mass of object                        [kg]
    vec2d drag_acceleration = drag(v)/m;
    vec2d total_acceleration = drag_acceleration + g;
    return total_acceleration;
}
int main(){
//initial conditions
    vec2d r = {5, 0}; //intial position r0 of object.       [m]
    vec2d v = {10, 7}; //initial velocity v0s of object.    [m/s]
    std::vector<vec2d> r_vector = {r};
    std::vector<vec2d> v_vector = {v};
    int N = 100;       //amount of steps for simulation
    int n = 0;          //index which will increment    
    float T = 2;        //s, duration of simulation
    float dt = T/N;     //timestep for simulation
    while(N>n){         //Euler-Cromer integration loop
        v = v + acceleration(v)*dt;
        r = r + v*dt;
        r_vector.push_back(r);
        v_vector.push_back(v);
        n++;
    }
    std::cout << "r_final:\t" << r << std::endl << "v_final:\t" << v << std::endl;
    std::cout << "r_vector: " << r_vector << std::endl;
    return 0; 
}