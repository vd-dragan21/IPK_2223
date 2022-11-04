//ub1, Aufgabe 2, Paul Bruckert, Valeriia Dragan
#include <iostream>
#include <cmath>

using namespace std;

int main(int argc, char** argv){
    double a, b, c;
    cout << "a = " << flush;
    cin >> a;
    cout << "b = " << flush;
    cin >> b;
    cout << "c = " << flush;
    cin >> c;
    double d = pow(b,2) - 4*a*c;
    if (d < 0){
        cout << "Keine Nullstelle gefunden" << endl;
    } else if (d == 0) {
        double x = (-b + sqrt(d)/(2*a));
        cout << "Nur eine Nullstelle gefunden:" << x << endl;
    } else {
        double x1 = (-b + sqrt(d)/(2*a));
        double x2 = (-b - sqrt(d)/(2*a));
        cout << x1 << x2 << endl;
    }
    return 0;
}
