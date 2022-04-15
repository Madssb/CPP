#ifndef vec3d_H
#define vec3d_H
#include <iostream>
#include <cmath>
struct vec3d
{ // defining 2d vectors, and creating their "rules". no invariants to enforce, ergo struct is fine.
    float x;
    float y;
    float z;
    float norm()
    {
        return std::sqrt(x * x + y * y + z * z);
    }
    vec3d unit()
    {
        vec3d v{x, y, z};
        return v / v.norm();
    }
    // rules for addition of vectors (vector calculus + numpy-array behaviour)
    friend vec3d operator+(vec3d const &c1, vec3d const &c2)
    {
        return {c1.x + c2.x, c1.y + c2.y, c1.z + c2.z};
    }
    // rules for subtracting vectors (vector calculus + array behaviour)
    friend vec3d operator-(vec3d const &c1, vec3d const &c2)
    {
        return {c1.x - c2.x, c1.y - c2.y, c1.z - c2.z};
    }
    // rules for scaling vectors by multiplication
    friend vec3d operator*(vec3d const &c1, float const &c2)
    {
        return {c1.x * c2, c1.y * c2, c1.z * c2};
    }
    // same as above, but making it commutative.
    friend vec3d operator*(float const &c1, vec3d const &c2)
    {
        return {c1 * c2.x, c1 * c2.y, c1 * c2.z};
    }
    // rules for scaling vectors by division.
    friend vec3d operator/(vec3d const &c1, float const &c2)
    {
        return {c1.x / c2, c1.y / c2, c1.z / c2};
    }
    // makes vec3d objects printable with std::cout
    friend std::ostream &operator<<(std::ostream &os, const vec3d &c2)
    {
        return os << "[" << c2.x << "," << c2.y << "," << c2.z "]";
    }
    // makes vec3d able to be assigned values with std::cin
    friend std::istream &operator>>(std::istream &is, vec3d &c2)
    {
        return is >> c2.x >> c2.y << c2.z;
    }
};
#endif // vec3d_H