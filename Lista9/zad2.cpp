#include <iostream>
#include <numeric>
#include <array>
#include <algorithm>
#include <iterator>
#include <fstream>

using namespace std;

int totient(int n) {
    int res = 1;
    for (int i = 2; i < n; ++i) {
        if (gcd(n, i) == 1)
            ++res;
    }
    return res;
}

int main() {
    constexpr int k = 12;
    array<int, k> arr;
    generate(arr.begin(), arr.end(), [n = 1]() mutable {return totient(n++);});
    ofstream file("phi.txt");
    ostream_iterator<int> out_iter(file, "; ");
    copy(arr.begin(), arr.end(), out_iter);
    return 0;
}
