#include <iostream>
#include "vec2d.h"

int main(){
    vec2d a= {1,3};
    float c = 2;
    vec2d b = a*c;
    std::cout << b <<std::endl;
    return 0;
}