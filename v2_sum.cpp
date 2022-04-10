#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>     //defines the standard stream objects that input and output data.
#include <algorithm>
using namespace std; 


int main() {
    int a, b, c; //accomplishes the same  in less lines
    cout << "enter 3 integers you wish to sum:" << endl;
    cin >> a >> b >> c; //assigns inputs to variables
    cout  << "the sum is " << a+b+c << "." << endl; // returns sum of variables
    return 0;
}