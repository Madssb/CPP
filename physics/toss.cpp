#include <iostream>

using namespace std;

struct vec1d{
    float x;
};

int main(){
    float dt; //declaring variables prior to assignment in cin
    vec1d x, v;
    float t = 0.0; //must be initialized
    float g = -9.81; //gravitational field
    cout << "insert x0:" << endl;
    cin >> x.x;
    cout << "insert v0:" << endl;
    cin >> v.x;
    cout << "insert dt:" << endl;
    cin >> dt;
    while (x.x > 0){ //Euler-cromer integration method!
        v.x = v.x + g*dt;
        x.x = x.x + v.x*dt;
        t += dt;
    }
    cout << "it took" << t <<"seconds for whatever to hit the ground" << endl;
    return 0;
}