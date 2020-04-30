#include <iostream>
#include <vector>
#include <list>
#include <set>
#include <algorithm>

using namespace std;

int main()
{
    vector<double> doubles;
    list<string> strings;
    set<int> ints;

    doubles.push_back(1.111);
    doubles.push_back(2.0987);
    doubles.push_back(20.092387);
    doubles.push_back(0.230982317);
    doubles.push_back(0.00987);
    doubles.push_back(1000.098674687);
    doubles.push_back(0.0000098674687);

    strings.push_back("Karol");
    strings.push_back("Karolina");
    strings.push_back("Agata");
    strings.push_back("Jacek");
    strings.push_back("Julia");
    strings.push_back("Joanna");
    strings.push_back("Adolf");
    strings.push_back("Zbyszek");
    strings.push_back("Dobroslaw");

    ints.insert(20);
    ints.insert(2);
    ints.insert(0);
    ints.insert(1);
    ints.insert(1000);
    ints.insert(500);
    ints.insert(10);
    ints.insert(562);
    ints.insert(122);

    // zad 1
    cout << "#######################" << endl;
    cout << "Zadanie 1" << endl;
    cout << "#######################" << endl << endl;

    double a1 = 0.2, b1 = 100.0;
    for_each(doubles.begin(), doubles.end(), [=] (double elem) {
        if (elem < b1 && elem > a1) {
            cout << elem << endl;
        }
        
    });

    cout << endl;

    string a2 = "Czwartek", b2="Piatek";
    for_each(strings.begin(), strings.end(), [=] (string elem) {
        if(elem > a2 && elem < b2) {
            cout << elem << endl;
        }
    });

    cout << endl;

    int a3 = 5, b3 = 1000;
    for_each(ints.begin(), ints.end(), [=] (int elem) {
        if(elem > a3 && elem < b3) {
            cout << elem << endl;
        }
    });

    cout << endl;

    // zad 2
    cout << "#######################" << endl;
    cout << "Zadanie 2" << endl;
    cout << "#######################" << endl << endl;

    int p = 1, k = 2;

    for (unsigned int i = p; i < doubles.size(); i += k)
    {
        cout << doubles[i] << endl;
    }

    cout << endl;

    int i = 0;
    for(string elem : strings) {
        if(i >= p && (i - p) % k == 1) {
            cout << elem << endl;
        }
        i++;
    }  

    i = 0;

    cout << endl;

    for(int elem : ints) {
        if(i >= p && i % k == 1) {
            cout << elem << endl;
        }
        i++;
    }

    cout << endl;

    // zad 3
    cout << "#######################" << endl;
    cout << "Zadanie 3" << endl;
    cout << "#######################" << endl << endl;

    double suma1 = 0, srednia1;
    for (double elem : doubles)
    {
        suma1 += elem;
    }
    srednia1 = suma1/doubles.size();
    cout << "srednia doubli to: " << srednia1 << endl;
    
    cout << endl;

    int suma2 = 0;
    double srednia2;
    for (double elem : ints)
    {
        suma2 += elem;
    }
    srednia2 = suma2/ints.size();
    cout << "srednia intow to: " << srednia2 << endl;

    cout << endl;

    // zad 4
    cout << "#######################" << endl;
    cout << "Zadanie 4" << endl;
    cout << "#######################" << endl << endl;

    auto minmax = [](auto &container) {
        return minmax_element(container.begin(), container.end());
    };

    auto doublesminmax = minmax(doubles);
    cout << *doublesminmax.first << *doublesminmax.second << endl;

    auto intsminmax = minmax(doubles);
    cout << *intsminmax.first << " " << *intsminmax.second << endl;

    // zad 5
    cout << "#######################" << endl;
    cout << "Zadanie 5" << endl;
    cout << "#######################" << endl << endl;

    double sum1 = 0;
    for_each(doubles.begin(), doubles.end(), [&] (double elem) {
        sum1 += elem;
    });
    cout << "suma doubli to: " << sum1 << endl;

    cout << endl;

    string all = "";
    for_each(strings.begin(), strings.end(), [&] (string elem) {
        all += elem + " ";
    });
    cout << all << endl;

    cout << endl;

    int sum2 = 0;
    for_each(ints.begin(), ints.end(), [&] (int elem) {
        sum2 += elem;
    });
    cout << "suma intow to: " << sum2 << endl;

    return 0;
}
