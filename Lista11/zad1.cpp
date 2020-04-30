#include <iostream>

using namespace std;

template<int N>
struct Lucas {
    enum { value = Lucas<N-1>::value + Lucas<N-2>::value};
    constexpr int operator()() const {
        return value;
    }
};

template<>
struct Lucas<0> {
    enum { value = 2 };
    constexpr int operator()() const {
        return value;
    }
};

template<>
struct Lucas<1> {
    enum { value = 1 };
    constexpr int operator()() const {
        return value;
    }
};

int main()
{
    constexpr int L = Lucas<4>()();
    cout << L << endl;
    return 0;
}
