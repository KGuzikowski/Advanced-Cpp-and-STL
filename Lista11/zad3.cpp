#include <iostream>

using namespace std;

template<int A, int B>
struct NWD {
    enum { value = NWD<B, A%B>::value};
    constexpr int operator()() const {
        return value;
    }
};

template<int A>
struct NWD<A, 0> {
    enum { value = A };
    constexpr int operator()() const {
        return value;
    }
};

int main()
{
    constexpr int L = NWD<1989, 867>()();
    cout << L << endl;
    return 0;
}
