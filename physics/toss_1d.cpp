#include <iostream>
#include <cmath>
using namespace std;

struct vec1d{
    float x;
};


float drag(float v){
    float rho =1.2;     //density of air at sea level
    float A  = 0.1*M_PI;//cross section of ball with radius r=10cm
    float Cd = 0.47;    //Drag coefficient for a sphere
    return -0.5*rho*Cd*A*pow(v,2);
}

float acceleration(float v){
    float g = -9.81;    //gravitational field
    float m = 1;      //kg, mass of ball
    float drag_acceleration = drag(v)/m;
    float total_acceleration = drag_acceleration+g;
    return total_acceleration;

}

int main(){
    vec1d x, v;
    x.x = 20;
    v.x = 50;
    float t = 0.0;  //must be initialized
    float T=2;     //duration of simulation
    int N=1000000 ;    //amount of steps within simulation   
    float dt =T/N;  //timestep 
    int n=0;        //increment
    while (N > n){  //Euler-cromer integration method!
        v.x = v.x + acceleration(v.x)*dt;
        x.x = x.x + v.x*dt;
        t += dt;
        n++;
    }
    cout << "x_final:" << x.x << "\tv_final" << v.x << endl;
    return 0;
}