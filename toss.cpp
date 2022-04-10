#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

double x(double t){
    float g = -9.81; //gravitational acceleration [m/s^2]
    float v0 = 5; //initial velocity [m/s]
    float answer =(g*pow(t, 2.0))/2.0 + v0*t;
    return answer;
}

int main(){
    float time = 1.0;
    cout << "time:" << time << "s. y-coordinate: " << x(time) << endl;
    return 0;
}