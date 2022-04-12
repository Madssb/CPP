#include <iostream>
#include <cmath>
using namespace std;

struct vec2d        //defining 2d vectors, and creating their "rules"
{
    float x, y;     //defines vec2d as a datatype
    vec2d(float x_input = 0, float y_input = 0)
    {
        x = x_input;
        y = y_input;
    }
    float norm(){
        return sqrt(x*x+y*y);
    }
    vec2d unit(){
        vec2d v(x,y);
        return v/v.norm();
    }
    friend vec2d operator+(vec2d const &, vec2d const &);   //lets the + operator interact with vec2d. + is basically declared a friend and is let into vec2d's house.
    friend vec2d operator-(vec2d const &, vec2d const &);   //lets - into struct house
    friend vec2d operator*(vec2d const &, vec2d const &);   // lets * into struct house
    friend vec2d operator*(vec2d const &, float const &);
    friend vec2d operator/(vec2d const &, vec2d const &);
    friend vec2d operator/(vec2d const &, float const &);
    friend ostream &operator<<(ostream &, const vec2d &);

};

vec2d operator+(vec2d const &c1, vec2d const &c2)           //house rules are established for +, and how + will behave inside vec2d's house
{
    return vec2d(c1.x + c2.x, c1.y + c2.y);
}
vec2d operator-(vec2d const &c1, vec2d const &c2)
{
    return vec2d(c1.x - c2.x, c1.y - c2.y);
}
vec2d operator*(vec2d const &c1, vec2d const &c2)
{
    return vec2d(c1.x * c2.x, c1.y * c2.y);
}
vec2d operator*(vec2d const &c1, float const &c2)
{
    return vec2d(c1.x * c2, c1.y * c2);
}
vec2d operator/(vec2d const &c1, vec2d const &c2)
{
    return vec2d(c1.x / c2.x, c1.y / c2.y);
}
vec2d operator/(vec2d const &c1, float const &c2)
{
    return vec2d(c1.x /c2, c1.y/c2);
}
ostream &operator<<(ostream &os, const vec2d &c2)
{
    os << "[" << c2.x << "," << c2.y <<"]";
    return os;
}

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
    cout << "r_final:\t" << r << endl << "v_final:\t" << v << endl;
    return 0; 
}