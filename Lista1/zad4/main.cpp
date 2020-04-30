#include <iostream>
#include <vector>

using namespace std;

enum class Names : uint16_t { karol, agata, julka, jacek, asia };

void message(string msg, Names nameCode) {
    switch (nameCode)
    {
    case Names::karol:
        cout << msg << ", Karol" << endl;
        break;
    case Names::agata:
        cout << msg << ", Agata" << endl;
        break;
    case Names::julka:
        cout << msg << ", Julka" << endl;
        break;
    case Names::jacek:
        cout << msg << ", Jacek" << endl;
        break;
    case Names::asia:
        cout << msg << ", Asia" << endl;
        break;
    }
}

int main()
{
    Names ka { Names::karol };

    message("Siema", ka);

    return 0;
}
