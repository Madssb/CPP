#include <iostream>
using namespace std;

int main() {
    int age;
    cout << "enter age" << endl;
    cin >> age;
    switch (age) {
        case 16:
            cout << "too young" << endl;
            break;
        case 42:
            cout << "adult" << endl;
            break;
        case 70:
            cout << "senior" << endl;
            break;
        default:
            cout << "this is the default case";
    }   
    return 0;
}