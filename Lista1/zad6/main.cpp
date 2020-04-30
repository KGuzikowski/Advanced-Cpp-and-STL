#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    float a, b, c;
    cin >> a >> b >> c;

    if(float delta = b*b - 4.0*a*c; delta > 0) {
       float x1 = (-b - sqrt(delta)) / 2.0*a;
       float x2 = (-b + sqrt(delta)) / 2.0*a;
       cout << "delta: " << delta << ", x1: " << x1 << ", x2: " << x2 << endl;
    } else if(delta == 0) {
        float x = -b / 2.0*a;
        cout << "delta: " << delta << ", x: " << x <<endl;
    } else {
        cout << "delta < 0, brak pierwiastków równania" << endl;
    }

    return 0;
}
