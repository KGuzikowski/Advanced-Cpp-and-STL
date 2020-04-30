#include <iostream>
#include <random>
#include <array>
#include <chrono>

using namespace std;

template <class iterator>
void randomShuffle (iterator first, iterator last)
{
    unsigned seed = chrono::system_clock::now().time_since_epoch().count();
    default_random_engine engine(seed);
    for (auto i = (last - first) - 1; i >  0; --i) {
        std::uniform_int_distribution<decltype(i)> d(0,i);
        swap (first[i], first[d(engine)]);
    }

    for(iterator i = first; i < last; i++) {
        cout << *i << " ";
    }
}

int main()
{
    array<int, 10> arr = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};

    cout << "Base:" << endl;

    for (int el : arr)
    {
        cout << el << " ";
    }

    cout << endl << endl;
    
    cout << "Permutations:" << endl;
    for(int i = 0; i < 10; i++) {
        cout << i + 1 << ") ";
        randomShuffle(arr.begin(), arr.end());
        cout << endl;
    }

    return 0;
}
