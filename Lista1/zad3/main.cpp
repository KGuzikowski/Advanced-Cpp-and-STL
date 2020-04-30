#include <iostream>
#include <vector>

using namespace std;

int main()
{
    using strings = vector<string>;
    strings task {"Karol", "Kasia", "Piotrek", "Horacy"};

    for(auto str : task) {
        cout << str << endl;
    }

    return 0;
}
