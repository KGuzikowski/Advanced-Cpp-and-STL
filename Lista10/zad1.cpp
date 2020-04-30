#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

struct person
{
    string name;
    unsigned int age;
    unsigned int weight;
    unsigned int height;
};

person Oldest(const vector<person> &people) {
    person oldest = people[0];
    for_each(people.begin(), people.end(), [&](const person &p){
        if (p.age > oldest.age) oldest = p;
    });
    return oldest;
}

person Heaviest(const vector<person> &people) {
    person heaviest = people[0];
    for_each(people.begin(), people.end(), [&](const person &p){
        if (p.weight > heaviest.weight) heaviest = p;
    });
    return heaviest;
}

person Tallest(const vector<person> &people) {
    person tallest = people[0];
    for_each(people.begin(), people.end(), [&](const person &p){
        if (p.height > tallest.height) tallest = p;
    });
    return tallest;
}

int main()
{
    vector<person> people = {
        { "Franek Trabka", 21, 82, 180 },
        { "Oliwia Duzababa", 24, 130, 170 },
        { "Zbychu Maly", 14, 52, 165 },
        { "Pan Wladek", 55, 90, 180 },
        { "Krystyna Lubi", 38, 69, 174 }
    };

    sort(people.begin(), people.end(), [](const person &p1, const person &p2) {
        return p1.weight/pow(p1.height, 2) > p2.weight/pow(p2.height, 2);
    });
    
    cout << "Sorted by BMI:" << endl;
    for(person p : people) cout << p.name << ", ";
    cout << endl << endl;

    cout << "The oldest person: " << Oldest(people).name << ", age is " << Oldest(people).age << endl;
    cout << "The heaviest person: " << Heaviest(people).name << ", weight is " << Heaviest(people).weight << endl;
    cout << "The tallest person: " << Tallest(people).name << ", height is " << Tallest(people).height << endl;

    return 0;
}
