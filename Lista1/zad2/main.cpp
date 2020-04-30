#include <iostream>

using namespace std;

int main()
{
    // normal string
    string normal = "Działa? \"Karol\"\n, () \")";

    // raw string
    string raw = R"!!(Działa?
    \"Karol\"\n, ()
    \")")!!";

    cout << normal << endl;
    cout << "raw: " << raw << endl;

    return 0;
}
