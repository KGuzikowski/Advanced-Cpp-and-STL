#include <iostream>
#include <complex>
#include <cmath>

using namespace std;

complex<double> Euler(complex<double> z){
    complex<double> wynik = 1;
    for(double i = 1; i < 1000; i += 1.0){
        wynik *= (pow(1.0 + 1.0/i, z) / (1.0 + z/i));
    }
    wynik *= 1.0/z;
    return wynik;
}

complex<double> odwrotnyEuler(complex<double> z){
    complex<double> wynik = 1;
    const double cnst = 0.5772156649;
    for(double i = 1; i < 1000; i += 1.0){
        wynik *= ((1.0 + z/i) * pow(M_E, -z/i));
    }
    wynik *= z * pow(M_E, z*cnst);
    return wynik;
}

int main()
{
    complex<double> a(1.0, 1.0);

    cout << "funkcja gamma Eulera:" << endl;
    cout << Euler(a) << endl;
    cout << endl;
    cout << "odwrotna funkcja gamma Eulera:" << endl;
    cout << odwrotnyEuler(a) << endl;

    return 0;
}
