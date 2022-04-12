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



int main(){
    vec2d a = {1 ,2};
    vec2d b = {3, 4};
    float c = 3;
    cout <<"a="<<a<<endl;
    cout <<"c="<<c<<endl;
    cout <<"a*c="<<a*c<<endl;
    cout <<"a*a="<<a*a<<endl;
    cout <<"a.norm()="<<a.norm()<<endl;
    cout <<"a.unit()="<<a.unit()<<endl;
    return 0;
}