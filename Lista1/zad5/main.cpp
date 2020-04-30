#include <iostream>

using namespace std;

constexpr auto LucasNumber(int n) {
    if(n == 0) return 2;
    if(n == 1) return 1;
    return LucasNumber(n-1) + LucasNumber(n-2);
}

int main()
{
    int Lucas = LucasNumber(100);

    cout << Lucas << endl;
    return 0;
}
