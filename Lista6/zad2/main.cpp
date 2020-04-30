#include <iostream>
#include <random>
#include <chrono>
#include <fstream>

using namespace std;

int main()
{
    unsigned seed1 = chrono::system_clock::now().time_since_epoch().count();
    default_random_engine dre1(seed1);
    uniform_real_distribution<double> di1(0, 100);
    ofstream UniformReal;
    UniformReal.open("UniformReal.csv");

    unsigned seed2 = chrono::system_clock::now().time_since_epoch().count();
    default_random_engine dre2(seed2);
    binomial_distribution<int> di2(1000, 0.5);
    ofstream Binomial;
    Binomial.open("Binomial.csv");

    unsigned seed3 = chrono::system_clock::now().time_since_epoch().count();
    default_random_engine dre3(seed3);
    normal_distribution<double> di3(0, 100);
    ofstream Normal;
    Normal.open("Normal.csv");

    for(int i = 0; i < 1000; i++) {
        UniformReal << di1(dre1) << endl;
    }

    for(int i = 0; i < 1000; i++) {
        Binomial << di2(dre2) << endl;
    }
    
    for(int i = 0; i < 1000; i++) {
        Normal << di3(dre3) << endl;

    }

    UniformReal.close();
    Binomial.close();
    Normal.close();

    return 0;
}
