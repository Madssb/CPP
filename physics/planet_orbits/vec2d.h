#ifndef VEC2D_H
#define VEC2D_H
#include <iostream>
#include <cmath>
struct vec2d
{ // defining 2d vectors, and creating their "rules". no invariants to enforce, ergo struct is fine.
    float x;
    float y;
    float norm()
    {
        return std::sqrt(x * x + y * y);
    }
    vec2d unit()
    {
        vec2d v{x, y};
        return v / v.norm();
    }
    // rules for addition of vectors (vector calculus + numpy-array behaviour)
    friend vec2d operator+(vec2d const &c1, vec2d const &c2)
    {
        return {c1.x + c2.x, c1.y + c2.y};
    }
    // rules for subtracting vectors (vector calculus + array behaviour)
    friend vec2d operator-(vec2d const &c1, vec2d const &c2)
    {
        return {c1.x - c2.x, c1.y - c2.y};
    }
    // rules for scaling vectors by multiplication
    friend vec2d operator*(vec2d const &c1, float const &c2)
    {
        return {c1.x * c2, c1.y * c2};
    }
    // same as above, but making it commutative.
    friend vec2d operator*(float const &c1, vec2d const &c2)
    {
        return {c1 * c2.x, c1 * c2.y};
    }
    // rules for scaling vectors by division.
    friend vec2d operator/(vec2d const &c1, float const &c2)
    {
        return {c1.x / c2, c1.y / c2};
    }
    // makes vec2d objects printable with std::cout
    friend std::ostream &operator<<(std::ostream &os, const vec2d &c2)
    {
        return os << "[" << c2.x << "," << c2.y << "]";
    }
    // makes vec2d able to be assigned values with std::cin
    friend std::istream &operator>>(std::istream &is, vec2d &c2)
    {
        return is >> c2.x >> c2.y;
    }
};
#endif // VEC2D_H