#include <iostream>
using namespace std;


int main(){
    float v0, g;
    v0 = 8.2; //m/s
    g = -9.81; //m/s**2
    float t_max = -v0/g;
    cout << "the ball is at its maximum height after " << t_max << "s." << endl;
    return 0;
}