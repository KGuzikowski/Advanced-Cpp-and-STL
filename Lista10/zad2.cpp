#include <iostream>
#include <list>
#include <algorithm>
#include <cmath>

using namespace std;

struct point
{
    string name;
    float x, y;
    unsigned int R, G, B;
};

void DivideToQuarters(const list<point> &points) {
    list<point> I, II, III, IV;
    for_each(points.begin(), points.end(), [&](const point &p){
        if(p.x >= 0 && p.y >= 0) I.push_back(p);
        else if(p.x < 0 && p.y >= 0) II.push_back(p);
        else if(p.x < 0 && p.y < 0) III.push_back(p);
        else if(p.x >= 0 && p.y <= 0) IV.push_back(p);
    });

    cout << "First quarter:" << endl;
    for(point p : I) cout << p.name << ", ";
    cout << "\nSecond quarter:" << endl;
    for(point p : II) cout << p.name << ", ";
    cout << "\nThird quarter:" << endl;
    for(point p : III) cout << p.name << ", ";
    cout << "\nFourth quarter:" << endl;
    for(point p : IV) cout << p.name << ", ";
    cout << endl << endl;
}

int ColorCode(point p) {
    return p.R * 65536 + p.G * 256 + p.B;
}

int main()
{
    list<point> points;
    points.push_back({"black", 5, 5, 0, 0, 0});
    points.push_back({"white", -1, 5, 255, 255, 255});
    points.push_back({"red", -3, -5, 255, 0, 0});
    points.push_back({"pink", 3, -5, 255, 0, 255});

    DivideToQuarters(points);

    points.sort([](point p1, point p2) {
        return ColorCode(p1) > ColorCode(p2);
    });

    cout << endl;
    cout << "Brightest: " << points.front().name << endl;
    cout << "Darkest: " << points.back().name << endl;

    return 0;
}
