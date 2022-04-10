#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>     //defines the standard stream objects that input and output data.
#include <algorithm>
using namespace std; 


int main() {
    float a, b; //accomplishes the same  in less lines
    a = 4.0;
    b = 0.0;

    cout  << "4 divided by zero is:"  << a/b << "." << endl; // returns sum of variables
    return 0;
}
/*
$ ./divide_by_zero 
4 divided by zero is:inf.
*/