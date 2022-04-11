#include <iostream>
using namespace std;






int main() {
    int passengers;
    int capacity=50;
    cout << "Enter amount of passengers: " << endl;
    cin >> passengers;
    int remainder = passengers % capacity;
    int empty_seats = capacity-remainder;

    cout << "the amount of empty seats on the last bus are "<< empty_seats << "." << endl;
    return 0;
}