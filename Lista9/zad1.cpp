#include <iostream> 
#include <iterator> 
#include <vector> 
#include <sstream>
#include <iomanip>

using namespace std;

int main() {
    vector<double> v;
    copy(istream_iterator<double>(cin), istream_iterator<double>(), back_inserter(v));
    
    cout << fixed << setprecision(3);
    for (auto it = v.end() - 1; it != v.begin() - 1; it=it-1)
        cout << *it << endl;


    return 0;
}
