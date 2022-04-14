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
    friend vec2d operator+(vec2d const &, vec2d const &);   //lets the + operator interact with vec2d. + is basically declared a friend and is let into vec2d's house.
    friend vec2d operator-(vec2d const &, vec2d const &);
    friend vec2d operator*(vec2d const &, vec2d const &);
    friend vec2d operator*(vec2d const &, float const &);
    friend vec2d operator/(vec2d const &, vec2d const &);
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
ostream &operator<<(ostream &os, const vec2d &c2)
{
    os << "x: " << c2.x << " y: " << c2.y << "\n";
    return os;
}
//ignore stuff above, defines 2d vector behaviour!




int main(){
//initial conditions
    vec2d r; //intial posistion r0 of object [m]
    r.x = 5;
    r.y = 0;
    vec2d v; //initial velocity v0 of object [m/s]
    v.x = 10;
    v.y = 7;
    vec2d g; //constant acceleration g acting on object [m/s**2]
    g.x = -9.81;
    g.y = 0;

                        //Integration loop parameters:
    int N = 1000;       //amount of steps for simulation
    int n = 0;          //index which will increment
    float T = 2;        //s, duration of simulation
    float dt = T/N;     //timestep for simulation
    while(N>n){         //Euler-Cromer integration loop
        v = v + g*dt;
        r = r + v*dt;
        n++;
    }
    cout << "r_final:\t" << r << endl << "v_final:\t" << v << endl;
    return 0; 
}