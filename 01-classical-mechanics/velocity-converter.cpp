#include <iostream>
using namespace std;

int main() {
    double velocity;

    cout << "Enter velocity in m/s: ";
    cin >> velocity;

    
    double kmh = velocity * 3.6;

    cout << "Velocity in km/h: " << kmh << '\n';

    return 0;
}