#include <iostream>

using namespace std;

template<int N, int K>
struct Newton {
    enum { value = Newton<N-1, K-1>::value * N/K};
    constexpr int operator()() const {
        return value;
    }
};

template<int N>
struct Newton<N, 0> {
    enum { value = 1 };
    constexpr int operator()() const {
        return value;
    }
};

template<int N>
struct Newton<N, N> {
    enum { value = 1 };
    constexpr int operator()() const {
        return value;
    }
};

int main()
{
    constexpr int L = Newton<10, 2>()();
    cout << L << endl;
    return 0;
}
