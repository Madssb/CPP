#ifndef VEC2D_H
#define VEC2D_H
#include <iostream>
#include <cmath>
struct vec2d{        //defining 2d vectors, and creating their "rules". no invariants to enforce, ergo struct is fine.
    float x;
    float y;
    float norm()
    {
        return std::sqrt(x*x+y*y);
    }   
    vec2d unit()
    {
        vec2d v{x,y};
        return v/v.norm();
    }
    
    friend vec2d operator+(vec2d const &c1, vec2d const &c2)           // rules for addition of vectors (vector calculus + array behaviour)
    {
        return {c1.x + c2.x, c1.y + c2.y};
    }
    friend vec2d operator-(vec2d const &c1, vec2d const &c2)           //rules for subtracting vectors (vector calculus + array behaviour)
    {
        return {c1.x - c2.x, c1.y - c2.y};
    }
    friend vec2d operator*(vec2d const &c1, vec2d const &c2)           //rules for multiplying vectors (array behaviour)
    {
        return {c1.x * c2.x, c1.y * c2.y};
    }
    friend vec2d operator/(vec2d const &c1, vec2d const &c2)           //rules for dividing vectors (array behaviour)
    {   
        return {c1.x / c2.x, c1.y / c2.y};
    }
    friend vec2d operator*(vec2d const &c1, float const &c2)           //rules for scaling vectors by multiplication
    {
        return {c1.x * c2, c1.y * c2};
    }
    friend vec2d operator*(float const &c1, vec2d const &c2)           //rules for scaling vectors by multiplication, commutative property.
    {
        return {c1 * c2.x, c1 * c2.y};
    }
    friend vec2d operator/(vec2d const &c1, float const &c2)           //rules for scaling vectors by dividing
    {
        return {c1.x /c2, c1.y/c2};
    }
    friend std::ostream &operator<<(std::ostream &os, const vec2d &c2)
    {
        os << "[" << c2.x << "," << c2.y <<"]";
        return os;
    }
};
#endif //VEC2D_H