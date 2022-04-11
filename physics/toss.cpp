#include <iostream>

using namespace std;

int main(){
    float x, v, dt; //declaring variables prior to assignment in cin
    float t = 0.0; //must be initialized
    float g = -9.81; //gravitational field
    cout << "insert x0:" << endl;
    cin >> x;
    cout << "insert v0:" << endl;
    cin >> v;
    cout << "insert dt:" << endl;
    cin >> dt;
    while (x > 0){
        v = v + g*dt;
        x = x + v*dt;
        t += dt;
    }
    cout << "it took" << t <<"seconds for whatever to hit the ground" << endl;
    return 0;
}